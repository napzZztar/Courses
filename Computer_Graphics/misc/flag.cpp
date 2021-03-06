#include <GL/glut.h>
#include <math.h>

void myDisplay();
void glutInit();
void drawCircle(int a, int r);

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Circle");
    glutDisplayFunc(myDisplay);
    glutInit();
    glutMainLoop();
    
    return 0;
}


void myDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(2.0);
    drawCircle(361, 200);

    glFlush();
}

void drawCircle(int a, int r){
    glBegin(GL_TRIANGLE_FAN);
    glVertex2d(0, 0);
    for (float i = 0; i<=((a*3.1416)/180); i+=0.01) {
        glVertex2f((r*cos(i)), (r*sin(i)));
    }
    glEnd();
}

void glutInit(){
    glClearColor(0.0, 0.35, 0.11, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-450, 550, -300, 300);
}
