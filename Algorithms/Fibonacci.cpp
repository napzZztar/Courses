#include <iostream>
using namespace std;


int fib(int n){
    if(n <= 1){
        return n;
    }else{
        return fib(n-1) + fib(n-2);

    }
}

int main(){
    int st = 0;
    int nd = 1;
    int fi;

    int n =1;

    cout<<"The "<<n<<"th number using Recursion : "<<fib(n)<<endl;

    if(n<=1){
        fi = n;
    }else{
        for(int i=0; i<=n-2; i++){
            fi = st + nd;
            st = nd;
            nd = fi;
        }
    }

    cout<<"The "<<n<<"th number using Iteration : "<<fi<<endl;

    return 0;
}
