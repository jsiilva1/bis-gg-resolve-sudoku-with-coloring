#include <iostream>
#include <memory>

#include "include/graph.hpp"
#include "include/sudoku.hpp"

using namespace std;

int main() {

    string fileDirectory = "J:\\Jr Silva\\Faculdade\\bis-gg-resolve-sudoku-with-coloring\\data\\";

    Sudoku sudoku;
    bool read = sudoku.loadBoardFromFile(fileDirectory+"data_sudoku_test_2.txt");

    if (sudoku.welshPowellAlgorithm())
        cout << "Solução válida encontrada!" << endl;
    else
        cout << "Impossível encontrar uma solução";

    sudoku.showFullBoard();
}