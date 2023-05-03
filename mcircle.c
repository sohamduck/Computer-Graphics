#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include "dda.h"

void draw(void);
void plot(int,int);
void myInit(void);
void circle(int,int,int);

int a,b,r;


int main(int argv,char **argc){
			
		printf("Enter x & y:\t");
		scanf("%d %d",&a,&b);	
		printf("Enter radius:\t");
		scanf("%d",&r);

		glutInit(&argv,argc);
		myInit();

		return 0;
}

void myInit(void){
		
		glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
		glutInitWindowSize(1024,720);
		glutCreateWindow("Mid-point Circle Drawing Algorithm");

		glPointSize(2.0);
		glClearColor(0.0,0.0,1.0,0.0);
		glColor4f(1.0f,0.0f,1.0f,1.0f);
		gluOrtho2D(0.0,1024.0,0.0,720.0);

		glutDisplayFunc(draw);
		glutMainLoop();

}

void draw(void){
		ddaLine(a,b,a,720);
		ddaLine(a,b,1024,b);
		ddaLine(a,b,-1024,b);
		ddaLine(a,b,a,-720);
		circle(a,b,r);

}

void circle(int x0,int y0,int r0){
		
		int x=0,y=r0,p=1-r0;
		plot(x,y);

		while(x<y){
			
			++x;
			if(p>=0){
				
				--y;
				p+=2*(x-y)+5;
			}
			else
				p+=2*x+3;
			
			plot(x,y);
		}
}

void plot(int x,int y){
		
		glBegin(GL_POINTS);
		glVertex2i(x+a,y+b);
		glVertex2i(-x+a,y+b);
		glVertex2i(x+a,-y+b);
		glVertex2i(-x+a,-y+b);
		glVertex2i(y+a,x+b);
		glVertex2i(-y+a,x+b);
		glVertex2i(y+a,-x+b);
		glVertex2i(-y+a,-x+b);

		glEnd();
		glFlush();
	
}

