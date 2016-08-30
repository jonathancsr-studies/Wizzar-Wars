#include <stdio.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

void inicializa (void){

  glClearColor(1,1,1,0);

}

void redimensiona(int w, int h) {

    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 100, 0, 100, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void desenha(double x,double y, double x2, double y2){

    glColor3f(0,1,0);
    glBegin(GL_TRIANGLE_STRIP);
   //          x  y  z
    glVertex3f(x+10,y+10,0);
    glVertex3f(x2+40,y+10,0);
    glVertex3f(x2+40,y2+30,0);
    glVertex3f(x+10,y2+30,0);
    glVertex3f(x+10,y+10,0);
    glEnd();
    glFlush();
}

void Botoes (void){
    glClear(GL_COLOR_BUFFER_BIT);
    //     x x2 y y2
    desenha(0,0,0,0);
    desenha(0,0,60,60);
    //desenha(0,100);
    //desenha(0,150);

}

void teclado (unsigned char key, int x, int y){

    switch(key)
    {
      case 27:
        exit(0);
        break;
      case 99:
      printf("OIE\n");
      break;
      default:
        break;

    }

}


int main(int argc, char **argv)
{

    glutInit(&argc, argv);

    glutInitContextVersion(1,1);
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(200,200);

    glutCreateWindow("Menu");

    inicializa();
    glutDisplayFunc(Botoes);
    glutReshapeFunc(redimensiona);
    glutKeyboardFunc(teclado);
    glutMainLoop();
    return 0;
}
