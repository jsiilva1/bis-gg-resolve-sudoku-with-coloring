#ifndef BIS_GG_RESOLVE_SUDOKU_WITH_COLORING_SUDOKU_H
#define BIS_GG_RESOLVE_SUDOKU_WITH_COLORING_SUDOKU_H

#include <tuple>
#include <vector>
#include <set>

#include "graph.hpp"

int tuple;

class Sudoku {

private:
    Graph graph;
    int colors[81];
    set<int> indexConstants;

public:
    Sudoku();
    Sudoku(vector<tuple<int, int> > numbers);
    ~Sudoku() = default;

};

#endif //BIS_GG_RESOLVE_SUDOKU_WITH_COLORING_SUDOKU_H
