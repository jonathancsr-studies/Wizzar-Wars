#include "include.h"
extern int ativa_projetil;
extern int vento,ativo;


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

void inittexture(){
  mage_3_Idle();
  mage_4_Idle();
  Mage_3_projetil_idle();
  Mage_4_projetil_idle();
  textura_vento(0);
  carrega_textura_menu(0);
  fundo = loadTexture("./util/fundo.png");
  lua = loadTexture("./util/moon.png");
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
        		mage_3 = loadTexture("./Mage_3/mage_3_Idle_0.png");
          }else if(texture_set_1 == 1){
        		mage_3 = loadTexture("./Mage_3/mage_3_Idle_1.png");
          }else if(texture_set_1 == 2){
        		mage_3 = loadTexture("./Mage_3/mage_3_Idle_2.png");
        	}else if(texture_set_1 == 3){
        		mage_3 = loadTexture("./Mage_3/mage_3_Idle_3.png");
          }else if(texture_set_1 == 4){
        		mage_3 = loadTexture("./Mage_3/mage_3_Idle_4.png");
          }else if(texture_set_1 == 5){
                mage_3 = loadTexture("./Mage_3/mage_3_Idle_5.png");
          }
          texture_set_1++;
        if(texture_set_1 >= 5)
            texture_set_1 =0;
        glutTimerFunc(400,mage_3_Idle,1);
}

void mage_3_Walk(){

    if(texture_set_1 == 0){
        mage_3 = loadTexture("./Mage_3/mage_3_Walk_0.png");
    }else if(texture_set_1 == 2){
        mage_3 = loadTexture("./Mage_3/mage_3_Walk_1.png");
    }else if(texture_set_1 == 4){
        mage_3 = loadTexture("./Mage_3/mage_3_Walk_2.png");
    }else if(texture_set_1 == 6){
        mage_3 = loadTexture("./Mage_3/mage_3_Walk_3.png");
    }else if(texture_set_1 == 8){
        mage_3 = loadTexture("./Mage_3/mage_3_Walk_4.png");
    }else if(texture_set_1 == 10){
        mage_3 = loadTexture("./Mage_3/mage_3_Walk_5.png");
    }else if(texture_set_1 == 12){
        mage_3 = loadTexture("./Mage_3/mage_3_Walk_6.png");
    }else if(texture_set_1 == 14){
        mage_3 = loadTexture("./Mage_3/mage_3_Walk_7.png");
    }
    texture_set_1++;
    if (texture_set_1 == 14) {
      texture_set_1=0;
    }
}

void mage_3_Attack(){
      if(texture_set_1 == 0){
          mage_3 = loadTexture("./Mage_3/mage_3_Atack_0.png");
      }else if(texture_set_1 == 1){
          mage_3 = loadTexture("./Mage_3/mage_3_Atack_1.png");
      }else if(texture_set_1 == 2){
          mage_3 = loadTexture("./Mage_3/mage_3_Atack_2.png");
      }else if(texture_set_1 == 3){
          ;mage_3 = loadTexture("./Mage_3/mage_3_Atack_3.png");
      }else if(texture_set_1 == 4){
          mage_3 = loadTexture("./Mage_3/mage_3_Atack_4.png");
      }else if(texture_set_1 == 5){
          mage_3 = loadTexture("./Mage_3/mage_3_Atack_5.png");
      }else if(texture_set_1 == 6){
          mage_3 = loadTexture("./Mage_3/mage_3_Atack_6.png");
          TimerFunc_1_constant = 0;
      }
      texture_set_1++;
}

void mage_3_Damage(){

  if(texture_set_1 ==0){
    mage_3 = loadTexture("./Mage_3/mage_3_Damage_0.png");
  }else if(texture_set_1 == 1){
    mage_3 = loadTexture("./Mage_3/mage_3_Damage_1.png");
  }else if(texture_set_1 == 2){
    mage_3 = loadTexture("./Mage_3/mage_3_Damage_2.png");
  }else if(texture_set_1 == 3){
    mage_3 = loadTexture("./Mage_3/mage_3_Damage_3.png");
  }else if(texture_set_1 == 4){
    mage_3 = loadTexture("./Mage_3/mage_3_Damage_4.png");
    TimerFunc_1_constant = 0;
  }
  texture_set_1++;
  if(texture_set_1 >= 5)
    texture_set_1 = 0;
    glutTimerFunc(80,mage_3_Damage,1);
}

