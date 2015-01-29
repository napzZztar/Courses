#include <stdio.h>
#include <GL/glut.h>

void myInit();
void DrawSquare();
void Chase();

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Chase");

    return 0;
}
