#include <GL/glut.h>
#include <math.h>

double parr[8];

void init()
{
    glClearColor(0, 0, 0, 1);
    gluOrtho2D(-500, 500, -500, 500);

    parr[0] = 10;
    parr[1] = 10;

    parr[2] = 200;
    parr[3] = 10;

    parr[4] = 200;
    parr[5] = 200;

    parr[6] = 10;
    parr[7] = 200;
}

void setPixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void drawAxes(void)
{
    glColor3f(1.0, 1.0, 1.0);
    drawLineBresenham(-500, 0, 500, 0);
    drawLineBresenham(0, -500, 0, 500);
}

void drawLineBresenham(int x0, int y0, int x1, int y1)
{
    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = -abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = dx + dy, e2;

    while (1)
    {
        setPixel(x0, y0);
        if (x0 == x1 && y0 == y1)
            break;
        e2 = 2 * err;
        if (e2 >= dy)
        {
            err += dy;
            x0 += sx;
        }
        if (e2 <= dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

void polygon(int transformed)
{
    if (transformed)
        glColor3f(1, 0, 0);
    else
        glColor3f(0, 1, 0);

    glBegin(GL_LINE_LOOP);
    glVertex2f(parr[0], parr[1]);
    glVertex2f(parr[2], parr[3]);
    glVertex2f(parr[4], parr[5]);
    glVertex2f(parr[6], parr[7]);
    glEnd();

    glFlush();
}

void scaling2d()
{
    polygon(0);

    double sx = 0.5, sy = 0.5;

    for (int i = 0; i < 8; i += 2)
    {
        parr[i] *= sx;
    }

    for (int i = 1; i < 8; i += 2)
    {
        parr[i] *= sy;
    }

    polygon(1);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawAxes();
    scaling2d();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("2D Scaling with Axes");
    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
