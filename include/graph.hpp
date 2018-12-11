#ifndef BIS_GG_RESOLVE_SUDOKU_WITH_COLORING_GRAPH_HPP
#define BIS_GG_RESOLVE_SUDOKU_WITH_COLORING_GRAPH_HPP

#include <vector>
#include <iostream>
#include <set>

using namespace std;

/*
 *
 * To-do:
 *
 * - Adicionar novo vértice [v] []
 * - Adicionar n vertices [v] []
 * - verificar se é adjacente [v] []
 * - adicionar uma aresta [v] []
 * - obter um dado vértice [v] []
 * - obter o grau do vértice [v] []
 * - mostrar o grafo [v] []
 *
 * */

class Graph {

private:
    vector<set<int> > vertex;

public:
    Graph() = default;
    Graph(vector<set<int> > vertices);
    ~Graph() = default;

    /*
     *
     * Adiciona um novo vértice e retorna o número
     *
     * */
    int newVertex();

    /*
     *
     * Adicionar n vértices ap grafo
     *
     * */
    void newManyVertex(int n);

    /*
     *
     * Obter um vértice por um índice específico
     *
     * */
    const set<int>& getVertex(int vertexIndex) const;

    /**
     *
     *	Obtém o grau de um vértice específico
     *
    */
    int getVertexDegree(int vertexIndex) const;

    /*
     *
     * Adicionar uma aresta entre dois vértices
     *
     * */
    void addEdge(int v1, int v2);

    /*
     *
     * Verificar se um vértice é adjacente a outro na lista
     *
     * */
    bool isEdgeExists(const set<int>& v1, int v2) const;

    /**
     *
     *	Mostra o grafo
     *
    */
    void showGraph() const;

};

#endif //BIS_GG_RESOLVE_SUDOKU_WITH_COLORING_GRAPH_HPP
