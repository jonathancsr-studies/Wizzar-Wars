double pos=0;
void movimentoPersonagem(){
      int i;

      glPushMatrix();                 // Importante!!

      glTranslatef(10+pos,global_py, 0);
            pos+=5;
            glBegin(GL_TRIANGLE_FAN);

              glVertex2f(0,0);
              glVertex2f(60,0);
              glVertex2f(60,150);
              glVertex2f(0,150);

            glEnd();

      glPopMatrix();                  // Importante!!


}
