#include "include.h"
PERSONAGEM p1,p2;
extern PREDIOS mapa[NUMPREDIOS];
extern GLuint vida_mage_3,vida_mage_4;

void geradorDePersonagem(double largura, double altura,int k){

  if(k == 0){
      glBegin(GL_TRIANGLE_FAN);
          glTexCoord2f(0.0, 0.0); glVertex3f(       0,       0,  0);
          glTexCoord2f(1.0, 0.0); glVertex3f( largura,       0,  0);
          glTexCoord2f(1.0, 1.0); glVertex3f( largura,  altura,  0);
          glTexCoord2f(0.0, 1.0); glVertex3f(       0,  altura,  0);
      glEnd();
  }else if(k == 1){
    glBegin(GL_TRIANGLE_FAN);
        glTexCoord2f(1.0, 0.0); glVertex3f(       0,       0,  0);
        glTexCoord2f(0.0, 0.0); glVertex3f( largura,       0,  0);
        glTexCoord2f(0.0, 1.0); glVertex3f( largura,  altura,  0);
        glTexCoord2f(1.0, 1.0); glVertex3f(       0,  altura,  0);
    glEnd();
  }
}
void movimentoPersonagem(float x,float y,int k){

      glPushMatrix();
            glTranslatef(x, y,0);
            glColor3f (1, 1, 1);
            glEnable(GL_TEXTURE_2D);
            if(k == 0)
              glBindTexture(GL_TEXTURE_2D, mage_3);
            else if(k == 1)
              glBindTexture(GL_TEXTURE_2D, mage_4);
              geradorDePersonagem(LARGURAPERSONAGEM,ALTURAPERSONAGEM,k);
            glDisable(GL_TEXTURE_2D);
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


void desenhaVida(int x, int y){

  glPushMatrix();
    glTranslatef(x,y,0);
    glColor3f(1,1,1);
    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, vida_mage_3);
        geradorDePersonagem(100,150,0);
  glPopMatrix();
}
void desenhaVida_2(int x, int y){

  glPushMatrix();
    glTranslatef(x,y,0);
    glColor3f(1,1,1);
    glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, vida_mage_4);
        geradorDePersonagem(100,150,0);
  glPopMatrix();
}
