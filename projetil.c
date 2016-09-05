#include "include.h"
int ativo;
double movimento_x,movimento_y;
double angulo;

void lancaProjetil(){

    movimento_x=cos((angulo*PI)/180)*(VELOCIDADE/50);
    movimento_y=sin((PI*angulo)/180)*(VELOCIDADE/50);

}
void movimento(){

      movimento_x+=cos((angulo*PI)/180)*(VELOCIDADE/50);
      movimento_y-=GRAVIDADE;
      glutPostRedisplay();

      glutTimerFunc(1,movimento,0);

}

void desenhaProjetil(double x,double y){

      glPushMatrix();
      double posiX;
            glTranslatef(x+movimento_x,y+movimento_y,0);
            criarRetangulo(30,60);
      glPopMatrix();
      glFlush();
}
