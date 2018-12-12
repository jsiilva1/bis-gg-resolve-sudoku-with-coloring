/**
 *
 * Created by Jr Silva on 11/12/2018
 *
**/

#include <fstream>
#include "../include/sudoku.hpp"

using namespace std;

Sudoku::Sudoku() {

    // Iniciliza o tabuleiro com todas as 81 posições com uma única cor (color 0)
    for (int i = 0; i < 81; i++) {
        this->colors[i] = 0;
    }
}

Sudoku::Sudoku(vector<tuple<int, int> >& numbers) {

    // Iniciliza o tabuleiro com todas as 81 posições com uma única cor (color 0)
    for (int i = 0; i < 81; i++) {
        this->colors[i] = 0;
    }

    /**
     * Pré-colore o grafo
     * O vetor de cores (colors) recebe no indice correspondente à toda a coluna da esquerda, os valores que estão à direita
     * Isso faz referência aos dados padrões do arquivo, onde mesmo é composto por linhas no formato {index value}
     *
     * */
    this->preColoring(numbers);
}

const Graph& Sudoku::getGraph() const {
    return this->graph;
}

int Sudoku::getColorAt(int n) const {
    return this->colors[n];
}

int Sudoku::getPreColorSize() const {
    return this->indexConstants.size();
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

void Sudoku::preColoring(vector<tuple<int, int> > numbersAux) {
    for (int i = 0; i < numbersAux.size(); i++) {
        // Pré-colorindo
        this->colors[get<0>(numbersAux.at(i))] = get<1>(numbersAux.at(i));
        this->indexConstants.insert(get<0>(numbersAux.at(i)));
    }
}

void Sudoku::showBoardPreColor() const {
    
}