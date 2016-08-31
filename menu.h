




void desenhaMenu()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,1);
    glBegin(GL_TRIANGLE_FAN);
      glVertex3f(0,0,0);
      glVertex3f(1280,0,0);
      glVertex3f(1280,768,0);
      glVertex3f(0,768,0);
    glEnd();
    glColor3f(0,1,0);
    glBegin(GL_TRIANGLE_STRIP);
      glVertex3f(540,50,0);
      glVertex3f(540,0,0);
      glVertex3f(1280,768,0);
      glVertex3f(0,768,0);
    glEnd();

    glFlush();

}



void menuprincipal()
{


}
