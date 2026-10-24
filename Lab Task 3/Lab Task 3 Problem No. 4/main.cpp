#include <GL/glut.h>
#include <cmath>

const float PI = 3.14159f;

// Draw a filled polygon
void Polygon(float p[][2], int n,
             float r, float g, float b)
{
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);

    for (int i = 0; i < n; i++)
        glVertex2f(p[i][0], p[i][1]);

    glEnd();
}

// Draw a filled circle
void Circle(float cx, float cy, float radius,
            float r, float g, float b)
{
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(cx, cy);

    for (int i = 0; i <= 60; i++) {
        float a = 2.0f * PI * i / 60;
        glVertex2f(cx + radius * cosf(a),
                   cy + radius * sinf(a));
    }

    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Main car body
    float body[][2] = {
        {0.08f,0.40f}, {0.08f,0.48f},
        {0.15f,0.50f}, {0.43f,0.62f},
        {0.53f,0.60f}, {0.89f,0.53f},
        {0.87f,0.41f}, {0.82f,0.36f},
        {0.18f,0.36f}, {0.08f,0.39f}
    };
    Polygon(body, 10, 0.58f,0.59f,0.60f);

    // Lower body and side skirt
    float lower[][2] = {
        {0.08f,0.40f}, {0.18f,0.38f},
        {0.82f,0.38f}, {0.87f,0.41f},
        {0.82f,0.35f}, {0.19f,0.35f},
        {0.12f,0.37f}
    };
    Polygon(lower, 7, 0.30f,0.31f,0.32f);

    // Front bumper (left)
    float front[][2] = {
        {0.08f,0.40f}, {0.13f,0.40f},
        {0.13f,0.46f}, {0.08f,0.46f}
    };
    Polygon(front, 4, 0.36f,0.37f,0.38f);

    // Rear bumper (right)
    float rear[][2] = {
        {0.86f,0.43f}, {0.90f,0.43f},
        {0.90f,0.51f}, {0.88f,0.51f}
    };
    Polygon(rear, 4, 0.78f,0.02f,0.03f);

    // Roof and windshield area
    float roof[][2] = {
        {0.18f,0.50f}, {0.43f,0.62f},
        {0.53f,0.60f}, {0.57f,0.54f},
        {0.28f,0.52f}
    };
    Polygon(roof, 5, 0.72f,0.73f,0.74f);

    // Front side window
    float window1[][2] = {
        {0.20f,0.515f}, {0.43f,0.595f},
        {0.46f,0.585f}, {0.44f,0.535f}
    };
    Polygon(window1, 4, 0.06f,0.07f,0.08f);

    // Rear side window
    float window2[][2] = {
        {0.45f,0.585f}, {0.52f,0.575f},
        {0.53f,0.535f}, {0.45f,0.535f}
    };
    Polygon(window2, 4, 0.04f,0.05f,0.06f);

    // Window divider
    float divider[][2] = {
        {0.435f,0.535f}, {0.447f,0.535f},
        {0.465f,0.585f}, {0.455f,0.585f}
    };
    Polygon(divider, 4, 0.22f,0.23f,0.24f);

    // Small reflections on glass
    Circle(0.43f,0.565f,0.012f,
           0.48f,0.49f,0.50f);
    Circle(0.52f,0.575f,0.009f,
           0.40f,0.41f,0.42f);

    // Wheels: outer tires
    Circle(0.235f,0.365f,0.070f,
           0.06f,0.06f,0.07f);
    Circle(0.735f,0.365f,0.070f,
           0.06f,0.06f,0.07f);

    // Wheel hubs
    Circle(0.235f,0.365f,0.043f,
           0.12f,0.14f,0.17f);
    Circle(0.735f,0.365f,0.043f,
           0.12f,0.14f,0.17f);

    glFlush();
}

void init()
{
    glClearColor(0.92f,0.92f,0.92f,1.0f);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,1.0,0.0,1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(700,400);
    glutCreateWindow("Simple Sports Car");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
