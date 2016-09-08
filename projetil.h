#ifndef PROJETIL_H
#define PROJETIL_H

typedef struct Vetor{
      double x;
      double y;
}VETOR;

typedef struct Projetil{
      VETOR posicao;
      VETOR velocidade;
      VETOR posicao_inicial;
      int direcao;
}PROJETIL;

void movimentoProjetil();
void criaProjetil();
void lancaProjetil();
void inicializa_Projetil();
void geraTrajetoria();
void geraAngulo();
#endif
