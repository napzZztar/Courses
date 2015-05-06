#include <iostream>
#include <GL/glut.h>
#include <cmath>

using namespace std;
 
float DEG2RAD = 3.14159/180.0;

float centerX;
float centerY;
float mejor;
float minor;

void myInit();
void myDisplay();
void ellipse();
void input();

int main(int argc, char **argv){
    input();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1200, 720);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Ellipse");
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

void ellipse(){
    float degInRad;
    glTranslatef(centerX, centerY, 0);

    glBegin(GL_POINTS);
    for(float i=0; i < 360; i+=.03)
    {
        degInRad = i*DEG2RAD;
        glVertex2f(cos(degInRad)*mejor,sin(degInRad)*minor);
    } 
    glEnd();
}

void input(){
    cout<<"Enter the coordinates fo the center:"<<endl;
    cout<<"\t X-coordinate :\t";
    cin>>centerX;
    cout<<"\t Y-coordinate :\t";
    cin>>centerY;

    cout<<endl<<endl<<"Enter the Minor axis :\t";
    cin>>minor;
    cout<<"Enter the Mejor axix :\t";
    cin>>mejor;
}
