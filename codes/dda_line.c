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

void drawLineDDA(float x_start, float y_start, float x_end, float y_end)
{
    float dx = x_end - x_start;
    float dy = y_end - y_start;
    float steps;
    float xIncrement, yIncrement;
    float x = x_start;
    float y = y_start;

    if (abs(dx) > abs(dy))
    {
        steps = abs(dx);
    }
    else
    {
        steps = abs(dy);
    }

    xIncrement = dx / steps;
    yIncrement = dy / steps;

    setPixel(round(x), round(y));

    for (int k = 0; k < steps; k++)
    {
        x += xIncrement;
        y += yIncrement;
        setPixel(round(x), round(y));
    }
}

void drawAxes(void)
{
    glColor3f(1.0, 1.0, 1.0);
    drawLineDDA(-320, 0, 320, 0);
    glColor3f(1.0, 1.0, 1.0);
    drawLineDDA(0, -240, 0, 240);
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawAxes();
    glColor3f(0.0, 0.0, 1.0);
    drawLineDDA(x_start, y_start, x_end, y_end);
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
    glutCreateWindow("DDA Line Drawing Algorithm with Colored Axes");
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
