#include <iostream>
#include <algorithm>
#include <queue>
#include <limits>
using namespace std;

struct process{
   int prcId;
   int bstTim;
   int arvTim;
   int prir;
};

struct pFcfs{
   int procId;
   int arvTim;
   int bstTim;
};

struct pSjf{
   int prcId;
   int bstTim;
   int arvTim;
};

bool operator<(const process& a, const process& b){
   return a.arvTim < b.arvTim;
}

bool operator<(const pFcfs& a, const pFcfs& b){
   return a.arvTim < b.arvTim;
}

bool operator<(const pSjf& a, const pSjf& b){
   return a.bstTim > b.bstTim;
}

process prc[5];

void FCFS(){
   int wait = 0;
   int turn = 0;
   int buffer = 0;
   pFcfs prcF[5];

   for(int i=0; i<5; i++){
      prcF[i].arvTim = prc[i].arvTim;
      prcF[i].bstTim = prc[i].bstTim;
      prcF[i].procId = prc[i].prcId;
   }

   sort(prcF, prcF + 5);
   
   for(int i=0; i<5; i++){
      wait += buffer - prcF[i].arvTim;
      buffer += prcF[i].bstTim;
      turn += buffer - prcF[i].arvTim;
   }
   cout<<"Wait time       = "<<wait/5<<endl;
   cout<<"Turnaround time = "<<turn/5<<endl;
}

void sJF(){
   int wait = 0;
   int begin = 0;
   int end = 0;
   priority_queue<pSjf> pq;
   pSjf prcS[5];
   pSjf active;

   for(int i=0; i<5; i++){
      prcS[i].arvTim = prc[i].arvTim;
      prcS[i].bstTim = prc[i].bstTim;
      prcS[i].prcId = prc[i].prcId;
   }

   active = prcS[0];
   begin = prcS[0].arvTim;

   for(int i=1; i<5; ){
      do{
         if(prcS[i].bstTim<active.bstTim){
            pq.push(active);
            active = prcS[i];
         }
      }while(prcS[i].arvTim == prcS[++i].arvTim);
      
      }
   }
}

int main(){
   prc[0].prcId = 1;
   prc[1].prcId = 2;
   prc[2].prcId = 3;
   prc[3].prcId = 4;
   prc[4].prcId = 5;

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


   sort(prc, prc+5);

   FCFS();

   cout<<endl<<"Sjf :"<<endl;
   sJF();

}
