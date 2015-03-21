#include <iostream>
#include <GL/glut.h>
using namespace std;
 

int st_x;
int st_y;
int ed_x;
int ed_y;

void myInit(void);
void myDisplay(void);
void dda();

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
    glBegin(GL_POINTS);                          
    dda();
    glEnd();                                     
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

void dda(){
    float m;
    int x = st_x;
    int y = st_y;

    m = (ed_y - st_y)/(ed_x - st_x);
    
    {
        y += m;
        x += 1/m;
        glVertex2d(x, y);
        
        if(x == ed_x && y == ed_y)
            break;
    }
}
