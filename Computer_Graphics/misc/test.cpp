#include <GL/glut.h>

float _angle = 0.0;

void Draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glPointSize(8);
glPushMatrix();

	glRotatef(_angle, 0.0, 0.0, 1.0);
		glBegin(GL_POINTS);
			glVertex3f(0.5, 0.0, 0.0);
		glEnd();
glPopMatrix();	

	glFlush();
}

void update(int value)
{
	_angle += 0.1;
	if (_angle > 360)
	{
	_angle -= 360;
	}

	glutPostRedisplay();
	glutTimerFunc(5,update,0);
}

void Initialize() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

int main(int iArgc, char** cppArgv) {
	glutInit(&iArgc, cppArgv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("CSE");
	Initialize();
	glutDisplayFunc(Draw);
	glutTimerFunc(25,update,0);
	glutMainLoop();
	return 0;
}