#include <iostream>
#include <locale>

#include "include/graph.hpp"
#include "include/sudoku.hpp"

using namespace std;

int main() {

    setlocale(LC_ALL, "portuguese");

    // Full path dos arquivos de entrada
    // Alterar para o contexto absoluto do projeto de sua máquina
    string fileDirectory = "J:\\Jr Silva\\Faculdade\\bis-gg-resolve-sudoku-with-coloring\\data\\";

    Sudoku sudoku;

    // Lê os dados do arquivo e implanta na instância do Sudoku
    bool read = sudoku.loadBoardFromFile(fileDirectory+"sudoku_data_2.txt");

    if (read) {

        cout  << "Tabuleiro pré-colorido: ";
        sudoku.showFullBoard();

        // Aplica o algoritmo para colorir
        sudoku.welshPowellAlgorithm();

        cout << "Tabuleiro com a resolução completa ou parcial";
        sudoku.showFullBoard();

    } else cout << "Impossível ler os dados do arquivo. Verifique se o nome/caminho do mesmo está correto!";

}