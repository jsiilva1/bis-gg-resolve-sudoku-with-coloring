/**
 *
 * Created by Jr Silva on 11/12/2018
 *
**/

#include "../include/sudoku.hpp"

using namespace std;

Sudoku::Sudoku() {

    // Iniciliza o tabuleiro com todas as 81 posições com uma única cor (color 0)
    for (int i = 0; i < 81; i++) {
        this->colors[i] = 0;
    }
}

Sudoku::Sudoku(vector<tuple<int, int> > numbers) {

    // Iniciliza o tabuleiro com todas as 81 posições com uma única cor (color 0)
    for (int i = 0; i < 81; i++) {
        this->colors[i] = 0;
    }

    /**
     * Pré-colorindo o grafo
     * O vetor de cores (colors) recebe no indice correspondente de toda a coluna esquerda os valores ques estão à direita
     * Isso faz referência aos dados padrões do arquivo, onde mesmo é composto por index e value
     *
     * */
    for (int j = 0; j < numbers.size(); j++) {
        this->colors[get<0>(numbers.at(j))] = get<1>(numbers.at(j));
        this->indexConstants.insert(get<0>(numbers.at(j)));
    }
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


