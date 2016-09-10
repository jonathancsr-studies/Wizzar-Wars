#include "include.h"

int loadTexture(char nometextura[]){

    tex = SOIL_load_OGL_texture(
           nometextura,
           SOIL_LOAD_AUTO,
           SOIL_CREATE_NEW_ID,
           SOIL_FLAG_INVERT_Y
     );
     glEnable( GL_BLEND );
     glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
     return tex;
}

void inittext(){
  glClearColor (1, 1, 1, 0);
  void mage_3_Idle();
  void mage_3_Walk();
  void mage_3_Attack();
  void mage_3_Damage();
  void mage_3_Die();
}

void mage_3_Idle(){

   mage_3_idle_0 = loadTexture("image/Mage_3/mage_3_Idle_0.png");

    if(mage_3_idle_0 == 0) {
        printf("Erro do SOIL: '%s'\n", SOIL_last_result());
    }
   mage_3_idle_1 = loadTexture("image/Mage_3/mage_3_Idle_1.png");
   mage_3_idle_2 = loadTexture("image/Mage_3/mage_3_Idle_2.png");
   mage_3_idle_3 = loadTexture("image/Mage_3/mage_3_Idle_3.png");
   mage_3_idle_4 = loadTexture("image/Mage_3/mage_3_Idle_4.png");
   mage_3_idle_5 = loadTexture("image/Mage_3/mage_3_Idle_5.png");
}

void mage_3_Walk(){

    mage_3_walk_0 = loadTexture("image/Mage_3/mage_3_Walk_0.png");
    mage_3_walk_1 = loadTexture("image/Mage_3/mage_3_Walk_1.png");
    mage_3_walk_2 = loadTexture("image/Mage_3/mage_3_Walk_2.png");
    mage_3_walk_3 = loadTexture("image/Mage_3/mage_3_Walk_3.png");
    mage_3_walk_4 = loadTexture("image/Mage_3/mage_3_Walk_4.png");
    mage_3_walk_5 = loadTexture("image/Mage_3/mage_3_Walk_5.png");
    mage_3_walk_6 = loadTexture("image/Mage_3/mage_3_Walk_6.png");
    mage_3_walk_7 = loadTexture("image/Mage_3/mage_3_Walk_7.png");
}
void mage_3_Attack(){

  mage_3_attack_0 = loadTexture("image/Mage_3/mage_3_Atack_0.png");
  mage_3_attack_1 = loadTexture("image/Mage_3/mage_3_Atack_1.png");
  mage_3_attack_2 = loadTexture("image/Mage_3/mage_3_Atack_2.png");
  mage_3_attack_3 = loadTexture("image/Mage_3/mage_3_Atack_3.png");
  mage_3_attack_4 = loadTexture("image/Mage_3/mage_3_Atack_4.png");
  mage_3_attack_5 = loadTexture("image/Mage_3/mage_3_Atack_5.png");
  mage_3_attack_6 = loadTexture("image/Mage_3/mage_3_Atack_6.png");
}

void mage_3_Damage(){

    mage_3_damage_0 = loadTexture("image/Mage_3/mage_3_Damage_0.png");
    mage_3_damage_1 = loadTexture("image/Mage_3/mage_3_Damage_1.png");
    mage_3_damage_2 = loadTexture("image/Mage_3/mage_3_Damage_2.png");
    mage_3_damage_3 = loadTexture("image/Mage_3/mage_3_Damage_3.png");
    mage_3_damage_4 = loadTexture("image/Mage_3/mage_3_Damage_4.png");

}
void mage_3_Die(){

    mage_3_die_0 = loadTexture("image/Mage_3/mage_3_Die_0.png");
    mage_3_die_1 = loadTexture("image/Mage_3/mage_3_Die_1.png");
    mage_3_die_2 = loadTexture("image/Mage_3/mage_3_Die_2.png");
    mage_3_die_3 = loadTexture("image/Mage_3/mage_3_Die_3.png");
    mage_3_die_4 = loadTexture("image/Mage_3/mage_3_Die_4.png");
    mage_3_die_5 = loadTexture("image/Mage_3/mage_3_Die_5.png");
}
