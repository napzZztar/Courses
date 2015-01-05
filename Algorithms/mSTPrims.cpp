#include <iostream>
#include <string>
#include <list>
#include <queue>

using namespace std;

struct edg{
    char src;
    char dst;
    char vlu;
};

struct vert{
    char vlu;
    char clr;
    int par;
    int prior;
};

list<edg> graph;
list<vert> vertex;
priority_queue<edg> que;
list<edg> tree;

//@ Just a method to input the graph and findout the vertx
void inpGraph(int len){
    edg te;
    vert tv;
    list<char> vTemp;

    //@ taking input and keeping them in linklist
    for(int i=0; i<len; i++){
        cin>>te.src;
        cin>>te.dst;
        cin>>te.vlu;
        graph.push_back(te);

        //@ keeping the vertex in a temp char list so dupli can be cancled
        vTemp.push_back(te.src);
        vTemp.push_back(te.dst);
    }

    //@ sort and cancle duplicate
    vTemp.sort();
    vTemp.unique();

    //@ inserting into main link list
    list<char>::iterator x;
    for(x= vTemp.begin(); x != vTemp.end(); x++){
        tv.vlu = *x;
        tv.clr = 'w';
        tv.prior = 99999;
        tv.par = 0;
        vertex.push_back(tv);
    }
}

void prims(edg temp){
    que.push(temp);
    while(!que.empty()){
    }
}

int main(){
    inpGraph(3);
    vert temp;

    //@ picking any vertex(first in this case)
    temp = vertex.front();



    return 0;
}
