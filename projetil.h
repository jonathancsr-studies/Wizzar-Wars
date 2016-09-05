#ifndef PROJETIL_H
#define PROJETIL_H
#include "include.h "

typedef struct Vetor{
      float x;
      float y;
}VETOR;

typedef struct Projetil{
      VETOR posicao;
      VETOR velocidade;
}PROJETIL;

void movimento();
void desenhaProjetil(double x,double y);
void lancaProjetil();
#endif
