#include <iostream>
#include <stdio.h>
#include <GL/glut.h>
using namespace std;


int nPoints;
int window_min_x, window_min_y;
int window_max_x, window_max_y;
bool bits[3][4] = {0};
float coords[10][10];

void calculateBinary(int x, int y, int p); //Calculate the binary string (top bottom left right)
void myInit(void);
void myDisplay(void);
void theRect(); //Draws the racgangle from input
void theLine(float line_start_x, float line_start_y, float line_end_x, float line_end_y); //Draws the line using DDA Algorithm
void input();

int main(int argc, char** argv){
    input();

    // window_min_x = 200;
    // window_min_y = 250;
    // window_max_x = 300;
    // window_max_y = 350;
    //
    // line_start_x = 100;
    // line_start_y = 200;
    // line_end_x = 300;
    // line_end_y = 350;

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

void myInit(void){
    glClearColor(1.0, 1.0, 1.0, 0.0);            
    glColor3f(0.0f, 0.0f, 0.0f);                 
    glPointSize(2.0);                            
    glMatrixMode(GL_PROJECTION);                 
    glLoadIdentity();                            
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);          
}

void myDisplay(void){
    glClear(GL_COLOR_BUFFER_BIT);                
    glColor3f(0.0, 0.0, 0.0);                    
    glPointSize(4.0);                            
    theRect();

    for (int i = 0; i < nPoints; i++) {
        theLine(coords[i][0], coords[i][1], coords[i+1][0], coords[i+1][1]);
    }
    theLine(coords[0][0], coords[0][1], coords[nPoints-1][0], coords[nPoints-1][1]);

    glFlush();                                   
}

void theRect(){
    glBegin(GL_LINE_LOOP);                          
    glVertex2d(window_min_x, window_min_y);
    glVertex2d(window_max_x, window_min_y);
    glVertex2d(window_max_x, window_max_y);
    glVertex2d(window_min_x, window_max_y);
    glEnd();
}

void theLine(float line_start_x, float line_start_y, float line_end_x, float line_end_y){
    cout<<line_start_x<<" , "<<line_start_y<<" - "<<line_end_x<<" , "<<line_end_y<<endl;

    float dx, dy;   //point increments
    float x, y;     //initial point
    float m;

    x = line_start_x;
    y = line_start_y;

    m = (float)(line_end_y - line_start_y)/ (float)(line_end_x - line_start_x);

    for (int i = 0; x <= line_end_x ; i++) {
        if(m<1){ //if the line have a negative slop
            dx = 1;
            dy = m*dx;
        }else{ //for positive slop
            dy = 1;
            dx = dy/m;
        }

        x = x+dx;
        y = y+dy;

        calculateBinary((int)x, (int)y, 2); //varify if current point is inside

        if(bits[2][0] || bits[2][1] || bits[2][2] || bits[2][3]){
            glColor3f(1, 0, 0); //red for outside
            glBegin(GL_POINTS);
            glVertex2d(x, y);
            glEnd();
        }else{
            glColor3f(0, 1, 0); //green for outside
            glBegin(GL_POINTS);
            glVertex2d(x, y);
            glEnd();
        }
        
        for (int j = 0; j < 4; j++) {
            bits[2][j] = 0; //re initialize the binary string
        }

    }

}

void calculateBinary(int x, int y, int p){
    if(y>window_max_y)
        bits[p][0] = 1;

    if(y<window_min_y)
        bits[p][1] = 1;

    if(x>window_max_x)
        bits[p][2] = 1;

    if(x<window_min_x)
        bits[p][3] = 1;

}

void input(){
    cout<<"Enter the minimum window Coordinate: ";
    cin>>window_min_x>>window_min_y;
    cout<<"Enter the maximum window Coordinate: ";
    cin>>window_max_x>>window_max_y;

    cout<<endl<<"Enter the number of points : ";
    cin>>nPoints;

    cout<<endl<<"Enter the coordinates followed by Enter : "<<endl;
    for (int i = 0; i < nPoints; i++) {
        cin>>coords[i][0]>>coords[i][1];
    }
}
