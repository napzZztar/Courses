// Tis code is not complete yet.
// I'll do the rest when I can manage some times
#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

struct edge{
   char s;
   char d;
   int w;
};

int nVert;
int nEdge;
edge graph[20];
char vert[20] = "ABCDEFG";
int vDist[20] = {9999};
int dist[20] = {9999};
int pred[20] = {-1};

list<char> temp;

void inGraph(){ 
   cout<<"Enter the number of Edges:";
   cin>>nEdge;
   cout<<"Enter the vertices(<src> <dst> <wt>)"<<endl; 
   for(int i=0; i<nEdge; i++){
      cin>>graph[i].s;
      cin>>graph[i].d;
      cin>>graph[i].w;
      temp.push_back(graph[i].s);
      temp.push_back(graph[i].d);
   }
   temp.sort();
   temp.unique();

   list<char>::iterator i;
   nVert = 0;

   for(i = temp.begin(); i!=temp.end(); i++){
      vert[nVert] = *i;
      nVert++;
   }


   /*
      nEdge = 11;
      nVert = 7;
      graph[0].s = 'A';
      graph[0].d = 'C';
      graph[0].w = 1;

      graph[1].s = 'B';
      graph[1].d = 'D';
      graph[1].w = 1;

      graph[2].s = 'A';
      graph[2].d = 'B';
      graph[2].w = 2;

      graph[3].s = 'C';
      graph[3].d = 'D';
      graph[3].w = 2;

      graph[4].s = 'G';
      graph[4].d = 'F';
      graph[4].w = 3;

      graph[5].s = 'B';
      graph[5].d = 'C';
      graph[5].w = 3;

      graph[6].s = 'B';
      graph[6].d = 'G';
      graph[6].w = 4;

      graph[7].s = 'C';
      graph[7].d = 'F';
      graph[7].w = 4;

      graph[8].s = 'D';
      graph[8].d = 'G';
      graph[8].w = 5;

      graph[9].s = 'D';
      graph[9].d = 'E';
      graph[9].w = 6;

      graph[10].s = 'E';
      graph[10].d = 'F';
      graph[10].w = 7;
      */
}

void shoGraph(){
   cout<<"Source - Destination - Weight"<<endl;

   for(int i= 0 ; i<nEdge; i++){
      cout<<graph[i].s<<"  -  "<<graph[i].d<<"  -  "<<graph[i].w<<endl;
   }

   cout<<endl<<endl<<"Vertices : ";
   for(int i=0; i<nVert; i++){
      cout<<vert[i];
   }
   cout<<endl<<endl<<"Node - Distance - Parent"<<endl;

   for(int i=0; i<nVert; i++){
      cout<<vert[i]<<"   -  "<<dist[i]<<" - "<<vert[pred[i]]<<endl;
   }
}

void relax(int u, int v, int g){
   if(dist[v]<dist[u]+graph[g].w){
      dist[v] = dist[u] + graph[g].w;
      pred[v] = u;
      cout<<dist[v];
   }
}

bool isRelax(int u, int v, int g){
   if(dist[v]>dist[u]+graph[g].w){
      return false;
   }else{
      return true;
   }
}

void bellFord(){
   int uI;
   int vI;
   bool flag = true;
   dist[0] = 0;
   for(int i=0; i<nEdge; i++){
      uI = 0;
      while(graph[i].s != vert[uI]){
         uI++;
      }

      vI = 0;

      while(graph[i].d != vert[vI]){
         vI++;
      }

      relax(uI, vI, i);
   }


   for(int i=0; i<nEdge; i++){

      uI = 0;
      while(graph[i].s != vert[uI]){
         uI++;
      }

      vI = 0;

      while(graph[i].d != vert[vI]){
         vI++;
      }

      if(isRelax(uI, vI, i)){
         cout<<"There is a cycle!"<<endl;
         flag = true;
      }

   }

   if(flag) shoGraph();
}

int main(){
   inGraph();
   bellFord();
   return 0;
}
