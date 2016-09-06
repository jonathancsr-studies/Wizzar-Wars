#include "include.h"
int ativo;

PERSONAGEM p1,p2;
PROJETIL A1,A2;
int ativo;
int timer;
void lancaProjetil(){
      if(ativo){
          A1.velocidade.x=cos(PI*ANGULO/180)*(VELOCIDADE/50);
          A1.velocidade.y=sin(PI*ANGULO/180)*(VELOCIDADE/50);
    }else{
          A2.velocidade.x=(cos(PI*ANGULO/180)*(VELOCIDADE/50))*(-1);
          A2.velocidade.y=sin(PI*ANGULO/180)*(VELOCIDADE/50);
   }

}
PREDIOS mapa[NUMPREDIOS];
void movimentoProjetil(){

int i;
//PARTES DE CONDIÇOES PARA ACABAR COM O LANÇAMENTO
      if(ativo){
          A1.posicao.x+=A1.velocidade.x;
          A1.posicao.y+=A1.velocidade.y;
          A1.velocidade.y-=GRAVIDADE;
    }else{
          A2.posicao.x+=A2.velocidade.x;
          A2.posicao.y+=A2.velocidade.y;
          A2.velocidade.y-=GRAVIDADE;
   }
   //SE SAIR DA TELA
   if(A1.posicao.x >= LARGURA||A2.posicao.x+LARGURAPROJETIL <= 0)
         {
               A1.posicao.x=A1.posicao_inicial.x;
               A1.posicao.y=A1.posicao_inicial.y;
               A2.posicao.x=A2.posicao_inicial.x;
               A2.posicao.y=A2.posicao_inicial.y;
               timer=0;
               if(ativo){
               ativo=0;
         }else{
               ativo=1;
            }
         }

// SE ACERTAR UM DOS PREDIOS
 for(i=0;i<NUMPREDIOS;i++){
             if(ativo){
               if(A1.posicao.x+LARGURAPROJETIL >= mapa[i].cont && A1.posicao.x < mapa[i].cont+(LARGURA/NUMPREDIOS)){
                     if(A1.posicao.y <= mapa[i].y){
                           A1.posicao.x=A1.posicao_inicial.x;
                           A1.posicao.y=A1.posicao_inicial.y;
                           timer=0;
                           if(ativo){
                           ativo=0;
                           }
                           ativo=1;
                     }
               }
         }else{
               if(A2.posicao.x > mapa[i].cont && A2.posicao.x <= mapa[i].cont+(LARGURA/NUMPREDIOS)){
                     if(A2.posicao.y <= mapa[i].y){
                           A2.posicao.x=A2.posicao_inicial.x;
                           A2.posicao.y=A2.posicao_inicial.y;
                           timer=0;
                           if(ativo){
                           ativo=0;
                           }
                           ativo=1;
                     }
               }
         }
   }
      glutPostRedisplay();
      if(timer)
      glutTimerFunc(60,movimentoProjetil,0);

}

void criaProjetil(){

      glPushMatrix();
            if(ativo){
            glTranslatef(A1.posicao.x,A1.posicao.y,0);
      }else{
            glTranslatef(A2.posicao.x,A2.posicao.y,0);
      }
            criarRetangulo(LARGURAPROJETIL,ALTURAPROJETIL);
      glPopMatrix();

}

void inicializa_Projetil(){

            //Projetil do personagem 1
            A1.posicao.x=p1.posicao[0]+(LARGURAPERSONAGEM+10);
            A1.posicao.y=p1.posicao[1]+(LARGURAPERSONAGEM+10);
            A1.velocidade.x=0;
            A1.velocidade.y=0;
            A1.posicao_inicial.x=A1.posicao.x;
            A1.posicao_inicial.y=A1.posicao.y;
            //Projetil o personagem 2
            A2.posicao.x=p2.posicao[0]-(LARGURAPERSONAGEM+10);
            A2.posicao.y=p2.posicao[1]+(LARGURAPERSONAGEM+10);
            A2.velocidade.x=0;
            A2.velocidade.y=0;
            A2.posicao_inicial.x=A2.posicao.x;
            A2.posicao_inicial.y=A2.posicao.y;
}
