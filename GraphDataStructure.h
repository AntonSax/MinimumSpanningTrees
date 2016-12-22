//Programmer: Anton Sax   Date: 12/8/16
//Student ID: askz6       Class: CS2500 Algorithms
//File: GraphDataStructure.h          Section: A
//Purpose:

#ifndef GRAPHDATASTRUCTURE_H
#define GRAPHDATASTRUCTURE_H

#include <iostream>

using namespace std;

class Graph
{
public:
  int m_size;
  int treeWeight;
  int** graph;
  int* queue;
  int* treeVertices;

  //Edit this

  //Purpose: Creates a 2D matrix to contain the edges between each location.
  //          Also creates two other matrices for the names of each location
  //          and the possible locations that can be reached.
  //          The 1D matrices' default values are spaces " ".
  //Preconditions: An optional (though usually used) string for the name
  //                of the city and integer for how many locations there are.
  //Postconditions: A 2D array, and two normal arrays, the same length as the 2D array.
  Graph (int s = 0, int tW = 0) : m_size(s), treeWeight(tW)
  {
    graph = new int*[m_size];
    for(int j = 0; j < m_size; j++)
    {
      graph[j] = new int[m_size];
    }

    queue = new int[m_size * 5];

    treeVertices = new int[m_size];
    for(int v = 0; v < m_size; v++)
    {
      treeVertices[v] = -1;
    }
  }

  //Purpose:  Frees the arrays from memory. Resets the member variables.
  //Preconditions: None.
  //Postconditions: Array graph is deleted
  //                  and set to NULL. Other values are set to 0 or "".
  void clearGraph();

  //Purpose:
  //Preconditions:  Two nonnegative integers and a third integer below 1000.
  //Postconditions:
  void fillEdge(int row, int column, int weight);

  //Purpose:  Fills the queue array with all the possible edge vertex pairs.
  //Preconditions:  Two integers
  //Postconditions:
  //-------------For Prim's Algorithm----------
  void addQueue(int source);

  //-------------For Kruskal's Algorithm
  void fillQueue();

  //this should sort the queue so that it is in order of ascending edge weight
  //----------For Prim's Algorithm---------------
  void sortPrim();

  //--------------------For Kruskal's Algorithm--------------
  void sortKruskal();

  //------------------For Kruskal's Algorithm-------------------
  int getEdgeNumber();

  //-----For Kruskal's Algorithm------
  int getVertex1(int currentEdgeNumber);

  //---------For Kruskal's Algorithm----------
  int getVertex2(int currentEdgeNumber);

  //check if the queue array is empty
  bool checkArrayNotEmpty();

  //returns if a vertex is in the "tree" array
  bool checkVertexArray(int vertex);

  //add the vertex of the smallest edge to the "tree" array
  //-----For Prim's Algorithm-------
  void addVertex(int vertex);

  //--------------For Kruskal's Algorithm-----------
  void addEdge(int currentEdgeNumber);

  //-------------For Prim's Algorithm----------------
  //returns the weight of the edge from the first position of the queue
  int getPrimWeight();

  //------------------For Kruskal's Algorithm---------------
  int getKruskalWeight(int edgeNumber);

  //add the weight of the edge to the total weight
  void addWeight(int weight);

  //check to see if there are any edges on what will be the next sr
  bool checkEdges();

  //returns what will be the next source
  int getNextSource();

  //removes the edge and vertex from the queue
  void removeQueue();

  //display the graph in an array format
  void displayGraph();

  //output the weight of the minimum spanning tree
  void displayWeight();

  //display what the numbers in the tree array
  void displayQueue();
};

#endif
