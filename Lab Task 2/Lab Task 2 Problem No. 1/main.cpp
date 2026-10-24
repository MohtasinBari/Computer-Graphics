#include <windows.h>
#include <GL/glut.h>

void initGL() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 9.0, 0.0, 8.0);
    glMatrixMode(GL_MODELVIEW);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);

        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(1.0f, 0.0f);
        glVertex2f(8.0f, 0.0f);
        glVertex2f(8.0f, 1.0f);
        glVertex2f(1.0f, 1.0f);

        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(1.0f, 1.0f);
        glVertex2f(8.0f, 1.0f);
        glVertex2f(8.0f, 2.0f);
        glVertex2f(1.0f, 2.0f);

        glColor3ub(232, 133, 20);
        glVertex2f(1.0f, 2.0f);
        glVertex2f(8.0f, 2.0f);
        glVertex2f(8.0f, 3.0f);
        glVertex2f(1.0f, 3.0f);

        glColor3f(0.0f, 0.8f, 0.0f);
        glVertex2f(1.0f, 3.0f);
        glVertex2f(8.0f, 3.0f);
        glVertex2f(8.0f, 4.0f);
        glVertex2f(1.0f, 4.0f);

        glColor3f(0.2f, 0.6f, 0.9f);
        glVertex2f(1.0f, 4.0f);
        glVertex2f(8.0f, 4.0f);
        glVertex2f(8.0f, 5.0f);
        glVertex2f(1.0f, 5.0f);

        glColor3f(0.2f, 0.4f, 0.7f);
        glVertex2f(1.0f, 5.0f);
        glVertex2f(8.0f, 5.0f);
        glVertex2f(8.0f, 6.0f);
        glVertex2f(1.0f, 6.0f);

        glColor3f(0.5f, 0.3f, 0.6f);
        glVertex2f(1.0f, 6.0f);
        glVertex2f(8.0f, 6.0f);
        glVertex2f(8.0f, 7.0f);
        glVertex2f(1.0f, 7.0f);

    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Rainbow Flag");
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(50, 50);
    glutDisplayFunc(display);
    initGL();
    glutMainLoop();
    return 0;
}
