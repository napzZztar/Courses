#include <iostream>
#include <GL/glut.h>
#include <cmath>

using namespace std;
 
void myInit();
void myDisplay();
void ellipse();

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Circle");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    return 0;
}

void myInit(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-400, 400, -400, 400);
}

void myDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(2.0);
    ellipse();

    glFlush();
}
