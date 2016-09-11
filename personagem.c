#include "include.h"
PERSONAGEM p1,p2;
extern PREDIOS mapa[NUMPREDIOS];
extern unsigned int textureuse_mage3;
extern unsigned int textureuse_mage4;

void geradorDePersonagem(double largura, double altura){

      glBegin(GL_TRIANGLE_FAN);
          glTexCoord2f(0.0, 0.0); glVertex3f(       0,       0,  0);
          glTexCoord2f(1.0, 0.0); glVertex3f( largura,       0,  0);
          glTexCoord2f(1.0, 1.0); glVertex3f( largura,  altura,  0);
          glTexCoord2f(0.0, 1.0); glVertex3f(       0,  altura,  0);
      glEnd();
}
void movimentoPersonagem(float x,float y,int k){

      glPushMatrix();
            glTranslatef(x, y,0);
            glColor3f (1, 1, 1);
            glEnable(GL_TEXTURE_2D);
            if(k == 0)
              glBindTexture(GL_TEXTURE_2D, textureuse_mage3);
            else if(k == 1)
              glBindTexture(GL_TEXTURE_2D, textureuse_mage4);
              geradorDePersonagem(LARGURAPERSONAGEM,ALTURAPERSONAGEM);
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
