
#include <GL/glut.h>
#include <math.h>

const float PI = 3.14159265f;

// Draw rectangle
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

// Draw ellipse
void ellipse(float cx, float cy, float rx, float ry,
             float r, float g, float b)
{
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);

    for (int i = 0; i <= 80; i++) {
        float a = 2.0f * PI * i / 80.0f;
        glVertex2f(cx + rx * cosf(a),
                   cy + ry * sinf(a));
    }

    glEnd();
}

// Draw window
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

// BUILDING
void drawBuilding()
{
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

    // Upper windows
    window(0.33f, 0.69f);
    window(0.455f, 0.69f);
    window(0.58f, 0.69f);

    // Middle windows
    window(0.33f, 0.50f);
    window(0.455f, 0.50f);
    window(0.58f, 0.50f);

    // Lower windows
    window(0.32f, 0.25f);
    window(0.59f, 0.25f);

    // Entrance frame and glass
    rectangle(0.40f, 0.12f, 0.60f, 0.43f,
              0.20f, 0.15f, 0.13f);

    rectangle(0.41f, 0.12f, 0.59f, 0.42f,
              0.0f, 0.62f, 0.76f);

    // Door dividers
    rectangle(0.498f, 0.12f, 0.502f, 0.42f,
              0.20f, 0.15f, 0.13f);

    rectangle(0.41f, 0.38f, 0.59f, 0.39f,
              0.20f, 0.15f, 0.13f);

    // Door handles
    glPointSize(4.0f);
    glColor3f(0.95f, 0.80f, 0.30f);
    glBegin(GL_POINTS);
    glVertex2f(0.49f, 0.26f);
    glVertex2f(0.51f, 0.26f);
    glEnd();
}

// TREE
void drawTree()
{
    // Ground shadow
    ellipse(0.50f, 0.09f, 0.16f, 0.03f,
            0.42f, 0.55f, 0.25f);

    // Trunk
    glColor3f(0.35f, 0.20f, 0.10f);
    glBegin(GL_POLYGON);
    glVertex2f(0.44f, 0.09f);
    glVertex2f(0.56f, 0.09f);
    glVertex2f(0.52f, 0.16f);
    glVertex2f(0.52f, 0.36f);
    glVertex2f(0.48f, 0.36f);
    glVertex2f(0.48f, 0.16f);
    glEnd();

    // Canopy
    ellipse(0.50f, 0.58f, 0.38f, 0.26f,
            0.20f, 0.58f, 0.12f);
}

// LAMP POST
void drawLamp()
{
    // Base
    ellipse(0.46f, 0.055f, 0.105f, 0.018f,
            0.18f, 0.19f, 0.21f);

    rectangle(0.40f, 0.055f, 0.52f, 0.075f,
              0.28f, 0.29f, 0.31f);

    // Pole
    rectangle(0.435f, 0.075f, 0.478f, 0.745f,
              0.22f, 0.23f, 0.25f);

    rectangle(0.445f, 0.09f, 0.453f, 0.735f,
              0.42f, 0.43f, 0.44f);

    // Roof
    glColor3f(0.20f, 0.22f, 0.25f);
    glBegin(GL_POLYGON);
    glVertex2f(0.32f, 0.865f);
    glVertex2f(0.38f, 0.895f);
    glVertex2f(0.46f, 0.940f);
    glVertex2f(0.54f, 0.895f);
    glVertex2f(0.60f, 0.865f);
    glEnd();

    // Finial
    glColor3f(0.25f, 0.27f, 0.30f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.445f, 0.925f);
    glVertex2f(0.460f, 0.970f);
    glVertex2f(0.475f, 0.925f);
    glEnd();

    // Lantern outer body
    rectangle(0.35f, 0.72f, 0.57f, 0.835f,
              0.16f, 0.17f, 0.19f);

    // Glowing glass
    rectangle(0.38f, 0.73f, 0.435f, 0.815f,
              1.0f, 0.91f, 0.55f);

    rectangle(0.445f, 0.73f, 0.54f, 0.815f,
              1.0f, 0.91f, 0.55f);

    // Lantern frame
    rectangle(0.432f, 0.71f, 0.447f, 0.825f,
              0.12f, 0.13f, 0.15f);

    rectangle(0.34f, 0.835f, 0.58f, 0.855f,
              0.12f, 0.13f, 0.15f);

    rectangle(0.385f, 0.69f, 0.545f, 0.71f,
              0.12f, 0.13f, 0.15f);
}

// Draw an object at a new position and size
void placeObject(void (*draw)(), float x, float y,
                 float sx, float sy)
{
    glPushMatrix();
    glTranslatef(x, y, 0.0f);
    glScalef(sx, sy, 1.0f);
    draw();
    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Ground
    rectangle(0.0f, 0.0f, 1.0f, 0.12f,
              0.40f, 0.62f, 0.20f);
    // Building in the center
    drawBuilding();

    // Trees on both sides
    placeObject(drawTree, -0.02f, 0.07f, 0.34f, 0.60f);

    // Street lamps on both sides
    placeObject(drawLamp, -0.11f, 0.07f, 0.65f, 0.70f);

    glFlush();
}

void init()
{
    glClearColor(0.53f, 0.81f, 0.88f, 1.0f);

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
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Building, Trees and Street Lamps");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
