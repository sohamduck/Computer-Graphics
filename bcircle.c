#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include "dda.h"

int x11,y11,r;
void myInit(void);
void draw(void);
void circle(int,int,int);

int main(int argc,char** argv){
	printf("Enter x:\t");
	scanf("%d",&x11);
	printf("Enter y:\t");
	scanf("%d",&y11);
	printf("Enter Radius:\t");
	scanf("%d",&r);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1024,720);
	//glutInitWindowPosition(300,300);
	glutCreateWindow("Bresenham Circle Drawing Algorithm");
	myInit();
	glutDisplayFunc(draw);
	glutMainLoop();

	return 0;
}

void myInit(void){
	//glClearColor(0.0,0.0,0.0,0.0);
	//glColor4f(0.0f,0.0f,1.0f,0.0f);
	gluOrtho2D(0.0,1024.0,0.0,720.0);
	glPointSize(2.0);
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
}

void draw(void){
        ddaLine(x11,y11,x11,720);
        ddaLine(x11,y11,1024,y11);
        ddaLine(x11,y11,x11,-720);
        ddaLine(x11,y11,-1024,y11);
	circle(x11,y11,r);
}

void circle(int x1,int y1,int r){
	float x=0,y=r,p=3-2*r;
	while(x<=y){
	        ++x;
		if(p<0)	
			p+=4*x+6;
		
		else if(p>=0){
			y-=1;
			p+=4*(x-y)+10;
		}
		
		glBegin(GL_POINTS);
		//Interpolating first point in four quadrants
		glVertex2i(x+x11,y+y11);
		glVertex2i(x+x11,-y+y11);
		glVertex2i(-x+x11,-y+y11);
		glVertex2i(-x+x11,y+y11);
		//Interpolating other points
		glVertex2i(y+x11,x+y11);
		glVertex2i(-y+x11,x+y11);
		glVertex2i(y+x11,-x+y11);
		glVertex2i(-y+x11,-x+y11);
		glEnd();
		glFlush();
	}
	
}
