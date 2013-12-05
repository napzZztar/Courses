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
}prc[5];

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

struct pPqu{
   int prcId;
   int bstTim;
   int arvTim;
   int prior;
};

bool operator<(const process& a, const process& b){
   return a.arvTim < b.arvTim;
}

bool operator<(const pFcfs& a, const pFcfs& b){
   return a.arvTim > b.arvTim;
}

bool operator<(const pSjf& a, const pSjf& b){
   return a.bstTim > b.bstTim;
}

bool operator<(const pPqu& a, const pPqu& b){
   return a.prior> b.prior;
}


void input(){
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
}

void FCFS(){
   int wait = 0;
   int turn = 0;
   int buffer = 0;
   pFcfs prcF;
   priority_queue<pFcfs> pq;

   for(int i=0; i<5; i++){
      prcF.arvTim = prc[i].arvTim;
      prcF.bstTim = prc[i].bstTim;
      prcF.procId = prc[i].prcId;
      pq.push(prcF);
   }
   
   prcF = pq.top();

   for(int i=1;buffer>=0; i++){
      while(prcF.arvTim == i && !pq.empty()){
         if(buffer)wait += (i + buffer) - prcF.arvTim;
         buffer += prcF.bstTim;
         turn += (i + buffer) - prcF.arvTim;
         pq.pop();
         prcF = pq.top();
      }
      buffer--;
   }
   cout<<"Wait time       = "<<wait/5.0<<endl;
   cout<<"Turnaround time = "<<turn/5.0<<endl;
}

void sJF(){
   int wait = 0;
   int turn = 0;
   int next = 1;
   priority_queue<pSjf> pq;
   pSjf prcS[5];
   pSjf active;
   for(int i=0; i<5; i++){
      prcS[i].arvTim = prc[i].arvTim;
      prcS[i].bstTim = prc[i].bstTim;
      prcS[i].prcId = prc[i].prcId;
   }

   pq.push(prcS[0]);
   active.bstTim = 0;
   active.arvTim = 1;

   for(int i=1; ; i++){
      if(active.bstTim==0){
         turn += i-active.arvTim;
         if(pq.empty()){
            break;
         }
         active = pq.top();
         pq.pop();
      }
      
      if(i==prcS[next].arvTim){
         do{
            if(active.bstTim<prcS[next].bstTim){
               pq.push(prcS[next]);
            }else{
               pq.push(active);
               active = prcS[next];
            }
         }while(prcS[++next].arvTim == i);
      }
      wait += pq.size();
      active.bstTim--;
   }

   cout<<"Avg wait time = "<<wait/5<<endl;
   cout<<"Avg returnaround time = "<<turn/5<<endl;
}

void pQue(){
   int wait = 0;
   int turn = 0;
   int next = 1;
   priority_queue<pPqu> pq;
   pPqu prcP[5];
   pPqu active;
   for(int i=0; i<5; i++){
      prcP[i].arvTim = prc[i].arvTim;
      prcP[i].bstTim = prc[i].bstTim;
      prcP[i].prcId = prc[i].prcId;
      prcP[i].prior = prc[i].prir;
   }

   pq.push(prcP[0]);
   active.bstTim = 0;
   active.prior = 9999999;
   active.arvTim = 1;

   for(int i=1; ; i++){
      if(active.bstTim==0){
         turn += i-active.arvTim;
         if(pq.empty()){
            break;
         }
         active = pq.top();
         pq.pop();
      }
      
      if(i==prcP[next].arvTim){
         do{
            if(active.prior<prcP[next].prior){
               pq.push(prcP[next]);
            }else{
               pq.push(active);
               active = prcP[next];
            }
         }while(prcP[++next].arvTim == i);
      }
      wait += pq.size();
      active.bstTim--;
   }

   cout<<"Avg wait time = "<<wait/5<<endl;
   cout<<"Avg returnaround time = "<<turn/5<<endl;
}

int main(){
   input();

   cout<<endl<<"FCFS  : "<<endl;
   FCFS();

   cout<<endl<<"Sjf   : "<<endl;
   sJF();
   
   cout<<endl<<"Queue : "<<endl;
   pQue();
}
