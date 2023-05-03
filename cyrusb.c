#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include "dda.h"

void draw(void);
void polygon(int*,int*,float[]);
void myInit(void);
void accept();
void cyrus();

int n,xdif,ydif,x1,x2,y1,y2;
int *x,*y,*nx,*ny,*px,*py;
float t;

int main(int argv,char **argc){
		
		printf("No. of vertices:\t");
		scanf("%d",&n);

		x=(int*)calloc(n,sizeof(int));
		y=(int*)calloc(n,sizeof(int));
		nx=(int*)calloc(n,sizeof(int));
		ny=(int*)calloc(n,sizeof(int));
		px=(int*)calloc(2,sizeof(int));
		py=(int*)calloc(2,sizeof(int));

		//t=(float*)calloc(n,sizeof(float));


		for(int i=0;i<n;++i){
				printf("Enter x%d & y%d:\t",i+1,i+1);
				scanf("%d %d",x+i,y+i);
		}
		
		printf("\nEnter Co-ord for line:\n\n");
		printf("Enter x1 & y1:\t");
		scanf("%d %d",&x1,&y1);

		printf("Enter x2 & y2:\t");
		scanf("%d %d",&x2,&y2);
		
		xdif=x2-x1;
		ydif=y2-y1;

		glutInit(&argv,argc);
		myInit();

		return 0;

}

void myInit(void){
		glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
		glutInitWindowSize(1024,720);
		glutCreateWindow("Cyrus Beck LCA");


		glClearColor(0.0,1.0,1.0,0.0);
		glPointSize(5.0);
		gluOrtho2D(-100,1024,-100,720);

		glutDisplayFunc(draw);
		glutMainLoop();

}

void draw(void){
		ddaLine(0,-100,0,720);
		ddaLine(-100,0,1024,0);

		float color[]={1,0,0};
		polygon(x,y,color);
		accept();
		
		cyrus();

}

void polygon(int *x,int *y,float color[]){
		glColor3f(color[0],color[1],color[2]);

		for(int i=0;i<n-1;++i)
				ddaLine(x[i],y[i],x[i+1],y[i+1]);

		ddaLine(x[0],y[0],x[n-1],y[n-1]);

}

void accept(){
                for(int i=0;i<n;++i){
			printf("Enter nx%d & ny%d:\t",i+1,i+1);
			scanf("%d %d",nx+i,ny+i);
		}

}

void cyrus(){
		int ec=0,lc=0,ntor,dtor;
		float ept,lpt;
		for(int i=0;i<n;++i){
			
			int a=x[i]-x1;
			int b=y[i]-y1;

			ntor=nx[i]*a+b*ny[i];
			dtor=nx[i]*xdif+ny[i]*ydif;

			t=(float)ntor/dtor;
			
			if(dtor<0 && ec==0){
				ept=t;
				++ec;
			}

			if(dtor>0 && lc==0){
				lpt=t;
				++lc;
			}

			if(dtor<0 && t>ept)
				//Entering Point
				ept=t;

			if(dtor>0 && t<lpt)
				//Leaving Point
				lpt=t;
		}

		//P(t) is found from value of ept & lpt

		//Entering Point
		px[0]=x1+ept*xdif;
		py[0]=y1+ept*ydif;
		
		//Leaving Point
		px[1]=x1+lpt*xdif;
		py[1]=y1+lpt*ydif;
		
		glColor3f(1.0,0.5,0);
		ddaLine(px[0],py[0],px[1],py[1]);

}
