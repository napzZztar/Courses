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
    print();
    return 0;
}

void solve(){
    int temp;
    for (int row = 0; row < 8; row++) {
        temp = placeQueen(row);

        if (temp == 9) {
            row--;
            
            for (int i = 8; i >= 0; i--) {
                if(board[row][i] == 1){
                    board[row][i] = 2;
                    break;
                }
            }

            for (int j = row+1; j < 8; j++) {
                for (int k = 0; k < 8; k++) {
                    board[j][k] = 0;
                }
            }
        }

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

                for (int k = 0; k < 8; k++) {
                    if(((j+k) == (row+col)) || (j-k) == (row - col)){
                        if(board[j][k] == 1){
                            possible = false;
                            break;
                        }
                    }
                }
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
