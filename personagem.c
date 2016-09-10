#include "include.h"

PERSONAGEM p1,p2;
extern PREDIOS mapa[NUMPREDIOS];
void geradorDePersonagem(double largura, double altura){
    // Habilita o uso de texturas
    glEnable(GL_TEXTURE_2D);

    // Come�a a usar a textura que criamos
    glBindTexture(GL_TEXTURE_2D, mage_3_idle_0);
    glBegin(GL_TRIANGLE_FAN);
        // Associamos um canto da textura para cada v�rtice
        glTexCoord2f(0,   0); glVertex3f(  0,  0,  0);
        glTexCoord2f(1,  0); glVertex3f( largura,  0,  0);
        glTexCoord2f(1, 1); glVertex3f( largura, altura,  0);
        glTexCoord2f(0,  1); glVertex3f(  0, altura,  0);
    glEnd();
    glDisable(GL_TEXTURE_2D);
}
void movimentoPersonagem(float x,float y){

      glPushMatrix();
            glTranslatef(x, y,0);
            geradorDePersonagem(LARGURAPERSONAGEM,ALTURAPERSONAGEM);
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
