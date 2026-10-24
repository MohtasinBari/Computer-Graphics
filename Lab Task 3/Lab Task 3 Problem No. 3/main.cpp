#include <GL/glut.h>
#include <cmath>

const float PI = 3.14159265f;

void polygon(float pts[][2], int n,
             float r, float g, float b)
{
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < n; i++)
        glVertex2f(pts[i][0], pts[i][1]);
    glEnd();
}

void quad(float x1, float y1, float x2, float y2,
          float x3, float y3, float x4, float y4,
          float r, float g, float b)
{
    float p[4][2] = {
        {x1,y1}, {x2,y2}, {x3,y3}, {x4,y4}
    };
    polygon(p, 4, r, g, b);
}

void ellipse(float cx, float cy, float rx, float ry,
             float r, float g, float b)
{
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 40; i++) {
        float a = 2.0f * PI * i / 40.0f;
        glVertex2f(cx + rx*cos(a),
                   cy + ry*sin(a));
    }
    glEnd();
}

void drawLamp()
{
    // Base
    ellipse(0.46f, 0.055f, 0.105f, 0.018f,
            0.18f, 0.19f, 0.21f);
    quad(0.39f, 0.055f, 0.53f, 0.055f,
         0.52f, 0.075f, 0.40f, 0.075f,
         0.28f, 0.29f, 0.31f);
    ellipse(0.46f, 0.075f, 0.060f, 0.010f,
            0.32f, 0.33f, 0.35f);

    // Vertical pole
    quad(0.435f, 0.075f, 0.480f, 0.075f,
         0.478f, 0.745f, 0.442f, 0.745f,
         0.22f, 0.23f, 0.25f);

    // Pole highlight
    quad(0.445f, 0.09f, 0.453f, 0.09f,
         0.455f, 0.735f, 0.450f, 0.735f,
         0.42f, 0.43f, 0.44f);

    // Lamp housing top cap
    float roof[5][2] = {
        {0.32f,0.865f}, {0.38f,0.895f},
        {0.46f,0.940f}, {0.54f,0.895f},
        {0.60f,0.865f}
    };
    polygon(roof, 5, 0.20f, 0.22f, 0.25f);

    // Small finial
    float finial[3][2] = {
        {0.445f,0.925f}, {0.460f,0.970f},
        {0.475f,0.925f}
    };
    polygon(finial, 3, 0.25f, 0.27f, 0.30f);

    // Upper rim
    quad(0.31f,0.855f, 0.61f,0.855f,
         0.58f,0.835f, 0.34f,0.835f,
         0.12f,0.13f,0.15f);

    // Outer lantern body
    float body[4][2] = {
        {0.35f,0.835f}, {0.57f,0.835f},
        {0.535f,0.700f}, {0.395f,0.700f}
    };
    polygon(body, 4, 0.16f, 0.17f, 0.19f);

    // Left glass panel
    float leftGlass[4][2] = {
        {0.375f,0.815f}, {0.435f,0.815f},
        {0.435f,0.720f}, {0.400f,0.720f}
    };
    polygon(leftGlass, 4, 1.0f, 0.91f, 0.55f);

    // Right glass panel
    float rightGlass[4][2] = {
        {0.445f,0.815f}, {0.545f,0.815f},
        {0.510f,0.720f}, {0.445f,0.720f}
    };
    polygon(rightGlass, 4, 1.0f, 0.91f, 0.55f);

    // Central frame
    quad(0.432f,0.825f, 0.447f,0.825f,
         0.447f,0.710f, 0.432f,0.710f,
         0.12f,0.13f,0.15f);

    // Lower lantern rim
    quad(0.385f,0.710f, 0.545f,0.710f,
         0.530f,0.690f, 0.400f,0.690f,
         0.12f,0.13f,0.15f);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    drawLamp();

    glFlush();
}

void init()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1.0, 0.0, 1.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Street Lamp");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
