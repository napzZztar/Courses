#include <GL/glut.h>
#include <ostream>
#include <math.h>
using namespace std;

int obj = 0;

static GLfloat spin = 0.0;
static GLfloat spin_speed = 20.0;
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
void drawSphare(int x, int r);

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

void drawSphare(int x, int r){
    
    for(float j = 0; j<=r; j+=0.01){
        glBegin(GL_LINES);
        for (float i = 0; i<=((x*3.1416)/180); i+=0.01) {
            glColor4f(j/r, i/3.1416, i/j, j-1);
            glVertex3f((j*cos(i)), j, (j*sin(i)));
        }
        glEnd();
    }

}

void drawColorCube(int x, int y, int z, int s){
    glBegin(GL_TRIANGLE_STRIP);
    glVertex2i(x, y);
    glVertex2i(x+s, y);
    glVertex2i(x, y+s);
    glVertex2i(x+s, y+s);
    glEnd();

    glColor4f(0.5, 0.5, 0.0, 1.0);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex3i(x, y, z+s);
    glVertex3i(x+s, y, z+s);
    glVertex3i(x, y+s, z+s);
    glVertex3i(x+s, y+s, z+s);
    glEnd();

    for (float i = z; i <= z+s; i+=0.05) {
        glColor4f(i/s, (1-i)/s, 0.5, 1.0);
        glBegin(GL_LINE_LOOP);
        glVertex3f(x, y, i);
        glVertex3f(x+s, y, i);
        glVertex3f(x+s, y+s, i);
        glVertex3f(x, y+s, i);
        glEnd();
    }

}

void init(){
    glClearColor(1,1,1,0);
    glShadeModel(GL_SMOOTH);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
}

void myDisplay(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(translate_x, translate_y, translate_z);
    glColor3f(1.0, 0.5, 0.0);
    drawColorCube(-2, -4, -2, 4);

    glPushMatrix();
    glTranslatef(translate_x, translate_y, translate_z);
    glRotatef(spin, spin_x, spin_y, spin_z);
    drawSphare(361, 2);
    glPopMatrix();

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
    }else if (key == '1') {
        obj = 1;
    }else{
        obj = 0;
    }
}


