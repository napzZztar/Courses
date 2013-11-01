#include <iostream>
using namespace std;

struct edg{
   char s;
   char d;
   int v;
};

//@ A method that will arrange the vertexs
void vArrange(edg *ar, int ln){
   for(int i=0; i<ln; i++){

   }
}

int main(){
   int len = 1;
   cin>>len;
   edg graph[len];

   int temp;
   int sI, dI;
   int cost = 0;
   int paint = 0;
   int clr[8] = {0};
   //char *vrt;
   char vrt[8] = {"ABCDEFG"};

   cout<<"Enter the vertexes and values followed by Enter: "<<endl;
   for(int i=0; i<len; i++){
      cin>>graph[i].s>>graph[i].d>>graph[i].v;
   }

/*{{{*/

/*
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
   graph[10].v = 7;*/
/*}}}*/
   //done with the crappy input.
//**********************************
   //@ main for loop
   for(int g=0; g<11; g++){
      //@ find starting index of vertex
      sI = 0;
      while(graph[g].s != vrt[sI]){sI++;}
      //cout<<vrt[sI];

      //@ find ending index of vertex
      dI = 0;
      while(graph[g].d != vrt[dI]){dI++;}
      //cout<<vrt[dI]<<" :"<<graph[g].v<<endl;
      //***********************************

      if(clr[sI] == 0 && clr[dI] == 0){
      //@ When both vertexes are not in any tree yet
         clr[sI] = clr[dI] = ++paint;
         cost += graph[g].v;
         cout<<graph[g].s<<"-"<<graph[g].d<<endl;

      }else if(clr[sI] != clr[dI]){
      //@ When color of the vertexes are different

         if(clr[sI] != 0 && clr[dI] != 0){
         //@ both vertexes are connected to different tree
            //@ Convert both tree into one tree.
            temp = clr[dI];
            for(int t=0; t<8; t++){
               if(temp == clr[t]){
                  clr[t] = clr[sI];
               }

            }
            cost += graph[g].v;
            cout<<graph[g].s<<"-"<<graph[g].d<<endl;

         }else{
         //@ one of the vertex is not connected
            if(clr[sI] == 0){
            //@ Source vertex not connected
               cost += graph[g].v;
               clr[sI] = clr[dI];
               cout<<graph[g].s<<"-"<<graph[g].d<<endl;

            }else{
            //@ Destination vertex not connected
               cost += graph[g].v;
               clr[dI] = clr[sI];
               cout<<graph[g].s<<"-"<<graph[g].d<<endl;

            }
         }
      }//end of tree varification
   }//end of main for loop
   cout<<"The cost to travle the MSP is : "<<cost<<endl;

}//end of main method
