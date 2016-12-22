//Programmer: Anton Sax   Date: 12/8/16
//Student ID: askz6       Class: CS2500 Algorithms
//File: GraphDataStructure.cpp          Section: A
//Purpose:

#include "GraphDataStructure.h"

void Graph::clearGraph()
{
  for(short u = 0; u < m_size; u++)
  {
      delete [] graph[u];
  }
  delete [] graph;
  graph = NULL;

  m_size = 0;
}

void Graph::fillEdge(int row, int column, int weight)
{
  graph[row][column] = weight;
  graph[column][row] = weight;
  return;
}

void Graph::addQueue(int source)
{
  int counter;
  for(int p = 0; p < m_size*3; p++)
  {
    if(queue[p] == 0)
    {
      counter = p;
      p = m_size*3;
    }
  }
  //should add everything to the queue for the next starting source vertex
  for(int t = 0; t < m_size; t++)
  {
    if((graph[source][t] != 0) && (t > source))
    {
      //puts the edge and vertex pair in the queue
      queue[counter] = graph[source][t];
      queue[counter+1] = t;
      counter += 2;
    }
  }
  return;
}

void Graph::fillQueue()
{
  int counter = 0;
  for(int m = 0; m < m_size; m++)
  {
    for(int n = m; n < m_size; n++)
    {
      if(graph[m][n] != 0)
      {
        queue[counter] = graph[m][n];
        queue[counter+1] = m;
        queue[counter+2] = n;
        counter += 3;
      }
    }
  }
  return;
}

void Graph::sortPrim()
{
  for(int abc = 0; abc < m_size; abc++)
  {
    //cout << "1" << endl;
    for(int def = 0; def < (m_size*4); def = def+2)
    {
      //cout << "\t2" << endl;
      //cout << queue[def] << "---" << queue[def+2] << endl;
      if((queue[def] != 0) && (queue[def+2] != 0))
      {
        //cout << "\t3" << endl;
        if(queue[def] > queue[def+2])
        {
          //cout << "\t4" << endl;
          //switch the values
          //make temp numbers
          int tempq = queue[def];
          int tempq2 = queue[def+1];
          //change the first two values
          queue[def] = queue[def+2];
          queue[def+1] = queue[def+3];
          //change the second two values
          queue[def+2] = tempq;
          queue[def+3] = tempq2;
        }
      }
    }
  }
  return;
}

void Graph::sortKruskal()
{
  int mno;
  int pqr;
  for(mno = 0; mno < m_size*4; mno+=3)
  {
    for(pqr = 0; pqr < m_size*4; pqr+=3)
    {
      if((queue[pqr] != 0) && (queue[pqr+3] != 0))
      {
        if(queue[pqr] > queue[pqr+3])
        {
          //switch the values
          //make temp numbers
          int tempq = queue[pqr];
          int tempq2 = queue[pqr+1];
          int tempq3 = queue[pqr+2];
          //change the first three values
          queue[pqr] = queue[pqr+3];
          queue[pqr+1] = queue[pqr+4];
          queue[pqr+2] = queue[pqr+5];
          //change the second three values
          queue[pqr+3] = tempq;
          queue[pqr+4] = tempq2;
          queue[pqr+5] = tempq3;
        }
      }
    }
  }
}

int Graph::getEdgeNumber()
{
  int edgeNumber = 0;
  int pos = 0;
  for(int i = 0; i < m_size*4; i++)
  {
    if(queue[pos] != 0)
    {
      edgeNumber++;
      pos += 3;
    }
  }
  return edgeNumber;
}

int Graph::getVertex1(int currentEdgeNumber)
{
  int vertex1;
  int edgeNumber = 0;
  if(currentEdgeNumber != 0)
  {
    edgeNumber = (currentEdgeNumber * 3) + 1;
  }
  else
  {
    edgeNumber += 1;
  }
  vertex1 = queue[edgeNumber];

  return vertex1;
}

