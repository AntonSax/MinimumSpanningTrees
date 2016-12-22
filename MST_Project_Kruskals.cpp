//Programmer: Anton Sax   Date: 12/8/16
//Student ID: askz6       Class: CS2500 Algorithms
//File: MST_Project_Kruskals.cpp        Section: A
//Purpose:

#include <iostream>
#include "GraphDataStructure.h"
using namespace std;

int main()
{
  int edgeNumber = 0;
  Graph Kruskal(4,0);

  Kruskal.fillEdge(0, 0, 0); //weight of 0, no connection to itself
  Kruskal.fillEdge(0, 1, 1);
  Kruskal.fillEdge(0, 2, 2);
  Kruskal.fillEdge(0, 3, 4);
  Kruskal.fillEdge(1, 1, 0); //no connection to itself
  Kruskal.fillEdge(1, 2, 3);
  Kruskal.fillEdge(1, 3, 1);
  Kruskal.fillEdge(2, 2, 0); //no connection to itself
  Kruskal.fillEdge(2, 3, 4);
  Kruskal.fillEdge(3, 3, 0); //no connection to itself

  //display what the graph (array) currently looks like
  Kruskal.displayGraph();

  Kruskal.fillQueue();
  Kruskal.sortKruskal();

  //do this to show the sorted "queue"
  Kruskal.displayQueue();

  //do this to show initial value of 0;
  Kruskal.displayWeight();

  edgeNumber = Kruskal.getEdgeNumber();
  cout << "Total Edge Number: " << edgeNumber << endl;
  cout << endl;
  cout << endl;

  for(int i = 0; i < edgeNumber; i++)
  {
    cout << endl;
    cout << "i = " << i << endl;
    if(Kruskal.checkVertexArray(Kruskal.getVertex1(i)) && Kruskal.checkVertexArray(Kruskal.getVertex2(i)))
    {
      //do nothing
      //because both vertices are in the array
      //and this would create a cycle
    }
    else
    {
      Kruskal.addEdge(i);

      //do this to show progress
      Kruskal.displayWeight();
    }

  }

  cout << endl;
  cout << "End of Kruskal's Algorithm" << endl;
  cout << endl;
  return 0;
}
