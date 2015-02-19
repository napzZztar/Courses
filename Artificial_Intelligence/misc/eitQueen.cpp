#include <iostream>

using namespace std;

// 0 = not tried yet
// 1 = queen
// 2 = won't work
int board[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}};

int placeQueen(int row);
void solve();
void print();


int main(){
    solve();

    return 0;
}

void solve(){
    int temp;
    int lastCol;
    for (int i = 0; i < 8;) {
        cout<<i<<endl<<endl;
        temp = placeQueen(i);

        if (temp == 9) {
            board[--i][lastCol] = 2;
            for (int j = i; j < 8; j++) {
                for (int k = lastCol+1; k < 8; k++) {
                    board[j][k] = 0;
                }
            }
        }else{
            lastCol= temp;
            i++;
        }

        print();
        cout<<endl<<"=============================="<<endl<<endl;
    }
}

int placeQueen(int row){
    bool possible;
    int col;

    for (col = 0; col < 8; col++) {
        possible = true;
        if(board[row][col] != 2){
            for (int j = 0; j < 8; j++) {
                if ((board[row][j]==1) || (board[j][col]==1)){
                    possible = false;
                    break;
                }
                if(!possible)
                    break;
            }

            if(possible){
                board[row][col] = 1;
                return col;
            }
        }

    }

    return 9;
}

void print(){
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout<<board[i][j]<<" - ";
        }
        cout<<endl<<endl;
    }
}
