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

int main(){
    
    return 0;
}

void solve(){
    int temp;
    int lastQueen;
    for (int i = 0; i < 8; i++) {
        if ((temp = placeQueen(i)) == 9) {
            board[--i][lastQueen] = 2;
        }else{
            lastQueen = temp;
        }
    }
}

int placeQueen(int row){
    bool possible;
    for (int col = 0; col < 8; col++) {
        if(board[row][col] != 2){
            for (int j = row; j < 8; j++) {
                for (int k = col; k < 8; k++) {
                    if ((board[row][j]!=1) || (board[j][col]!=1) || (board[j][k]!=1)) {
                        possible = true;
                    }else
                        possible = false;
                }
            }
        }
    }

    if(possible){
        for (int col = 8; col >= 0; col--) {
            if(board[row][col] != 2){
                for (int j = row; j >= 0; j--) {
                    for (int k = col; k >= 0; k--) {
                        if ((board[row][j]!=1) || (board[j][col]!=1) || (board[j][k]!=1)) {
                            board[row][col] = 1;
                            return col;
                        }
                    }
                }
            }
        }
    }

    return 9;
}
