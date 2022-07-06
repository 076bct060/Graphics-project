

#define _USE_MATH_DEFINES 

#include <cmath>
#include <iostream>

#include <GL/glew.h>
#include <GL/freeglut.h>

// Globals.
static int p = 30; 
static int q = 30; 
static float Xangle = 0.0, Yangle = 0.0, Zangle = 0.0; 

// Initialization routine.
void setup(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
}
void sphere(int radius)
{
	int  i, j;
	for (j = 0; j < 2 * q; j++)
	{
		glBegin(GL_TRIANGLE_STRIP);
		for (i = 0; i <= p; i++)
		{
			glVertex3f(radius * cos((float)(j + 1) / q * M_PI) * cos(2.0 * (float)i / p * M_PI),
				radius * sin((float)(j + 1) / q * M_PI),
				-radius * cos((float)(j + 1) / q * M_PI) * sin(2.0 * (float)i / p * M_PI));
			glVertex3f(radius * cos((float)j / q * M_PI) * cos(2.0 * (float)i / p * M_PI),
				radius * sin((float)j / q * M_PI),
				-radius * cos((float)j / q * M_PI) * sin(2.0 * (float)i / p * M_PI));
		}
		glEnd();
	}
}
// Drawing routine.
void drawScene(void)
{


	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();

	//Sun
	glTranslatef(0.0, 0.0, -10.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(1.0, 1.0, 0.0);
	sphere(5);
	//Mercury
	glTranslatef(7, 0.0, -10.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(1.0, 0.0, 0.0);
	sphere(1);
	//Venus
	glTranslatef(11, 0.0, -10.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(.3, 0.0, .5);
	sphere(1.5);
	//Earth
	glTranslatef(16, 0.0, -10.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(1.0, 0.0, 0.0);
	sphere(2.0);
	//Mars
	glTranslatef(21, 0.0, -10.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(1.0, 0.0, 0.0);
	sphere(1.2);
	//Jupiter
	glTranslatef(28, 0.0, -10.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(1.0, 0.0, 0.0);
	sphere(3.5);
	//Saturn
	glTranslatef(37, 0.0, -10.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(1.0, 0.0, 0.0);
	sphere(3.0);
	//Uranus
	glTranslatef(45.5, 0.0, -10.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(1.0, 0.0, 0.0);
	sphere(2.5);
	//Neptune
	glTranslatef(53.6, 0.0, -10.0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	glColor3f(1.0, 0.0, 0.0);
	sphere(2.3);
	glFlush();
}



void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
}


void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;
	case 'P':
		p += 1;
		glutPostRedisplay();
		break;
	case 'p':
		if (p > 3) p -= 1;
		glutPostRedisplay();
		break;
	case 'Q':
		q += 1;
		glutPostRedisplay();
		break;
	case 'q':
		if (q > 3) q -= 1;
		glutPostRedisplay();
		break;
	case 'x':
		Xangle += 5.0;
		if (Xangle > 360.0) Xangle -= 360.0;
		glutPostRedisplay();
		break;
	case 'X':
		Xangle -= 5.0;
		if (Xangle < 0.0) Xangle += 360.0;
		glutPostRedisplay();
		break;
	case 'y':
		Yangle += 5.0;
		if (Yangle > 360.0) Yangle -= 360.0;
		glutPostRedisplay();
		break;
	case 'Y':
		Yangle -= 5.0;
		if (Yangle < 0.0) Yangle += 360.0;
		glutPostRedisplay();
		break;
	case 'z':
		Zangle += 5.0;
		if (Zangle > 360.0) Zangle -= 360.0;
		glutPostRedisplay();
		break;
	case 'Z':
		Zangle -= 5.0;
		if (Zangle < 0.0) Zangle += 360.0;
		glutPostRedisplay();
		break;
	default:
		break;
	}
}

// Routine to output interaction instructions to the C++ window.
void printInteraction(void)
{
	std::cout << "Interaction:" << std::endl;
	std::cout << "Press P/p to increase/decrease the number of longitudinal slices." << std::endl
		<< "Press Q/q to increase/decrease the number of latitudinal slices." << std::endl
		<< "Press x, X, y, Y, z, Z to turn the hemisphere." << std::endl;
}

// Main routine.
int main(int argc, char** argv)
{
	printInteraction();
	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("hemisphere.cpp");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop();
}

