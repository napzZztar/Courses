#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct vert{
    int s;
    int d;
    int v;
};

vert graph[6];
char color[6] = {'w'};

void init(){
    graph[0].s = 0;
    graph[0].d = 1;
    graph[0].v = 1;

    graph[1].s = 0;
    graph[1].d = 3;
    graph[1].v = 1;

    graph[2].s = 1;
    graph[2].d = 2;
    graph[2].v = 1;

    graph[3].s = 2;
    graph[3].d = 3;
    graph[3].v = 1;

    graph[4].s = 3;
    graph[4].d = 1;
    graph[4].v = 1;

}

void bfs(int x);

int main(){
    int dest = 3;
    init();
    bfs(dest);
    return 0;
}

void bfs(int x){
    int u;
    queue<int> q;
    q.push(0);
    cout<<"0";

    while(!q.empty()){
        u = q.front();
        q.pop();

        for (int i = 0; i < 6; i++) {
            if(graph[i].s == u){
                cout<<graph[i].d;
                if(graph[i].d == x){
                    return;
                }
                q.push(graph[i].d);
            }
        }
    }
}
