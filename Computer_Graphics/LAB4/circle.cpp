#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#include <iostream>
using namespace std;

int center_x;
int center_y;
int radious;

void myDisplay();
void myInit();
void drawCircle(int x,int y, int r);

int main(int argc, char **argv){
    cout<<"Enter th Coordinate of the center: ";
    cin>>center_x>>center_y;
    cout<<"Enter the radous: ";
    cin>>radious;

    myInit(&argc, argv);
    myInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    myInitWindowSize(400, 400);
    myInitWindowPosition(100, 100);
    glutCreateWindow("Circle");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    
    return 0;
}

void myDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(2.0);
    drawCircle(center_x,center_y, radious);

    glFlush();
}

void drawCircle(int x, int y, int r){
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(x, y);
    for (float i = 0; i<=((361*3.1416)/180); i+=0.01) {
        glVertex2f((x+r*cos(i)), (y+r*sin(i)));
    }

    glEnd();
}

void myInit(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-400, 400, -400, 400);
}
