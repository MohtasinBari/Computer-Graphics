#include <GL/glut.h>
#include <cmath>

// Draw a filled ellipse given center (cx, cy) and radii (rx, ry)
void drawEllipse(float cx, float cy, float rx, float ry, int segments = 80) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= segments; ++i) {
        float theta = 2.0f * M_PI * (float)i / (float)segments;
        glVertex2f(cx + rx * cosf(theta), cy + ry * sinf(theta));
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.80f, 0.90f, 0.96f);
    drawEllipse(0.50f, 0.09f, 0.16f, 0.03f);

    glColor3f(0.30f, 0.32f, 0.34f);
    glBegin(GL_POLYGON);
        glVertex2f(0.44f, 0.09f);
        glVertex2f(0.56f, 0.09f);
        glVertex2f(0.52f, 0.16f);
        glVertex2f(0.52f, 0.36f);
        glVertex2f(0.48f, 0.36f);
        glVertex2f(0.48f, 0.16f);
    glEnd();

    glColor3f(0.72f, 0.88f, 0.22f);
    drawEllipse(0.50f, 0.58f, 0.38f, 0.26f);

    glFlush();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1.0, 0.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Tree Drawing");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