void mage_3_Die(){

    if(texture_set_1 ==0){
        mage_3 = loadTexture("./Mage_3/mage_3_Die_0.png");
    }else if(texture_set_1 == 1){
        mage_3 = loadTexture("./Mage_3/mage_3_Die_1.png");
    }else if(texture_set_1 == 2){
        mage_3 = loadTexture("./Mage_3/mage_3_Die_2.png");
    }else if(texture_set_1 == 3){
        mage_3 = loadTexture("./Mage_3/mage_3_Die_3.png");
    }else if(texture_set_1 == 4){
        mage_3 = loadTexture("./Mage_3/mage_3_Die_4.png");
    }else if(texture_set_1 == 5){
        mage_3 = loadTexture("./Mage_3/mage_3_Die_5.png");
    }
    if(texture_set_1 != 5)
      texture_set_1++;
}

void Mage_3_projetil_idle(){

  if(texture_set_1_projetil == 0){
      mage_3_projetil = loadTexture("./Mage_3/mage_3_projetil_idle_0.png");
  }else if(texture_set_1_projetil == 1){
      mage_3_projetil = loadTexture("./Mage_3/mage_3_projetil_idle_1.png");
  }else if(texture_set_1_projetil == 2){
      mage_3_projetil = loadTexture("./Mage_3/mage_3_projetil_idle_2.png");
  }else if(texture_set_1_projetil== 3){
      mage_3_projetil = loadTexture("./Mage_3/mage_3_projetil_idle_3.png");
  }else if(texture_set_1_projetil == 4){
      mage_3_projetil = loadTexture("./Mage_3/mage_3_projetil_idle_4.png");
  }else if(texture_set_1_projetil == 5){
      mage_3_projetil = loadTexture("./Mage_3/mage_3_projetil_idle_5.png");
  }
  texture_set_1_projetil++;
  if(texture_set_1_projetil >= 5)
      texture_set_1_projetil = 0;
  glutTimerFunc(80,Mage_3_projetil_idle,1);
}

void Mage_3_projetil_colision(){
  if(texture_set_1_projetil == 0){
      mage_3_projetil = loadTexture("./Mage_3/mage_3_projetil_colision_1.png");
  }else if(texture_set_1_projetil == 1){
      mage_3_projetil = loadTexture("./Mage_3/mage_3_projetil_colision_2.png");
  }else if(texture_set_1_projetil == 2){
      mage_3_projetil = loadTexture("./Mage_3/mage_3_projetil_colision_3.png");
  }else if(texture_set_1_projetil == 3){
      mage_3_projetil = loadTexture("./Mage_3/mage_3_projetil_colision_4.png");
  }else if(texture_set_1_projetil == 4){
      mage_3_projetil = loadTexture("./Mage_3/mage_3_projetil_colision_5.png");
  }else if(texture_set_1_projetil == 5){
      mage_3_projetil = loadTexture("./Mage_3/mage_3_projetil_colision_6.png");
      ativa_projetil=0;
  }

  texture_set_1_projetil++;
}

void mage_4_Idle(){
  if(texture_set_2 == 0){
      mage_4 = loadTexture("./Mage_4/mage_4_Idle.png");
  }else if(texture_set_2 == 1){
        mage_4 = loadTexture("./Mage_4/mage_4_Idle.png");
    }
  texture_set_2++;
  if(texture_set_2 >= 1)
      texture_set_2 = 0;
  glutTimerFunc(80,mage_4_Idle,1);
}

