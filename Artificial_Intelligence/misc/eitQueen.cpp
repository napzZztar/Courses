#include <iostream>
#include <GL/glut.h>
#include <math.h>

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

// find methods
int placeQueen(int row);
void solve();
void print();

//openGL methods
void myInit();
void DrawSquare(int x, int y);
void Chess();
void drawCircle(int x, int y);

int main(int argc, char **argv){
    solve();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Chess");
    glutDisplayFunc(Chess);
    myInit();
    glutMainLoop();

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
            row--;
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




void DrawSquare(int x, int y){
    glBegin(GL_QUADS);
    glVertex2i(x, y);
    glVertex2i(x, y+100);
    glVertex2i(x+100, y+100);
    glVertex2i(x+100, y);
    glEnd();
}

void Chess(){
    glClear(GL_COLOR_BUFFER_BIT);

    for (int i = 0; i <8; i++) {     //along X axis
        for (int j=0; j <8; j++) {   //along Y axis
            if( (i%2==0) && (j%2==0) )
                DrawSquare(i*100,j*100);
            else if( (i%2!=0) && (j%2!=0) )
                DrawSquare(i*100,j*100);

            if(board[i][j] == 1){
                glColor4f(0.5, 0.5, 0.5, 0.5);
                drawCircle(i*100+50, j*100+50);
                glColor3f(0, 0, 0);
            }
        }
    }

    glFlush();
}

void myInit(){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 800);
}

void drawCircle(int x, int y){
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(x, y);
    for (float i = 0; i<=((362*3.1416)/180); i+=0.01) {
        glVertex2f(x+(40*cos(i)), y+(40*sin(i)));
    }

    glEnd();
}
