#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <string.h>
#include <time.h>
#include "keyboard.h"
#include "draw.h"
//#include "menu.h"

//Estrutura que tem as variaveis do projetil
struct projetil{
  double x;
  double y;
};
void desenhaCena(){

  desenhaCenaInicialJogo();
  desenhaPersonagem(1);
  desenhaPersonagem(0);
}

void inicializa(void)
{
    glClearColor(1, 1, 1, 0);
}

void redimensionada(int width, int height)
{
   glViewport(0, 0, width, height);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0, 900.0, 0.0, 1440.0, -1.0, 1.0);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

int main(int argc, char **argv) {

      glutInit(&argc, argv);
      glutInitContextVersion(1,1);
      glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
      glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
      glutInitWindowSize(1440,900);
      glutInitWindowPosition(0,0);

      glutCreateWindow("Nome_do_Jogo");
      glutDisplayFunc(desenhaCena);
      glutReshapeFunc(redimensionada);
      glutKeyboardFunc(teclaPresionada);

      inicializa();
      glutMainLoop();
      return 0;
}
