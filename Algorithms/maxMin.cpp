#include <iostream>
using namespace std;

int max1, max2;
int min1, min2;
int mid;
int A[]={3,45,30,57,1,6};


void devNConc(int lft, int rit, int *max, int *min){
   if(rit-lft <= 1){
      if(A[lft]<A[rit]){
         *max = A[rit];
         *min = A[lft];

      }else{
         *max = A[lft];
         *min = A[rit];

      }

   }else{
      mid = (lft + rit)/2;
      devNConc(lft, mid, &max1, &min1);
      devNConc(mid+1, rit, &max2, &min2);

      if(max1>max2){
         *max = max1;

      }else{
         *max = max2;

      }

      if(min1<min2){
         *min = min1;

      }else{
         *min = min2;

      }

   }

}

int main(){
   int maxF;
   int minF;

   devNConc(0, 5, &maxF, &minF);
   cout<<"Max :"<<maxF<<endl<<"Min :"<<minF;
}
