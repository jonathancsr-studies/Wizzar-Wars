#ifndef CENARIO_H
#define CENARIO_H

typedef struct astro{

      VETOR posicao;
      VETOR velocidade;

}ASTRO;

typedef struct janela{

      float R,G,B;

}JANELA;

void criarRetangulo(double largura, double altura,unsigned int texture);
void desenhaCenaInicialJogo(PREDIOS predio[]);
void gerarMapa(PREDIOS* predio) ;
void planodeFundo();
void JogoRoda();
void telaPause();
void criaAstro();
void iniciaAstro();
void movimentoAstro();
void barraForca();
void vento_func();
void criaVento();
void desenha_Vento();
void reiniciaJogo(void);
void desenhaJanela();
void geraCorJanela();
#endif // CENARIO_H
