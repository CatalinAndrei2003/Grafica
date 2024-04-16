#include "glos.h"
#include "gl.h"
#include "glu.h"
#include "glaux.h"

GLUnurbsObj* theNurb;

void myInit()
{
	glShadeModel(GL_FLAT);
	theNurb = gluNewNurbsRenderer(); 
	gluNurbsProperty(theNurb, GLU_SAMPLING_TOLERANCE, 10.0);
}

void CALLBACK display()
{	
	glLoadIdentity();

	GLfloat ctlpoints[16][3] = {
		{1.0, 0.5, 0.0},
		{0.5, 0.25, 0.0},
		{0.0, 0.25 , 0.0},
		{-0.5, 0.5, 0.0},
		{-0.85, 1.0, 0.0},
		{-0.85, 1.5, 0.0},
		{-0.5, 2.0, 0.0},
		{0.0, 2.25, 0.0},
		{0.5, 2.25, 0.0},
		{1.0, 2.0, 0.0},
		{1.25, 1.90, 0.0},
		{1.5, 1.35, 0.0},
		{1.0, 1.25, 0.0},
		{1, 0.5, 0.0},
		{1, 0.5, 0.0},
		{1, 0.5, 0.0}

	};

	GLfloat knots[17] = { 0.0, 0.0, 0.0, 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 10.0, 10.0, 10.0 };
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0); 
	gluBeginCurve(theNurb);
	gluNurbsCurve(theNurb,	
		17, knots,			
		sizeof(ctlpoints[0]) / sizeof(GLfloat), 
		&ctlpoints[0][0],	
		4, GL_MAP1_VERTEX_3);	
	gluEndCurve(theNurb);
	glFlush();
}

void CALLBACK myReshape(GLsizei w, GLsizei h)
{
	if (!h) return;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h) {
		gluOrtho2D(-5.0, 5.0, -5.0 * (GLfloat)h / (GLfloat)w, 5.0 * (GLfloat)h / (GLfloat)w);
	}
	else {
		gluOrtho2D(-5.0 * (GLfloat)w / (GLfloat)h, 5.0 * (GLfloat)w / (GLfloat)h, -5.0, 5.0);
	}
	glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char** argv)
{
	auxInitDisplayMode(AUX_SINGLE | AUX_RGB);
	auxInitPosition(0, 0, 500, 500);
	auxInitWindow("Curba B-spline");
	myInit();
	auxReshapeFunc(myReshape);
	auxMainLoop(display);
	return 0;
}
