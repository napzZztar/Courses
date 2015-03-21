#include <GL/glut.h>
#include <ostream>
#include <math.h>
using namespace std;

char obj = '0';

static GLfloat spin = 0.0;
static GLfloat spin_1 = 0.0;
static GLfloat spin_2 = 0.0;
static GLfloat spin_speed = 2.0;
float spin_x = 0;
float spin_y = 1;
float spin_z = 0;

float translate_x = 0.0;
float translate_y = 0.0;
float translate_z = -30.0;

void init();
void myDisplay();
void setSpin(float x,float y,float z);
void reset();
void reshape(int w, int h);
void spinDisplay(void);
void spinDisplayReverse(void);
void mouse(int button, int state, int x, int y);
void keyboard(unsigned char key, int x, int y);
void drawSphare(int r);


int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Keyboard and mouse interaction");
    init();
    glutDisplayFunc(myDisplay);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    glutSwapBuffers();
    return 0;
}

void drawSphare(int r){
    float x;
    float y;
    float z;

    for (float i = 0; i<=((361*3.1416)/180); i+=0.1) {
        glColor3f(i/3.1416, 1-(i/3.1416), 1-i/3.1416);
        glBegin(GL_LINE_LOOP);
        for (float j = 0; j<=((361*3.1416)/180); j+=0.15) {
            z = r * cos(j);
            x = pow((r*r - z*z), .5) * cos(i);
            y = pow((r*r - z*z), .5) * sin(i);
            glVertex3f(x, y, z);
        }
        glEnd();
    }

}

void init(){
    glClearColor(0,0,0,0);
    glShadeModel(GL_SMOOTH);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
}

void myDisplay(void){   


    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glColor3f(1.0, 0.5, 0.0);

    glLoadIdentity();
    glTranslatef(translate_x, translate_y, translate_z);
    glRotatef(spin, spin_x, spin_y, spin_z);
    drawSphare(2);


    glFlush();
    glutSwapBuffers();
}

void setSpin(float x,float y,float z){
    spin_x = x;
    spin_y = y;
    spin_z = z;
}

void reset(){
    spin_x = 0;
    spin_y = 1;
    spin_z = 0;

    translate_x = 0.0;
    translate_y = 0.0;
    translate_z = -30.0;
}

void reshape(int w, int h){
    glViewport(0,0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100.0f, (GLsizei)w/(GLsizei)h, 1.0f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void spinDisplay(void){

    spin += spin_speed;

    if (spin>360.0) {

        spin -= 360.0;
    }
    glutPostRedisplay();
}

void spinDisplayReverse(void){
    spin -= spin_speed;

    if (spin<360.0) {

        spin += 360.0;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y){

    switch (button) {
        case GLUT_LEFT_BUTTON:
            if(state==GLUT_DOWN)
                glutIdleFunc(spinDisplay);
            break;
        case GLUT_MIDDLE_BUTTON:
            if(state==GLUT_DOWN)
                glutIdleFunc(NULL);
            break;
        case GLUT_RIGHT_BUTTON:
            if(state==GLUT_DOWN)
                glutIdleFunc(spinDisplayReverse);
            break;
        default:
            break;
    }
}

void keyboard(unsigned char key, int x, int y){

    if (key=='x') {
        setSpin(1.0, 0.0, 0.0);
        glutPostRedisplay();

    }else if (key=='y') {
        setSpin(0.0, 1.0, 0.0);
        glutPostRedisplay();

    }else if (key=='z') {
        setSpin(0.0, 0.0, 1.0);
        glutPostRedisplay();

    }else if (key=='a') {
        setSpin(1.0, 1.0, 1.0);
        glutPostRedisplay();

    }else if (key=='i') {
        translate_z++;
        glutPostRedisplay();

    }else if (key=='o') {
        translate_z--;
        glutPostRedisplay();
    }else if (key=='r') {
        reset();
        glutPostRedisplay();
    }
}
