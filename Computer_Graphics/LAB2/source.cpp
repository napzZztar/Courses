#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
using namespace std;


int promt();
void myInit();
void myDisplay();

int main(int argc, char** argv){
    
    promt();

    // glutInit(&argc, argv);
    // glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // glutInitWindowSize(800, 800);
    // glutInitWindowPosition(100, 100);
    // glutCreateWindow("Transformation");
    // glutDisplayFunc(myDisplay);
    // myInit();
    // glutMainLoop();
    cout<<"Wrong"<<endl;
    return 0;
}

void myInit(){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 800);
}

int promt(){
    int choice;
    cout<<"Enger Your Choice: "<<endl;
    cout<<"1. Translation"<<endl;
    cout<<"2. Rotation"<<endl;
    cout<<"3. Scaling"<<endl;
    cout<<"4. Exit"<<endl;

    cin>>choice;
    if (choice<1 || choice>3)
        exit(0);

    return choice;
}

// void myDisplay(){
//     glClear(GL_COLOR_BUFFER_BIT);
//     glColor3f(0.0, 0.0, 0.0);
//     glPointSize(5.0);
//
//     glBegin(GL_POINTS);
//     glVertex2i(100, 200);
//     glEnd();
//
//     glBegin(GL_POINTS);
//     glColor3f(1, 0, 0);
//     glVertex2i(100+x, 200+y);
//     glEnd();
//
//     glFlush();
// }
