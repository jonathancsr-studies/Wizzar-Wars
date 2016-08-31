void desenhaCenaInicialJogo(){
  int i,x,y;
double cont=0;
  glClear(GL_COLOR_BUFFER_BIT);
srand(time(0));
  glColor3f(0.5,1,1);

  for(i=0;i<8;i++){
      y=200+rand()%900;

      if(i==0||i==7){
        y+=200;
        if(i==0)
          global_py=y;
          else{
            global_uy=y;
          }
      }
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

void desenhaPersonagem(int personagem){

      int i;
      double altura;
      glClear(GL_COLOR_BUFFER_BIT);
      glColor3f(0,0,0);

      if(personagem==1){
        altura=global_uy;
      }else{
        altura=global_py;
      }

      for(i=0;i<4;i++){

        glBegin(GL_TRIANGLE_STRIP);

        glVertex2f(10,altura);
        glVertex2f(30,altura);
        glVertex2f(30,altura+40);
        glVertex2f(10,altura+40);
        glVertex2f(10,altura);

        glEnd();
      }
      glFlush();
}
