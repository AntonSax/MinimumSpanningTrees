//Programmer: Anton Sax   Date: 12/8/16
//Student ID: askz6       Class: CS2500 Algorithms
//File: MST_Project_Prims.cpp          Section: A
//Purpose:

#include <iostream>
#include "GraphDataStructure.h"
using namespace std;

int main()
{
  int nextSource = 0;
  Graph Prim(4,0);

  //weight with a values of 0 represent no connection;
  //edges between points of the same value always have a 0
  //    because they cannot have a connection;
  //fillEdge() fills in the 2D array symetrically
  //    this means there doesn't need to be any values
  //    for the bottom most line (3);
  Prim.fillEdge(0, 0, 0); //no connection to itself
  Prim.fillEdge(0, 1, 1);
  Prim.fillEdge(0, 2, 2);
  Prim.fillEdge(0, 3, 4);
  Prim.fillEdge(1, 1, 0); //no connection to itself
  Prim.fillEdge(1, 2, 3);
  Prim.fillEdge(1, 3, 1);
  Prim.fillEdge(2, 2, 0); //no connection to itself
  Prim.fillEdge(2, 3, 4);
  Prim.fillEdge(3, 3, 0); //no connection to itself

  //display what the graph (array) currently looks like
  Prim.displayGraph();

  Prim.addQueue(nextSource);
  Prim.sortPrim();

  //
  Prim.displayQueue();

  //
  Prim.displayWeight();

  while(Prim.checkArrayNotEmpty() == true)
  {
    //treeVertices array initializes to -1
    if(Prim.checkVertexArray(Prim.getNextSource()) == false)
    {
      cout << endl;
      cout << "------------------" << endl;
      //cout << "First IF Statement" << endl;
      cout << endl;

      cout << "Current Source: " << nextSource << endl;
      Prim.addVertex(nextSource);
      Prim.addWeight(Prim.getPrimWeight()); //should add 1 the first time

      Prim.displayQueue();
      Prim.displayWeight();
      nextSource = Prim.getNextSource(); //should be 1 after first iteration

      cout << endl;
      cout << "Next Source: " << nextSource << endl;
      Prim.addVertex(nextSource);

      if(Prim.checkEdges() == true)
      {
        cout << endl;
        //cout << "\t\t\t2" << endl;
        Prim.addQueue(nextSource);
      }

      cout << "Removing..." << endl;
      Prim.removeQueue();
      cout << "Sorting..." << endl;
      Prim.sortPrim();
      Prim.displayQueue();
    }
    else
    {
      if(nextSource == 0)
      {
        //do nothing because it will always be in the array
      }
      else
      {
        Prim.removeQueue();
      }
      /*
      cout << endl;
      cout << "The next starting point is: " << nextSource << endl;
      cout << endl;
      */
    }
  }
  cout << "-----------------------" << endl;
  cout << "End of Prim's Algorithm" << endl;
  cout << "-----------------------" << endl;
  return 0;
}
