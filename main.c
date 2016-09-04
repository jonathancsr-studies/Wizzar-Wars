#include "include.h"
PREDIOS mapa[NUMPREDIOS];

PERSONAGEM p1,p2;



void inicializa(void)
{
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



void desenhaCena(){

  planodeFundo();
  desenhaCenaInicialJogo(mapa);
  movimentoPersonagem(p1.posicao[0],p1.posicao[1]);
  movimentoPersonagem(p2.posicao[0],p2.posicao[1]);
  desenhaProjetil();
}

void teclaPresionada(unsigned char key, int x, int y){
  switch (key) {
    case 80:
      //pause();
      break;
    case 82:
      //reiniciaJogo();
      break;
    case 27:
      exit(0);
      break;
    case 'd':
      if(p1.posicao[0]<LARGURA/NUMPREDIOS-60)
            p1.posicao[0]+=TRANSLADA;
      glutPostRedisplay();
      break;
    case 'a':
      if(p1.posicao[0]>0)
            p1.posicao[0]-=TRANSLADA;
      glutPostRedisplay();
      break;
    case 'j':
      if(p2.posicao[0]>(LARGURA - (LARGURA/NUMPREDIOS)))
            p2.posicao[0]-=TRANSLADA;
      glutPostRedisplay();
      break;

    case 'l':
      if(p2.posicao[0]<LARGURA-60)
            p2.posicao[0]+=TRANSLADA;
      glutPostRedisplay();
      break;
     case' ':
      //glutTimerFunc(0,movimento,0);
     break;
      case 70:
     glutFullScreen();
     default:
     break;

  }

}

int main(int argc, char **argv) {

      gerarMapa(mapa);
      p1.posicao[0]=10;
      p2.posicao[0]=830;
      p1.posicao[1]=mapa[0].y;
      p2.posicao[1]=mapa[NUMPREDIOS-1].y;
      glutInit(&argc, argv);

      glutInitContextVersion(1,1);
      glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
      glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
      glutInitWindowSize(ALTURA,LARGURA);
      glutInitWindowPosition(0,0);
      glutCreateWindow("Piroca");

      glutDisplayFunc(desenhaCena);
      glutReshapeFunc(redimensionada);
      glutKeyboardFunc(teclaPresionada);
//      glutMouseFunc(mouse);

      inicializa();
      glutMainLoop();
      return 0;
}
