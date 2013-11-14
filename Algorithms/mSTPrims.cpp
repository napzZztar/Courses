#include <iostream>
#include <string>
#include <list>

using namespace std;

struct edg{
   char src;
   char dst;
   char vlu;
};

struct vert{
   char vlu;
   char clr;
};

list<edg> graph;
list<vert> vertex;
list<edg> stk;

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
      vertex.push_back(tv);
   }
}

void prims(vert temp){
   //@ for all unvisited vertex started form this vertex
   vert dV;
   list<edg>::iterator i;
   for(*i=graph.front(); i!=graph.end(); i++){
      if(i->src == temp.vlu){
         list<vert>::iterator j;
         *j = vertex.front();
         for( ;j->vlu != i->dst ; j++){}
         dV = *j;
      }
      
      //@ First visit to this node
      if(dV.clr == 'w'){
         stk.push_back(*i);
      //@ node is inside the stack
      }else if(dV.clr == 'g'){
         //@ looking for the node inside stack
         list<edg>::iterator j;
         *j=stk.front();
         for( ;j->dst == dV.vlu; j++){}
         
      }
   }
}

int main(){
   inpGraph(3);
   vert temp;

   //@ picking any vertex(first in this case)
   temp = vertex.front();



   return 0;
}
