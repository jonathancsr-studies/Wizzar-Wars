#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <string.h>

//Estrutura que tem as variaveis do projetil
struct projetil{
  double x;
  double y;
};


void desenhaCenaInicialJogo(){




  glutSwapBuffers();
}

void teclaPresionada(unsigned char key, int x, int y){

  switch (key) {
    case 27:
      exit(0);
      break;
    default:
      break;
  }

}

void redimensionada(int width, int height)
{
   glViewport(0, 0, width, height);

   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

int main(int argc, char const *argv) {
  glutIniti(&argc , argv);

  glutInitContextVersion(1, 1);
  glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

  glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
  glutInitWindowSize(800,600);
  glutInitWindowPosition(200, 200);

  glutCreateWindow("Nome_do_Jogo");

  glutDisplayFunc(desenhaCenaInicialJogo);
  glutReshapeFunc(redimensionada);
  glutKeyboardFunc(teclaPresionada);

  glutMainLoop();
  return 0;
}
