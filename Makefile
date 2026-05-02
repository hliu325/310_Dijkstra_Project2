all: Main.o Edge.o Vertex.o Graph.o
		g++ -g -Wall Main.o Edge.o Vertex.o Graph.o -o dijkstra

Edge.o: Edge.h Edge.cpp
		g++ -g -Wall -c Edge.cpp

Vertex.o: Vertex.h Vertex.cpp	
		g++ -g -Wall -c Vertex.cpp

Main.o: Main.cpp
		g++ -g -Wall -c Main.cpp

Graph.o: Graph.cpp
		g++ -g -Wall -c Graph.cpp
clean:
	rm -rf *.o dijkstra
