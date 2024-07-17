#include <GL/glut.h>

void display();
void init();

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("RIC building");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

void drawRectangle(float x1, float y1, float x2, float y2, float r, float g, float b)
{
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(x1, y1);
    glVertex2f(x1, y2);
    glVertex2f(x2, y2);
    glVertex2f(x2, y1);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Building background
    drawRectangle(-0.9, -0.5, 0.9, 0.5, 0.9647, 0.8431, 0.4863);

    // Left side of the building
    drawRectangle(-0.9, -0.5, -0.85, 0.5, 0.8235, 0.3843, 0.1804);  // First pillar
    drawRectangle(-0.75, -0.5, -0.70, 0.5, 0.8235, 0.3843, 0.1804); // Second pillar
    drawRectangle(-0.6, -0.5, -0.55, 0.5, 0.8235, 0.3843, 0.1804);  // Third pillar

    // Right side of the building
    drawRectangle(0.55, -0.5, 0.6, 0.5, 0.8235, 0.3843, 0.1804); // First pillar
    drawRectangle(0.7, -0.5, 0.75, 0.5, 0.8235, 0.3843, 0.1804); // Second pillar
    drawRectangle(0.85, -0.5, 0.9, 0.5, 0.8235, 0.3843, 0.1804); // Third pillar

    glFlush();
}
