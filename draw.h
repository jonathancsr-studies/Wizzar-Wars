void desenhaCenaInicialJogo(){
  int i,x,y;
double cont=0;
  glClear(GL_COLOR_BUFFER_BIT);
  srand(time(0));
  glColor3f(0,0,1);
  glBegin(GL_TRIANGLE_STRIP);
  for(i=0;i<12;i++){
      y=205+rand()%600;
     //          x  y  z
      glVertex3f(0+cont,0,0);
      glVertex3f(150+cont,0,0);
      glVertex3f(150+cont,y,0);
      glVertex3f(0+cont,y,0);
      glVertex3f(0+cont,0,0);
      cont+=75;
    }
    glEnd();
    glFlush();
}
