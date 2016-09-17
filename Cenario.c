
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
int vento;
extern int vento_set;
JANELA window [10000];

PREDIOS mapa [NUMPREDIOS];
extern GLuint fundo,lua,vento_texture;

void reiniciaJogo(void){
    ativo = 1;
    gerarMapa(mapa);
    inicializa_personagem();
    inicializa_Projetil();
    iniciaAstro();
    glClearColor(0, 0, 0, 0);
    glutPostRedisplay();
}

void criarRetangulo(double largura, double altura,unsigned int texture){

  if(texture != 0){
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);
   }
  glBegin(GL_TRIANGLE_FAN);
    glTexCoord2f(0.0, 0.0); glVertex3f(0,0,0);
    glTexCoord2f(1.0, 0.0); glVertex3f(largura,0,0);
    glTexCoord2f(1.0, 1.0); glVertex3f(largura,altura,0);
    glTexCoord2f(0.0, 1.0); glVertex3f(0,altura,0);


  glEnd();
  glDisable(GL_TEXTURE_2D);
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

void geraCorJanela(){
      int i,j,k,d,cont=0;
      for(i=0;i<NUMPREDIOS;i++)
      {
            for(j=30;j<mapa[i].y-25;j+=30){
                  for(k=0;k<3;k++)
                  {
                        d=rand()%10;
                        if(d<4){
                        window[cont].R=0;
                        window[cont].G=0;
                        window[cont].B=0;
                        }
                        if (d>= 3) {
                        window[cont].R=0.8;
                        window[cont].G=0.6;
                        window[cont].B=0.1;
                        }
                        cont++;
                  }
            }
      }
}

void desenhaJanela(){
if(pause){
      int i,j,k,numjanelas=0;
      float cont;
      for(i=0;i<NUMPREDIOS;i++)
      {
            for(j=30;j<mapa[i].y-25;j+=30){
              cont = (LARGURA/NUMPREDIOS/9);
                  for(k=0;k<3;k++)
                  {
                        glColor3f(window[numjanelas].R,window[numjanelas].G,window[numjanelas].B);
                        glBegin(GL_TRIANGLE_FAN);
                          glVertex3f(mapa[i].cont+cont,j,0);
                          glVertex3f(mapa[i].cont+cont+10,j,0);
                          glVertex3f(mapa[i].cont+cont+10,j+20,0);
                          glVertex3f(mapa[i].cont+cont,j+20,0);

                        glEnd();
                  cont+=(2*(LARGURA/NUMPREDIOS/7));
                  numjanelas++;
                  }
            }
      }
}
}

void planodeFundo(){
  glClear(GL_COLOR_BUFFER_BIT);
      glColor3f(0,0,0.3);
      criarRetangulo(800,1300,fundo);
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
      glutTimerFunc(20,JogoRoda,0);

}

void telaPause(){

      if(pause==0){

      criarRetangulo(LARGURA,ALTURA,menu_texture);
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
      criarRetangulo(LARGURASOL,ALTURASOL,lua);
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

void vento_func(){
      srand(time(0));
      int i,f_vento,l_vento;
      // d=0 esquerda d=1 direita

      f_vento=rand()%100;
      l_vento=rand()%10;

      if(l_vento >= 0 && l_vento <= 5)
         l_vento=0;
      else
         l_vento=1;
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
void criaVento(){
      srand(time(0));
      int f_vento;

      f_vento = rand()%5;

      if(f_vento>2){
      vento = f_vento*(-1);
      }else{
      vento = f_vento;
      }
      desenha_texture_vento();
}
void desenha_texture_vento(){

        if(vento == 0){
          vento_set = 0;
        }else if(vento == 1) {
          if(ativo)
            vento_set = 1;
          else
            vento_set = 4;
        }else if(vento == 2) {
          if(ativo)
            vento_set = 2;
          else
            vento_set = 5;
        }else if(vento >= 3 ){
          if(ativo)
            vento_set = 3;
          else
            vento_set = 6;
        }else if (vento == -1) {
          if(ativo)
            vento_set = 4;
          else
            vento_set = 1;
        }else if (vento == -2) {
          if(ativo)
            vento_set = 5;
          else
            vento_set = 2;
        }else if (vento <= -3) {
          if(ativo)
            vento_set = 6;
          else
            vento_set = 3;
        }
        glutTimerFunc(80,desenha_texture_vento,1);
}
void desenha_Vento(){

  glPushMatrix();
    glTranslatef(LARGURA/2-190,1120,0);
    glColor3f(1,1,1);
    criarRetangulo(100,150,vento_texture);
  glPopMatrix();
}
