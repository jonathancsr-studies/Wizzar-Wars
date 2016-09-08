#include "include.h"
double velocidade;
int timer;
int pause;
int ativo;
double gravidade;
ASTRO Sol;
void criarRetangulo(double largura, double altura){
  glBegin(GL_TRIANGLE_FAN);
    glVertex3f(0,0,0);
    glVertex3f(largura,0,0);
    glVertex3f(largura,altura,0);
    glVertex3f(0,altura,0);
  glEnd();
}

void desenhaCenaInicialJogo(PREDIOS predio[]){
 int i;
for (i = 0; i < NUMPREDIOS; i++) {
                  glColor3f(1,0.5,0.6);

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

          y=300+rand()%500;
          predio[i].y=y;
          if(i==0||i==NUMPREDIOS-1){
            y=400+rand()%300;
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

void Timer(){



}

void JogoRoda(){

if(pause){
      if(timer)
      movimentoProjetil();
      barraForca();
}
      movimentoAstro();
      glutPostRedisplay();
      glutTimerFunc(20,JogoRoda,0);

}

void telaPause(){

      if(pause==0){
      glColor3f(0,1,0);
      criarRetangulo(LARGURA,ALTURA);

      }

}

void iniciaAstro(){

      Sol.posicao.x=LARGURA/16;
      Sol.posicao.y=((ALTURA/9)*7)-ALTURASOL;
      Sol.velocidade.x=0.106;
      Sol.velocidade.y=0.15;
      //Sol.velocidade.x=(7*LARGURA)/(4000);
      //Sol.velocidade.y=(2*ALTURA)/(4000);
}

void criaAstro(){

      glPushMatrix();
      glTranslatef(Sol.posicao.x,Sol.posicao.y,0);
      criarRetangulo(LARGURASOL,ALTURASOL);
      glPopMatrix();
}

void movimentoAstro(){

      Sol.posicao.x+=Sol.velocidade.x/3;
      Sol.posicao.y+=Sol.velocidade.y/3;
      Sol.velocidade.y-=0.00006/3;
}

void barraForca(){

    int cont=0,i,x=0,y;
    glTranslatef(LARGURA/2-50,25,0);
    glPushMatrix();
        glBegin(GL_TRIANGLE_FAN);
            glVertex3f(0,0,0);
            glVertex3f(x,0,0);
            glVertex3f(x,20,0);
            glVertex3f(0,20,0);
        glEnd();
    glPopMatrix();

    if(cont == 0)
    {
        x+=3;
        velocidade+=5;
        if(x>=100)
            cont=1;
    }else if(cont == 1)
    {
        x-=3;
        velocidade-=5;
        if(x<=0)
        {
            cont = 0;
        }
    }
}
