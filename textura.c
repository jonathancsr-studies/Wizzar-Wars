#include "include.h"
extern int ativa_projetil;
extern int vento,ativo;
extern PERSONAGEM p1,p2;
int cont=0;

unsigned int loadTexture(char nometextura[]){
    glClearColor (1, 1, 1, 0);

    tex = SOIL_load_OGL_texture(
        nometextura,
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
    SOIL_FLAG_INVERT_Y
      );

    glEnable( GL_BLEND );
    glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );


    if (tex == 0) {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }
    return tex;
}
void carrega_textura() {
  mage_3_texture[0]=loadTexture("./Mage_3/mage_3_Idle_0.png");
  mage_3_texture[1]=loadTexture("./Mage_3/mage_3_Idle_1.png");
  mage_3_texture[2]=loadTexture("./Mage_3/mage_3_Idle_2.png");
  mage_3_texture[3]=loadTexture("./Mage_3/mage_3_Idle_3.png");
  mage_3_texture[4]=loadTexture("./Mage_3/mage_3_Idle_4.png");
  mage_3_texture[5]=loadTexture("./Mage_3/mage_3_Idle_5.png");
  mage_3_texture[6]=loadTexture("./Mage_3/mage_3_Walk_0.png");
  mage_3_texture[7]=loadTexture("./Mage_3/mage_3_Walk_1.png");
  mage_3_texture[8]=loadTexture("./Mage_3/mage_3_Walk_2.png");
  mage_3_texture[9]=loadTexture("./Mage_3/mage_3_Walk_3.png");
  mage_3_texture[10]=loadTexture("./Mage_3/mage_3_Walk_4.png");
  mage_3_texture[11]=loadTexture("./Mage_3/mage_3_Walk_5.png");
  mage_3_texture[12]=loadTexture("./Mage_3/mage_3_Walk_6.png");
  mage_3_texture[13]=loadTexture("./Mage_3/mage_3_Walk_7.png");
  mage_3_texture[14]=loadTexture("./Mage_3/mage_3_Atack_0.png");
  mage_3_texture[15]=loadTexture("./Mage_3/mage_3_Atack_1.png");
  mage_3_texture[16]=loadTexture("./Mage_3/mage_3_Atack_2.png");
  mage_3_texture[17]=loadTexture("./Mage_3/mage_3_Atack_3.png");
  mage_3_texture[18]=loadTexture("./Mage_3/mage_3_Atack_4.png");
  mage_3_texture[19]=loadTexture("./Mage_3/mage_3_Atack_5.png");
  mage_3_texture[20]=loadTexture("./Mage_3/mage_3_Atack_6.png");
  mage_3_texture[21]=loadTexture("./Mage_3/mage_3_Damage_0.png");
  mage_3_texture[22]=loadTexture("./Mage_3/mage_3_Damage_1.png");
  mage_3_texture[23]=loadTexture("./Mage_3/mage_3_Damage_2.png");
  mage_3_texture[24]=loadTexture("./Mage_3/mage_3_Damage_3.png");
  mage_3_texture[25]=loadTexture("./Mage_3/mage_3_Damage_4.png");
  mage_3_texture[26]=loadTexture("./Mage_3/mage_3_Die_0.png");
  mage_3_texture[27]=loadTexture("./Mage_3/mage_3_Die_1.png");
  mage_3_texture[28]=loadTexture("./Mage_3/mage_3_Die_2.png");
  mage_3_texture[29]=loadTexture("./Mage_3/mage_3_Die_3.png");
  mage_3_texture[30]=loadTexture("./Mage_3/mage_3_Die_4.png");
  mage_3_texture[31]=loadTexture("./Mage_3/mage_3_Die_5.png");
  mage_3_texture[32]=loadTexture("./Mage_3/mage_3_projetil_idle_0.png");
  mage_3_texture[33]=loadTexture("./Mage_3/mage_3_projetil_idle_1.png");
  mage_3_texture[34]=loadTexture("./Mage_3/mage_3_projetil_idle_2.png");
  mage_3_texture[35]=loadTexture("./Mage_3/mage_3_projetil_idle_3.png");
  mage_3_texture[36]=loadTexture("./Mage_3/mage_3_projetil_idle_4.png");
  mage_3_texture[37]=loadTexture("./Mage_3/mage_3_projetil_idle_5.png");
  mage_3_texture[38]=loadTexture("./Mage_3/mage_3_projetil_colision_1.png");
  mage_3_texture[39]=loadTexture("./Mage_3/mage_3_projetil_colision_2.png");
  mage_3_texture[40]=loadTexture("./Mage_3/mage_3_projetil_colision_3.png");
  mage_3_texture[41]=loadTexture("./Mage_3/mage_3_projetil_colision_4.png");
  mage_3_texture[42]=loadTexture("./Mage_3/mage_3_projetil_colision_5.png");
  mage_3_texture[43]= loadTexture("./Mage_3/mage_3_projetil_colision_6.png");


  mage_4_texture[0]=loadTexture("./Mage_4/mage_4_Idle.png");
  mage_4_texture[1]=loadTexture("./Mage_4/mage_4_Idle.png");
  mage_4_texture[2]= loadTexture("./Mage_4/mage_4_Andando_0.png");
  mage_4_texture[3]=loadTexture("./Mage_4/mage_4_Andando_1.png");
  mage_4_texture[4]=loadTexture("./Mage_4/mage_4_Andando_2.png");
  mage_4_texture[5]=loadTexture("./Mage_4/mage_4_Andando_3.png");
  mage_4_texture[6]=loadTexture("./Mage_4/mage_4_Andando_4.png");
  mage_4_texture[7]=loadTexture("./Mage_4/mage_4_Andando_5.png");
  mage_4_texture[8]=loadTexture("./Mage_4/mage_4_Andando_6.png");
  mage_4_texture[9]=loadTexture("./Mage_4/mage_4_Andando_7.png");
  mage_4_texture[10]=loadTexture("./Mage_4/mage_4_Ataque_0.png");
  mage_4_texture[11]=loadTexture("./Mage_4/mage_4_Ataque_1.png");
  mage_4_texture[12]=loadTexture("./Mage_4/mage_4_Ataque_2.png");
  mage_4_texture[13]=loadTexture("./Mage_4/mage_4_Ataque_3.png");
  mage_4_texture[14]=loadTexture("./Mage_4/mage_4_Ataque_1.png");
  mage_4_texture[15]=loadTexture("./Mage_4/mage_4_Ataque_0.png");
  mage_4_texture[16]=loadTexture("./Mage_4/mage_4_dano.png");
  mage_4_texture[17]=loadTexture("./Mage_4/mage_4_Ataque_1.png");
  mage_4_texture[18]=loadTexture("./Mage_4/mage_4_Ataque_0.png");
  mage_4_texture[19]=loadTexture("./Mage_4/mage_4_morrendo_0.png");
  mage_4_texture[20]=loadTexture("./Mage_4/mage_4_morrendo_1.png");
  mage_4_texture[21]=loadTexture("./Mage_4/mage_4_morrendo_2.png");
  mage_4_texture[22]=loadTexture("./Mage_4/mage_4_morrendo_3.png");
  mage_4_texture[23]=loadTexture("./Mage_4/mage_4_projetil_idle_0.png");
  mage_4_texture[24]=loadTexture("./Mage_4/mage_4_projetil_idle_1.png");
  mage_4_texture[25]=loadTexture("./Mage_4/mage_4_projetil_idle_2.png");
  mage_4_texture[26]=loadTexture("./Mage_4/mage_4_projetil_idle_3.png");
  mage_4_texture[27]=loadTexture("./Mage_4/mage_4_projetil_idle_4.png");
  mage_4_texture[28]=loadTexture("./Mage_4/mage_4_projetil_idle_5.png");
  mage_4_texture[29]=loadTexture("./Mage_4/mage_4_projetil_colision_1.png");
  mage_4_texture[30]=loadTexture("./Mage_4/mage_4_projetil_colision_2.png");
  mage_4_texture[31]=loadTexture("./Mage_4/mage_4_projetil_colision_3.png");
  mage_4_texture[32]=loadTexture("./Mage_4/mage_4_projetil_colision_4.png");
  mage_4_texture[33]=loadTexture("./Mage_4/mage_4_projetil_colision_5.png");


  vento_texture_v[0]=loadTexture("./vento/v_0.png");
  vento_texture_v[1]=loadTexture("./vento/v_d_01.png");
  vento_texture_v[2]=loadTexture("./vento/v_d_02.png");
  vento_texture_v[3]=loadTexture("./vento/v_d_03.png");
  vento_texture_v[4]=loadTexture("./vento/v_e_01.png");
  vento_texture_v[5]=loadTexture("./vento/v_e_02.png");
  vento_texture_v[6]=loadTexture("./vento/v_e_03.png");


  menu_texture_v[0] = loadTexture("./menus/menu.png");
  menu_texture_v[1] = loadTexture("./menus/menu_WWITC_hover_jogar.png");
  menu_texture_v[2] = loadTexture("./menus/menu_WWITC_hover_creditos.png");
  menu_texture_v[3] = loadTexture("./menus/menu_WWITC_hover_Sair.png");
  menu_texture_v[4] = loadTexture("./menus/creditos.png");
  menu_texture_v[5] = loadTexture("./menus/menu_Pause.png");
  menu_texture_v[6] = loadTexture("./menus/menu_sair.png");
  menu_texture_v[7] = loadTexture("./menus/ganhou_1.png");
  menu_texture_v[8] = loadTexture("./menus/ganhou_2.png");
  menu_texture_v[9] = loadTexture("./menus/menu_reiniciar.png");


  vida_texture_f[0]= loadTexture("./vidas/jogador_1_vida_3.png");
  vida_texture_f[1]= loadTexture("./vidas/jogador_1_vida_2.png");
  vida_texture_f[2]= loadTexture("./vidas/jogador_1_vida_1.png");
  vida_texture_f[3]= loadTexture("./vidas/jogador_1_vida_0.png");
  vida_texture_f[4]= loadTexture("./vidas/j3.png");
  vida_texture_f[5]= loadTexture("./vidas/j2.png");
  vida_texture_f[6]= loadTexture("./vidas/j1.png");
  vida_texture_f[7]= loadTexture("./vidas/j.png");


  fundo = loadTexture("./util/fundo.png");
  lua = loadTexture("./util/moon.png");

}


