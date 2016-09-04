#include "include.h"
double movimento_x=0,movimento_y=0;
void movimento(){

      movimento_x+=cos(ANGULO)*(VELOCIDADE-GRAVIDADE);
      movimento_y+=cos(ANGULO)*(VELOCIDADE-GRAVIDADE);
      glutPostRedisplay();

      glutTimerFunc(60,movimento,1);

}

void desenhaProjetil(double x,double y){

      glPushMatrix();
            glTranslatef(x,y,0);
            criarRetangulo(30,60);
      glPopMatrix();
      glFlush();
}
