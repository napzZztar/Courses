#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
using namespace std;

int inPoints;
int points[20][2];

int promt();
void myInit();
void myDisplay();
void translation();
void rotation();
void scaling();

int main(int argc, char** argv){
    
    cout<<promt();

    // glutInit(&argc, argv);
    // glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // glutInitWindowSize(800, 800);
    // glutInitWindowPosition(100, 100);
    // glutCreateWindow("Transformation");
    // glutDisplayFunc(myDisplay);
    // myInit();
    // glutMainLoop();
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
    cout<<"Enter Your Choice: "<<endl;
    cout<<"\t1. Translation"<<endl;
    cout<<"\t2. Rotation"<<endl;
    cout<<"\t3. Scaling"<<endl;
    cout<<"\t0. Exit"<<endl;
    cout<<":>";

    cin>>choice;
    if (choice<1 || choice>3)
        exit(0);
    
    cout<<"Enter the number of points: ";
    cin>>inPoints;

    cout<<"Plese enter the coordinates."<<endl;
    for (int i = 0; i < inPoints; i++) {
        cout<<"Coordinate "<<i<<" (x y) :\t";
        cin>>points[i][0]>>points[i][1];
    }

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
