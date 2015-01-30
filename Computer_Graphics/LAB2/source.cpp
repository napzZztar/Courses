//******************************
//*** Ahmed Ashik **************
//*** 30th-Jan-2014 ************
//******************************

#include <stdio.h>
#include <iostream>
#include <GL/glut.h>
#include <math.h>
using namespace std;

#define PI 3.14159

int inPoints;
int points[20][2];
int pointsC[20][2];

void promt();
void myInit();
void showPolygon();
void translation(int n[2]);
void rotation(int n);
void scaling(int n[2]);

int main(int argc, char** argv){

    promt();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Transformation");
    glutDisplayFunc(showPolygon);
    myInit();
    glutMainLoop();
    return 0;
}

void myInit(){
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 800);
}

void showPolygon(){
    glClear(GL_COLOR_BUFFER_BIT);
    
    //before transformation
    glColor3f(0.5, 0.5, 0.5);
    glPointSize(4.0);
    glBegin(GL_POLYGON);

    for (int i = 0; i < inPoints; i++) {
        glVertex2i(points[i][0], points[i][1]);
    }
    glEnd();

    //after transformation
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < inPoints; i++) {
        cout<<pointsC[i][0]<<" - "<<pointsC[i][1]<<endl;
        glVertex2i(pointsC[i][0], pointsC[i][1]);
    }
    glEnd();

    glFlush();
}

void promt(){
    int factor[2];
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


    switch(choice){
        case 1:
            cout<<endl<<"Enter Translation Factor (x y) :\t";
            cin>>factor[0]>>factor[1];
            translation(factor);
            break;
        case 2:
            cout<<endl<<"Enter Rotation Factor (θ) :\t";
            cin>>factor[0];
            rotation(factor[0]);
            break;
        case 3:
            scaling(factor);
    }

}


void translation(int n[2]){
    cout<<"Initating Translation";
    for (int i = 0; i < inPoints; i++) {
        pointsC[i][0] = points[i][0]+n[0];
        pointsC[i][1] = points[i][1]+n[1];
    }
}

void rotation(int n){
    int r;
    int th1;
    for (int i = 0; i < inPoints; i++) {

        th1 = (atan(points[i][1]/ points[i][0])*180) / PI;
        cout<<th1<<endl;
        r = sqrt(pow(points[i][0], 2) + pow(points[i][1], 2));
        cout<<r<<endl;

        pointsC[i][0] = r * cos( (n + th1)*PI / 180);
        pointsC[i][1] = r * sin( (n + th1)*PI / 180);
    }
}

void scaling(int n[2]){
    cout<<"Initating Scaling";
    for (int i = 0; i < inPoints; i++) {
        pointsC[i][0] = points[i][0]*n[0];
        pointsC[i][1] = points[i][1]*n[1];
    }
}
