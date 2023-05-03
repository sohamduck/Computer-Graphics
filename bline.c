#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>

void draw(void);
void bresenham(int,int,int,int);
void myInit(void);
void plot(int,int);

int a,b,c,d;

int main(int argv,char **argc){
		
		printf("Enter x1 & y1:\t");
		scanf("%d %d",&a,&b);
		printf("Enter x2 & y2:\t");
		scanf("%d %d",&c,&d);

		glutInit(&argv,argc);
		myInit();

		return 0;
}

void myInit(){
	
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1024,720);
	glutCreateWindow("Bresenhem Line Drawing");

        glPointSize(2.0);
	glClearColor(0.0,0.0,1.0,0.0);
	glColor4f(1.0f,0.0f,1.0f,1.0f);
	gluOrtho2D(0.0,1024.0,0.0,720.0);

	glutDisplayFunc(draw);
	glutMainLoop();

}

void draw(void){
	bresenham(a,b,c,d);
}


void bresenham(int x1,int y1,int x2,int y2){
		
		int x=x1;
		int y=y1;
		plot(x,y);

		int dy=y2-y1;
		int dx=x2-x1;

		float m=dy/dx;

		int temp;
		if(m>=1){
			temp=dy;
			dy=dx;
			dx=temp;
		}

		int p=2*dy-dx;
                printf("%d %d\t%d\n",x,y,p);
                
		for(int k=0;k<dx;++k){
		        
			x++;
			
			if(p>=0){
				++y;
				p+=2*dy-2*dx;
			}
			else
			        p+=2*dy;
			
			m>=1?(plot(y,x),printf("%d %d\t%d\n",y,x,p)):(plot(x,y),printf("%d %d\t%d\n",x,y,p));
			
		}

}

void plot(int x,int y){
		glBegin(GL_POINTS);
		glVertex2i(x,y);
		glEnd();
		glFlush();
}
