#include <stdio.h>
#include <GL/glut.h>

void myInit(void);
void myDisplay(void);

int main(int argc, char** argv){
    glutInit(&argc, argv); // Initializes the GLUT library
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //sets the initial display mode (unsigned int mode)
    glutInitWindowSize(640, 480); //name says what it does. :P
    glutInitWindowPosition(100, 150); //position from the upper left conrner
    glutCreateWindow("Point window"); //creates window, title as parameter
    glutDisplayFunc(myDisplay); //comment this line, you'll see the magic
    myInit();
    glutMainLoop(); // keeps the current view till end, never returns

    return 0;
}

void myDisplay(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(4.0);
    glBegin(GL_POINTS);
    glVertex2i(100, 50);
    glVertex2i(100, 130);
    glVertex2i(150, 130);
    glEnd();
    glFlush();
}

void myInit(void){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}
