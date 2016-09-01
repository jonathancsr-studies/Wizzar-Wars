double global_py,global_uy;
void desenhaCenaInicialJogo(){
  int i,x,y;
double cont=0;
  glClear(GL_COLOR_BUFFER_BIT);
srand(time(0));
  glColor3f(0.5,1,1);

  for(i=0;i<8;i++){
      y=200+rand()%800;

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
      double x0,x1;
      //glClear(GL_COLOR_BUFFER_BIT);
      glColor3f(0,0,0);

      if(personagem==1){
        altura=global_uy;
        x0=830;
        x1=890;
      }else{
        altura=global_py;
        x0=10;
        x1=70;
      }

      for(i=0;i<4;i++){

        glBegin(GL_TRIANGLE_STRIP);

        glVertex2f(x0,altura);
        glVertex2f(x1,altura);
        glVertex2f(x1,altura+150);
        glVertex2f(x0,altura+150);
        glVertex2f(x0,altura);

        glEnd();
      }
      glFlush();
}
