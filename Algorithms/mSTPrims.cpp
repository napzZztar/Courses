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

void inpGraph(int len){
   edg te;
   vert tv;
   for(int i=0; i<len; i++){
      cin>>te.src;
      cin>>te.dst;
      cin>>te.vlu;
      graph.push_back(te);
      
      tv.vlu = te.src;
      tv.clr = 'w';
      vertex.push_back(tv);
      
      tv.vlu = te.dst;
      tv.clr = 'w';
      vertex.push_back(tv);
      
   }

}

int main(){
   inpGraph(3);
   list<vert>::iterator i;

   for(i = vertex.begin(); i != vertex.end(); i++){
      cout<<i->vlu;
   }
   return 0;
}
