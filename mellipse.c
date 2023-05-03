#include<stdlib.h>
#include<stdio.h>
#include<GL/glut.h>
#include "dda.h"

int a,b,rx,ry;
void myInit(void);
void draw(void);
void ellipse();
void plot(int,int);

void myInit(void){
        
        glutInitWindowSize(1024,720);
	glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
	glutCreateWindow("Ellipse");
	
        glClearColor(0.0,0.0,1.0,0.0);
        glColor4f(0.0,1.0,1.0,0.0f);
	glPointSize(2.0);
	gluOrtho2D(0.0,1024.0,0.0,720.0);
	
	glutDisplayFunc(draw);
	glutMainLoop();
}

int main(int argc,char** argv){
	printf("Value of centre:\t");
	scanf("%d %d",&a,&b);
	printf("Enter rx and ry:\t");
	scanf("%d %d",&rx,&ry);
	
	
	glutInit(&argc,argv);
	
	myInit();

	return 0;
}

void draw(void){
        ddaLine(a,b,1024,b);
        ddaLine(a,b,a,720);
        ddaLine(a,b,a,-720);
        ddaLine(a,b,-1024,b);
        ellipse();
}

void ellipse(){
        float dx,dy,x,y;
        //Decision parameters
        float d1,d2;
        
        x=0;
        y=ry;
        plot(x,y);
        
        //Region 1
        d1=(0.25*rx*rx)+(ry*ry)-(rx*rx*ry);
        dx=2*ry*ry*x;
        dy=2*rx*rx*y;
        
        while(dx<dy){
            plot(x,y);
            
            ++x;
            dx+=2*ry*ry;
            
            if(d1>=0){
                --y;
                dy-=2*rx*rx;
                d1+=dx+ry*ry-dy;
            }
            else
                d1+=dx+ry*ry;
        }
        
        //Region 2        
        d2=(ry*ry*(x+0.5)*(x+0.5))+(rx*rx*(y-1)*(y-1))-(rx*rx*ry*ry);
        
        while(y>=0){
              plot(x,y);
              
              --y;
              dy-=2*rx*rx;
              
              if(d2<0){
                    ++x;
                    d2+=(rx*rx)-dy+dx;
              }
              else
                    d2+=(rx*rx)-dy;
        }
}

void plot(int x,int y){
      glBegin(GL_POINTS);
      glVertex2i(a+x,b+y);
      glVertex2i(a-x,b+y);
      glVertex2i(a+x,b-y);
      glVertex2i(a-x,b-y);
      glEnd();
      glFlush();
}
