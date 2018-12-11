#ifndef BIS_GG_RESOLVE_SUDOKU_WITH_COLORING_GRAPH_HPP
#define BIS_GG_RESOLVE_SUDOKU_WITH_COLORING_GRAPH_HPP

#include <vector>
#include <iostream>
#include <set>

using namespace std;

class Graph {

private:
    vector<set<int> > vertex;

public:
    Graph() = default;
    Graph(vector<set<int> > vertices);
    ~Graph() = default;

    /*
     *
     * To-do:
     *
     * - Adicionar novo vértice
     * - verificar se é adjacente
     * - adicionar uma aresta
     * - obter um dado vértice
     * - obter o grau do vértice
     * - mostrar o grafo
     *
     *
     * */
};

#endif //BIS_GG_RESOLVE_SUDOKU_WITH_COLORING_GRAPH_HPP
