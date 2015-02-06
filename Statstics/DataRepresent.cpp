#include <stdio.h>
#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

struct tab{
    int lower;
    int higher;
    int freaqu;
};

int h;
int fn;
int noOfData = 0;
float data[500] = {-1};
tab table[50];


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
    input();
    createTable();

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


//******************************
//** Grapics Functions *********
//******************************

void drawGraph(){
    glColor3f(1.0, 0.0, 0.0);
    glLineWidth(4.0);
    glBegin(GL_LINES);
    glVertex2i(-100, 0);
    glVertex2i(700, 0);
    glVertex2i(0, -100);
    glVertex2i(0, 800);
    glEnd();

    glColor4f(0.5, 0.5, 0.5, 0.5);
    glLineWidth(1);
    glBegin(GL_LINES);

    for (int i = -10; i < 70; i++) {
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
    x *= 5;
    l *= 10;

    glBegin(GL_POLYGON);
    glVertex2d(x, 0);
    glVertex2d(x+h*5, 0);
    glVertex2d(x+h*5, l);
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
    glColor3f(0, 0, 0);
    glPointSize(4.0);

    //* All the things to draw *****
    drawGraph();
    for (int i = 0; i < fn; i++) {
        glColor3f(0.5, 0.5, ((float)i/fn));

        drawRect(table[i].lower, table[i].freaqu);
    }

    glFlush();

}


//******************************
//** Statstics Functions *******
//******************************

void input(){
    fstream myfile("input.txt", ios_base::in);

    int i=0;
    while (myfile >> data[i++])
        noOfData++;
}

void createTable(){
    float max = data[0];
    float min = data[0];

    //find the max and min values
    for (int i = 0; i < noOfData; i++) {
        if(data[i] < min)
            min = data[i];

        if(data[i] > max)
            max = data[i];
    }

    h = ceil((max-min)/(1+3.3*log10(noOfData)));

    table[0].lower = min;
    table[0].higher = min+h;

    for (fn = 1; ; fn++) {
        table[fn].lower = table[fn-1].higher;
        table[fn].higher = table[fn].lower +h;
        table[fn].freaqu = 0;

        if(table[fn].higher >= max){
            fn++;
            break;
        }
    }

    for (int i = 0; i < noOfData; i++) {
        for (int j = 0; j < fn; j++) {
            if(data[i] < table[j].higher){
                table[j].freaqu++;
                break;
            }
        }
    }

    for (int i = 0; i < fn; i++) {
        printf("%d-%d\t%d\n", table[i].lower, table[i].higher, table[i].freaqu);
    }
}
