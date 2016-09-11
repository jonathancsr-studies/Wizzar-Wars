#ifndef PERSONAGEM_H
#define PERSONAGEM_H


void movimentoPersonagem(float x,float y,int k);
void desenhaPersonagem();
void inicializa_personagem();
void criarPersonagem(double largura, double altura);

typedef struct Personagem{
      double posicao[2];
      int vida;
}PERSONAGEM;

#endif
