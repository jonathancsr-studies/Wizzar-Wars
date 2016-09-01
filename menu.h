void mouse(int button, int state, int x, int y)
{

}

void criarRetangulo(double largura, double altura,double x,double y,double c0,double c1,double c2)
{
  glPushMatrix();
  glTranslatef(x,y,0);
  glColor3f(c0,c1,c2);
  glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0,0,0);
    glVertex3f(largura,0,0);
    glVertex3f(largura,altura,0);
    glVertex3f(0,altura,0);
  glEnd();
  glPopMatrix();
}
void desenhaMenu()
{

  criarRetangulo(700,700,0,0,0.1,0.2,0.3);
  //LOGO
  criarRetangulo(500,200,100,450,0.5,0.6,0.8);
  //menu jogar
  criarRetangulo(200,100,260,280,0.5,0.6,0.3);
  //menu opções
  criarRetangulo(200,100,260,160,0.5,0.6,0.3);
  //menu sair
  criarRetangulo(200,100,260,40,0.5,0.6,0.3);

  glFlush();
}

void menuprincipal()
{


}

void menu(int item)
{
  switch (item) {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
  }
}