void mage_4_Walk(){
  if(texture_set_2 == 0){
      mage_4 = loadTexture("./Mage_4/mage_4_Andando_0.png");
  }else if(texture_set_2 == 2){
      mage_4 = loadTexture("./Mage_4/mage_4_Andando_1.png");
  }else if (texture_set_2 == 4) {
      mage_4 = loadTexture("./Mage_4/mage_4_Andando_2.png");
  }else if (texture_set_2 == 6) {
      mage_4 = loadTexture("./Mage_4/mage_4_Andando_3.png");
  }else if (texture_set_2 == 8) {
      mage_4 = loadTexture("./Mage_4/mage_4_Andando_4.png");
  }else if (texture_set_2 == 10) {
      mage_4 = loadTexture("./Mage_4/mage_4_Andando_5.png");
  }else if (texture_set_2 == 12) {
      mage_4 = loadTexture("./Mage_4/mage_4_Andando_6.png");
  }else if (texture_set_2 == 14) {
      mage_4 = loadTexture("./Mage_4/mage_4_Andando_7.png");
  }
    if (texture_set_2 >= 7) {
      texture_set_2=-1;
    }
      texture_set_2++;
}

void mage_4_Attack(){
  if(texture_set_2 == 0){
      mage_4 = loadTexture("./Mage_4/mage_4_Ataque_0.png");
  }else if(texture_set_2 == 1){
      mage_4 = loadTexture("./Mage_4/mage_4_Ataque_1.png");
  }else if(texture_set_2 == 2){
      mage_4 = loadTexture("./Mage_4/mage_4_Ataque_2.png");
  }else if(texture_set_2 == 3){
      mage_4 = loadTexture("./Mage_4/mage_4_Ataque_3.png");
      TimerFunc_2_constant = 0;
  }
  texture_set_2++;
  if(texture_set_2 != 3)
    glutTimerFunc(80,TimerFunc_2,1);
}

void mage_4_Damage(){
    if(texture_set_2 == 0){
        mage_4 = loadTexture("./Mage_4/mage_4_Ataque_1.png");
    }else if(texture_set_2 == 1){
        mage_4 = loadTexture("./Mage_4/mage_4_Ataque_0.png");
    }else if(texture_set_2 == 2){
        mage_4 = loadTexture("./Mage_4/mage_4_dano.png");
    }else if(texture_set_2 == 3){
        mage_4 = loadTexture("./Mage_4/mage_4_Ataque_1.png");
    }else if(texture_set_2 == 4){
        mage_4 = loadTexture("./Mage_4/mage_4_Ataque_0.png");
        TimerFunc_2_constant = 0;
    }

    texture_set_2++;
    if(texture_set_2 <= 4)
      glutTimerFunc(80,TimerFunc_2,1);
}

void mage_4_Die(){
  if(texture_set_2 == 0){
      mage_4 = loadTexture("./Mage_4/mage_4_morrendo_0.png");
  }else if(texture_set_2 == 1){
      mage_4 = loadTexture("./Mage_4/mage_4_morrendo_1.png");
  }else if(texture_set_2 == 2){
      mage_4 = loadTexture("./Mage_4/mage_4_morrendo_2.png");
  }else if(texture_set_2 == 3){
      mage_4 = loadTexture("./Mage_4/mage_4_morrendo_3.png");
  }
  if(texture_set_2 != 3)
  texture_set_2++;
  if(texture_set_2 < 4)
    glutTimerFunc(80,TimerFunc_2,1);
}

void Mage_4_projetil_idle(){
  if(texture_set_2_projetil == 0){
      mage_4_projetil = loadTexture("./Mage_4/mage_4_projetil_idle_0.png");
  }else if(texture_set_2_projetil == 1){
      mage_4_projetil = loadTexture("./Mage_4/mage_4_projetil_idle_1.png");
  }else if(texture_set_2_projetil == 2){
      mage_4_projetil = loadTexture("./Mage_4/mage_4_projetil_idle_2.png");
  }else if(texture_set_2_projetil == 3){
      mage_4_projetil = loadTexture("./Mage_4/mage_4_projetil_idle_3.png");
  }else if(texture_set_2_projetil == 4){
      mage_4_projetil = loadTexture("./Mage_4/mage_4_projetil_idle_4.png");
  }else if(texture_set_2_projetil == 5){
      mage_4_projetil = loadTexture("./Mage_4/mage_4_projetil_idle_5.png");
  }

  texture_set_2_projetil++;
  if(texture_set_2_projetil >= 5)
    texture_set_2_projetil = 0;
    glutTimerFunc(80,Mage_4_projetil_idle,1);
}

