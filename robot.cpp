﻿
#include "glos.h"
#include "gl.h"
#include "glu.h"
#include "glaux.h"

static int shoulder = 0, elbow = 0;
static int shoulderFrontBack = 0, elbowFrontBack = 0;

void CALLBACK elbowAdd()
{
	elbow = (elbow + 5) % 360;
}

void CALLBACK elbowSubtract()
{
	elbow = (elbow - 5) % 360;
}

void CALLBACK shoulderAdd()
{
	shoulder = (shoulder + 5) % 360;
}

void CALLBACK shoulderSubtract()
{
	shoulder = (shoulder - 5) % 360;
}

void CALLBACK shoulderFrontAdd()
{
	shoulderFrontBack = (shoulderFrontBack + 5) % 360;
}

void CALLBACK shoulderFrontSubtract()
{
	shoulderFrontBack = (shoulderFrontBack - 5) % 360;
}

void CALLBACK elbowFrontAdd()
{
	elbowFrontBack = (elbowFrontBack + 5) % 360;
}

void CALLBACK elbowFrontSubtract()
{
	elbowFrontBack = (elbowFrontBack - 5) % 360;
}

void CALLBACK display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -5.0);

	glColor3f(1.0, 0, 0);

	float lungimeBrat = 2;
	glRotatef((GLfloat)shoulder, 0.0, 0.0, 1.0);
	glRotatef((GLfloat)shoulderFrontBack, 1.0, 0.0, 0.0); 
	glTranslatef(lungimeBrat / 2, 0.0, 0.0);
	auxWireBox(lungimeBrat, 0.4, 1.0);

	float lungimeAntebrat = 1.5;
	glTranslatef(lungimeBrat / 2, 0.0, 0.0);
	glRotatef((GLfloat)elbow, 0.0, 0.0, 1.0);
	glRotatef((GLfloat)elbowFrontBack, 1.0, 0.0, 0.0); 
	glTranslatef(lungimeAntebrat / 2, 0.0, 0.0);
	auxWireBox(lungimeAntebrat, 0.4, 1.0);
	glFlush();
}

void myInit()
{
}

void CALLBACK myReshape(GLsizei w, GLsizei h)
{
	if (!h) return;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	auxInitDisplayMode(AUX_SINGLE | AUX_RGB);
	auxInitPosition(0, 0, 800, 600);
	auxInitWindow("Composite Modeling Transformations");
	myInit();
	auxKeyFunc(AUX_LEFT, shoulderSubtract);
	auxKeyFunc(AUX_RIGHT, shoulderAdd);
	auxKeyFunc(AUX_UP, elbowAdd);
	auxKeyFunc(AUX_DOWN, elbowSubtract);

	auxKeyFunc(AUX_a, shoulderFrontSubtract);
	auxKeyFunc(AUX_d, shoulderFrontAdd);
	auxKeyFunc(AUX_w, elbowFrontSubtract);
	auxKeyFunc(AUX_s, elbowFrontAdd);
	auxReshapeFunc(myReshape);
	auxMainLoop(display);
	return 0;
}

