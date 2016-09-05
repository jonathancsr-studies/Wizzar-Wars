#include "include.h"

void criarRetangulo(double largura, double altura){
  glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0,0,0);
    glVertex3f(largura,0,0);
    glVertex3f(largura,altura,0);
    glVertex3f(0,altura,0);
  glEnd();
}

void desenhaCenaInicialJogo(PREDIOS predio[]){
 int i,x;



for (i = 0; i < NUMPREDIOS; i++) {
      x=rand()%6;
            //if(x==0){
                  glColor3f(0.512,0,0.512);
          //  }
          /* if(x==1){
                   glColor3f(0.5,0.5,0.5);
            }
            if(x==2){
                   glColor3f(0.5,0,0.9);
            }
            if(x==3){
                   glColor3f(0,1,0.);
            }
            if(x==4){
                   glColor3f(0,0,1);
            }
            if(x==5){
                   glColor3f(1,0,0);
            }*/

      glBegin(GL_TRIANGLE_FAN);
     //          x  y  z
            glVertex3f(0+predio[i].cont,0,0);
            glVertex3f(LARGURA/NUMPREDIOS+predio[i].cont,0,0);
            glVertex3f(LARGURA/NUMPREDIOS+predio[i].cont,predio[i].y,0);
            glVertex3f(0+predio[i].cont,predio[i].y,0);

      glEnd();

      }
}
void gerarMapa(PREDIOS* predio) {

     srand(time(0));
      int i;
      int cont=0,y;
      double global_py=0,global_uy=0;
      for(i=0;i<NUMPREDIOS;i++){

          y=500+rand()%400;
          predio[i].y=y;
          printf("%d alt %d\n",i,predio[i].y );
          if(i==0||i==NUMPREDIOS-1){
            y=300+rand()%600;
            predio[i].y=y;
            if(i==0){
              global_py=y;
          }else{
                global_uy=y;
            }
          }
          if((i==1||i==NUMPREDIOS-2)&& (y>global_py+100 || y>global_uy+100)){

                y-=200;
                predio[i].y=y;
          }
            predio[i].cont=cont;
            cont+=LARGURA/NUMPREDIOS;
      }
}

void planodeFundo(){
  glClear(GL_COLOR_BUFFER_BIT);
      glColor3f(0,0,0.3);
      criarRetangulo(LARGURA,ALTURA);
}