void inittexture(){
  mage_3_Idle();
  mage_4_Idle();
  Mage_3_projetil_idle();
  Mage_4_projetil_idle();
  textura_vento();
  carrega_textura();
  texture_set_menu = 0;

}

void TimerFunc_1(){
  if (TimerFunc_1_constant == 0) {
      texture_set_1 = 0;
      mage_3_Idle();
  }else if(TimerFunc_1_constant == 1){
      texture_set_1 = 0;
      mage_3_Walk();
  }else if(TimerFunc_1_constant == 2){
      texture_set_1 = 0;
      mage_3_Attack();
  }else if(TimerFunc_1_constant == 3){
      texture_set_1 = 0;
      mage_3_Damage();
  }else if(TimerFunc_1_constant == 4){
      texture_set_1 = 0;
      mage_3_Die();
  }
  //glutTimerFunc(60,TimerFunc_1,1);
}

void TimerFunc_1_Projetil(){
  if (TimerFunc_1_constant_projetil == 0){
      texture_set_1_projetil = 0;
      Mage_3_projetil_idle();
  }else if (TimerFunc_1_constant_projetil == 1){
      texture_set_1_projetil = 0;
      Mage_3_projetil_colision();
  }
//    glutTimerFunc(60,TimerFunc_1_Projetil,1);
}

