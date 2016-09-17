#ifndef PERSONAGEM_H
#define PERSONAGEM_H


void movimentoPersonagem(float x,float y,int k);
void desenhaPersonagem();
void inicializa_personagem();
void criarPersonagem(double largura, double altura);
void  vida_texture();
void desenhaVida(int x, int y);
void desenhaVida_2(int x, int y);
typedef struct Personagem{
      double posicao[2];
      int vida;
}PERSONAGEM;

#endif
