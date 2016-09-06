#include "include.h"

PERSONAGEM p1,p2;
extern PREDIOS mapa[NUMPREDIOS];


void desenhaPersonagem(){
      glColor3f(1,0,1);
      criarRetangulo(LARGURAPERSONAGEM,ALTURAPERSONAGEM);
}
void movimentoPersonagem(float x,float y){

      glPushMatrix();
            glTranslatef(x, y,0);
            desenhaPersonagem();
      glPopMatrix();
}

void inicializa_personagem(){
      p1.posicao[0]=mapa[0].cont+rand()%30;
      p2.posicao[0]=mapa[NUMPREDIOS-1].cont+rand()%30;
      p1.vida=3;
      p2.vida=3;
      p1.posicao[1]=mapa[0].y;
      p2.posicao[1]=mapa[NUMPREDIOS-1].y;
}
