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

void Graph::newManyVertex(int n) {
    for (int i = 0; i < n; i++)
        this->newVertex();
}

const set<int>& Graph::getVertex(unsigned int vertexIndex) const {
    return this->vertex.at(vertexIndex);
}

int Graph::getVertexDegree(unsigned int vertexIndex) const {
    return this->vertex.at(vertexIndex).size();
}

void Graph::pushBackEdge(int vertexIndex, int vertexTarget) {
    this->vertex[vertexIndex].insert(vertexTarget);
}

bool Graph::isEdgeExists(const set<int> &v1, int v2) const {
    return v1.find(v2) != v1.end();
}

void Graph::addEdge(int v1, int v2) {
    if (v1 >= this->vertex.size() || v2 >= this->vertex.size())
        return;

    if (!this->isEdgeExists(this->getVertex(v1), v2))
        pushBackEdge(v1, v2);

    if (!this->isEdgeExists(this->getVertex(v2), v1))
        pushBackEdge(v2, v1);
}