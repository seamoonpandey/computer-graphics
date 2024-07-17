#include <GL/glut.h>
#include <math.h>

void display();
void init();

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 800);
    glutInitWindowPosition(100, 0);
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

void drawWindow(float x1, float y1, float x2, float y2)
{
    drawRectangle(x1, y1, x2, y2, 0.8627, 0.9686, 1.0);
    // Draw divider line
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2f((x1 + x2) / 2, y1);
    glVertex2f((x2 + x1) / 2, y2);
    glEnd();
}

void drawCircle(float x, float y, float radius, float r, float g, float b)
{
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float theta = i * 3.142 / 180;
        glVertex2f(x + radius * cos(theta), y + radius * sin(theta));
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    drawCircle(0, 0.4, 0.54, 0.8627, 0.9686, 1.0);
    drawCircle(0, 0.4, 0.53, 0.8235, 0.3843, 0.1804);

    // Building background
    drawRectangle(-0.9, -0.5, 0.9, 0.5, 0.9647, 0.8431, 0.4863);

    // Roof
    // ralling
    drawRectangle(-0.93, 0.5, -0.4, 0.7, 0.7961, 0.2706, 0.1725); // left side
    drawRectangle(0.4, 0.5, 0.93, 0.7, 0.7961, 0.2706, 0.1725);   // right side
    // blue strap
    drawRectangle(-0.93, 0.5, -0.4, 0.51, 0.8627, 0.9686, 1.0); // left side
    drawRectangle(0.4, 0.5, 0.93, 0.51, 0.8627, 0.9686, 1.0);   // right side

    // blue strap at the center
    drawRectangle(-0.4, 0.55, 0.4, 0.56, 0.8627, 0.9686, 1.0);
    // blue strap over the ralling
    drawRectangle(-0.93, 0.7, -0.4, 0.71, 0.8627, 0.9686, 1.0); // left side
    drawRectangle(0.4, 0.7, 0.93, 0.71, 0.8627, 0.9686, 1.0);   // right side

    // Left side of the building (30%)
    drawRectangle(-0.9, -0.5, -0.85, 0.5, 0.8235, 0.3843, 0.1804); // First pillar
    drawWindow(-0.84, 0.3, -0.76, 0.4);
    drawWindow(-0.84, 0.1, -0.76, 0.2);
    drawWindow(-0.84, -0.1, -0.76, 0);
    drawRectangle(-0.75, -0.5, -0.70, 0.5, 0.8235, 0.3843, 0.1804); // Second pillar
    drawWindow(-0.69, 0.3, -0.61, 0.4);
    drawWindow(-0.69, 0.1, -0.61, 0.2);
    drawWindow(-0.69, -0.1, -0.61, 0);
    drawRectangle(-0.6, -0.5, -0.55, 0.5, 0.8235, 0.3843, 0.1804); // Third pillar
    drawWindow(-0.54, 0.3, -0.46, 0.4);
    drawWindow(-0.54, 0.1, -0.46, 0.2);
    drawWindow(-0.54, -0.1, -0.46, 0);

    drawRectangle(-0.45, -0.5, -0.4, 0.5, 0.8235, 0.3843, 0.1804); // Fourth pillar

    // Right side of the building (30%)
    drawRectangle(0.4, -0.5, 0.45, 0.5, 0.8235, 0.3843, 0.1804); // Fourth pillar
    drawWindow(0.46, 0.3, 0.54, 0.4);
    drawWindow(0.46, 0.1, 0.54, 0.2);
    drawWindow(0.46, -0.1, 0.54, 0);

    drawRectangle(0.85, -0.5, 0.9, 0.5, 0.8235, 0.3843, 0.1804); // Third pillar
    drawWindow(0.76, 0.3, 0.84, 0.4);
    drawWindow(0.76, 0.1, 0.84, 0.2);
    drawWindow(0.76, -0.1, 0.84, 0);
    drawRectangle(0.7, -0.5, 0.75, 0.5, 0.8235, 0.3843, 0.1804); // Second pillar
    drawWindow(0.61, 0.3, 0.69, 0.4);
    drawWindow(0.61, 0.1, 0.69, 0.2);
    drawWindow(0.61, -0.1, 0.69, 0);
    drawRectangle(0.55, -0.5, 0.6, 0.5, 0.8235, 0.3843, 0.1804); // First pillar

    // Middle part of the building (40%)
    drawRectangle(-0.4, -0.5, 0.4, 0.5, 0.8235, 0.3843, 0.1804);
    drawWindow(-0.35, -0.1, -0.25, 0.55);
    drawWindow(-0.15, -0.1, -0.05, 0.55);
    drawWindow(0.05, -0.1, 0.15, 0.55);
    drawWindow(0.25, -0.1, 0.35, 0.55);

    // the entrance with big door with our primary building color
    drawRectangle(-0.4, -0.5, 0.4, -0.2, 0.9647, 0.8431, 0.4863);
    // red strip over the entrance
    drawRectangle(-0.5, -0.2, 0.5, -0.15, 0.7961, 0.2706, 0.1725);
    // blue strip over the entrance right below the red strap
    drawRectangle(-0.5, -0.2, 0.5, -0.22, 0.8627, 0.9686, 1.0);

    // door at the entrance
    drawRectangle(-0.3, -0.5, -.01, -0.25, 0.110, 0.070, 0.067);
    drawRectangle(0.01, -0.5, 0.3, -0.25, 0.110, 0.070, 0.067);

    // circle at the circumference of the building
    // left side
    drawCircle(-.2, .67, 0.05, 0.8627, 0.9686, 1.0);
    drawCircle(-.2, .67, 0.04, 1, 1, 1);
    // center
    drawCircle(0, .7, 0.06, 0.8627, 0.9686, 1.0);
    drawCircle(0, .7, 0.05, 1, 1, 1);
    // right side
    drawCircle(0.2, .67, 0.05, 0.8627, 0.9686, 1.0);
    drawCircle(0.2, .67, 0.04, 1, 1, 1);

    glFlush();
}
