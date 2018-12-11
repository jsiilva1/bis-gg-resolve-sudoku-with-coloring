/**
 *
 * Created by Jr Silva on 11/12/2018
 *
* */

#include "../include/graph.hpp"

Graph::Graph(vector<set<int> > vertex) : vertex(std::move(vertex)) {}

int Graph::newVertex()
{
    this->vertex.emplace_back(set<int>());
    return this->vertex.size() - 1;
}