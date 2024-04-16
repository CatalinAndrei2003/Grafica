
#include "glos.h"
#include "gl.h"
#include "glu.h"
#include "glaux.h"

GLfloat ctrlpoints[4][4][3] = {
    {{-1.5, -1.5, -4.0}, {-0.5, -2.5, -4.0},
    {0.5, -2.5, -4.0}, {1.5, -1.5, -4.0}},
    {{-2.5, -0.5, -4.0}, {-2.0, -0.5, 4.0},
    {2.0, -0.5, 4.0}, {2.5, -0.5, -4.0}},
    {{-2.5, 0.5, -4.0}, {-2.0, 0.5, 4.0},
    {2.0, 0.5, 4.0}, {2.5, 0.5, -4.0}},
    {{-1.5, 1.5, -4.0}, {-0.5, 2.5, -4.0},
    {0.5, 2.5, -4.0}, {1.5, 1.5, -4.0}}
};  

GLfloat ctrlpoints1[4][4][3] = {
    {{-1.5, -1.5, -4.0}, {-0.5, -2.5, -4.0},
    {0.5, -2.5, -4.0}, {1.5, -1.5, -4.0}},
    {{-2.5, -0.5, -4.0}, {-2.0, -0.5, -10.0},
    {2.0, -0.5, -10.0}, {2.5, -0.5, -4.0}},
    {{-2.5, 0.5, -4.0}, {-2.0, 0.5, -10.0},
    {2.0, 0.5, -10.0}, {2.5, 0.5, -4.0}},
    {{-1.5, 1.5, -4.0}, {-0.5, 2.5, -4.0},
    {0.5, 2.5, -4.0}, {1.5, 1.5, -4.0}}
};

void CALLBACK display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    glLoadIdentity();
    glRotatef(-90.0, 1.0, 0.0, 0.0);

    glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4, 0, 1, 12, 4, &ctrlpoints[0][0][0]);
    glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0); 

    glColor3f(1.0, 0.0, 0.0);
    for (int j = 0; j <= 8; j++) {
        glBegin(GL_LINE_STRIP);
        {
            for (int i = 0; i <= 30; i++) {
                glEvalCoord2f((GLfloat)i / 30.0, (GLfloat)j / 8.0); 
            }
        }
        glEnd();
        glBegin(GL_LINE_STRIP);
        {
            for (int i = 0; i <= 30; i++) {
                glEvalCoord2f((GLfloat)j / 8.0, (GLfloat)i / 30.0);
            }
        }
        glEnd();
    }
    glMap2f(GL_MAP2_VERTEX_3, 0, 1, 3, 4, 0, 1, 12, 4, &ctrlpoints1[0][0][0]);
    glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);
    for (int j = 0; j <= 8; j++) {
        glBegin(GL_LINE_STRIP);
        {
            for (int i = 0; i <= 30; i++) {
                glEvalCoord2f((GLfloat)i / 30.0, (GLfloat)j / 8.0);
            }
        }
        glEnd();
        glBegin(GL_LINE_STRIP);
        {
            for (int i = 0; i <= 30; i++) {
                glEvalCoord2f((GLfloat)j / 8.0, (GLfloat)i / 30.0);
            }
        }
        glEnd();
    }
    glFlush();
}

void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 1.0); 
    glEnable(GL_MAP2_VERTEX_3);
}

void CALLBACK myReshape(GLsizei w, GLsizei h)
{
    if (!h) return;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h) {
        glOrtho(-10.0, 10.0, -10.0 * (GLfloat)h / (GLfloat)w, 10.0 * (GLfloat)h / (GLfloat)w, -15.0, 15.0);
    }
    else {
        glOrtho(-10.0 * (GLfloat)w / (GLfloat)h, 10.0 * (GLfloat)w / (GLfloat)h, -10.0, 10.0, -15.0, 15.0);
    }
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    auxInitDisplayMode(AUX_SINGLE | AUX_RGB);
    auxInitPosition(0, 0, 500, 500);
    auxInitWindow("Suprafata Bezier wireframe");
    myInit();
    auxReshapeFunc(myReshape);
    auxMainLoop(display);
    return 0;
}
