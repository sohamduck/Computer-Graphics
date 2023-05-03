#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>

void ddaLine(int x1,int y1,int x2,int y2){
      float dx,dy,step,xin,yin,x,y;
      dx=x2-x1;
      dy=y2-y1;
      
      step=abs(dy)>abs(dx)?abs(dy):abs(dx);
      xin=dx/step;
      yin=dy/step;
      
      x=x1;
      y=y1;
      glBegin(GL_POINTS);
      glVertex2i(x,y);
      glEnd();
      
      for(int k=1;k<=step;++k){
          x+=xin;
          y+=yin;
          
          glBegin(GL_POINTS);
          glVertex2i(x,y);
          glEnd();
      }
      glFinish();
}
