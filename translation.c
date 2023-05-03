#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include "dda.h"

void draw(void);
void polygon(int*,int*,float[]);
void myInit(void);
void translate(int,int);

int n,a,b;
int *x,*y;

int main(int argv,char** argc){
		
		printf("No. of vertices:\t");
		scanf("%d",&n);
		
		x=(int*)calloc(n,sizeof(int));
		y=(int*)calloc(n,sizeof(int));

		for(int i=0;i<n;++i){
				printf("Enter x%d & y%d:\t",i+1,i+1);
				scanf("%d %d",x+i,y+i);
		}

		printf("Enter Tx & Ty:\t");
		scanf("%d %d",&a,&b);

		glutInit(&argv,argc);
		myInit();

		return 0;

}

void myInit(void){
		
		glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
		glutInitWindowSize(1024,720);
		glutCreateWindow("Translation 2D");
		
		glClearColor(0.0,1.0,1.0,0.0);
		glPointSize(2.0);
		gluOrtho2D(-100,1024.0,-100,720.0);

		glutDisplayFunc(draw);
		glutMainLoop();
}

void draw(void){
		ddaLine(0,-100,0,720);
		ddaLine(-100,0,1024,0);

		
		float color[]={0,1,1};
		polygon(x,y,color);
		translate(a,b);

}

void polygon(int *x,int *y,float color[]){
		glColor3f(color[0],color[1],color[2]);

		for(int i=0;i<n-1;++i)
			ddaLine(x[i],y[i],x[i+1],y[i+1]);

		ddaLine(x[0],y[0],x[n-1],y[n-1]);
}

void translate(int tx,int ty){
		for(int i=0;i<n;++i){
				x[i]+=tx;
				y[i]+=ty;
		}
		float color[]={0.5f,0.0f,1.0f};
		polygon(x,y,color);

}
