#include "include.h"

PREDIOS mapa[NUMPREDIOS];

extern int ativo;
extern PROJETIL A1,A2;
extern PERSONAGEM p1,p2;
extern int timer;
void inicializa(void)
{
    ativo = 1;
    gerarMapa(mapa);
    inicializa_personagem();
    inicializa_Projetil();
    glClearColor(1, 1, 1, 0);
    glutPostRedisplay();
}

void redimensionada(int width, int height)
{
   glViewport(0, 0, width, height);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0, LARGURA, 0.0, ALTURA, -1.0, 1.0);
   //gluPerspective(30.0, (1440)/(900) , 1.0, 0.0);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

extern double angulo=30;
void desenhaCena(){

  planodeFundo();
  desenhaCenaInicialJogo(mapa);
  movimentoPersonagem(p1.posicao[0],p1.posicao[1]);
  movimentoPersonagem(p2.posicao[0],p2.posicao[1]);
  criaProjetil();
  glutSwapBuffers();
}

void teclasPressionada(unsigned char key, int x, int y){
  switch (key) {
   // case 80:
      //pause();
      //break;
    case 82:
      //reiniciaJogo();
      break;
    case 27:
      exit(0);
      break;
    case 'j':
//if(ativo){
   //         ativo=0;
 //     }else{
    //        ativo=1;
  //    }
     // 
      break;
     case 'C':
     case 'c':
     //geraTrajetoria();
      break;
     case 'e':
     case 'E':
     break;
     case' ':
     if(timer==0){
     timer=1;
        lancaProjetil();
        glutTimerFunc(0,movimentoProjetil,0);
    }
        break;
      case 70:
     glutFullScreen();
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

int main(int argc, char **argv) {
      glutInit(&argc, argv);
      glutInitContextVersion(1,1);
      glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
      glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
      glutInitWindowSize(ALTURA,LARGURA);
      glutInitWindowPosition(0,0);
      glutCreateWindow("JOGO");

      glutDisplayFunc(desenhaCena);
      glutReshapeFunc(redimensionada);
      glutKeyboardFunc(teclasPressionada);
      glutSpecialFunc(setasPressionadas);
//      glutMouseFunc(mouse);

      inicializa();
      glutMainLoop();
      return 0;
}
