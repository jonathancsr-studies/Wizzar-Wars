
#include "include.h"
double velocidade;
int timer,j;
int pause;
int ativo;
double gravidade;
PROJETIL A1,A2;
ASTRO Sol;
int varia=0;
int forca;
PREDIOS mapa [NUMPREDIOS];

void reiniciaJogo(void){
    ativo = 1;
    gerarMapa(mapa);
    inicializa_personagem();
    inicializa_Projetil();
    iniciaAstro();
    glClearColor(0, 0, 0, 0);
    glutPostRedisplay();
}

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

      glColor3f(0.501, 0.501, 0.501);

      glBegin(GL_TRIANGLE_FAN);
     //          x  y  z
            glVertex3f(0+predio[i].cont,0,0);
            glVertex3f(LARGURA/NUMPREDIOS+predio[i].cont-5,0,0);
            glVertex3f(LARGURA/NUMPREDIOS+predio[i].cont-5,predio[i].y,0);
            glVertex3f(0+predio[i].cont,predio[i].y,0);
      glEnd();
/*for (j = 0; j < ; j++) {
  glColor3f(0)


}*/
      glColor3f(0.3, 0.3, 0.3);
      glBegin(GL_TRIANGLE_FAN);
     //          x  y  z
            glVertex3f(0+predio[i].cont+55,0,0);
            glVertex3f(LARGURA/NUMPREDIOS+predio[i].cont,0,0);
            glVertex3f(LARGURA/NUMPREDIOS+predio[i].cont,predio[i].y-10,0);
            glVertex3f(0+predio[i].cont+55,predio[i].y,0);
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
//  glEnable(GL_TEXTURE_2D);
//  glBindTexture(GL_TEXTURE_2D, texturaMario);
      criarRetangulo(LARGURA,ALTURA);
//  glDisable(GL_TEXTURE_2D);
}

void Timer(){
}

void JogoRoda(){
if(pause){
      if(timer)
      movimentoProjetil();
      movimentoAstro();
      if(forca){
                  barraForca();
                  velocidade+=varia;
                  if(velocidade==0){
                  varia = 1;
                  }else{
                  if(velocidade==100)
                  varia =-1;
            }
      }
}
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

      if(pause){
      glColor3f(1,0,0);
      glBegin(GL_TRIANGLE_FAN);
      glVertex3f((LARGURA/2)-50,ALTURA-40,0);
      glVertex3f((LARGURA/2)-50+velocidade,ALTURA-40,0);
      glVertex3f((LARGURA/2)-50+velocidade,ALTURA-10,0);
      glVertex3f((LARGURA/2)-50,ALTURA-10,0);
      glEnd();
      }
}

void vento(){
      srand(time(0));
      int i,f_vento,l_vento;
      // d=0 esquerda d=1 direita

      f_vento=rand()%100;
      l_vento=rand()%10;

      if(l_vento >= 0 && l_vento <= 5)
         l_vento=0;
      else
         l_vento=1;

      if(l_vento == 0)
         printf("Vento para <<<\nvelocidade = %d\n",f_vento);
      if(l_vento == 1)
         printf("Vento para >>>\nvelocidade = %d\n",f_vento);

      if(ativo)
      {
         if(l_vento==0)
              A1.velocidade.x-=f_vento;
         else if(l_vento==1)
              A1.velocidade.x+=f_vento;
      }else{
         if(l_vento==0)
              A2.velocidade.x+=f_vento;
         else if(l_vento==1)
              A2.velocidade.x-=f_vento;
      }
}
