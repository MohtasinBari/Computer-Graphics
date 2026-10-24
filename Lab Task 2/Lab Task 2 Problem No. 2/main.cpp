#include <windows.h>
#include <GL/glut.h>
#include <math.h>

void rectangle(float x1, float y1, float x2, float y2,
               float r, float g, float b)
{
    glColor3f(r, g, b);

    glBegin(GL_QUADS);
        glVertex2f(x1, y1);
        glVertex2f(x2, y1);
        glVertex2f(x2, y2);
        glVertex2f(x1, y2);
    glEnd();
}

void circle(float radius, float xc, float yc,
            float r, float g, float b)
{
    glBegin(GL_POLYGON);

    for(int i = 0; i < 200; i++)
    {
        glColor3f(r, g, b);

        float pi = 3.1416;
        float A = (i * 2 * pi) / 200;

        float x = radius * cos(A);
        float y = radius * sin(A);

        glVertex2f(x + xc, y + yc);
    }

    glEnd();
}

void display()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    // Bangladesh
    rectangle(10, 4, 16, 8, 0.0, 0.42, 0.22);
    circle(1.2, 13, 6, 1.0, 0.0, 0.0);

    // Germany
    rectangle(18, 4, 24, 5.33, 0.0, 0.0, 0.0);
    rectangle(18, 5.33, 24, 6.67, 0.85, 0.0, 0.0);
    rectangle(18, 6.67, 24, 8, 1.0, 0.8, 0.0);

    // Japan
    rectangle(26, 4, 32, 8, 1.0, 1.0, 1.0);
    circle(1.2, 29, 6, 0.8, 0.0, 0.0);

    // Italy
    rectangle(10, 10, 12, 14, 0.0, 0.5, 0.2);
    rectangle(12, 10, 14, 14, 1.0, 1.0, 1.0);
    rectangle(14, 10, 16, 14, 0.8, 0.0, 0.0);

    // France
    rectangle(18, 10, 20, 14, 0.0, 0.0, 0.65);
    rectangle(20, 10, 22, 14, 1.0, 1.0, 1.0);
    rectangle(22, 10, 24, 14, 0.8, 0.0, 0.0);

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(900, 600);
    glutCreateWindow("Five Country Flags");

    gluOrtho2D(0, 34, 0, 18);

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
