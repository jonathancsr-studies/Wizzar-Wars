#include "include.h"

PREDIOS mapa[NUMPREDIOS];
extern double velocidade = 0;
extern int ativo;
extern PROJETIL A1,A2;
extern PERSONAGEM p1,p2;
extern int timer;
extern double gravidade= 0.1;
extern int pot;
extern int pause=1;
extern ASTRO Sol;
extern int cheat=0;
extern int new_w=0;
extern int new_h=0;
extern int forca = 1;

void inicializa(void)
{
    ativo = 1;
    gerarMapa(mapa);
    inicializa_personagem();
    inicializa_Projetil();
    iniciaAstro();
    glClearColor(0, 0, 0, 0);
    glutPostRedisplay();

}
void redimensionada(int w, int h)
{
    double area=w/h;

      if(area > 16/9)
      {
      new_w=(h/16)*16;
      new_h=(h/16)*9;

      }else{

      new_w=(w/16)*16;
      new_h=(w/16)*9;

      }
   glViewport((w-new_w)/2,(h-new_h)/2,new_w,new_h);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0, LARGURA, 0.0, ALTURA, -1.0, 1.0);

   glMatrixMode(GL_MODELVIEW);
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
  barraForca();
  geraAngulo();
  glutSwapBuffers();
}
void Idle()
{
  glutPostRedisplay();
}
int main(int argc, char **argv) {

      glutInit(&argc, argv);
      glutInitContextVersion(1,1);
      glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
      glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
      glutInitWindowSize(ALTURA,LARGURA);
      glutInitWindowPosition(0,0);
      glutCreateWindow("JOGO");

      glutDisplayFunc(desenhaCena);
      glutReshapeFunc(redimensionada);
      glutKeyboardFunc(teclasPressionada);
      glutSpecialFunc(setasPressionadas);
      glutIdleFunc(Idle);
//      glutMouseFunc(mouse);
      glutTimerFunc(0,JogoRoda,0);
      glutTimerFunc(50,mage_3_Idle,0);

      inittexture();
      inicializa();
      glutMainLoop();
      return 0;
}
