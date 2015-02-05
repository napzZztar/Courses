#include <stdio.h>
#include <GL/glut.h>
#include <iostream>
#include <math.h>

using namespace std;
 
//******************************
//** Grapics Functions *********
//******************************
void drawGraph();
void myInit();
void drawRect(int x, int l);
void myDisplay();

//******************************
//** Statstics Functions *******
//******************************
void input();
void createTable();

int main(int argv, char** argc){
    glutInit(&argv,argc);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Title ");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();

    return 0;
}

void drawGraph(){
    glLineWidth(2.5);
    glBegin(GL_LINES);
    glVertex2i(-100, 0);
    glVertex2i(700, 0);
    glVertex2i(0, -100);
    glVertex2i(0, 800);
    glEnd();

    glColor4f(0.5, 0.5, 0.5, 0.5);
    glLineWidth(1);
    glBegin(GL_LINES);

    for (int i = 1; i < 70; i++) {
        if(i%5 == 0){
            glEnd();
            glLineWidth(2.0);
            glBegin(GL_LINES);
            glVertex2i(-100, i*10);
            glVertex2i(700, i*10);
            glVertex2i(i*10, -100);
            glVertex2i(i*10, 700);
            glEnd();

            glLineWidth(1);
            glBegin(GL_LINES);
        }else{
            glVertex2i(-100, i*10);
            glVertex2i(700, i*10);
            glVertex2i(i*10, -100);
            glVertex2i(i*10, 700);
        }

    }

    glEnd();

}

void drawRect(int x, int l){
    x *= 10;
    l *= 10;

    glBegin(GL_POLYGON);
    glVertex2d(x, 0);
    glVertex2d(x+50, 0);
    glVertex2d(x+50, l);
    glVertex2d(x, l);
    glEnd();
}

void myInit(){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100, 700, -100, 700);
}

void myDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3i(0, 0, 0);
    glPointSize(4.0);

//******************************
//* All the things to draw *****
//******************************

    drawGraph();
    drawRect(5, 10);

    glFlush();

}
