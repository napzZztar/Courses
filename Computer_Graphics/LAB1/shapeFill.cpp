//******************************
//*** Ahmed Ashik **************
//*** 29th-Jan-2014 ************
//******************************

#include <stdio.h>
#include <GL/glut.h>

void myInit();
void myDisplay();

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Shapes Filled");

    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();

    return 0;
}

void myInit(){
    glClearColor(1.0, 1.0, 1.0, 0.0 );
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1024.0, 0.0, 768.0);
}

void myDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glPointSize(4.0);
    //Drawing Triangle
    glBegin(GL_TRIANGLES);
    glVertex2i(550, 100);
    glVertex2i(550, 350);
    glVertex2i(750, 100);
    glEnd();

    //Drawing Rectangle
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2i(100, 100);
    glVertex2i(500, 100);
    glVertex2i(100, 400);
    glVertex2i(500, 400);
    glEnd();
    glFlush();
}
