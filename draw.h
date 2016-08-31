void desenhaCenaInicialJogo(){
  int i,x,y;
double cont=0;
  glClear(GL_COLOR_BUFFER_BIT);
srand(time(0));
  glColor3f(0.5,1,1);

  for(i=0;i<8;i++){
      y=200+rand()%900;

      if(i==0||i==7)
        y+=200;

      if(y%2==0 && i!=0 && i!=7)
        cont-=12.5;
      glBegin(GL_TRIANGLE_STRIP);
     //          x  y  z
      glVertex3f(0+cont,0,0);
      glVertex3f(112.5+cont,0,0);
      glVertex3f(112.5+cont,y,0);
      glVertex3f(0+cont,y,0);
      glVertex3f(0+cont,0,0);

      if(y%2==0 && i!=0 && i!=7)
        cont+=125;
        else{
          cont+=112.5;
        }
            glEnd();
      }

    glFlush();
}
