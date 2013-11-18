#include <iostream>
#include <algorithm>
using namespace std;

struct process{
   int prcID;
   int bstTim;
   int arvTim;
   int prir;
};
bool operator<(const process& a, const process& b){
      return a.arvTim < b.arvTim;
}

process prc[5];

void FCFS(){
   int wait = 0;
   int turn = 0;
   int buffer = 0;

   sort(prc, prc + 5);
   
   for(int i=0; i<5; i++){
      wait += buffer - prc[i].arvTim;
      buffer += prc[i].bstTim;
      turn += buffer - prc[i].arvTim;
   }
   cout<<"Wait time       = "<<wait/5<<endl;
   cout<<"Turnaround time = "<<turn/5<<endl;
}

int main(){
   prc[0].prcID = 1;
   prc[1].prcID = 2;
   prc[2].prcID = 3;
   prc[3].prcID = 4;
   prc[4].prcID = 5;

   prc[0].bstTim = 10;
   prc[1].bstTim = 8;
   prc[2].bstTim = 5;
   prc[3].bstTim = 4;
   prc[4].bstTim = 2;

   prc[0].arvTim = 1;
   prc[1].arvTim = 2;
   prc[2].arvTim = 3;
   prc[3].arvTim = 4;
   prc[4].arvTim = 1;

   
   prc[0].prir = 3;
   prc[1].prir = 2;
   prc[2].prir = 1;
   prc[3].prir = 5;
   prc[4].prir = 7;
   FCFS();

}
