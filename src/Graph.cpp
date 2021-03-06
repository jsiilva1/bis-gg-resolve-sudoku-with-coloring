// Copyright (c) 2018 Jr Silva
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <iomanip>
#include "../include/graph.hpp"

Graph::Graph(vector<set<int> > vertex) : vertex(std::move(vertex)) {  }

int Graph::newVertex() {
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

bool Graph::isAdjacent(const set<int>& v1, int v2) const {
    return v1.find(v2) != v1.end();
}

void Graph::addEdge(int v1, int v2) {
    if (v1 >= this->vertex.size() || v2 >= this->vertex.size())
        return;

    if (!this->isAdjacent(this->getVertex(v1), v2))
        pushBackEdge(v1, v2);

    if (!this->isAdjacent(this->getVertex(v2), v1))
        pushBackEdge(v2, v1);
}

void Graph::showGraph() const {

    for (unsigned int i = 0; i < this->getGraphSize(); i++) {
        cout << "v[" << i << "] -> ";

        for (auto j = this->vertex.at(i).begin(); j != this->vertex.at(i).end(); j++) {
            if (j != this->vertex.at(i).begin())
                cout << ", ";

            cout << setw(2) << *j;
        }

        cout << endl;
    }
}

int Graph::getGraphSize() const {
    return this->vertex.size();
}