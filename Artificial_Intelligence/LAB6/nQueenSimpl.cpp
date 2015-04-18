//***************************************************
//** solve:                                        **
//**     for each row                              **
//**         if [placeQueen = 9]                   **
//**             back to last queen and palce 2    **
//** palceQueen:                                   **
//**     if [board value is not 2]                 **
//**         if[placeable]                         **
//**             change board value to 1           **
//***************************************************


#include <iostream>
#include <math.h>    //will be needed while drawing circles

#define aSz 20

using namespace std;

// 0 = not tried yet
// 1 = queen
// 2 = won't work
int board[aSz][aSz] = {0};
int N;

// find methods
int placeQueen(int row);
void solve();
void print();

int main(){
    cout<<"Enter the number of N: ";
    cin>>N;
    solve();
    print();

    return 0;
}

void solve(){
    int temp;
    for (int row = 0; row < N; row++) {
        temp = placeQueen(row); //as every row will contain a queen 

        if (temp == (N+1)) { //if placing a queen is not possible in this row
            row--; //bakcing up a bit
            for (int i = N; i >= 0; i--) {
                if(board[row][i] == 1){ 
                    board[row][i] = 2; //placing a queen here won't work
                    break;
                }
            }

            for (int k = 0; k < N; k++) { //clean up the old mess
                board[row+1][k] = 0;
            }
            row--;
        }
    }
}

int placeQueen(int row){
    bool possible;
    int col;

    for (col = 0; col < N; col++) {
        possible = true; //let placing a queen here is possible
        if(board[row][col] != 2){ //well, you already tried this combination
            for (int j = 0; j < N; j++) {
                if ((board[row][j]==1) || (board[j][col]==1)){ //there are queen in this row and column
                    possible = false;
                    break;
                }

                for (int k = 0; k < N; k++) {
                    if(((j+k) == (row+col)) || (j-k) == (row - col)){ //diagonal check
                        if(board[j][k] == 1){
                            possible = false;
                            break;
                        }
                    }
                }
            }

            if(possible){ // no threat 
                board[row][col] = 1;
                return col;
            }
        }

    }

    return (N+1);
}

void print(){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout<<board[i][j]<<" - ";
        }
        cout<<endl<<endl;
    }
}
