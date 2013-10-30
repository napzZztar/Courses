#include <iostream>
using namespace std;

struct edg{
   char s;
   char d;
   int v;
};


int main(){
   edg graph[11];

   int sI, dI;
   int cost = 0;
   int paint = 0;
   int clr[8] = {0};
   char vrt[8] = {"ABCDEFG"};

   graph[0].s = 'A';/*{{{*/
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
   graph[10].v = 7;/*}}}*/

   //done with the crappy input.
//**********************************
   //@ main for loop
   for(int g; g<11; g++){
      //@ find starting index of vertex
      sI = 0;
      while(graph[g].s != vrt[sI++]){}

      //@ find ending index of vertex
      dI = 0;
      while(graph[g].s != vrt[dI++]){}
      //******************************

      if(clr[sI] == 0 && clr[dI] == 0){
      //@ When both vertexes are not in any tree yet

      }else if(clr[sI] != clr[dI]){
      //@ When color of the vertexes are different

         if(clr[sI] != 0 && clr[dI] != 0){
         //@ both vertexes are connected to different tree

         }else{
         //@ one of the vertex is not connected
            if(clr[sI] == 0){
            //@ Source vertex not connected

            }else{
            //@ Destination vertex not connected

            }
         }
      }//end of tree varification
   }//end of main for loop
}//end of main method
