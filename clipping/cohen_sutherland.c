#include <GL/glut.h>
#include <math.h>

#define xmin 50
#define ymin 50
#define xmax 400
#define ymax 400

const int INSIDE = 0;
const int LEFT = 1;
const int RIGHT = 2;
const int BOTTOM = 4;
const int TOP = 8;

typedef struct
{
    double x;
    double y;
} Point;

Point line[2] = {{10, 10}, {500, 500}};

int computeCode(double x, double y)
{
    int code = INSIDE;

    if (x < xmin)
        code |= LEFT;
    else if (x > xmax)
        code |= RIGHT;
    if (y < ymin)
        code |= BOTTOM;
    else if (y > ymax)
        code |= TOP;

    return code;
}

void drawLine(Point p1, Point p2, int transformed)
{
    if (transformed)
        glColor3f(1, 0, 0);
    else
        glColor3f(0, 1, 0);

    glBegin(GL_LINES);
    glVertex2f(p1.x, p1.y);
    glVertex2f(p2.x, p2.y);
    glEnd();

    glFlush();
}

void cohenSutherlandClip(Point p1, Point p2)
{
    drawLine(p1, p2, 0);

    int code1 = computeCode(p1.x, p1.y);
    int code2 = computeCode(p2.x, p2.y);

    int accept = 0;

    while (1)
    {
        if ((code1 == 0) && (code2 == 0))
        {
            accept = 1;
            break;
        }
        else if (code1 & code2)
        {
            break;
        }
        else
        {
            int code_out;
            double x, y;

            if (code1 != 0)
                code_out = code1;
            else
                code_out = code2;

            if (code_out & TOP)
            {
                x = p1.x + (p2.x - p1.x) * (ymax - p1.y) / (p2.y - p1.y);
                y = ymax;
            }
            else if (code_out & BOTTOM)
            {
                x = p1.x + (p2.x - p1.x) * (ymin - p1.y) / (p2.y - p1.y);
                y = ymin;
            }
            else if (code_out & RIGHT)
            {
                y = p1.y + (p2.y - p1.y) * (xmax - p1.x) / (p2.x - p1.x);
                x = xmax;
            }
            else if (code_out & LEFT)
            {
                y = p1.y + (p2.y - p1.y) * (xmin - p1.x) / (p2.x - p1.x);
                x = xmin;
            }

            if (code_out == code1)
            {
                p1.x = x;
                p1.y = y;
                code1 = computeCode(p1.x, p1.y);
            }
            else
            {
                p2.x = x;
                p2.y = y;
                code2 = computeCode(p2.x, p2.y);
            }
        }
    }

    if (accept)
    {
        drawLine(p1, p2, 1);
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    cohenSutherlandClip(line[0], line[1]);
}

void init()
{
    glClearColor(0, 0, 0, 1);
    gluOrtho2D(-500, 500, -500, 500);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("Cohen-Sutherland Line Clipping");
    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}