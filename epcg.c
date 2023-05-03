#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include "dda.h"

void draw(void);
void myInit(void);
void drawLine(int,int,int,int);

int x1,x2,y1,y2;

int main(int argv,char **argc){
		
		printf("\nEnter Co-ord for line:\n\n");
		printf("Enter x1 & y1:\t");
		scanf("%d %d",&x1,&y1);

		printf("Enter x2 & y2:\t");
		scanf("%d %d",&x2,&y2);

		glutInit(&argv,argc);
		myInit();

		return 0;

}

void myInit(void){
		glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
		glutInitWindowSize(1024,720);
		glutCreateWindow("End Point Code Generation");


		glClearColor(0.0,1.0,1.0,0.0);
		glPointSize(3.0);
		gluOrtho2D(-100,1024,-100,720);

		glutDisplayFunc(draw);
		glutMainLoop();

}

void draw(void){
		ddaLine(0,-100,0,720);
		ddaLine(-100,0,1024,0);

		float color[]={0.5,0.5,0};
		drawLine(x1,y1,x2,y2);
}

void drawLine(int x0, int y0, int x1, int y1)
{
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx, sy, err;

    if (x0 < x1)
    {
        sx = 1;
    }
    else
    {
        sx = -1;
    }

    if (y0 < y1)
    {
        sy = 1;
    }
    else
    {
        sy = -1;
    }

    err = dx - dy;

    while (1)
    {
        glBegin(GL_POINTS);
	glVertex2i(x0, y0);
	glEnd();
	glFinish();
        

        if (x0 == x1 && y0 == y1)
        {
            break;
        }

        int e2 = 2 * err;

        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }

        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}

