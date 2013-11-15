#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

struct edg{
   int src;
   int dst;
   int wt;
};

//@ nacessary values
edg graph[20];
int vert[20];
int vClr[20];
int nVert;
int nEdg;

//@ function that input the graph with a simple loop
void inpGraph(){
   cout<<"Number of Vertex? :";
   cin>>nVert;
   cout<<endl<<"Number of Edge? : ";
   cin>>nEdg;
   cout<<endl<<"Input the vertexes(<Source> <destination> <weight>)"<<endl;

   for(int i=0; i<nVert;i++){
      cin>>graph[i].src;
      cin>>graph[i].dst;
      cin>>graph[i].wt;
   }
   //@ we are gonna skip the fun part for saving time
   graph[1].src = 1;
   graph[2].src = 1;
   graph[3].src = 2;
   graph[4].src = 3;
   graph[5].src = 4;
   graph[6].src = 5;

   
   graph[1].dst = 2;
   graph[2].dst = 3;
   graph[3].dst = ;
   graph[4].dst = ;
   graph[5].dst = ;
   graph[6].dst = ;
}

void prims(){

}

int main(){
   
   return 0;
}
