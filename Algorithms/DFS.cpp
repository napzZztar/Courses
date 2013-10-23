#include <iostream>
using namespace std;
int time = 0;
int start[7] = {-1};
int end[7] = {-1};
int graph[7][7] = {0};
char vColor[7] = {'W'};
char aColor[7][7] = {'W'};

void DFS_Visit(int u){
	vColor[u] = 'G';
	start[7] = ++time;
	
	for(int i=0; i<7; i++){
		if(graph[u][i] == 1){
			if(vColor[i] == 'W'){
				DFS_Visit(i);
			}
		}
		
	}
	
}

void DFS(){
	for(int i=1; i<7; i++){
		if(aColor[i]=='W'){
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
	for(int i=1; i<7; i++){
		for(int j=1; j<7; j++){
			if(graph[i][j]==1){
				cout<<i<<" -> "<<j<<endl;
			}
		}
	}
}

int main(){
	inputGraph();
	
	showGraph();
	
	return 0;
}