void Mage_4_projetil_colision(){
  if(texture_set_2_projetil == 0){
      mage_4_projetil = loadTexture("./Mage_4/mage_4_projetil_colision_1.png");
  }else if(texture_set_2_projetil == 1){
      mage_4_projetil = loadTexture("./Mage_4/mage_4_projetil_colision_2.png");
  }else if(texture_set_2_projetil == 2){
      mage_4_projetil = loadTexture("./Mage_4/mage_4_projetil_colision_3.png");
  }else if(texture_set_2_projetil == 3){
      mage_4_projetil = loadTexture("./Mage_4/mage_4_projetil_colision_4.png");
  }else if(texture_set_2_projetil == 4){
      mage_4_projetil = loadTexture("./Mage_4/mage_4_projetil_colision_5.png");
  }else if(texture_set_2_projetil == 5){
      mage_4_projetil = loadTexture("./Mage_4/mage_4_projetil_colision_6.png");
  }

  if(texture_set_2_projetil == 5)
      ativa_projetil=0;

  texture_set_2_projetil++;
  if(texture_set_2_projetil <= 5)
    glutTimerFunc(80,TimerFunc_2_Projetil,1);
}



void carrega_textura_menu(){
  if(texture_set_menu == 0){
    menu_texture= loadTexture("./menus/menu.png");
  }else if(texture_set_menu == 1){
    menu_texture = loadTexture("./menus/menu_WWITC_hover_jogar.png");
  }else if(texture_set_menu == 2){
      menu_texture = loadTexture("./menus/menu_WWITC_hover_creditos.png");
  }else if(texture_set_menu == 3){
      menu_texture = loadTexture("./menus/menu_WWITC_hover_Sair.png");
  }else if(texture_set_menu == 4){
      menu_texture = loadTexture("./menus/creditos.png");
  }else if (texture_set_menu == 5) {
    menu_texture = loadTexture("./menus/menu_pause.png");
  }else if(texture_set_menu == 6){
    menu_texture = loadTexture("./menus/menu_sair.png");
  }else if(texture_set_menu == 7){
    menu_texture = loadTexture("./menus/ganhou_1.png");
  }else if(texture_set_menu == 8){
    menu_texture = loadTexture("./menus/ganhou_2.png");
  }else if(texture_set_menu == 9){
    menu_texture = loadTexture("./menus/ganhou_2.png");
  }

}

void textura_vento(int vento){

  if(ativo){
      if(vento == 0)
      {
        vento_texture = loadTexture("./util/vento_sem.png");
      }else if(vento == 1)
      {
        vento_texture = loadTexture("./util/vento_direita_1");
      }else if(vento == 2)
      {
        vento_texture = loadTexture("./util/vento_direita_2");
      }else if(vento >= 3 )
      {
        vento_texture = loadTexture("./util/vento_direita_3");
      }else if (vento == -1) {
        vento_texture = loadTexture("./util/vento_esquerda_1");
      }else if (vento == -2) {
        vento_texture = loadTexture("./util/vento_esquerda_2");
      }else if (vento <= -3) {
        vento_texture = loadTexture("./util/vento_esquerda_3");
      }
  }else{
      if(vento == 0)
      {
        vento_texture = loadTexture("./util/vento_sem_01.png");
      }else if(vento == -1)
      {
        vento_texture = loadTexture("./util/vento_direita_1");
      }else if(vento == -2)
      {
        vento_texture = loadTexture("./util/vento_direita_2");
      }else if(vento >= -3 )
      {
        vento_texture = loadTexture("./util/vento_direita_3");
      }else if (vento == 1) {
        vento_texture = loadTexture("./util/vento_esquerda_1");
      }else if (vento == 2) {
        vento_texture = loadTexture("./util/vento_esquerda_2");
      }else if (vento <= 3) {
        vento_texture = loadTexture("./util/vento_esquerda_3");
      }
  }

}
