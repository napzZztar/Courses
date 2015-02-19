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
    
    return false;
}
