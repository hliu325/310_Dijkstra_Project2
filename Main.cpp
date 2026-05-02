// #include "Edge.h"
#include "Vertex.h"
#include "Graph.h"
#include <iostream>

int main(){

    // start of the initial pipeline that loads the test case file stream from std::cin

    int numOfVertices;
    int numOfEdges;
    std::cin >> numOfVertices;
    std::cin >> numOfEdges;

    // if(!std::cin.eof()){
    //     std::cin >> numOfVertices;
    //     std::cin >> numOfEdges;
    // }
    // else{
    //     std::cout<<"Input not found!"<<std::endl;
    //     return -1;
    // }

    // Initialize Graph object. Due to constructor, adjMatrix will be init to size numOfVertices x numOfVertices with all 0 values.
    Graph graph(numOfVertices, numOfEdges);

    // READ THE VALUES FOR EACH LINE
    int startVertice;
    int endVertice;
    int weight;

    /* 
    == PROVIDED CODE FROM TEMPLATE - CHOSE NOT TO USE THE EDGE CLASS ==
        Edge* newEdge = new Edge(startVertice, endVertice);
        newEdge->setWeight(weight);
        Here is where you load up the Graph object
    */

    // === Add the Edge to the adjMatrix ===
    
    while(std::cin >> startVertice >> endVertice >> weight) {
        graph.addEdge(startVertice, endVertice, weight);
    }

    graph.printAdjMatrix();
    graph.checkOdd();
    graph.runDijkstra();

    // And here is where you start working on the three tasks

    return 0;
}