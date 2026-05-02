#include "Edge.h"
#include "Vertex.h"
#include "Graph.h"
#include <iostream>

int main(){

    // start of the initial pipeline that loads the test case file stream from std::cin

    int numOfVertices;
    int numOfEdges;

    if(!std::cin.eof()){
        std::cin >> numOfVertices;
        std::cin >> numOfEdges;
    }
    else{
        std::cout<<"Input not found!"<<std::endl;
        return NULL;
    }

    // Initialize Graph object. Due to constructor, adjMatrix will be init to size numOfVertices x numOfVertices with all 0 values.
    Graph graph(numOfVertices, numOfEdges);

    while(!std::cin.eof()){
        // READ THE VALUES FOR EACH LINE
        int startVertice;
        int endVertice;
        int weight;
        std::cin >> startVertice;
        std::cin >> endVertice;
        std::cin >> weight;

        /* 
        == PROVIDED CODE FROM TEMPLATE - CHOSE NOT TO USE THE EDGE CLASS ==
            Edge* newEdge = new Edge(startVertice, endVertice);
            newEdge->setWeight(weight);
            Here is where you load up the Graph object
        */

        // === Add the Edge to the adjMatrix ===
        graph.addEdge(startVertice, endVertice, weight);
    }

    graph.printAdjMatrix();
    graph.checkOdd();
    graph.printOdd();
    
    // And here is where you start working on the three tasks

    return 0;
}