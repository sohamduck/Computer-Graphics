//DDA line drawing algo
#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>

int x1,x2,y11,y2;
void myInit(void);
void draw(void);
void ddaline(int,int,int,int);

int main(int argc,char **argv){
  printf("Enter x1:\t");
  scanf("%d",&x1);
  printf("Enter y1:\t");
  scanf("%d",&y11);
  printf("Enter x2:\t");
  scanf("%d",&x2);
  printf("Enter y2:\t");
  scanf("%d",&y2);
  glutInit(&argc,argv);
  myInit();

  return 0;
}
  
void myInit(void){
  
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(1024,720);
  glutInitWindowPosition(300,300);
  glutCreateWindow("DDA Line Drawing Algorithm");
  
  glClearColor(0.0,0.0,1.0,0.0);
  glColor4f(1.0f, 0.0f, 1.0f, 1.0f);//purple
  //glMatrixMode(GL_PROJECTION);
  //glLoadIdentity();
  gluOrtho2D(0.0,1000.0,0.0,720.0);
  
  glutDisplayFunc(draw);
  glutMainLoop();
}

void draw(void){
    ddaline(x1,x2,y11,y2);
}

void ddaline(int x1,int x2,int y1,int y2){
    float x,y,m,step,dy,dx,xinc,yinc;
    
    dx=x2-x1;
    dy=y2-y1;
    
    step=abs(dy)>abs(dx)?abs(dy):abs(dx);
    
    xinc=dx/step;
    yinc=dy/step;
    
    x=x1;
    y=y1;
    
    glBegin(GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    
    for(int k=1;k<=step;++k){
        x+=xinc;
        y+=yinc;
        
        glBegin(GL_POINTS);
        glVertex2i(x,y);
        glEnd();
    }
    glFinish();
}
