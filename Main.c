#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <string.h>
#include <time.h>

//Estrutura que tem as variaveis do projetil
struct projetil{
  double x;
  double y;
};

void desenhaCenaInicialJogo(){
  int i,x,y;
double cont=10;
  glClear(GL_COLOR_BUFFER_BIT);
srand(time(0));
  glColor3f(0,0,1);
  glBegin(GL_TRIANGLE_STRIP);
  for(i=0;i<6;i++){
      y=200+rand()%600;
     //          x  y  z
      glVertex3f(0+cont,0,0);
      glVertex3f(150+cont,0,0);
      glVertex3f(150+cont,y,0);
      glVertex3f(0+cont,y,0);
      glVertex3f(0+cont,0,0);
      cont+=150;
    }
    glEnd();
    glFlush();
}
void desenhaCena(){

  desenhaCenaInicialJogo();


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
