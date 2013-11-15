#include <iostream>
using namespace std;

#define V 5

//@ METHOD TO FINDOUT MINIMUM KEY 
int minKey(int key[], bool mstSet[])
{
   int min = 99999;
   int ind;

   for (int i = 0; i < V; i++){
      //@ JUST CHECKS IF THE INDEX IS'NT iN MST & MINIMUM
      if (!mstSet[i] && key[i] < min){
         min = key[i];
         ind = i;
      }
   }
   return ind;
}

//@ PRINTS MST WITH VALUES
void printMST(int parent[], int graph[V][V])
{
   cout<<"Edge   | Weight"<<endl;
   for (int i = 1; i < V; i++){
      cout<<parent[i]<<" - "<<i<<"  |  "<<(graph[i][parent[i]])<<endl;
   }
}

//@ THE MAIN MST FUNCTION
void primMST(int graph[V][V]){
   int parent[V];
   int key[V];    
   bool mstSet[V];

   for(int i=0; i<V; i++){
      key[i] = 9999;
      mstSet[i] = false;
   }

   key[0] = 0;
   parent[0] = -1;

   //@ visit all the vertex 
   for (int i = 1; i < V; i++)
   {
      int u = minKey(key, mstSet);
      
      //include the min key to the tree
      mstSet[u] = true;
      
      for (int v = 0; v < V; v++){
         if (graph[u][v] && !mstSet[v] && graph[u][v] <  key[v]){
            parent[v]  = u, key[v] = graph[u][v];
         }
      }
   }
   printMST(parent, graph);
}


int main()
{
   int graph[V][V] = {{0, 2, 0, 6, 0},
      {2, 0, 3, 8, 5},
      {0, 3, 0, 0, 7},
      {6, 8, 0, 0, 9},
      {0, 5, 7, 9, 0},
   };


   primMST(graph);

   return 0;
}