void TimerFunc_2(){
  if (TimerFunc_2_constant == 0) {
    texture_set_2 = 0;
    mage_4_Idle();
  }else if(TimerFunc_2_constant == 1){
    texture_set_2 = 0;
    mage_4_Walk();
  }else if(TimerFunc_2_constant == 2){
    texture_set_2 = 0;
    mage_4_Attack();
  }else if(TimerFunc_2_constant == 3){
    texture_set_2 = 0;
    mage_4_Damage();
  }else if(TimerFunc_2_constant == 4){
    texture_set_2 = 0;
    mage_4_Die();
  }
  //  glutTimerFunc(60,TimerFunc_2,1);
}

void TimerFunc_2_Projetil(){
  if (TimerFunc_2_constant_projetil == 0){
      texture_set_2_projetil = 0;
      Mage_4_projetil_idle();
  }else if (TimerFunc_2_constant_projetil == 1){
      texture_set_2_projetil = 0;
      Mage_4_projetil_colision();
  }
    //glutTimerFunc(60,TimerFunc_2_Projetil,1);
}

void mage_3_Idle(){
            if(texture_set_1 == 0){
        		mage_3 = mage_3_texture[0];
          }else if(texture_set_1 == 1){
        		mage_3 = mage_3_texture[1];
          }else if(texture_set_1 == 2){
        		mage_3 = mage_3_texture[2];
        	}else if(texture_set_1 == 3){
        		mage_3 = mage_3_texture[3];
          }else if(texture_set_1 == 4){
        		mage_3 = mage_3_texture[4];
          }else if(texture_set_1 == 5){
            mage_3 = mage_3_texture[5];
          }
          texture_set_1++;
        if(texture_set_1 >= 5)
            texture_set_1 =0;
        glutTimerFunc(400,mage_3_Idle,1);
}

