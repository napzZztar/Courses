#include <iostream>
#include <GL/glut.h>
using namespace std;


int st_x;
int st_y;
int ed_x;
int ed_y;

void myInit(void);
void myDisplay(void);
void theLine();

int main(int argc, char** argv){
    cout<<"Enter the starting coordinate";
    cin>>st_x>>st_y;
    cout<<"Enter the ending coordinate:";
    cin>>ed_x>>ed_y;

    glutInit(&argc, argv);                       
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(640, 480);                
    glutInitWindowPosition(100, 150);            
    glutCreateWindow("Point window");            
    glutDisplayFunc(myDisplay);                  
    myInit();
    glutMainLoop();                              

    return 0;
}

void myDisplay(void){
    glClear(GL_COLOR_BUFFER_BIT);                
    glColor3f(0.0, 0.0, 0.0);                    
    glPointSize(4.0);                            
    theLine();
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

void theLine(){
    float dx, dy;   //point increments
    float x, y;     //initial point
    float m;

    x = st_x;
    y = st_y;

    m = (float)(ed_y - st_y)/ (float)(ed_x - st_x);

    glBegin(GL_POINTS);
    for (int i = 0; x <= ed_x ; i++) {
        if(m>1){ //if the line have a negative slop
            dx = 1;
            dy = m*dx;
        }else{ //for positive slop
            dy = 1;
            dx = dy/m;
        }

        x = x+dx;
        y = y+dy;

        glVertex2d(x, y);
    }
    glEnd();
}
