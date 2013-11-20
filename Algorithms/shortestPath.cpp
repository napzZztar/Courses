#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

struct edge{
   char s;
   char d;
   char v;
};

int nVert;
edge graph[20];
char vert[20];
list<char> temp;

void inGraph(){
   cout<<"Enter the number of vertex :";
   cin>>nVert;
   cout<<"Enter the vertices(<src> <dst> <wt>)"<<endl;

   for(int i=0; i<nVert; i++){
      cin>>graph[i].s;
      cin>>graph[i].d;
      cin>>graph[i].v;
      temp.push_back(graph[i].s);
      temp.push_back(graph[i].d);
   }
   temp.sort();
   temp.unique();

   list<char>::iterator i;

   for()
   

   graph[0].s = 'A';
   graph[0].d = 'C';
   graph[0].v = 1;

   graph[1].s = 'B';
   graph[1].d = 'D';
   graph[1].v = 1;

   graph[2].s = 'A';
   graph[2].d = 'B';
   graph[2].v = 2;

   graph[3].s = 'C';
   graph[3].d = 'D';
   graph[3].v = 2;

   graph[4].s = 'G';
   graph[4].d = 'F';
   graph[4].v = 3;

   graph[5].s = 'B';
   graph[5].d = 'C';
   graph[5].v = 3;

   graph[6].s = 'B';
   graph[6].d = 'G';
   graph[6].v = 4;

   graph[7].s = 'C';
   graph[7].d = 'F';
   graph[7].v = 4;

   graph[8].s = 'D';
   graph[8].d = 'G';
   graph[8].v = 5;

   graph[9].s = 'D';
   graph[9].d = 'E';
   graph[9].v = 6;

   graph[10].s = 'E';
   graph[10].d = 'F';
   graph[10].v = 7;
}


int main(){
   

   return 0;
}
