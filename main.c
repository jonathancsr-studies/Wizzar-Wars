#include "include.h"

PREDIOS mapa[NUMPREDIOS];
extern double angulo=45;
extern double velocidade=300;
extern int ativo;
extern PROJETIL A1,A2;
extern PERSONAGEM p1,p2;
extern int timer;
extern int pot;
extern int pause=1;
extern ASTRO Sol;
extern int cheat=0;
void inicializa(void)
{
    ativo = 1;
    gerarMapa(mapa);
    inicializa_personagem();
    inicializa_Projetil();
    iniciaAstro();
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
  criaProjetil();
  criaAstro();
  telaPause();
  geraTrajetoria();
  glutSwapBuffers();
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
      glutTimerFunc(0,JogoRoda,0);

      inicializa();
      glutMainLoop();
      return 0;
}
