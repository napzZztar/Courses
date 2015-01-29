#include <stdio.h>
#include <GL/glut.h>

void myInit();
void DrawSquare(int x, int y);
void Chase();

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Chase");
    glutDisplayFunc(Chase);
    myInit();
    glutMainLoop();
    return 0;
}

void DrawSquare(int x, int y){
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2i(x+100, y);
    glVertex2i(x, y);
    glVertex2i(x+100, y+100);
    glVertex2i(x, y+100);
    glEnd();
}

void Chase(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3i(0, 0, 0);
    glPointSize(1.0);

    for (int i = 0; i < 800; i+=100) {
        for (int j=0; j < 800; j+=100) {
            if( ((i/100)%2==0) && ((j/100)%2==0) )
                DrawSquare(i,j);
            else if( ((i/100)%2!=0) && ((j/100)%2!=0) )
                DrawSquare(i,j);
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
