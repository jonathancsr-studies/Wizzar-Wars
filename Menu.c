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

void desenha(void){

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);
    glBegin(GL_TRIANGLE_STRIP);
    glVertex3f(10,10,0);
    glVertex3f(10,20,0);
    glVertex3f(20,20,0);

    glEnd();
    glFlush();
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
    glutInitWindowPosition(100,100);

    glutCreateWindow("Menu");

    inicializa();
    glutDisplayFunc(desenha);
    glutReshapeFunc(redimensiona);
    glutKeyboardFunc(teclado);
    glutMainLoop();
    return 0;
}
