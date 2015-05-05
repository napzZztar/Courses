#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

#define size 7

struct nod{
    int dC;
    int dest[5];
    int cst;
};

char node[size] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

pair<char, int> font;
priority_queue<pair<char, int> > ftrQ;

nod graph[11];

void init(){
    int x = 1;
    for (int i = 0; i < 10; i++) graph[i].dC = 0;

    graph[x].dest[graph[x].dC++] = 4;
    graph[x].dest[graph[x].dC++] = 2;

    x++;
    graph[x].dest[graph[x].dC++] = 3;

    x++;
    graph[x].dest[graph[x].dC++] = 5;
    graph[x].dest[graph[x].dC++] = 7;

    x++;
    graph[x].dest[graph[x].dC++] = 5;
    graph[x].dest[graph[x].dC++] = 6;

    x++;
    graph[x].dest[graph[x].dC++] = 2;

    x++;
    graph[x].dest[graph[x].dC++] = 7;

    x++;
    graph[x].dest[graph[x].dC++] = 5;
    
}

void ucs(){
}

int main(){
    

    return 0;
}
