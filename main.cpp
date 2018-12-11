#include <iostream>
#include "include/graph.hpp"

using namespace std;

int main() {

    Graph graph;
    graph.newManyVertex(5);

    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);

    graph.showGraph();
}