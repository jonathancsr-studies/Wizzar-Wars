#include "include.h"
PROJETIL A1,A2;
PERSONAGEM p1,p2;
int ativo;
int timer;
int pot;
double angulo;
void teclasPressionada(unsigned char key, int x, int y){
  switch (key) {
    case 82:
      //reiniciaJogo();
      break;
    case 27:
      exit(0);
      break;
     case 'C':
     case 'c':
     JogoRoda();
      break;
     case 'e':
     case 'E':
     if(timer){
           timer=0;
     }else{
           timer=1;
     }
     break;
     case' ':
     if(timer==0){
     timer=1;
    }
     lancaProjetil();
  glutTimerFunc(0,movimentoProjetil,0);
        break;
      case 70:
     glutFullScreen();
     case '1':
     if(pot==1){
           angulo+=1;
     }else{
           if(pot==0)
           angulo+=10;
     }
     break;
     case '2':
     if(pot==1){
          angulo+=2;
     }else{
           if(pot==0)
          angulo+=20;
     }
     break;
     case '3':
     if(pot==1){
           if(pot==0)
          angulo+=3;
     }else{
          angulo+=30;
     }
     break;
     case '4':
     if(pot==1){
           if(pot==0)
           angulo+=4;
     }else{
           angulo+=40;
     }
     break;
     case '5':
     if(pot==1){
           angulo+=5;
     }else{
           if(pot==0)
           angulo+=50;
     }
     break;
     case '6':
     if(pot==1){
           angulo+=6;
     }else{
           if(pot==0)
           angulo+=60;
     }
     break;
     case '7':
     if(pot==1){
           angulo+=7;
     }else{
           if(pot==0)
           angulo+=70;
     }
     break;
     case '8':
     if(pot==1){
           angulo+=8;
     }else{
           if(pot==0)
           angulo+=80;
     }
     break;
     case '9':
     if(pot==1){
           angulo+=9;
     }else{
           if(pot==0)
           angulo+=90;
     }
     break;
     case '0':
           angulo+=0;
     break;
     case 13:
     pot=0;
     break;
     default:
     break;
  }
  criaProjetil();
  glutPostRedisplay();
}

void setasPressionadas(unsigned char key, int x, int y){
  if(timer==0){
  switch (key) {
    case GLUT_KEY_RIGHT:
        if(ativo){
            if(p1.posicao[0]<(LARGURA/NUMPREDIOS)-LARGURAPERSONAGEM)
                p1.posicao[0]+=TRANSLADA;
        }
        else
            if(p2.posicao[0]<LARGURA-LARGURAPERSONAGEM)
                p2.posicao[0]+=TRANSLADA;
      break;
    case GLUT_KEY_LEFT:
        if(ativo){
            if(p1.posicao[0]>0)
                p1.posicao[0]-=TRANSLADA;
        }
        else
            if(p2.posicao[0]>(LARGURA - (LARGURA/NUMPREDIOS)))
                p2.posicao[0]-=TRANSLADA;
      break;
     default:
        break;
  }
  inicializa_Projetil();
  glutPostRedisplay();
 }
}
