#include <GL/glut.h>
#include <windows.h>
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

void window(float x, float y)
{
    rectangle(x, y, x + 0.09f, y + 0.12f,
              0.20f, 0.15f, 0.13f);

    rectangle(x + 0.01f, y + 0.01f,
              x + 0.08f, y + 0.11f,
              0.0f, 0.65f, 0.78f);

    rectangle(x + 0.043f, y + 0.01f,
              x + 0.05f, y + 0.11f,
              0.15f, 0.15f, 0.15f);

    rectangle(x + 0.01f, y + 0.057f,
              x + 0.08f, y + 0.063f,
              0.15f, 0.15f, 0.15f);
}

void display()
{
    glClearColor(0.53f, 0.81f, 0.88f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // Green ground
    rectangle(0.0f, 0.0f, 1.0f, 0.12f,
              0.55f, 0.68f, 0.20f);

    // Main building
    rectangle(0.29f, 0.12f, 0.71f, 0.82f,
              0.96f, 0.86f, 0.70f);

    // Roof
    rectangle(0.27f, 0.82f, 0.73f, 0.85f,
              0.72f, 0.49f, 0.36f);

    rectangle(0.27f, 0.85f, 0.73f, 0.87f,
              0.88f, 0.70f, 0.57f);

    // Floor separator
    rectangle(0.27f, 0.43f, 0.73f, 0.46f,
              0.88f, 0.70f, 0.57f);

    // Top row windows
    window(0.33f, 0.69f);
    window(0.455f, 0.69f);
    window(0.58f, 0.69f);

    // Middle row windows
    window(0.33f, 0.50f);
    window(0.455f, 0.50f);
    window(0.58f, 0.50f);

    // Bottom side windows
    window(0.32f, 0.25f);
    window(0.59f, 0.25f);

    // Entrance frame
    rectangle(0.40f, 0.12f, 0.60f, 0.43f,
              0.20f, 0.15f, 0.13f);

    // Blue glass entrance
    rectangle(0.41f, 0.12f, 0.59f, 0.42f,
              0.0f, 0.62f, 0.76f);

    // Door vertical divider
    rectangle(0.498f, 0.12f, 0.502f, 0.42f,
              0.20f, 0.15f, 0.13f);

    // Door horizontal divider
    rectangle(0.41f, 0.38f, 0.59f, 0.39f,
              0.20f, 0.15f, 0.13f);

    // Door handles
    glPointSize(4.0f);
    glColor3f(0.95f, 0.80f, 0.30f);
    glBegin(GL_POINTS);
    glVertex2f(0.49f, 0.26f);
    glVertex2f(0.51f, 0.26f);
    glEnd();

    glFlush();
}

void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1.0, 0.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Building Drawing");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
