#include "include.h"
int ativo;
double velocidade;
PERSONAGEM p1,p2;
PROJETIL A1,A2;
double gravidade;
int ativo;
int timer;
int cheat;
int pause;
int forca;
extern int swap_texture_damage_mage_3;
PREDIOS mapa[NUMPREDIOS];
void lancaProjetil(){
      if(ativo){
          A1.velocidade.x=cos(PI*A1.direcao/180)*(velocidade/5);
          A1.velocidade.y=sin(PI*A1.direcao/180)*(velocidade/5);
    }else{
          A2.velocidade.x=(cos(PI*A2.direcao/180)*(velocidade/5))*(-1);
          A2.velocidade.y=sin(PI*A2.direcao/180)*(velocidade/5);
   }

}
void movimentoProjetil(){

int i;
//PARTES DE CONDIÇOES PARA ACABAR COM O LANÇAMENTO
      if(ativo){
          A1.posicao.x+=A1.velocidade.x;
          A1.posicao.y+=A1.velocidade.y;
          A1.velocidade.y-=gravidade;
    }else{
          A2.posicao.x+=A2.velocidade.x;
          A2.posicao.y+=A2.velocidade.y;
          A2.velocidade.y-=gravidade;
   }
   //SE SAIR DA TELA

   if(A1.posicao.x >= LARGURA||A2.posicao.x+LARGURAPROJETIL <= 0)
         {
               A1.posicao.x=A1.posicao_inicial.x;
               A1.posicao.y=A1.posicao_inicial.y;
               A2.posicao.x=A2.posicao_inicial.x;
               A2.posicao.y=A2.posicao_inicial.y;
               timer=0;
               forca=1;
               if(ativo){
               ativo=0;
         }else{
               ativo=1;
            }
         }
// SE ACERTAR UM DOS PREDIOS
 for(i=0;i<NUMPREDIOS;i++){
             if(ativo){
               if(((A1.posicao.x+LARGURAPROJETIL > mapa[i].cont) || (A1.posicao.x > mapa[i].cont))  && ((A1.posicao.x <= mapa[i].cont+(LARGURA/NUMPREDIOS)) || (A1.posicao.x+LARGURAPROJETIL <= mapa[i].cont+(LARGURA/NUMPREDIOS)))){
                     if(A1.posicao.y <= mapa[i].y){
                           A1.posicao.x=A1.posicao_inicial.x;
                           A1.posicao.y=A1.posicao_inicial.y;
                           timer=0;
                           ativo=0;
                           forca=1;

                     }
               }
         }else{
               if(((A2.posicao.x > mapa[i].cont) || (A2.posicao.x+LARGURAPROJETIL >= mapa[i].cont)) && ((A2.posicao.x <= mapa[i].cont+(LARGURA/NUMPREDIOS)) || (A2.posicao.x+LARGURAPROJETIL <= mapa[i].cont+(LARGURA/NUMPREDIOS)))){
                     if(A2.posicao.y <= mapa[i].y){
                           A2.posicao.x=A2.posicao_inicial.x;
                           A2.posicao.y=A2.posicao_inicial.y;
                           timer=0;
                           ativo=1;
                           forca=1;
                     }
               }
         }
   }
   //SE ACERTAR O INIMIGO
   if(ativo){
   		if(A1.posicao.x >= p2.posicao[0] && A1.posicao.x <= p2.posicao[0]+LARGURAPERSONAGEM){
   			if(A1.posicao.y <= p2.posicao[1]+ALTURAPERSONAGEM){
                           A1.posicao.x=A1.posicao_inicial.x;
                           A1.posicao.y=A1.posicao_inicial.y;
                           p2.vida--;
                           timer=0;
                           forca=1;
                           //     ANIMAÇÃO DE TEXTURA
                               glutTimerFunc(0,mage_4_Damage,0);
                               p2.posicao[0]+=TRANSLADA;
                               A2.posicao.x+=TRANSLADA;
                               A2.posicao_inicial.x+=TRANSLADA;
                           //     FIM DA ANIMAÇÃO DE TEXTURA
                           printf("\nACERTEI NO SEGUNDO\t\n %d",p2.vida);
                           if(ativo){
                                ativo=0;
                           }else{
                                ativo=1;
                           }

   			}
   		}
   	}else{
   		if(A2.posicao.x >= p1.posicao[0] && A2.posicao.x <= p1.posicao[0]+LARGURAPERSONAGEM){
   			if(A2.posicao.y <= p1.posicao[1]+ALTURAPERSONAGEM){
                           A2.posicao.x=A2.posicao_inicial.x;
                           A2.posicao.y=A2.posicao_inicial.y;
                           timer=0;
                           forca=1;
                           p1.vida--;
                           //    ANIMAÇÃO DE TEXTURA
                               swap_texture_damage_mage_3 = 0;
                               glutTimerFunc(0,mage_3_Damage,0);
                               p1.posicao[0]-=5*TRANSLADA;
                               A1.posicao.x-=5*TRANSLADA;
                               A1.posicao_inicial.x-=5*TRANSLADA;
                           //    FIM DA ANIMAÇÃO DE TEXTURA
                           if(ativo){
                                ativo=0;
                           }else{
                                ativo=1;
                           }
   			}
   		}
   	}
      cheat=0;
   	if(p1.vida == 0||p2.vida == 0){
      if (p1.vida == 0) {
        glutTimerFunc(0,mage_3_Die,0);
      }else if(p2.vida == 0){
        glutTimerFunc(0,mage_4_Die,0);
      }
   	}
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
            A1.posicao.x=p1.posicao[0]+(LARGURAPERSONAGEM);
            A1.posicao.y=p1.posicao[1]+(ALTURAPERSONAGEM);
            A1.velocidade.x=0;
            A1.velocidade.y=0;
            A1.direcao=0;
            A1.posicao_inicial.x=A1.posicao.x;
            A1.posicao_inicial.y=A1.posicao.y;
            //Projetil o personagem 2
            A2.posicao.x=p2.posicao[0]-LARGURAPROJETIL;
            A2.posicao.y=p2.posicao[1]+(ALTURAPERSONAGEM);
            A2.velocidade.x=0;
            A2.velocidade.y=0;
            A2.direcao=0;
            A2.posicao_inicial.x=A2.posicao.x;
            A2.posicao_inicial.y=A2.posicao.y;
}
void geraTrajetoria(){
	int i,j,v=0;
   double x,y,velocidade_x,velocidade_y;
if(pause)
if(cheat){
      if(timer==0){
            if(ativo){
                x=A1.posicao.x+LARGURAPROJETIL;
                y=A1.posicao.y;
                velocidade_x=cos(PI*A1.direcao/180)*(velocidade/5);
                velocidade_y=sin(PI*A1.direcao/180)*(velocidade/5);
          }else{
                x=A2.posicao.x;
                y=A2.posicao.y;
                velocidade_x=(cos(PI*A2.direcao/180)*(velocidade/5))*(-1);
                velocidade_y=sin(PI*A2.direcao/180)*(velocidade/5);
               }

         glColor3f(1,0,0);
         glBegin(GL_LINES);

         for(j=0;j<LARGURA;j++){


               	glVertex3f(x,y,0);
               	x+=velocidade_x;
               	y+=velocidade_y;
               	velocidade_y-=gravidade;
                  if(v){
                        break;
                  }
                  if(x >= LARGURA || x+LARGURAPROJETIL <= 0)
                       {
                              v=1;
                       }
               // SE ACERTAR UM DOS PREDIOS
                for(i=0;i<NUMPREDIOS;i++){
                            if(ativo){
                              if(((x+LARGURAPROJETIL > mapa[i].cont) || (x > mapa[i].cont))  && ((x < mapa[i].cont+(LARGURA/NUMPREDIOS)) || (x+LARGURAPROJETIL < mapa[i].cont+(LARGURA/NUMPREDIOS)))){
                                    if(y <= mapa[i].y)
                                    v=1;
                              }
                        }else{
                              if(((x > mapa[i].cont) || (x+LARGURAPROJETIL > mapa[i].cont)) && ((x < mapa[i].cont+(LARGURA/NUMPREDIOS)) || (x+LARGURAPROJETIL < mapa[i].cont+(LARGURA/NUMPREDIOS)))){
                                    if(y <= mapa[i].y)
                                    v=1;
                              }
                        }
                  }
                  //SE ACERTAR O INIMIGO
                  if(ativo){
                  		if(x > p2.posicao[0] && x < p2.posicao[0]+LARGURAPERSONAGEM){
                  			if(y < p2.posicao[1]+ALTURAPERSONAGEM)
                                          v=1;
                  		}
                  	}else{
                  		if(x > p1.posicao[0] && x < p1.posicao[0]+LARGURAPERSONAGEM){
                  			if(y < p1.posicao[1]+ALTURAPERSONAGEM)
                                          v=1;
                  		}
                  	}

                  }
   glEnd();
                  }
         }

}


void geraAngulo(){
      int i;
      double x,y,velocidade_x,velocidade_y;
      if(pause)
      if(timer==0){
      if(ativo){
          x=A1.posicao.x+LARGURAPROJETIL;
          y=A1.posicao.y;
          velocidade_x=cos(PI*A1.direcao/180);
          velocidade_y=sin(PI*A1.direcao/180);
   }else{
          x=A2.posicao.x;
          y=A2.posicao.y;
          velocidade_x=cos(PI*A2.direcao/180)*(-1);
          velocidade_y=sin(PI*A2.direcao/180);
         }

      glColor3f(1,0,0);

      glBegin(GL_LINE_STRIP);

      for(i=0;i<70;i++)
      {
      glVertex3f(x,y,0);
      x+=velocidade_x;
      y+=velocidade_y;
      }
      glEnd();
}
}
