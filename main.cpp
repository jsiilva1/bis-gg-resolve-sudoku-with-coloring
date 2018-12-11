#include <iostream>
#include "include/graph.hpp"
#include "include/sudoku.hpp"

using namespace std;

int main() {

    Graph graph;
    Sudoku sudoku;

    graph.newManyVertex(5);

    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);

    graph.showGraph();

    string fileDirectory = "J:\\Jr Silva\\Faculdade\\bis-gg-resolve-sudoku-with-coloring\\data\\";
    sudoku.loadBoardFromFile(fileDirectory+"data_sudoku_test.txt");

    
}