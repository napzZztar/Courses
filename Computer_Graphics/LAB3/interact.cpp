#include <GL/glut.h>

static GLfloat spin = 0.0;
static GLfloat spin_speed = 1.0;
float spin_x = 0;
float spin_y = 1;
float spin_z = 0;

float translate_x = 0.0;
float translate_y = 0.0;
float translate_z = -30.0;

void myInit();
void myDisplay();
void setSpin(float x,float y,float z);
void reset();
void reshape(int w, int h);
void spinDisplay(void);
void spinDisplayReverse(void);
void mouse(int button, int state, int x, int y);
void keyboard(unsigned char key, int x, int y);

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Keyboard and mouse interaction");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    
    return 0;
}

void myInit(){
    glClearColor(0,0,0,0);
    glShadeModel(GL_SMOOTH);
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
}

void myDisplay(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(translate_x, translate_y, translate_z);
    glRotatef(spin, spin_x, spin_y, spin_z);

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

}
void keyboard(unsigned char key, int x, int y){

}
