#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float x_start, y_start, x_end, y_end;

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

void drawLineBresenham(float x_start, float y_start, float x_end, float y_end)
{
    int x0 = round(x_start);
    int y0 = round(y_start);
    int x1 = round(x_end);
    int y1 = round(y_end);
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

void drawAxes(void)
{
    glColor3f(1.0, 1.0, 1.0);
    drawLineBresenham(-320, 0, 320, 0);
    drawLineBresenham(0, -240, 0, 240);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawAxes();
    glColor3f(0.0, 1.0, 1.0);
    drawLineBresenham(x_start, y_start, x_end, y_end);
    glFlush();
}

int main(int argc, char **argv)
{
    printf("Enter the coordinates of the first point (x_start, y_start): ");
    scanf("%f %f", &x_start, &y_start);
    printf("Enter the coordinates of the second point (x_end, y_end): ");
    scanf("%f %f", &x_end, &y_end);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham's Line Drawing Algorithm with Axes");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
