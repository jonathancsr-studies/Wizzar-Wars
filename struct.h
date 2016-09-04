#define  LARGURA 900
#define  ALTURA 1440
#define  TRANSLADA 1
#define NUMPREDIOS 12
#define  LARGURA 900
#define  ALTURA 1440
#define GRAVIDADE 9.8
#define ANGULO 0
#define VELOCIDADE 20
#define LARGURAPERSONAGEM 60
#define ALTURAPERSONAGEM 150

typedef struct Vetor{
      float x;
      float y;
}VETOR;

typedef struct Personagem{
      double posicao[2];
}PERSONAGEM;

typedef struct Predios{
      int y;
      int cont;
}PREDIOS;
typedef struct Projetil{
      VETOR posicao;
      VETOR velocidade;

}PROJETIL;
