#ifndef PERSONAGEM_H
#define PERSONAGEM_H

void movimentoPersonagem(float x,float y);
void desenhaPersonagem();
void inicializa_personagem();

typedef struct Personagem{
      double posicao[2];
      int vida;
}PERSONAGEM;

#endif
