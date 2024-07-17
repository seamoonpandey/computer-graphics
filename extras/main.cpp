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

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Building background

    glBegin(GL_POLYGON);
    glColor3f(0.9647, 0.8431, 0.4863); // that yellow color
    glVertex2f(-0.9, -0.5);
    glVertex2f(-0.9, 0.5);
    glVertex2f(0.9, 0.5);
    glVertex2f(0.9, -0.5);
    glEnd();

    // Left side of the building

    // first pillar
    glBegin(GL_POLYGON);
    glColor3f(0.8235, 0.3843, 0.1804);
    glVertex2f(-0.9, -0.5);
    glVertex2f(-0.9, 0.5);
    glVertex2f(-0.7, 0.5);
    glVertex2f(-0.7, -0.5);
    glEnd();

    // Right side of the building

    // second pillar
    glBegin(GL_POLYGON);
    glColor3f(0.8235, 0.3843, 0.1804);
    glVertex2f(0.7, -0.5);
    glVertex2f(0.7, 0.5);
    glVertex2f(0.9, 0.5);
    glVertex2f(0.9, -0.5);
    glEnd();

    glFlush();
}
