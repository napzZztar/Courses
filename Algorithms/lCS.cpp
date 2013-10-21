#include <iostream>
using namespace std;
char A[10] = "AJNMHIF2K";
char B[9]  = "JFMHIN2K";
int X[10][11] = {0};
int D[10][11] = {4};


void outPut(){
	cout<<"=================================="<<endl;
	cout<<"--_-";
	for(int i=0; i<9; i++) cout<<A[i]<<"-";
	cout<<endl;

	for(int i=0; i<9; i++){
		if(i==0) cout<<"_-";
		else cout<<B[i-1]<<"-";
		for(int j=0; j<10; j++){
			cout<<X[i][j]<<"-";
		}
		cout<<endl;
	}
	cout<<"=================================="<<endl;
}

void creatMat(){
	for(int i=1; i<9; i++){
		for(int j=1; j<10; j++){
			if(A[j-1] == B[i-1]){
				X[i][j] = X[i-1][j-1] + 1;
				D[i][j] = 0;
			}else{
				if(X[i][j-1] > X[i-1][j]){
					 X[i][j] = X[i][j-1];
					 D[i][j] = 1;

				}else{
					X[i][j] = X[i-1][j];
					D[i][j] = 2;

				}
			}
		}
	}
}

void printLCS(int i, int j){
	if(X[i][j] == 0){
		return;
	}else if(D[i][j] == 0){
		printLCS(i-1, j-1);
		cout<<A[i];
	}else if(D[i][j] == 1){
		printLCS(i, j-1);
	}else if(D[i][j] == 2){
		printLCS(i-1, j);
	}
}

int main(){
	creatMat();
	outPut();
	printLCS(8, 9);
	cout<<endl;

	return 0;
}
