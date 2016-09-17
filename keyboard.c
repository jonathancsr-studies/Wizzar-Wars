#include "include.h"
PROJETIL A1,A2;
PERSONAGEM p1,p2;
int ativo;
int timer;
int pot;
int cheat;
int pause;
int forca;
int menu;
int i;
extern int TimerFunc_1_constant,TimerFunc_2_constant;
extern int ativa_projetil;
extern int texture_set_menu;
extern Mix_Music *somFundo,*somIntro ;
extern Mix_Chunk *somSpell_0,*somSpell_1,*somSpell_2,*somSpell_3,*somSpell_4;

void teclasPressionada(unsigned char key, int x, int y){
unsigned char aux;
aux = key;
  switch (key) {
    case 'q':
            break;
    case 27:
            if(menu != 0 && menu != 1 && menu != 2 && menu != 3 && menu!=4){
                texture_set_menu = 6;
                if(menu != 8 && menu != 7)
                {
                  menu = 6;

                }
                pause = 0;
            }
            if(menu == 4)
            {

              menu=0;
              texture_set_menu = 0;
            }
            break;
     case 'C':
     case 'c':
             if(timer==0){
             if(cheat){
                   cheat=0;
             }else{
                   cheat=1;
              }
             }
              break;
     case 'p':
     case 'P':
            if(menu == 0 || menu == 1 || menu == 2 || menu == 3 || menu == 4){

             }else{
                if(pause){
                  menu = 5;
                  texture_set_menu = 5;
                  pause = 0;
                }else{
                  pause = 1;
                }
            }
     break;
     case' ':
             if(forca==0)
             if(timer==0){
               ativa_projetil=1;
               TimerFunc_1_constant = 2;
               lancaProjetil();
               timer=1;
               int i;
               i = rand()%5;
               if(i == 0)
                 Mix_PlayChannel( -1, somSpell_0, 0 );
               else if(i == 1)
                 Mix_PlayChannel(-1 , somSpell_1, 0);
               else if(i == 2)
                 Mix_PlayChannel(-1, somSpell_2, 0);
               else if(i == 3)
                 Mix_PlayChannel(-1, somSpell_3, 0);
               else if(i == 4)
                 Mix_PlayChannel(-1, somSpell_4, 0);

              }
                break;
      case 70:
              glutFullScreen();
              break;
     case 13:if(menu==1 || menu ==2 || menu ==3){
                if(menu == 1){
                  reiniciaJogo();
                  menu = 10;
                  pause = 1;
                  Mix_HaltMusic();
                  Mix_PlayMusic(somFundo, -1);
                  barraForca();
                }else if(menu == 2){
                  menu = 4;
                  texture_set_menu = 4;
                }else if(menu == 3){
                  exit(0);
                }
             }else{
               printf("ok\n");
                if(forca){
                  forca=0;
                }else{
                  forca=1;
                }
           }
             break;
     case 'n':
     case 'N':if(menu == 7 || menu == 8)
              {
                if(menu == 7)
                    texture_set_menu = 7;
                else if(menu == 8)
                    texture_set_menu = 8;
              }else if(menu == 6)
              {
                    pause = 1;
                    break;
              }else if(menu == 9){
                pause = 1;
              }
              break;
     case 'r':
     case 'R':
             if(menu != 0 && menu != 1 && menu != 2 && menu != 3){
                  if(menu == 7 || menu ==8){
                    reiniciaJogo();
                    pause = 0;
                  }else{
                    texture_set_menu = 9;
                    menu = 9;
                    pause = 0;
                  }
              }
              break;
     case 's':
     case 'S':
                if(menu == 6){
                  menu = 0;
                  texture_set_menu = 0;
                  Mix_HaltMusic();
                  Mix_PlayMusic(somIntro, -1);
                break;
              }else if(menu == 9)
              {
                pause = 1;
                reiniciaJogo();

              }

     break;
     default:
     break;
  }
  glutPostRedisplay();
}

void setasPressionadas(int key_special, int x, int y){

  switch (key_special) {
if(timer==0){
      case GLUT_KEY_RIGHT:
        if(ativo){
            if(p1.posicao[0]<(LARGURA/NUMPREDIOS)-LARGURAPERSONAGEM){
                p1.posicao[0]+=TRANSLADA;
                A1.posicao.x+=TRANSLADA;
                A1.posicao_inicial.x+=TRANSLADA;
                TimerFunc_1_constant = 1;
                mage_3_Walk();
                TimerFunc_1_constant = 0;
        }
 }else{
            if(p2.posicao[0]<LARGURA-LARGURAPERSONAGEM){
                p2.posicao[0]+=TRANSLADA;
                A2.posicao.x+=TRANSLADA;
                A2.posicao_inicial.x+=TRANSLADA;
                TimerFunc_1_constant = 1;
                mage_4_Walk();
                TimerFunc_1_constant = 0;
            }
      }
      break;
    case GLUT_KEY_LEFT:
        if(ativo){
            if(p1.posicao[0]>0){
                p1.posicao[0]-=TRANSLADA;
                A1.posicao.x-=TRANSLADA;
                A1.posicao_inicial.x-=TRANSLADA;
                TimerFunc_1_constant = 1;
                mage_3_Walk();
                TimerFunc_1_constant = 0;
        }
            }else{
            if(p2.posicao[0]>(LARGURA - (LARGURA/NUMPREDIOS))){
                p2.posicao[0]-=TRANSLADA;
                A2.posicao.x-=TRANSLADA;
                A2.posicao_inicial.x-=TRANSLADA;
                TimerFunc_1_constant = 1;
                mage_4_Walk();
                TimerFunc_1_constant = 0;
            }
      }
      break;
      case GLUT_KEY_UP:
      if(menu != 0 && menu != 1 && menu != 2 && menu != 3){
            if(ativo){
                  if(A1.direcao < 90)
                   A1.direcao++;
            }
            else
                  if(A1.direcao < 90)
                   A2.direcao++;
      }else if(menu <=3){
          if(menu == 0)
          {
             menu = 1;
          }else if(menu == 1){
            menu = 3;
          }else{
            menu--;
          }
       texture_set_menu = menu;
     }


      break;
      case GLUT_KEY_DOWN:
        if(menu != 0 && menu != 1 && menu != 2 && menu != 3){
          if(ativo){
              if(A1.direcao > 0)
                 A1.direcao--;
          }
          else
          if(A2.direcao > 0)
                 A2.direcao--;
        }else if(menu <=3){
            if(menu == 0)
            {
               menu = 1;
            }else if(menu == 3){
              menu = 1;
            }else{
              menu++;
            }
         texture_set_menu = menu;
       }

      break;
     default:

               glutPostRedisplay();
        break;
  }
}
}
