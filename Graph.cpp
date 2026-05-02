#include "Graph.h"
#include <iostream>
#include <climits>

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
        for (int i = 1; i < numVertices + 1; i++) {
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
        vertex1.setDegree(vertex1.getDegree() + 1);
        vertex2.setDegree(vertex2.getDegree() + 1);
    
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

    printOdd();
    // DEBUG LATER: consider changing odd_vertices to just indices only , int array instead.
}

/* === DIJKSTRAS WRAPPER FUNCTION === */

void Graph::runDijkstra() {
    for (int i = 0; i < num_odd; i++) {
        std::cout << "The shortest path lengths from Node " << odd_vertices[i].getIndex() << " to all other nodes are:" << std::endl;
        dijkstra(odd_vertices[i].getIndex());
    }
}




/* === MAIN DIJKSTRAS FUNCTION === */
void Graph::dijkstra(int current) {

    /* === INITIALIZATION PHASE === 
    
        1. Initialize the Distances Array; we will use indices of 1 to numVertices
            --> Set the original current index to distance of 0
            --> Set the other indices equal to MAX_INT or +INFINITY

        2. Initialize the boolean Visited Array. this array also uses indices 1 to numVertices
            --> Set the current index to true. Everything else to false
    
    */
    
    // 1. 
    int distances[numVertices + 1];
    for (int i = 1; i < numVertices + 1; i++) {
        if (i == current) {
            distances[i] = 0;
        }
        else {
            distances[i] = INT_MAX;
        }
    }

    
    bool visited[numVertices + 1];

    // 2. 
    for (int i = 1; i < numVertices + 1; i++) {
        if (i == current) {
            continue;
        }
        visited[i] = false;
    }

    visited[current] = true;
    

    /* === MAIN LOOP ===

        1. Outer Loop -> Iterate numVertices amount of times.
        2. Inner Loop -> Goes from 1 to the number of Cols within a particular adjacency matrix row (of current)
        
            --> Perform logic to check the adjacency map row for current --> if it has a non-zero value in any column, that is a neighbor.
            --> Calculate the new distance, accounting for the distance it takes starting from the OG starting node

            --> Overwrite the new distances if it's smaller than what we had before.
            --> Perform relaxation, finding the global min in the distance array and traversing through it
    */ 

    for (int i = 0; i < numVertices; i++) {

        // check the neighbors:
        for (int j = 1; j < numVertices + 1; j++) {
            
            // if the value in the adjacency matrix row for current node is not equal to 0 --> it has a connection
            // if the node has not been visited yet, we can include it
            if (adjMatrix[current][j] != 0 && !visited[j]) {
                
                int new_distance = distances[current] + adjMatrix[current][j];  

                // If the new distance is smaller than the current distance in the array, overwrite it
                if (new_distance < distances[j]) {
                    distances[j] = new_distance;
                }
            }
        }

    // distance calculations complete for the current node: 
    // RELAXATION - choose smallest global node if it's not visited yet

    // LOOP THROUGH THE DISTANCES ARRAY
    int min = INT_MAX;
    int min_index = -1;
    for (int i = 1; i < numVertices + 1; i++) {
        if (!visited[i] && distances[i] < min) {
            min = distances[i];
            min_index = i;
        }
    }

    // if we've visited all the nodes in the array, we stop the program here

    if (min_index == -1) {
        break;
    }

    // else, we can traverse into the new node, that being the globally smallest node
    // set the min index to true in the visited array
    current = min_index;
    visited[min_index] = true;

    }

    // Print distance array
        
    printDijkstras(distances);

}

/* === HELPER METHODS / PRINTING METHODS ARE BELOW: === */

/* === helper method for addEdge, alters the adjMatrix 2D array === */
void Graph::setAdjMatrix(int row, int col, int weight) {
    adjMatrix[row][col] = weight;
}

void Graph::printAdjMatrix() {
    std::cout << "The adjacency matrix of G is:" << std::endl;
    // loop through 2D array numVertices x numVertices amt of times
    for (int i = 1; i < numVertices+1; i++) {
        for (int j = 1; j < numVertices+1; j++) {
            std::cout << adjMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
}

void Graph::printOdd() {
    std::cout << "The nodes with odd degrees in G are:" << std::endl;
    std::cout << "O = { ";
    for (int i  = 0; i < num_odd; i++) {
        std::cout << odd_vertices[i].getIndex() << " ";
    }
    std::cout << "}" << std::endl << std::endl;
}

void Graph::printDijkstras(int num[]) {
    for (int i = 1; i < numVertices + 1; i++) {
        std::cout << i << ": " << num[i] << std::endl;
    }

    std::cout << std::endl;
}