void mage_3_Walk(){

    if(texture_set_1 == 0){
        mage_3 = mage_3_texture[6];
    }else if(texture_set_1 == 2){
        mage_3 = mage_3_texture[7];
    }else if(texture_set_1 == 4){
        mage_3 = mage_3_texture[8];
    }else if(texture_set_1 == 6){
        mage_3 = mage_3_texture[9];
    }else if(texture_set_1 == 8){
        mage_3 = mage_3_texture[10];
    }else if(texture_set_1 == 10){
        mage_3 = mage_3_texture[11];
    }else if(texture_set_1 == 12){
        mage_3 = mage_3_texture[12];
    }else if(texture_set_1 == 14){
        mage_3 = mage_3_texture[13];
    }
    texture_set_1++;
    if (texture_set_1 == 14) {
      texture_set_1=0;
    }
}

void mage_3_Attack(){
      if(texture_set_1 == 0){
          mage_3 = mage_3_texture[14];
      }else if(texture_set_1 == 1){
          mage_3 = mage_3_texture[15];
      }else if(texture_set_1 == 2){
          mage_3 = mage_3_texture[16];
      }else if(texture_set_1 == 3){
          ;mage_3 =mage_3_texture[17];
      }else if(texture_set_1 == 4){
          mage_3 = mage_3_texture[18];
      }else if(texture_set_1 == 5){
          mage_3 = mage_3_texture[19];
      }else if(texture_set_1 == 6){
          mage_3 = mage_3_texture[20];
          TimerFunc_1_constant = 0;
      }
      texture_set_1++;
}

void mage_3_Damage(){

  if(texture_set_1 ==0){
    mage_3 = mage_3_texture[21];
  }else if(texture_set_1 == 1){
    mage_3 = mage_3_texture[22];
  }else if(texture_set_1 == 2){
    mage_3 = mage_3_texture[23];
  }else if(texture_set_1 == 3){
    mage_3 =mage_3_texture[24];
  }else if(texture_set_1 == 4){
    mage_3 = mage_3_texture[25];
    TimerFunc_1_constant = 0;
  }
  texture_set_1++;
  if(texture_set_1 >= 5)
    texture_set_1 = 0;
    glutTimerFunc(80,mage_3_Damage,1);
}

void mage_3_Die(){

    if(texture_set_1 ==0){
        mage_3 = mage_3_texture[26];
    }else if(texture_set_1 == 1){
        mage_3 = mage_3_texture[27];
    }else if(texture_set_1 == 2){
        mage_3 = mage_3_texture[28];
    }else if(texture_set_1 == 3){
        mage_3 = mage_3_texture[29];
    }else if(texture_set_1 == 4){
        mage_3 = mage_3_texture[30];
    }else if(texture_set_1 == 5){
      while (1) {
        mage_3 = mage_3_texture[31];

      }
    }
    if(texture_set_1 != 5)
      texture_set_1++;
}

