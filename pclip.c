#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include "dda.h"

void draw(void);
void myInit(void);
int clip(int,int);

int a,b,xmax,ymax,xmin,ymin;

int main(int argv,char **argc){
		printf("Enter Xmax & Ymax:\t");
		scanf("%d %d",&xmax,&ymax);
		printf("Enter Xmin & Ymin:\t");
		scanf("%d %d",&xmin,&ymin);

		printf("Enter x & y of point:\t");
		scanf("%d %d",&a,&b);

		glutInit(&argv,argc);
		myInit();

		return 0;
}

void myInit(void){
		glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
		glutInitWindowSize(1024,720);
		glutCreateWindow("Point Clipping 2D");

		glClearColor(0,0,0,0);
		glPointSize(2.0);
		gluOrtho2D(-100,1024,-100,720);

		glutDisplayFunc(draw);
		glutMainLoop();

}

void draw(void){
		
		//Drawing x-axis & y-axis
		ddaLine(-100,0,1024,0);
		ddaLine(0,-100,0,720);

		//Drawing a rectangle
		ddaLine(xmin,ymin,xmax,ymin);
		ddaLine(xmin,ymin,xmin,ymax);
		ddaLine(xmax,ymin,xmax,ymax);
		ddaLine(xmin,ymax,xmax,ymax);
		clip(a,b);
}

int clip(int x,int y){
		if(x>=xmin && x<=xmax){
				if(y>=ymin && y<=ymax){
						printf("\nInside The Rectangle\n");
						glBegin(GL_POINTS);
						glColor3f(1,0,0);
						glVertex2i(x,y);
						glEnd();
						glFlush();
				}
				return 0;
		}
		printf("\nNot inside rectangle\n");
}
