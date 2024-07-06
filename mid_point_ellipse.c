#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float xc, yc, rx, ry;

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-320.0, 320.0, -240.0, 240.0);
}

void setPixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void drawEllipsePoints(int xc, int yc, int x, int y)
{
    setPixel(xc + x, yc + y);
    setPixel(xc - x, yc + y);
    setPixel(xc + x, yc - y);
    setPixel(xc - x, yc - y);
}

void drawEllipseMidPoint(float xc, float yc, float rx, float ry)
{
    float dx, dy, d1, d2;
    int x, y;

    x = 0;
    y = ry;

    d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;

    while (dx < dy)
    {
        drawEllipsePoints(xc, yc, x, y);
        x++;

        dx = dx + (2 * ry * ry);
        if (d1 < 0)
        {
            d1 = d1 + dx + (ry * ry);
        }
        else
        {
            y--;
            dy = dy - (2 * rx * rx);
            d1 = d1 + dx - dy + (ry * ry);
        }
    }

    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + ((rx * rx) * ((y - 1) * (y - 1))) - (rx * rx * ry * ry);
    while (y >= 0)
    {
        drawEllipsePoints(xc, yc, x, y);
        y--;

        dy = dy - (2 * rx * rx);
        if (d2 > 0)
        {
            d2 = d2 + (rx * rx) - dy;
        }
        else
        {
            x++;
            dx = dx + (2 * ry * ry);
            d2 = d2 + dx - dy + (rx * rx);
        }
    }
}

void drawAxes(void)
{
    glColor3f(1.0, 1.0, 1.0);
    drawLineBresenham(-320, 0, 320, 0);
    drawLineBresenham(0, -240, 0, 240);
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

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawAxes();
    glColor3f(0.0, 1.0, 1.0);
    drawEllipseMidPoint(xc, yc, rx, ry);
    glFlush();
}

int main(int argc, char **argv)
{
    printf("Enter the coordinates of the center of the ellipse (xc, yc): ");
    scanf("%f %f", &xc, &yc);
    printf("Enter the semi-major axis length (rx): ");
    scanf("%f", &rx);
    printf("Enter the semi-minor axis length (ry): ");
    scanf("%f", &ry);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Mid-Point Ellipse Drawing Algorithm with Axes");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
