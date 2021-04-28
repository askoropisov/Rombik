#include "glut.h"

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glut32.lib")
float vx = 00;
float vy = 00;
float vz = 00;
float zoom = -12;


void read_special(int key, int, int)
{
	if (key == GLUT_KEY_DOWN)
	{
		vx -= 1.0f;
		glutPostRedisplay();
	}
	if (key == GLUT_KEY_UP) {
		vx += 1.0f;
		glutPostRedisplay();
	}
	if (key == GLUT_KEY_LEFT) {
		vy -= 1.0f;
		glutPostRedisplay();
	}
	if (key == GLUT_KEY_RIGHT) {

		vy += 1.0f;
		glutPostRedisplay();
	}
	if (key == '8') {
		vz -= 1.0f;
		glutPostRedisplay();
	}
	if (key == '7') {

		vz += 1.0f;
		glutPostRedisplay();
	}

	if (key == GLUT_KEY_HOME) {

		zoom += 1;
		glutPostRedisplay();
	}
	if (key == GLUT_KEY_INSERT) {

		zoom -= 1.0f;
		glutPostRedisplay();
	}

}
void idle() {
	vx += 0.02;
	glutPostRedisplay();
	vy += 0.01;
	glutPostRedisplay();
	vz += 0.05;
	glutPostRedisplay();


}

void RenderScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	// РќР°С‡Р°Р»Рѕ РЅР°С€РµРіРѕ РєРѕРґР°
	glTranslatef(0, 0, -1);

	glTranslatef(0, 0, zoom);
	glRotatef(vx, 1, 0, 0);
	glRotatef(vy, 0, 1, 0);
	glRotatef(vz, 0, 0, 1);
	glBegin(GL_TRIANGLES);
	glColor3f(0, 1, 0);
		glVertex3f(1, 1, 0);
		glVertex3f(1, -1, 0);
		glColor3f(1, 1, 1);
		glVertex3f(0, 0, 2.5);
		glColor3f(0, 1, 0);
		glVertex3f(-1, -1, 0);
		glVertex3f(-1, 1, 0);
		glColor3f(1, 1, 1);
		glVertex3f(0, 0, 2.5);
		glColor3f(0, 1, 0);
		glVertex3f(-1, 1, 0);
		glVertex3f(1, 1, 0);
		glColor3f(1, 1, 1);
		glVertex3f(0, 0, 2.5);
		glColor3f(0, 1, 0);
		glVertex3f(-1, -1, 0);
		glVertex3f(1, -1, 0);
		glColor3f(1, 1, 1);
		glVertex3f(0, 0, 2.5);

		glColor3f(0, 1, 0);
		glVertex3f(1, 1, 0);
		glVertex3f(1, -1, 0);
		glColor3f(1, 1, 1);
		glVertex3f(0, 0, -2.5);
		glColor3f(0, 1, 0);
		glVertex3f(-1, -1, 0);
		glVertex3f(-1, 1, 0);
		glColor3f(1, 1, 1);
		glVertex3f(0, 0, -2.5);
		glColor3f(0, 1, 0);
		glVertex3f(-1, 1, 0);
		glVertex3f(1, 1, 0);
		glColor3f(1, 1, 1);
		glVertex3f(0, 0, -2.5);
		glColor3f(0, 1, 0);
		
		glColor3f(1, 1, 1);
		glVertex3f(0, 0, -2.5);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0, 0.9, 0);
	glVertex3f(0, 0, -2.5);
	glVertex3f(1, 1, 0);
	glVertex3f(0, 0, -2.5);
	glVertex3f(-1, -1, 0);
	glVertex3f(0, 0, -2.5);
	glVertex3f(1, -1, 0);
	glVertex3f(0, 0, -2.5);
	glVertex3f(-1, 1, 0);

	glVertex3f(0, 0, 2.5);
	glVertex3f(1, 1, 0);
	glVertex3f(0, 0, 2.5);
	glVertex3f(-1, -1, 0);
	glVertex3f(0, 0, 2.5);
	glVertex3f(1, -1, 0);
	glVertex3f(0, 0, 2.5);
	glVertex3f(-1, 1, 0);

	glVertex3f(-1, 1, 0);
	glVertex3f(-1, -1, 0);

	glVertex3f(-1, -1, 0);
	glVertex3f(1, -1, 0);

	glVertex3f(1, -1, 0);
	glVertex3f(1, 1, 0);

	glVertex3f(1, 1, 0);
	glVertex3f(-1, 1, 0);
	glEnd();
	// РљРѕРЅРµС† РЅР°С€РµРіРѕ РєРѕРґР°
	glutSwapBuffers();
}

void ReshapeWindow(GLsizei width, GLsizei height) {
	if (height == 0)
		height = 1;
	GLfloat aspect = (GLfloat)width / (GLfloat)height;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, aspect, 0.1f, 1000.0f);
}

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Ромбик");
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glClearColor(0, 0, 0, 1);
	glutSpecialFunc(read_special);
	glutDisplayFunc(RenderScene);
	glutIdleFunc(idle);
	glutReshapeFunc(ReshapeWindow);

	glutMainLoop();

	return 0;
}