#include <windows.h>
#include <GL/glut.h>
#include <math.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);

    glBegin(GL_LINE_STRIP);
    glVertex2f(0.02,0.55);
    glVertex2f(0.14,0.67);
    glVertex2f(0.23,0.84);
    glVertex2f(0.30,0.72);
    glVertex2f(0.42,0.86);
    glVertex2f(0.55,0.66);
    glVertex2f(0.61,0.63);
    glVertex2f(0.72,0.70);
    glVertex2f(0.96,0.48);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(0.02,0.55);
    glVertex2f(0.12,0.60);
    glVertex2f(0.23,0.84);
    glVertex2f(0.18,0.66);
    glVertex2f(0.30,0.72);
    glVertex2f(0.39,0.69);
    glVertex2f(0.42,0.64);
    glVertex2f(0.48,0.76);
    glVertex2f(0.42,0.86);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(0.72,0.70);
    glVertex2f(0.79,0.62);
    glVertex2f(0.83,0.62);
    glVertex2f(0.96,0.48);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(0.05,0.52);
    glVertex2f(0.20,0.49);
    glVertex2f(0.32,0.48);
    glVertex2f(0.42,0.50);
    glVertex2f(0.52,0.48);
    glVertex2f(0.63,0.50);
    glVertex2f(0.75,0.47);
    glVertex2f(0.88,0.49);
    glVertex2f(0.96,0.48);
    glEnd();

    glBegin(GL_LINE_LOOP);
    for(int i=0;i<100;i++)
    {
        float a=2*3.14159*i/100;
        glVertex2f(0.59+0.065*cos(a),0.91+0.065*sin(a));
    }
    glEnd();

    for(int i=0;i<9;i++)
    {
        float x=0.10+i*0.035;
        glBegin(GL_TRIANGLES);
        glVertex2f(x,0.48);
        glVertex2f(x-0.012,0.52);
        glVertex2f(x+0.012,0.52);

        glVertex2f(x,0.50);
        glVertex2f(x-0.009,0.54);
        glVertex2f(x+0.009,0.54);
        glEnd();
    }

    for(int i=0;i<5;i++)
    {
        float x=0.68+i*0.035;
        glBegin(GL_TRIANGLES);
        glVertex2f(x,0.47);
        glVertex2f(x-0.012,0.51);
        glVertex2f(x+0.012,0.51);
        glEnd();
    }

    glBegin(GL_TRIANGLES);
    glVertex2f(0.52,0.46);
    glVertex2f(0.48,0.52);
    glVertex2f(0.56,0.52);

    glVertex2f(0.52,0.49);
    glVertex2f(0.49,0.56);
    glVertex2f(0.55,0.56);

    glVertex2f(0.52,0.52);
    glVertex2f(0.50,0.60);
    glVertex2f(0.54,0.60);
    glEnd();

    glFlush();
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(800,500);
    glutCreateWindow("Mountain Landscape");

    glClearColor(1,1,1,1);
    gluOrtho2D(0,1,0,1);

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
