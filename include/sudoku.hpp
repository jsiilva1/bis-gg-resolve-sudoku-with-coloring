#ifndef BIS_GG_RESOLVE_SUDOKU_WITH_COLORING_SUDOKU_H
#define BIS_GG_RESOLVE_SUDOKU_WITH_COLORING_SUDOKU_H

#include <tuple>
#include <vector>
#include <set>

#include "graph.hpp"

/*
 *
 * Todo:
 * - Obter a instancia de Grafo e garantir que seja a unica [v] [v]
 * - Obter uma cor em uma dada posição [v] [v]
 * - Implementar o Welsh Powell para coloração [v] [v]
 * - Implementar o Dsatur para coloração [v] []
 * - Mostrar o tabuleiro [v] [v]
 * - Mostrar o tabuleiro pré-colorido dos dados do arquivo [v] [v]
 * - Lê o arquivo no formato index -> value [v] [v]
 * - Retorna o número de cores iniciais do arquivo [v]
 *
 * */

class Sudoku {

private:

    Graph graph;

    set<int> indexConstants;
    int colors[81];
    vector<tuple<int, int> > numbers;

    /**
     *
     * Pré-colorindo o grafo
     * O vetor de cores (colors) recebe no indice correspondente de toda a coluna esquerda os valores ques estão à direita
     * Isso faz referência aos dados padrões do arquivo, onde mesmo é composto por index e value
     *
     * */
    void preColoring (vector<tuple<int, int> > numbersAux);

public:
    Sudoku();
    Sudoku(vector<tuple<int, int> > numbers);
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
    bool DSaturAlgorithm();

    /**
     *
     *	Implementação do algoritmo Welsh Powell para coloração
     *
     */
    bool welshPowellAlgorithm();

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
     *	Gera as arestas do grafo baseado no arquivo
     *
    */
    void generateGraph();

    /**
     *
     *	Método para obter uma linha/coluna referente ao índice do grafo, para pôr no tabuleiro
     *	Garante a logica da posição dos números na matriz ou nas submatrizes do tabuleiro
     *
    */
    int getRowQuadrant(int i) const;
    int getColumnQuadrant(int i) const;

    /**
     *
     *	Obtém o grau de saturação de um dado vértice
     *
    */
    void getSaturation (int index);

    /**
     *
     *	Verifica se um vértice esta colorido
     *
    */
    bool isColored (int index) const;


    int getColorsSize() const;
};

#endif //BIS_GG_RESOLVE_SUDOKU_WITH_COLORING_SUDOKU_H
