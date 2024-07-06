#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float xc, yc, radius;

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

void drawCirclePoints(int xc, int yc, int x, int y)
{
    setPixel(xc + x, yc + y);
    setPixel(xc - x, yc + y);
    setPixel(xc + x, yc - y);
    setPixel(xc - x, yc - y);
    setPixel(xc + y, yc + x);
    setPixel(xc - y, yc + x);
    setPixel(xc + y, yc - x);
    setPixel(xc - y, yc - x);
}

void drawCircleMidPoint(float xc, float yc, float radius)
{
    int x = 0;
    int y = round(radius);
    int p = 1 - y;

    drawCirclePoints(xc, yc, x, y);

    while (x < y)
    {
        x++;
        if (p < 0)
        {
            p += 2 * x + 1;
        }
        else
        {
            y--;
            p += 2 * (x - y) + 1;
        }
        drawCirclePoints(xc, yc, x, y);
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
    drawCircleMidPoint(xc, yc, radius);
    glFlush();
}

int main(int argc, char **argv)
{
    printf("Enter the coordinates of the center of the circle (xc, yc): ");
    scanf("%f %f", &xc, &yc);
    printf("Enter the radius of the circle: ");
    scanf("%f", &radius);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Mid-Point Circle Drawing Algorithm with Axes");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
