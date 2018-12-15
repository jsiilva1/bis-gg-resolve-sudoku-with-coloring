// Copyright (c) 2018 Jr Silva
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <iostream>
#include <fstream>
#include <algorithm>
#include "../include/sudoku.hpp"

using namespace std;

Sudoku::Sudoku() {

    // Iniciliza o tabuleiro com todas as 81 posições com uma única cor (color 0)
    for (int i = 0; i < 81; i++)
        this->colors[i] = 0;

    // Gera o grafo a partir da lógica de conexões do tabuleiro do Sudoku
    this->generateGraph();
}

Sudoku::Sudoku(vector<tuple<int, int> > numbers) {

    // Iniciliza o tabuleiro com todas as 81 posições com uma única cor (color 0)
    for (int i = 0; i < 81; i++)
        this->colors[i] = 0;

    /**
     * Pré-colore o grafo
     * O vetor de cores (colors) recebe no indice correspondente à toda a coluna da esquerda, os valores que estão à direita
     * Isso faz referência aos dados padrões do arquivo, onde mesmo é composto por linhas no formato {index value}
     *
     * */
    // Pré-colore os números do tabuleiro no formato index -> value
    this->preColoring(numbers);

    // Gera o grafo a partir da lógica de conexões do tabuleiro do Sudoku
    this->generateGraph();
}

const Graph& Sudoku::getGraph() const {
    return this->graph;
}

int Sudoku::getColorAt(int n) const {
    return this->colors[n];
}

bool Sudoku::isColored(int index) const {
    return this->colors[index] > 0;
}

int Sudoku::getPreColorSize() const {
    return this->indexConstants.size();
}

int Sudoku::getColorsSize () const {
    return sizeof(this->colors) / 4;
}

void Sudoku::preColoring(vector<tuple<int, int> > numbersAux) {
    for (int i = 0; i < numbersAux.size(); i++) {
        // Pré-colorindo
        this->colors[get<0>(numbersAux.at(i))] = get<1>(numbersAux.at(i));
        this->indexConstants.insert(get<0>(numbersAux.at(i)));
    }
}

void Sudoku::generateGraph() {

    // Aloca 81 vértices para o grafo
    this->graph.newManyVertex(81);

    static int j, quadrantColumn, quadrantRow;

    for (int i = 0; i < 81; i++) {

        quadrantRow = this->getRowQuadrant(i);
        quadrantColumn = this->getColumnQuadrant(i);

        j = i + 1; // Conexões entre as colunas

        while (this->getColumnQuadrant(j) == quadrantColumn) {
            if (this->getRowQuadrant(j) == quadrantRow) {
                this->graph.addEdge(i, j);
                j++;
            } else {
                j += 6;
            }
        }

        j = i + 1; // Conexões entre linhas

        // Evita repetições das arestas
        while (this->getRowQuadrant(j) == quadrantRow) j++;

        while (j % 9 > i % 9) {
            this->graph.addEdge(i, j);
            j++;
        }

        j = i + 9; // Conexões das linhas

        // Evita repetições das arestas
        while (this->getColumnQuadrant(j) == quadrantColumn) j += 9;

        while (j < 81) {
            this->graph.addEdge(i, j);
            j += 9;
        }
    }
}

int Sudoku::getRowQuadrant(int i) const {
    return (i % 9) / 3;
}

int Sudoku::getColumnQuadrant(int i) const {
    return (i / 9) / 3;
}

bool Sudoku::loadBoardFromFile(const string& name) {
    ifstream file;
    string lines;

    int index, colors, j = 0;
    vector<tuple<int, int> > numbers;

    file.open(name);
    if (!file.is_open())
        return false;

    while (!file.eof() && j < 81) {
        getline(file, lines);
        sscanf(lines.c_str(), "%d %d", &index, &colors);
        numbers.emplace_back(make_tuple(index, colors));
        j++;
    }

    // Pré-colore os números do tabuleiro no formato index -> value
    this->preColoring(numbers);

    return true;
}

void Sudoku::showBoardPreColorIndex() const {
    set<int>::iterator i;
    int contador = 0;

    cout << endl << "[";

    for (i = this->indexConstants.begin(); i != this->indexConstants.end(); i++) {
        if (i != this->indexConstants.begin())
            cout << ", ";

        if (contador % 10 == 0 && contador)
            cout << " ";

        cout << *i;
        contador++;
    }

    cout << "]" << endl;
}

void Sudoku::showFullBoard() const {

    cout << endl;
    cout << "  ----------------------- " << endl;

    for (int i = 0; i < 81; i++) {

        if (i % 9 == 0 && i != 0){
            cout << " |" << endl;

            if ((i / 9) % 3 == 0)
                cout << "  ----------------------- " << endl;
        }

        if (i % 3 == 0)
            cout << " |";

        if (this->colors[i] == 0)
            cout << "  ";
        else
            cout << " " << this->colors[i];
    }

    cout << " |" << endl;
    cout << "  ----------------------- " << endl;
}

bool Sudoku::welshPowellAlgorithm() {
    vector<set<int>> possible_colors(81, set<int>());
    vector<int> uncolored;

    for (int i = 0; i < 81; i++) {
        if (this->indexConstants.find(i) == this->indexConstants.end()) {
            // Marca o vértice como não colorido
            uncolored.push_back(i);

            // Marca uma possível cor para o vértice
            for (int j = 1; j <= 9; j++)
                possible_colors.at(i).insert(j);
        }
    }

    // Para cada vértice pré-colorido
    for (auto i = this->indexConstants.begin(); i != this->indexConstants.end(); i++) {
        // obtém seus adjacentes
        set<int> neighbors = this->graph.getVertex(*i);

        // Para cada vizinho deste vértice pré-colorido
        for (auto j = neighbors.begin(); j != neighbors.end(); j++) {

            auto eraser = possible_colors.at(*j).find(this->colors[*i]);

            if (eraser != possible_colors.at(*j).end())
                possible_colors.at(*j).erase(eraser);
        }
    }

    // Ordenar os vértices na crescente, mediante uma expressão lambda, considerando a quantidade possivel de cores
    sort(uncolored.begin(), uncolored.end(), [possible_colors](const int& i, const int& j) -> bool {
        return possible_colors.at(i).size() < possible_colors.at(j).size();
    });

    // Iterar as possibilidades concretas de cores
    for (int i = 1; i < uncolored.size() + 1; i++) {

        if (possible_colors.at(uncolored.at(i-1)).size() == 0)
            return false;

        this->colors[uncolored.at(i-1)] = *(possible_colors.at(uncolored.at(i-1)).begin());

        set<int> neighbors = this->getGraph().getVertex(uncolored.at(i-1));

        for (auto j = neighbors.begin(); j != neighbors.end(); j++) {

            auto eraser = possible_colors.at(*j).find(this->colors[uncolored.at(i-1)]);

            if (eraser != possible_colors.at(*j).end())
                possible_colors.at(*j).erase(eraser);
        }
    }

    return true;
}