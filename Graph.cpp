#include "Graph.h"
#include <iostream>

// Constructor
Graph::Graph(int numVertices, int numEdges) {

        // init number of vertices + vertices array
        this->numVertices = numVertices;
        vertices = new Vertex[numVertices + 1];

        // init all vertices from [1 to n]
        for (int i = 1; i < numVertices + 1; i++) {
            Vertex vertex_i;
            vertex_i.setIndex(i);

            // add to the vertices array at its corresponding index
            vertices[i] = vertex_i;
        }
        
        // init number of edges
        this->numEdges = numEdges;

        // init the adjacency matrix 2D array: 
        adjMatrix = new int*[numVertices+1];
        for (int i = 0; i < numVertices + 1; i++) {
            adjMatrix[i] = new int[numVertices+1]();
        }
}

void Graph::addEdge(int v1, int v2, int weight) {
    // 1) count degrees every time you add an edge

    // create Vertex objects from the index in Vertices for convenience, as we will reuse it here
        Vertex& vertex1 = vertices[v1];
        Vertex& vertex2 = vertices[v2];

    // IF vertices have a degree of -1 still, set it to 1. 
    // ELSE increment its previous value by 1
        if (vertex1.getDegree() == -1) {
            vertex1.setDegree(1);
        }
        else {
            vertex1.setDegree(vertex1.getDegree() + 1);
        }

        if (vertex2.getDegree() == -1) {
            vertex2.setDegree(1);
        }
        else {
            vertex2.setDegree(vertex2.getDegree() + 1);
        }
    
    // 2) add to the adjacency matrix

    // We add both because it's an undirected graph
    setAdjMatrix(v1, v2, weight);
    setAdjMatrix(v2, v1, weight);
}

/* === This method will be used once we have added ALL nodes and edges, so we only need to call it once. === */
void Graph::checkOdd() {
    // Set odd_vertices array to max possible size (numVertices)
    odd_vertices = new Vertex[numVertices];
    num_odd = 0;

    for (int i = 1; i < numVertices + 1; i++) {
        if (vertices[i].getDegree() % 2 != 0) {
            odd_vertices[num_odd] = vertices[i];
            num_odd++;
        }
    }

    // DEBUG LATER: consider changing odd_vertices to just indices only , int array instead.
}

/* === helper method for addEdge, alters the adjMatrix 2D array === */
void Graph::setAdjMatrix(int row, int col, int weight) {
    adjMatrix[row][col] = weight;
}

void Graph::printAdjMatrix() {
    // loop through 2D array numVertices x numVertices amt of times
    for (int i = 1; i < numVertices+1; i++) {
        for (int j = 1; j < numVertices+1; j++) {
            std::cout << adjMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void Graph::printOdd() {
    std::cout << "{ ";
    for (int i = 0; i < num_odd; i++) {
        std::cout << odd_vertices[i].getIndex() << " ";
    }
    std::cout << "}" << std::endl;
}


