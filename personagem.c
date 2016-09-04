#include "include.h"

void desenhaPersonagem(){
      glColor3f(1,0,1);
      criarRetangulo(LARGURAPERSONAGEM,ALTURAPERSONAGEM);
      glFlush();
}
void movimentoPersonagem(float x,float y){

      glPushMatrix();
            glTranslatef(x, y,0);
            desenhaPersonagem();
      glPopMatrix();
}