int Graph::getVertex2(int currentEdgeNumber)
{
  int vertex2;
  int edgeNumber = 0;
  if(currentEdgeNumber != 0)
  {
    edgeNumber = (currentEdgeNumber * 3) + 2;
  }
  else
  {
    edgeNumber += 2;
  }
  vertex2 = queue[edgeNumber];

  return vertex2;
}

bool Graph::checkArrayNotEmpty()
{
  bool notEmpty = false;
  for(int q = 0; q < m_size*4; q += 2)
  {
    if(queue[q] != 0)
    {
      notEmpty = true;
    }
  }

  return notEmpty;
}

//remember, the treeVertices array initializes to -1
bool Graph::checkVertexArray(int vertex)
{
  bool inTree = false;

  //loop through array of vertices to check if the vertex is in the array
  for(int v = 0; v < m_size; v++)
  {
    if(treeVertices[v] == vertex)
    {
      inTree = true;
    }
  }

  return inTree;
}

void Graph::addVertex(int vertex)
{
  bool inTree = false;

  //loop through array of vertices to check if the vertex is in the array
  for(int v = 0; v < m_size; v++)
  {
    if(treeVertices[v] == vertex)
    {
      inTree = true;
    }
  }

  //vertex is not in tree
  if(inTree == false)
  {
    //loop through array of vertices that are in the tree
    for(int v = 0; v < m_size; v++)
    {
      //find end of array
      if(treeVertices[v] == -1)
      {
        //insert vertex
        treeVertices[v] = vertex;
        v = m_size;
      }
    }
  }
  return;
}

void Graph::addEdge(int currentEdgeNumber)
{
  int vertex1 = getVertex1(currentEdgeNumber);
  int vertex2 = getVertex2(currentEdgeNumber);

  cout << endl;
  cout << "Current Vertex 1: " << vertex1 << endl;
  cout << "Current Vertex 2: " << vertex2 << endl;

  addVertex(vertex1);
  addVertex(vertex2);

  //also add weight to the tree for convenience
  addWeight(getKruskalWeight(currentEdgeNumber));

  return;
}

int Graph::getPrimWeight()
{
  int weight = queue[0];
  return weight;
}

int Graph::getKruskalWeight(int currentEdgeNumber)
{
  int weight;
  int edgeNumber = 0;
  if(currentEdgeNumber != 0)
  {
    edgeNumber = (currentEdgeNumber * 3);
  }
  weight = queue[edgeNumber];

  return weight;
}

void Graph::addWeight(int weight)
{
  treeWeight = treeWeight + weight;
}

bool Graph::checkEdges()
{
  int nextSource = queue[1];
  bool existEdges = false;

  for(int v = 0; v < m_size; v++)
  {
    if(graph[nextSource][v] != 0)
    {
      existEdges = true;
    }
  }

  return existEdges;
}

void Graph::removeQueue()
{
  for(int q = 0; q < m_size*3; q += 2)
  {
    //move the next two numbers up
    queue[q] = queue[q+2];
    queue[q+1] = queue[q+3];
  }
  return;
  //the vertex that was removed should be the new source
}

int Graph::getNextSource()
{
  int nextSource = queue[1];
  return nextSource;
}


void Graph::displayGraph()
{
  cout << endl;
  for(int i = 0; i < m_size; i++)
  {
    for(int j = 0; j < m_size; j++)
    {
      cout << " " << graph[i][j];
    }
    cout << endl;
  }
  cout << endl;
  return;
}

void Graph::displayWeight()
{
  cout << endl;
  cout << "Weight of Tree: " << treeWeight << endl;
  cout << endl;
}

void Graph::displayQueue()
{
  cout << "Queue: " << endl;
  for(int i = 0; i < m_size*5; i++)
  {
    cout << " " << queue[i];
  }
  cout << endl;

  return;
}
