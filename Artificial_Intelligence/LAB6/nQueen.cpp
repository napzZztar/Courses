#include <iostream>
#include <GL/glut.h>
#include <math.h>

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

//openGL methods
void myInit();
void DrawSquare(int x, int y);
void Chess();
void drawCircle(int x, int y);

int main(int argc, char **argv){
    cout<<"Enter the number of N: ";
    cin>>N;
    solve();
    print();

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
    for (int row = 0; row < N; row++) {
        temp = placeQueen(row);

        if (temp == (N+1)) {
            row--;
            for (int i = N; i >= 0; i--) {
                if(board[row][i] == 1){
                    board[row][i] = 2;
                    break;
                }
            }

            for (int j = row+1; j < N; j++) {
                for (int k = 0; k < N; k++) {
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

    for (col = 0; col < N; col++) {
        possible = true;
        if(board[row][col] != 2){
            for (int j = 0; j < N; j++) {
                if ((board[row][j]==1) || (board[j][col]==1)){
                    possible = false;
                    break;
                }

                for (int k = 0; k < N; k++) {
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


void DrawSquare(int x, int y){
    int w = 800/N;
    x *= w;
    y *= w;
    glBegin(GL_QUADS);
    
    glVertex2i(x, y);
    glVertex2i(x, y+w);
    glVertex2i(x+w, y+w);
    glVertex2i(x+w, y);
    glEnd();
}

void Chess(){
    glClear(GL_COLOR_BUFFER_BIT);

    for (int i = 0; i <N; i++) {     //along X axis
        for (int j=0; j <N; j++) {   //along Y axis
            if( (i%2==0) && (j%2==0) )
                DrawSquare(i,j);
            else if( (i%2!=0) && (j%2!=0) )
                DrawSquare(i,j);

            if(board[i][j] == 1){
                glColor4f(0.8, 0.8, 0.8, 0.8);
                drawCircle(i*(800/N)+(400/N), j*(800/N)+(400/N));
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
    gluOrtho2D(0, 795, 0, 795);
}

void drawCircle(int x, int y){
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(x, y);
    for (float i = 0; i<=((362*3.1416)/180); i+=0.01) {
        glVertex2f(x+((350/N)*cos(i)), y+((350/N)*sin(i)));
    }

    glEnd();
}
