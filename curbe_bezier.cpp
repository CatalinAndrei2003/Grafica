/*
 Programul utilizeaza evaluatorii pentru determinarea punctelor de pe curba Bezier
*/
#include "glos.h"
#include "gl.h"
#include "glu.h"
#include "glaux.h"

GLfloat ctrlpoints[4][3] = {
	{ -4.0, -4.0, 0.0}, { -4.0, 2.0, 0.0}, {4.0, 2.0, 0.0}, {4.0, -4.0, 0.0} };

GLfloat ctrlpoints1[4][3] = {
	{ 4.0, -4.0, 0.0}, { 4.0, -10.0, 0.0}, {12.0, -10.0, 0.0}, {12.0, -4.0, 0.0} };

void myInit()
{
	glClearColor(1.0, 1.0, 1.0, 1.0); 
	glLineStipple(1, 0x0F0F); 
	glEnable(GL_MAP1_VERTEX_3);
}

void CALLBACK display(void)
{
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 0.0f); 

	glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoints[0][0]);
	glBegin(GL_LINE_STRIP); 
	{
		for (int i = 0; i <= 30; i++) {
			glEvalCoord1f((GLfloat)i / 30.0f); 
		}
	}
	glEnd();

	glPointSize(5.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_POINTS);
	{
		for (int i = 0; i < 4; i++) {
			glVertex3fv(&ctrlpoints[i][0]);
		}
	}
	glEnd();

	glColor3f(1.0f, 0.0f, 1.0f);
	glEnable(GL_LINE_STIPPLE);
	glBegin(GL_LINE_STRIP);
	{
		for (int i = 0; i < 4; i++) {
			glVertex3fv(&ctrlpoints[i][0]);
		}
	}
	glEnd();
	glDisable(GL_LINE_STIPPLE);

	glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, &ctrlpoints1[0][0]);
	glBegin(GL_LINE_STRIP);
	{
		for (int i = 0; i <= 30; i++) {
			glEvalCoord1f((GLfloat)i / 30.0f);
		}
	}
	glEnd();

	glPointSize(5.0f);
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_POINTS);
	{
		for (int i = 0; i < 4; i++) {
			glVertex3fv(&ctrlpoints1[i][0]);
		}
	}
	glEnd();

	glColor3f(1.0f, 0.0f, 1.0f);
	glEnable(GL_LINE_STIPPLE);
	glBegin(GL_LINE_STRIP);
	{
		for (int i = 0; i < 4; i++) {
			glVertex3fv(&ctrlpoints1[i][0]);
		}
	}
	glEnd();
	glDisable(GL_LINE_STIPPLE);

	glFlush();
}

void CALLBACK myReshape(GLsizei w, GLsizei h)
{
	if (!h) return;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h) {
		glOrtho(-15.0, 15.0, -15.0 * (GLfloat)h / (GLfloat)w, 15.0 * (GLfloat)h / (GLfloat)w, -15.0, 15.0);
	}
	else {
		glOrtho(-15.0 * (GLfloat)w / (GLfloat)h, 15.0 * (GLfloat)w / (GLfloat)h, -15.0, 15.0, -15.0, 15.0);
	}
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
	auxInitDisplayMode(AUX_SINGLE | AUX_RGB);
	auxInitPosition(0, 0, 500, 500);
	auxInitWindow("Curbe Bezier");
	myInit();
	auxReshapeFunc(myReshape);
	auxMainLoop(display);
	return 0;
}
