#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h

/* Initialize OpenGL Graphics */
void initGL() {
	// Set "clearing" or background color
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
void display() {
	glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color


glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow

    glVertex2f(-0.7f, 0.3f); // Bottom-left
    glVertex2f(-0.3f, 0.3f); // Bottom-right
    glVertex2f(-0.3f, 0.7f); // Top-right
    glVertex2f(-0.7f, 0.7f); // Top-left
glEnd();
glFlush();

		// Draw a Red 1x1 Square centered at origin
	glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow

    glVertex2f(0.2f, -0.7f); // Bottom-left
    glVertex2f(0.8f, -0.7f); // Bottom-right
    glVertex2f(0.5f, -0.2f); // Top peak
glEnd();
glFlush();
   // 1. Arrow Shaft (Stem)
// 1. Arrow Stem (Horizontal Rectangle)
glBegin(GL_QUADS);
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow
    glVertex2f(0.2f, 0.45f);     // Bottom-left
    glVertex2f(0.6f, 0.45f);     // Bottom-right
    glVertex2f(0.6f, 0.55f);     // Top-right
    glVertex2f(0.2f, 0.55f);     // Top-left
glEnd();

// 2. Arrow Head (Triangle pointing right)
glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow
    glVertex2f(0.6f, 0.35f);     // Bottom corner
    glVertex2f(0.85f, 0.50f);    // Tip (pointing right)
    glVertex2f(0.6f, 0.65f);     // Top corner
glEnd();

glFlush();

 glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow

    glVertex2f(-0.8f, -0.5f); // Tip (pointing left)
    glVertex2f(-0.3f, -0.2f); // Top-right corner
    glVertex2f(-0.3f, -0.8f); // Bottom-right corner
glEnd();
glFlush();
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);          // Initialize GLUT
	glutCreateWindow("Vertex, Primitive & Color");  // Create window with the given title
	glutInitWindowSize(320, 320);   // Set the window's initial width & height
	glutDisplayFunc(display);       // Register callback handler for window re-paint event
	initGL();                       // Our own OpenGL initialization
	glutMainLoop();                 // Enter the event-processing loop
	return 0;
}
