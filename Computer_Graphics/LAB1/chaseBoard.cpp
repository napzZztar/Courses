//******************************
//*** Ahmed Ashik **************
//*** 29th-Jan-2014 ************
//******************************


#include <stdio.h>
#include <GL/glut.h>

void myInit();
void DrawSquare(int x, int y);
void Chess();

int main(int argc, char** argv){
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
    glColor3f(0, 0, 0);
    glPointSize(1.0);

    for (int i = 0; i <8; i++) {
        for (int j=0; j <8; j++) {
            if( (i%2==0) && (j%2==0) )
                DrawSquare(i*100,j*100);
            else if( (i%2!=0) && (j%2!=0) )
                DrawSquare(i*100,j*100);
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
