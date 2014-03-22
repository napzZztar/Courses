#include <iostream>

using namespace std;

int D[] = {2,1,4,3,6};
int M[5][5] = {0};
int S[5][5] = {0};

int mCM(int i, int j){
   if(i == j){
      return 0;
   }
   else{
      int temp;
      M[i][j] = 99999;
      for(int k = i; k < j; k++){
         temp = mCM(i, k) + mCM(k+1, j) + D[i-1] * D[k] * D[j];
         if(temp < M[i][j]){
            M[i][j] = temp;
            S[i][j] = k;
         }
      }
      return M[i][j];
   }

}


void printOptimaPren(int i, int j){
   if(i==j){
      cout<<"M["<<i<<"]";
   }else{
      cout<<" (";
      printOptimaPren(i, S[i][j]);
      printOptimaPren(S[i][j]+1, j);
      cout<<") ";
   }
}

int main(){
   mCM(0,5);
   cout<<endl<<endl<<"Matrix M : "<<endl<<endl;
   for(int t=0; t<2;t++){
      for(int i = 1; i < 5; i++){
         for(int j = 1; j < 5; j++){
            if(t==0){
               cout<<M[i][j]<<"  ";
               if(M[i][j]<=9) cout<<" ";
            }else{
               cout<<S[i][j]<<"  ";
            }
         }
         cout<<endl<<endl;
      }
      if(t==0)cout<<endl<<endl<<"Matrix S : "<<endl<<endl;
   }

   printOptimaPren(1, 4);
   return 0;
}
