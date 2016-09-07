#ifndef CENARIO_H
#define CENARIO_H

typedef struct astro{

      VETOR posicao;
      VETOR velocidade;

}ASTRO;

void criarRetangulo(double largura, double altura);
void desenhaCenaInicialJogo(PREDIOS predio[]);
void gerarMapa(PREDIOS* predio) ;
void planodeFundo();
void JogoRoda();
void telaPause();
void criaAstro();
void iniciaAstro();
void movimentoAstro();
#endif // CENARIO_H
