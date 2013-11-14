#include <iostream>
#include <string>

using namespace std;

struct vert{
   char s;
   char d;
   char v;
};

void inpGraph(vert *g, int l, char *v){
   int flag;
   int counter = 0;
   for(int i=0; i<l; i++){
      cin>>(g+i)->s;
      cin>>(g+i)->d;
      cin>>(g+i)->v;
      flag = 0;
      for(int j=0; j<counter; j++){
         if(*(v+j)==(g+i)->s){
            flag = 1;
            counter++;
            cout<<"True"<<endl;
         }
      }
      if(!flag)
         *(v+counter) = (g+i)->s;

      flag = 0;
      for(int j=0; j<counter; j++){
         if(*(v+j)==(g+i)->d){
            flag = 1;
            counter++;
         }
      }

      if(!flag)
         *(v+counter) = (g+i)->d;
      cout<<*(v+counter);
   }
}

int main(){
   char v[20] = " ";
   vert graph[5];
   
   inpGraph(graph, 2, v);
   cout<<v[2];
   return 0;
}
