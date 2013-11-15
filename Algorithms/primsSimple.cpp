#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

struct node{
   int src;
   int dst;
   int vlu;
};

struct cmp{
   bool operator()(const node& a, const node& b){
      return a.vlu<b.vlu;
   } 
};

priority_queue<node, vector<node>, cmp> stk;

//@ nacessary values
int graph[20][20]= {{0}};
int vert[20]={0};
int vClr[20]={0};
int par[20] = {0};
int nVert;
int nEdg;
node tmp;


/*
//@ function that input the graph with a simple loop
void inpGraph(){
   cout<<"Number of Vertex? :";
   cin>>nVert;
   cout<<endl<<"Number of Edge? : ";
   cin>>nEdg;
   cout<<endl<<"Input the vertexes(<Source> <destination> <weight>)"<<endl;

   for(int i=1; i<nVert;i+=2){
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
*/

void inpGraph(){
   int x;
   int y;

   cout<<"Input the number of Vertex : ";
   cin>>nVert;
   cout<<"Input the number of Edges : ";
   cin>>nEdg;
   cout<<"Enter the edges (<source> <destinaiton> <weight>) : "<<endl;

   for(int i=0; i<nVert; i++){
      cin>>x;
      cin>>y;
      cin>>graph[x][y];
      graph[y][x] = graph[x][y];
      if(i==0){
         tmp.src = x;
         tmp.dst = y;
         tmp.vlu = graph[x][y];
      }
   }
}

void prims(){
   int iTemp;
   /*
    * I used a shorcut instade
   for(int i=1; i<=nEdg; i++){
      for(int j=1; j<=nEdg; j++){
         if(graph[i][j] && !par[i]){
            
         }
      }
   }*/

   for(int i=1; i<=nVert; i++){
      if(graph[1][i]){
         tmp.src = 1;
         tmp.dst = i;
         tmp.vlu = graph[1][i];
         stk.push(tmp);
      }
   }

   while(!stk.empty()){
      tmp = stk.top();
      cout<<tmp.src<<" - "<<tmp.dst;
      iTemp = tmp.src;
      for(int i=0; i<=nVert; i++){
         if(graph[iTemp][i]){
            
         }
      }
   }

}

int main(){
   
   return 0;
}
