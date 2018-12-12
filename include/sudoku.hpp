#ifndef BIS_GG_RESOLVE_SUDOKU_WITH_COLORING_SUDOKU_H
#define BIS_GG_RESOLVE_SUDOKU_WITH_COLORING_SUDOKU_H

#include <tuple>
#include <vector>
#include <set>

#include "graph.hpp"

/*
 *
 * Todo:
 * - Obter a instancia de Grafo e garantir que sea a unica [v] []
 * - Obter uma cor em uma dada posição [v] []
 * - Implementar o Welsh Powell para coloração [v] []
 * - Implementar o Dsatur para coloração [v] []
 * - Mostrar o tabuleiro [v] []
 * - Mostrar o tabuleiro pré-colorido dos dados do arquivo [v] []
 * - Lê o arquivo no formato index -> value [v] []
 * - Retorna o número de cores iniciais do arquivo [v]
 *
 * */

class Sudoku {

private:
    Graph graph;
    int colors[81];
    vector<tuple<int, int> > numbers;
    set<int> indexConstants;

public:
    Sudoku();
    Sudoku(vector<tuple<int, int> >& numbers);
    ~Sudoku() = default;

    /**
     *
     * Garante uma instância Singleton para grafo
     *
     * */
    const Graph& getGraph() const;

    /**
     *
     *	Retorna a cor numa posição n
     *
    */
    int getColorAt(int n) const;

    /**
     *
     *	Implementação do algoritmo DSatur para coloração
     *
     */
    bool DSatur();

    /**
     *
     *	Implementação do algoritmo Welsh Powell para coloração
     *
     */
    bool WelshPowell();

    /**
     *
     *	Mostra os índices da pré-coloração
     *
    */
    void showBoardPreColorIndex() const;

    /**
     *
     *	Mostra o board do sudoku
     *
    */
    void showFullBoard() const;

    /**
     *
     *	Retorna o número inicial de cores
     *
    */
    int getPreColorSize() const;

    /**
     *
     *	Pré carrega as cores vindo do arquivo
     *
    */
    bool loadBoardFromFile(const string& name);

    /**
     *
     * Pré-colorindo o grafo
     * O vetor de cores (colors) recebe no indice correspondente de toda a coluna esquerda os valores ques estão à direita
     * Isso faz referência aos dados padrões do arquivo, onde mesmo é composto por index e value
     *
     * */
    void preColoring (vector<tuple<int, int> > numbersAux);
};

#endif //BIS_GG_RESOLVE_SUDOKU_WITH_COLORING_SUDOKU_H
