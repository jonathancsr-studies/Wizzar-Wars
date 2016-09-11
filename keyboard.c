#include "include.h"
PROJETIL A1,A2;
PERSONAGEM p1,p2;
int ativo;
int timer;
int pot;
int cheat;
int pause;
int forca;

void teclasPressionada(unsigned char key, int x, int y){
  switch (key) {
    case 27:
      exit(0);
      break;
     case 'C':
     case 'c':
     if(timer==0){
     if(cheat){
           cheat=0;
     }else{
           cheat=1;
      }
     }
      break;
     case 'p':
     case 'P':
     if(pause){
           pause=0;
     }else{
           pause=1;
     }
     //telaPause();
     break;
     case' ':
    if(forca==0)
     if(timer==0){
     lancaProjetil();
     timer=1;
      }
        break;
      case 70:
     glutFullScreen();
     break;
     case 13:
     if(forca){
          forca=0;
     }else{
          forca=1;
     }
     break;
     case 'r':
     case 'R':
     reiniciaJogo();
     break;
     default:
     break;
  }
  glutPostRedisplay();
}

void setasPressionadas(unsigned char key, int x, int y){
if(pause)
  if(timer==0){
  switch (key) {
    case GLUT_KEY_RIGHT:
        if(ativo){
            if(p1.posicao[0]<(LARGURA/NUMPREDIOS)-LARGURAPERSONAGEM){
                p1.posicao[0]+=TRANSLADA;
                A1.posicao.x+=TRANSLADA;
                A1.posicao_inicial.x+=TRANSLADA;
        }
 }else{
            if(p2.posicao[0]<LARGURA-LARGURAPERSONAGEM){
                p2.posicao[0]+=TRANSLADA;
                A2.posicao.x+=TRANSLADA;
                A2.posicao_inicial.x+=TRANSLADA;
            }
      }
      mage_3_Idle();
      break;
    case GLUT_KEY_LEFT:
        if(ativo){
            if(p1.posicao[0]>0){
                p1.posicao[0]-=TRANSLADA;
                A1.posicao.x-=TRANSLADA;
                A1.posicao_inicial.x-=TRANSLADA;
        }
            }else{
            if(p2.posicao[0]>(LARGURA - (LARGURA/NUMPREDIOS))){
                p2.posicao[0]-=TRANSLADA;
                A2.posicao.x-=TRANSLADA;
                A2.posicao_inicial.x-=TRANSLADA;
            }
      }
      break;
      case GLUT_KEY_UP:
      if(ativo){
            if(A1.direcao < 90)
             A1.direcao++;
      }
      else
            if(A1.direcao < 90)
             A2.direcao++;
      break;
      case GLUT_KEY_DOWN:
      if(ativo){
          if(A1.direcao > 0)
             A1.direcao--;
      }
      else
      if(A2.direcao > 0)
             A2.direcao--;
      break;
     default:
        break;
  }
//  glutPostRedisplay();
 }
}