void Mage_3_projetil_idle(){

  if(texture_set_1_projetil == 0){
      mage_3_projetil = mage_3_texture[32];
  }else if(texture_set_1_projetil == 1){
      mage_3_projetil = mage_3_texture[33];
  }else if(texture_set_1_projetil == 2){
      mage_3_projetil = mage_3_texture[34];
  }else if(texture_set_1_projetil== 3){
      mage_3_projetil = mage_3_texture[35];
  }else if(texture_set_1_projetil == 4){
      mage_3_projetil = mage_3_texture[36];
  }else if(texture_set_1_projetil == 5){
      mage_3_projetil = mage_3_texture[37];
  }
  texture_set_1_projetil++;
  if(texture_set_1_projetil >= 5)
      texture_set_1_projetil = 0;
  glutTimerFunc(80,Mage_3_projetil_idle,1);
}

void Mage_3_projetil_colision(){
  if(texture_set_1_projetil == 0){
      mage_3_projetil = mage_3_texture[38];
  }else if(texture_set_1_projetil == 1){
      mage_3_projetil = mage_3_texture[39];
  }else if(texture_set_1_projetil == 2){
      mage_3_projetil = mage_3_texture[40];
  }else if(texture_set_1_projetil == 3){
      mage_3_projetil = mage_3_texture[41];
  }else if(texture_set_1_projetil == 4){
      mage_3_projetil = mage_3_texture[42];
  }else if(texture_set_1_projetil == 5){
      mage_3_projetil =mage_3_texture[43];
      ativa_projetil=0;
  }

  texture_set_1_projetil++;
}

void mage_4_Idle(){
  if(texture_set_2 == 0){
      mage_4 = mage_4_texture[0];
  }else if(texture_set_2 == 1){
        mage_4 = mage_4_texture[1];
    }
  texture_set_2++;
  if(texture_set_2 >= 1)
      texture_set_2 = 0;
  glutTimerFunc(80,mage_4_Idle,1);
}

void mage_4_Walk(){
  if(texture_set_2 == 0){
      mage_4 =mage_4_texture[2];
  }else if(texture_set_2 == 2){
      mage_4 = mage_4_texture[3];
  }else if (texture_set_2 == 4) {
      mage_4 = mage_4_texture[4];
  }else if (texture_set_2 == 6) {
      mage_4 = mage_4_texture[5];
  }else if (texture_set_2 == 8) {
      mage_4 = mage_4_texture[6];
  }else if (texture_set_2 == 10) {
      mage_4 = mage_4_texture[7];
  }else if (texture_set_2 == 12) {
      mage_4 = mage_4_texture[8];
  }else if (texture_set_2 == 14) {
      mage_4 = mage_4_texture[9];
  }
    if (texture_set_2 >= 7) {
      texture_set_2=-1;
    }
      texture_set_2++;
}

void mage_4_Attack(){
  if(texture_set_2 == 0){
      mage_4 = mage_4_texture[10];
  }else if(texture_set_2 == 1){
      mage_4 = mage_4_texture[11];
  }else if(texture_set_2 == 2){
      mage_4 =mage_4_texture[12];
  }else if(texture_set_2 == 3){
      mage_4 =mage_4_texture[13];
      TimerFunc_2_constant = 0;
  }
  texture_set_2++;
  if(texture_set_2 != 3)
    glutTimerFunc(80,TimerFunc_2,1);
}

void mage_4_Damage(){
    if(texture_set_2 == 0){
        mage_4 = mage_4_texture[14];
    }else if(texture_set_2 == 1){
        mage_4 = mage_4_texture[15];
    }else if(texture_set_2 == 2){
        mage_4 = mage_4_texture[16];
    }else if(texture_set_2 == 3){
        mage_4 = mage_4_texture[17];
    }else if(texture_set_2 == 4){
        mage_4 = mage_4_texture[18];
        TimerFunc_2_constant = 0;
    }

    texture_set_2++;
    if(texture_set_2 <= 4)
      glutTimerFunc(80,TimerFunc_2,1);
}

void mage_4_Die(){
  if(texture_set_2 == 0){
      mage_4 = mage_4_texture[19];
  }else if(texture_set_2 == 1){
      mage_4 = mage_4_texture[20];
  }else if(texture_set_2 == 2){
      mage_4 = mage_4_texture[21];
  }else if(texture_set_2 == 3){
      mage_4 = mage_4_texture[22];
  }
  if(texture_set_2 != 3)
  texture_set_2++;
  if(texture_set_2 < 4)
    glutTimerFunc(80,TimerFunc_2,1);
}

