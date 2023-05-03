#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include "dda.h"

void draw(void);
void myInit(void);
int mpsd(int,int,int,int);
void check(int,int);

int a,b,c,d,xmax,ymax,xmin,ymin,flag=0,x,y;
//int r_codeb[4]={0,0,0,0},r_codee[4]={0,0,0,0};

int main(int argv,char **argc){
		printf("Enter Xmax & Ymax:\t");
		scanf("%d %d",&xmax,&ymax);
		printf("Enter Xmin & Ymin:\t");
		scanf("%d %d",&xmin,&ymin);

		printf("Enter x1 & y1 of line:\t");
		scanf("%d %d",&a,&b);
		printf("Enter x2 & y2 of line:\t");
		scanf("%d %d",&c,&d);
		
		

		glutInit(&argv,argc);
		myInit();

		return 0;
}

void myInit(void){
		glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
		glutInitWindowSize(1024,720);
		glutCreateWindow("Midpoint Subdivision Line Clipping");

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
		
		mpsd(a,b,c,d);
}

void check(int x,int y){
                
		//Flag==1 then outside
		if(y>ymax){
		        //code[0]=1;
			flag=1;
		}
		else if(y<ymin){
		        //code[1]=1;
			flag=1;
		}
		if(x>xmax){
		        //code[2]=1;
			flag=1;
		}
		else if(x<xmin){
		        //code[3]=1;
			flag=1;
		}
		        
}

int mpsd(int x1,int y1,int x2,int y2){

		flag=0;
		check(x1,y1);
		int f1=flag;
		flag=0;
		check(x2,y2);
		int f2=flag;


		if(f1==0 && f2==0){
			//printf("No clipping reqd, Line is already inside\n");
			glColor3f(1,0,1);
			ddaLine(x1,y1,x2,y2);
			return 0;
		}
		else if(f1==1 && f2==1){
			//printf("Line is completely outside\n");
			return 0;
		}
		else{
			//printf("Line is partially inside\n");
			
			int xm=(x1+x2)/2;
			int ym=(y1+y2)/2;
			
			
		        mpsd(x1,y1,xm,ym);
			mpsd(xm,ym,x2,y2);

		}
}

