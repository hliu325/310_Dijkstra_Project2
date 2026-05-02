#ifndef GRAPH_H
#define GRAPH_H

#include "Vertex.h"
#include "Edge.h"

class Graph {
    private:
    // Attributes of a Graph:
    // 1D Array for the Vertices, 2d Array for the Adj Matrix
        Vertex* vertices;
        int** adjMatrix;

    // 1D Array for Odd Degree Vertices
        Vertex* odd_vertices;
        int num_odd;

        // input parameters for size; required for other methods like printing
        int numVertices = 0;
        int numEdges = 0;
    public:
        // constructor:
        Graph(int numVertices, int numEdges);

        // core methods:
        void addEdge(int v1, int v2, int weight);
        void checkOdd();
        
        // helper methods:
        void setAdjMatrix(int row, int col, int weight);
        void printAdjMatrix();
        void printOdd();
        
};              

#endif