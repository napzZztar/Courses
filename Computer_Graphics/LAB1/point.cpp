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
    glClear(GL_COLOR_BUFFER_BIT); //clears the current pixels
    glColor3f(0.0, 0.0, 0.0); //background clolor of the screen
    glPointSize(4.0); // whatever
    glBegin(GL_POINTS); // defined what will be created (pint)
    glVertex2i(100, 50);  // position of point
    glVertex2i(100, 130); // position of point
    glVertex2i(150, 130); // position of point
    glEnd(); // end of pints
    glFlush(); // implements and empties buffer
}

void myInit(void){
    glClearColor(1.0, 1.0, 1.0, 0.0); // sets the color for glClear()
    glColor3f(0.0f, 0.0f, 0.0f); // does noting???
    glPointSize(4.0); // you know what, but why is it here??
    glMatrixMode(GL_PROJECTION); // not clear yet
    glLoadIdentity(); // replace current matrix with identity matrix
    gluOrtho2D(0.0, 640.0, 0.0, 480.0); //defines from where the matrix starts from "L,R,B,T"
}