void Mage_4_projetil_idle(){
  if(texture_set_2_projetil == 0){
      mage_4_projetil = mage_4_texture[23];
  }else if(texture_set_2_projetil == 1){
      mage_4_projetil =  mage_4_texture[24];
  }else if(texture_set_2_projetil == 2){
      mage_4_projetil = mage_4_texture[25];
  }else if(texture_set_2_projetil == 3){
      mage_4_projetil = mage_4_texture[26];
  }else if(texture_set_2_projetil == 4){
      mage_4_projetil =  mage_4_texture[27];
  }else if(texture_set_2_projetil == 5){
      mage_4_projetil =  mage_4_texture[28];
  }

  texture_set_2_projetil++;
  if(texture_set_2_projetil >= 5)
    texture_set_2_projetil = 0;
    glutTimerFunc(80,Mage_4_projetil_idle,1);
}

void Mage_4_projetil_colision(){
  if(texture_set_2_projetil == 0){
      mage_4_projetil =  mage_4_texture[29];
  }else if(texture_set_2_projetil == 1){
      mage_4_projetil = mage_4_texture[30];
  }else if(texture_set_2_projetil == 2){
      mage_4_projetil =  mage_4_texture[31];
  }else if(texture_set_2_projetil == 3){
      mage_4_projetil = mage_4_texture[32];
  }else if(texture_set_2_projetil == 4){
      mage_4_projetil =  mage_4_texture[33];
  }else if(texture_set_2_projetil == 5){
      mage_4_projetil =  mage_4_texture[34];
  }

  if(texture_set_2_projetil == 5)
      ativa_projetil=0;

  texture_set_2_projetil++;
  if(texture_set_2_projetil <= 5)
    glutTimerFunc(80,TimerFunc_2_Projetil,1);
}



void carrega_textura_menu(){
  if(cont == 0){
    cont++;
  }


  if(texture_set_menu == 0){
    menu_texture = menu_texture_v[0];
  }else if(texture_set_menu == 1){
    menu_texture = menu_texture_v[1];
  }else if(texture_set_menu == 2){
      menu_texture = menu_texture_v[2];
  }else if(texture_set_menu == 3){
      menu_texture = menu_texture_v[3];
  }else if(texture_set_menu == 4){
      menu_texture =  menu_texture_v[4];
  }else if (texture_set_menu == 5) {
    menu_texture =  menu_texture_v[5];
  }else if(texture_set_menu == 6){
    menu_texture =  menu_texture_v[6];
  }else if(texture_set_menu == 7){
    menu_texture =  menu_texture_v[7];
  }else if(texture_set_menu == 8){
    menu_texture =  menu_texture_v[8];
  }else if(texture_set_menu == 9){
    menu_texture =  menu_texture_v[9];
  }
  glutTimerFunc(20,carrega_textura_menu,1);
}

void textura_vento(){

  if(vento_set == 0){
    vento_texture = vento_texture_v[0];
  }else if(vento_set == 1) {
    vento_texture =  vento_texture_v[1];
  }else if(vento_set == 2) {
    vento_texture = vento_texture_v[2];
  }else if(vento_set == 3 ){
    vento_texture =  vento_texture_v[3];
  }else if (vento_set == 4) {
    vento_texture =  vento_texture_v[4];
  }else if (vento_set == 5) {
    vento_texture =  vento_texture_v[5];
  }else if (vento_set == 6) {
    vento_texture =  vento_texture_v[6];
  }
  glutTimerFunc(50,textura_vento,1);
}

void vidas_func() {
  if(p1.vida == 3 )
    vida_mage_3 = vida_texture_f[0];
  else if(p1.vida == 2 )
    vida_mage_3 = vida_texture_f[1];
  else if(p1.vida == 1 )
    vida_mage_3 = vida_texture_f[2];
  else if(p1.vida == 0 )
    vida_mage_3 = vida_texture_f[3];
  if (p2.vida == 3) {
    vida_mage_4 = vida_texture_f[4];
  }else if(p2.vida == 2){
    vida_mage_4 = vida_texture_f[5];
  }else if(p2.vida == 1){
    vida_mage_4 = vida_texture_f[6];
  }else if(p2.vida == 0){
    vida_mage_4 = vida_texture_f[7];
  }

  glutTimerFunc(50,vidas_func,1);
}
