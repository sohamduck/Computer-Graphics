#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include "dda.h"

void draw(void);
void myInit(void);
int cohen();
int* check(int,int,int[]);
void plot(int[]);

int a,b,c,d,xmax,ymax,xmin,ymin,flag=0,x,y;
int r_codeb[4]={0,0,0,0},r_codee[4]={0,0,0,0};
float m;

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
		glutCreateWindow("Cohen Sutherland Line Clipping");

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
		
		cohen();
}

int* check(int x,int y,int code[]){
                
		//Flag==1 then outside
		if(y>ymax){
		        code[0]=1;
			flag=1;
		}
		else if(y<ymin){
		        code[1]=1;
			flag=1;
		}
		if(x>xmax){
		        code[2]=1;
			flag=1;
		}
		else if(x<xmin){
		        code[3]=1;
			flag=1;
		}
		        
		
		return code;
}

int cohen(){

		int *codeb=(int*)calloc(4,sizeof(int));
		int *codee=(int*)calloc(4,sizeof(int));
		flag=0;
		codeb=check(a,b,r_codeb);
		int f1=flag;
		flag=0;
		codee=check(c,d,r_codee);
		int f2=flag;
		

		if(f1==0 && f2==0){
			printf("No clipping reqd, Line is already inside");
			glColor3f(1,0,1);
			ddaLine(a,b,c,d);
			return 0;
		}
		else if(f1==1 && f2==1){
			printf("Line is completely outside");
			return 0;
		}
		else{
			printf("Line is partially inside\n");
			int x1,y1,x2,y2;
			if(f1==1){
				plot(codeb);
				x1=x;
				y1=y;
			}
			else{
				x1=a;
				y1=b;
			}

			if(f2==1){
				plot(codee);
				x2=x;
				y2=y;
			}
			else{
				x2=c;
				y2=d;
			}

			glColor3f(1,0,1);
			ddaLine(x1,y1,x2,y2);
		}
}


void plot(int code[]){
		//slope
		m=(float)(d-b)/(c-a);

		if(code[2]==0 && code[3]==1){
			//left
			x=xmin;
			y=d+(float)m*(x-c);
		}
		else if(code[2]==1 && code[3]==0){
			//right
			x=xmax;
			y=d+(float)m*(x-c);
		}

		if(code[0]==1 && code[1]==0){
			//top
			y=ymax;
			x=c+(float)(y-d)/m;
		}
		else if(code[0]==0 && code[1]==1){
			//bottom
			y=ymin;
			x=c+(float)(y-d)/m;
		}

		if(code[0]==1 && code[3]==1){
			x=xmin;
			y=ymax;
		}
		if(code[1]==1 && code[3]==1){
			x=xmin;
			y=ymin;
		}
		if(code[0]==1 && code[2]==1){
			x=xmax;
			y=ymax;
		}
		if(code[1]==1 && code[2]==1){
			x=xmax;
			y=ymin;
		}
}
