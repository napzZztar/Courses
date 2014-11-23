#include <iostream>
using namespace std;

int times;
int start[7] = {-1};
int finish[7] = {-1};
int graph[7][7] = {0};
int parent[7] = {0};
char vColor[7];
char aColor[7][7];

void DFS_Visit(int u){
    vColor[u] = 'G';
    start[u] = ++times;
    for(int i=1; i<7; i++){
        if(graph[u][i] == 1){
            if(vColor[i] == 'W'){
      DFS_Visit(i);
      aColor[u][i] = 'T';
      parent[i] = u;
  }else if(start[u] < start[i]){
      aColor[u][i] = 'F';
  }else{
      aColor[u][i] = 'B';
  }
        }
    }
    vColor[u] = 'B';
    finish[u] = ++times;
    cout<<"==========="<<endl;
    cout<<"Vertex : "<<u<<endl;
    cout<<"Start  : "<<start[u]<<endl;
    cout<<"Finish : "<<finish[u]<<endl;
}

void DFS(){
    times = 0;
    for(int i=0; i<7; i++) vColor[i] = 'W';
    for(int i=1; i<7; i++){
        if(vColor[i] == 'W'){
            DFS_Visit(i);
        }
    }
}

void inputGraph(){
    /*
       for(int i=1; i<7; i++){
       for(int j=1; j<7; j++){
       cout<<i<<" -> "<<j<<" :";
       cin>>graph[i][j];
       }
       }*/
    //Just a little short cut.
    graph[1][2] = 1;
    graph[1][4] = 1;
    graph[2][3] = 1;
    graph[3][4] = 1;
    graph[4][2] = 1;
    graph[5][3] = 1;
    graph[5][6] = 1;
    graph[6][6] = 1;
}

void showGraph(){
    cout<<"Edges of the grapth are : "<<endl;
    for(int i=1; i<7; i++){
        for(int j=1; j<7; j++){
            if(graph[i][j]) cout<<i<<" -> "<<j<<" : "<<aColor[i][j]<<endl;
        }
    }
}

int main(){
    for(int i=0; i<7;i++) for(int j=0; j<7; j++) aColor[i][j] = 'N';
    inputGraph();
    showGraph();
    DFS();
    showGraph();
    for(int i=1; i<7; i++) cout<<parent[i]<<", ";
    return 0;
}
