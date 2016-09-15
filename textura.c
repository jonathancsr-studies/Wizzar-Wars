#include "include.h"
extern int ativa_projetil;

int swap_texture_idle_mage_3=-1,
    swap_texture_walk_mage_3=-1,
    swap_texture_attack_mage_3=-1,
    swap_texture_damage_mage_3=-1,
    swap_texture_die_mage_3=-1,
    swap_texture_idle_mage_4=-1,
    swap_texture_walk_mage_4=-1,
    swap_texture_attack_mage_4=-1,
    swap_texture_damage_mage_4=-1,
    swap_texture_die_mage_4=-1,
    swap_texture_projetil_idle_mage_3=-1,
    swap_texture_projetil_colision_mage_3=-1,
    swap_texture_projetil_idle_mage_4=-1,
    swap_texture_projetil_colision_mage_4=-1;

void setTextureUse_Mage(int k,int c){
    if(c == 0 && k == 0)
      textureuse_mage3=mage_3_idle;
    else if(c == 1 && k == 0)
      textureuse_mage3=mage_3_walk;
    else if(c == 2 && k == 0)
      textureuse_mage3=mage_3_attack;
    else if(c == 3 && k == 0)
      textureuse_mage3=mage_3_damage;
    else if(c == 4 && k == 0)
      textureuse_mage3=mage_3_die;
    else if(c == 5 && k == 0)
      textureuse_mage3_projetil=mage_3_projetil_idle;
    else if(c == 6 && k == 0)
      textureuse_mage3_projetil=mage_3_projetil_colision;
    if(c == 0 && k == 1)
      textureuse_mage4=mage_4_idle;
    else if(c == 1 && k == 1)
      textureuse_mage4=mage_4_walk;
    else if(c == 2 && k == 1)
      textureuse_mage4=mage_4_attack;
    else if(c == 3 && k == 1)
      textureuse_mage4=mage_4_damage;
    else if(c == 4 && k == 1)
      textureuse_mage4=mage_4_die;
    else if(c == 5 && k == 1)
      textureuse_mage4_projetil=mage_4_projetil_idle;
    else if(c == 6 && k == 1)
      textureuse_mage4_projetil=mage_4_projetil_colision;
}

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

unsigned int loadTexture_2(char nometextura[]){
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
}

void mage_3_Idle(){
    setTextureUse_Mage(0,0);
    int i;
for (i = 0; i < 10; i++,swap_texture_idle_mage_3++) {
      if(swap_texture_idle_mage_3==-1)
        break;
      if(swap_texture_idle_mage_3 == 0){
    		mage_3_idle = loadTexture("./Mage_3/mage_3_Idle_0.png");
      }else if(swap_texture_idle_mage_3 == 20){
    		mage_3_idle = loadTexture("./Mage_3/mage_3_Idle_1.png");
      }else if(swap_texture_idle_mage_3 == 40){
    		mage_3_idle = loadTexture("./Mage_3/mage_3_Idle_2.png");
    	}else if(swap_texture_idle_mage_3 == 60){
    		mage_3_idle = loadTexture("./Mage_3/mage_3_Idle_3.png");
      }else if(swap_texture_idle_mage_3 == 80){
    		mage_3_idle = loadTexture("./Mage_3/mage_3_Idle_4.png");
      }else if(swap_texture_idle_mage_3 == 100){
    		{
            mage_3_idle = loadTexture("./Mage_3/mage_3_Idle_5.png");
            swap_texture_idle_mage_3=0;
        }
        glutPostRedisplay();
    	}
}

/*
    if(swap_texture_idle_mage_3 == 5)
        swap_texture_idle_mage_3 =0;
    glutTimerFunc(500,mage_3_Idle,1);
*/
}

void mage_3_Walk(){

    if(swap_texture_walk_mage_3 == 0){
        mage_3_walk = loadTexture("./Mage_3/mage_3_Walk_0.png");
    }else if(swap_texture_walk_mage_3 == 2){
        mage_3_walk = loadTexture("./Mage_3/mage_3_Walk_1.png");
    }else if(swap_texture_walk_mage_3 == 4){
        mage_3_walk = loadTexture("./Mage_3/mage_3_Walk_2.png");
    }else if(swap_texture_walk_mage_3 == 6){
        mage_3_walk = loadTexture("./Mage_3/mage_3_Walk_3.png");
    }else if(swap_texture_walk_mage_3 == 8){
        mage_3_walk = loadTexture("./Mage_3/mage_3_Walk_4.png");
    }else if(swap_texture_walk_mage_3 == 10){
        mage_3_walk = loadTexture("./Mage_3/mage_3_Walk_5.png");
    }else if(swap_texture_walk_mage_3 == 12){
        mage_3_walk = loadTexture("./Mage_3/mage_3_Walk_6.png");
    }else if(swap_texture_walk_mage_3 == 14){
        mage_3_walk = loadTexture("./Mage_3/mage_3_Walk_7.png");
    }
    swap_texture_walk_mage_3++;
    if (swap_texture_walk_mage_3==14) {
      swap_texture_walk_mage_3=0;
    }
}

void mage_3_Walk_2(){

      if(swap_texture_walk_mage_3 == 0){
          mage_3_walk = loadTexture_2("./Mage_3/mage_3_Walk_0.png");
      }else if(swap_texture_walk_mage_3 == 1){
          mage_3_walk = loadTexture_2("./Mage_3/mage_3_Walk_1.png");
      }else if(swap_texture_walk_mage_3 == 2){
          mage_3_walk = loadTexture_2("./Mage_3/mage_3_Walk_2.png");
      }else if(swap_texture_walk_mage_3 == 3){
          mage_3_walk = loadTexture_2("./Mage_3/mage_3_Walk_3.png");
      }else if(swap_texture_walk_mage_3 == 4){
          mage_3_walk = loadTexture_2("./Mage_3/mage_3_Walk_4.png");
      }else if(swap_texture_walk_mage_3 == 5){
          mage_3_walk = loadTexture_2("./Mage_3/mage_3_Walk_5.png");
      }else if(swap_texture_walk_mage_3 == 6){
          mage_3_walk = loadTexture_2("./Mage_3/mage_3_Walk_6.png");
      }else if(swap_texture_walk_mage_3 == 7){
          mage_3_walk = loadTexture_2("./Mage_3/mage_3_Walk_7.png");
      }
      swap_texture_walk_mage_3++;
        if (swap_texture_walk_mage_3==7) {
          swap_texture_walk_mage_3=0;
        }
}

void mage_3_Attack(){
      setTextureUse_Mage(0,2);

      if(swap_texture_attack_mage_3 == 0){
          mage_3_attack = loadTexture("./Mage_3/mage_3_Atack_0.png");
          printf("1\n");
      }else if(swap_texture_attack_mage_3 == 1){
          mage_3_attack = loadTexture("./Mage_3/mage_3_Atack_1.png");
          printf("2\n");
      }else if(swap_texture_attack_mage_3 == 2){
        printf("3\n");  mage_3_attack = loadTexture("./Mage_3/mage_3_Atack_2.png");
      }else if(swap_texture_attack_mage_3 == 3){
          printf("4\n");mage_3_attack = loadTexture("./Mage_3/mage_3_Atack_3.png");
      }else if(swap_texture_attack_mage_3 == 4){
          printf("5\n");mage_3_attack = loadTexture("./Mage_3/mage_3_Atack_4.png");
      }else if(swap_texture_attack_mage_3 == 5){
          printf("6\n");mage_3_attack = loadTexture("./Mage_3/mage_3_Atack_5.png");
      }else if(swap_texture_attack_mage_3 == 6){
          printf("7\n");mage_3_attack = loadTexture("./Mage_3/mage_3_Atack_6.png");
      }
      swap_texture_attack_mage_3++;
      if(swap_texture_attack_mage_3 != 6)
        glutTimerFunc(80,mage_3_Attack,1);
}

void mage_3_Damage(){
  setTextureUse_Mage(0,3);

  if(swap_texture_damage_mage_3 ==0){
    printf("1\n");mage_3_damage = loadTexture("./Mage_3/mage_3_Damage_0.png");
  }else if(swap_texture_damage_mage_3 == 1){
    printf("2\n");mage_3_damage = loadTexture("./Mage_3/mage_3_Damage_1.png");
  }else if(swap_texture_damage_mage_3 == 2){
    printf("3\n");mage_3_damage = loadTexture("./Mage_3/mage_3_Damage_2.png");
  }else if(swap_texture_damage_mage_3 == 3){
    printf("4\n");mage_3_damage = loadTexture("./Mage_3/mage_3_Damage_3.png");
  }else if(swap_texture_damage_mage_3 == 4){
    printf("5\n");mage_3_damage = loadTexture("./Mage_3/mage_3_Damage_4.png");
  }
  swap_texture_damage_mage_3++;
  if(swap_texture_damage_mage_3 != 5)
    glutTimerFunc(80,mage_3_Damage,1);
}

void mage_3_Die(){

    if(swap_texture_die_mage_3 ==0){
        mage_3_die = loadTexture("./Mage_3/mage_3_Die_0.png");
    }else if(swap_texture_die_mage_3 == 1){
        mage_3_die = loadTexture("./Mage_3/mage_3_Die_1.png");
    }else if(swap_texture_die_mage_3 == 2){
        mage_3_die = loadTexture("./Mage_3/mage_3_Die_2.png");
    }else if(swap_texture_die_mage_3 == 3){
        mage_3_die = loadTexture("./Mage_3/mage_3_Die_3.png");
    }else if(swap_texture_die_mage_3 == 4){
        mage_3_die = loadTexture("./Mage_3/mage_3_Die_4.png");
    }else if(swap_texture_die_mage_3 == 5){
        mage_3_die = loadTexture("./Mage_3/mage_3_Die_5.png");
    }
    swap_texture_die_mage_3++;
    if(swap_texture_die_mage_3 != 6)
      glutTimerFunc(80,mage_3_Die,1);
}

void Mage_3_projetil_idle(){

  if(swap_texture_projetil_idle_mage_3 == 0){
      mage_3_projetil_idle = loadTexture("./Mage_3/mage_3_projetil_idle_0.png");
  }else if(swap_texture_projetil_idle_mage_3 == 1){
      mage_3_projetil_idle = loadTexture("./Mage_3/mage_3_projetil_idle_1.png");
  }else if(swap_texture_projetil_idle_mage_3 == 2){
      mage_3_projetil_idle = loadTexture("./Mage_3/mage_3_projetil_idle_2.png");
  }else if(swap_texture_projetil_idle_mage_3 == 3){
      mage_3_projetil_idle = loadTexture("./Mage_3/mage_3_projetil_idle_3.png");
  }else if(swap_texture_projetil_idle_mage_3 == 4){
      mage_3_projetil_idle = loadTexture("./Mage_3/mage_3_projetil_idle_4.png");
  }else if(swap_texture_projetil_idle_mage_3 == 5){
      mage_3_projetil_idle = loadTexture("./Mage_3/mage_3_projetil_idle_5.png");
  }

  swap_texture_projetil_idle_mage_3++;
  if(swap_texture_projetil_idle_mage_3 <= 5 && swap_texture_projetil_idle_mage_3 >= 0 )
    glutTimerFunc(10,Mage_3_projetil_idle,1);
}

void Mage_3_projetil_colision(){
  setTextureUse_Mage(0,6);

  if(swap_texture_projetil_colision_mage_3 == 0){
      mage_3_projetil_colision = loadTexture("./Mage_3/mage_3_projetil_colision_1.png");
  }else if(swap_texture_projetil_colision_mage_3 == 1){
      mage_3_projetil_colision = loadTexture("./Mage_3/mage_3_projetil_colision_2.png");
  }else if(swap_texture_projetil_colision_mage_3 == 2){
      mage_3_projetil_colision = loadTexture("./Mage_3/mage_3_projetil_colision_3.png");
  }else if(swap_texture_projetil_colision_mage_3 == 3){
      mage_3_projetil_colision = loadTexture("./Mage_3/mage_3_projetil_colision_4.png");
  }else if(swap_texture_projetil_colision_mage_3 == 4){
      mage_3_projetil_colision = loadTexture("./Mage_3/mage_3_projetil_colision_5.png");
  }else if(swap_texture_projetil_colision_mage_3 == 5){
      mage_3_projetil_colision = loadTexture("./Mage_3/mage_3_projetil_colision_6.png");
      ativa_projetil=0;
  }

  swap_texture_projetil_colision_mage_3++;
  if(swap_texture_projetil_colision_mage_3 != 5)
    glutTimerFunc(40,Mage_3_projetil_colision,1);
}

void mage_4_Idle(){
  setTextureUse_Mage(1,1);

  if(swap_texture_idle_mage_4 == 0){
      mage_4_idle = loadTexture("./Mage_4/mage_4_Idle.png");
  }else if(swap_texture_idle_mage_4 == 1){
        mage_4_idle = loadTexture("./Mage_4/mage_4_Idle.png");
    }
  swap_texture_idle_mage_4++;
  if(swap_texture_idle_mage_4 == 1)
      swap_texture_idle_mage_4 =0;
  glutTimerFunc(500,mage_4_Idle,1);
}

void mage_4_Walk(){
  setTextureUse_Mage(1,1);

  if(swap_texture_walk_mage_4 == 0){
      mage_4_walk = loadTexture("./Mage_4/mage_4_Andando_0.png");
  }else if(swap_texture_walk_mage_4 == 1){
      mage_4_walk = loadTexture("./Mage_4/mage_4_Andando_1.png");
  }else if (swap_texture_walk_mage_4 == 2) {
      mage_4_walk = loadTexture("./Mage_4/mage_4_Andando_2.png");
  }else if (swap_texture_walk_mage_4 == 3) {
      mage_4_walk = loadTexture("./Mage_4/mage_4_Andando_3.png");
  }else if (swap_texture_walk_mage_4 == 4) {
      mage_4_walk = loadTexture("./Mage_4/mage_4_Andando_4.png");
  }else if (swap_texture_walk_mage_4 == 5) {
      mage_4_walk = loadTexture("./Mage_4/mage_4_Andando_5.png");
  }else if (swap_texture_walk_mage_4 == 6) {
      mage_4_walk = loadTexture("./Mage_4/mage_4_Andando_6.png");
  }else if (swap_texture_walk_mage_4 == 7) {
      mage_4_walk = loadTexture("./Mage_4/mage_4_Andando_7.png");
  }
  swap_texture_walk_mage_4++;
    if (swap_texture_walk_mage_4==7) {
      swap_texture_walk_mage_4=0;
    }
}

void mage_4_Attack(){
  setTextureUse_Mage(1,2);

  if(swap_texture_attack_mage_4 == 0){
      mage_4_attack = loadTexture("./Mage_4/mage_4_Ataque_0.png");
  }else if(swap_texture_attack_mage_4 == 1){
      mage_4_attack = loadTexture("./Mage_4/mage_4_Ataque_1.png");
  }else if(swap_texture_attack_mage_4 == 2){
      mage_4_attack = loadTexture("./Mage_4/mage_4_Ataque_2.png");
  }else if(swap_texture_attack_mage_4 == 3){
      mage_4_attack = loadTexture("./Mage_4/mage_4_Ataque_3.png");
  }

  swap_texture_walk_mage_4++;
  if(swap_texture_attack_mage_4 != 3)
    glutTimerFunc(80,mage_4_Attack,1);
}

void mage_4_Damage(){

    setTextureUse_Mage(1,3);

    if(swap_texture_damage_mage_4 == 0){
        mage_4_damage = loadTexture("./Mage_4/mage_4_Ataque_1.png");
    }else if(swap_texture_damage_mage_4 == 1){
        mage_4_damage = loadTexture("./Mage_4/mage_4_Ataque_0.png");
    }else if(swap_texture_damage_mage_4 == 2){
        mage_4_damage = loadTexture("./Mage_4/mage_4_dano.png");
    }else if(swap_texture_damage_mage_4 == 3){
        mage_4_damage = loadTexture("./Mage_4/mage_4_Ataque_1.png");
    }else if(swap_texture_damage_mage_4 == 4){
        mage_4_damage = loadTexture("./Mage_4/mage_4_Ataque_0.png");
    }

    swap_texture_damage_mage_4++;
    if(swap_texture_damage_mage_4 != 5)
      glutTimerFunc(80,mage_4_Damage,1);
}

void mage_4_Die(){
  if(swap_texture_die_mage_4 == 0){
      mage_4_die = loadTexture("./Mage_4/mage_4_morrendo_0.png");
  }else if(swap_texture_die_mage_4 == 1){
      mage_4_die = loadTexture("./Mage_4/mage_4_morrendo_1.png");
  }else if(swap_texture_die_mage_4 == 2){
      mage_4_die = loadTexture("./Mage_4/mage_4_morrendo_2.png");
  }else if(swap_texture_die_mage_4 == 3){
      mage_4_die = loadTexture("./Mage_4/mage_4_morrendo_3.png");
  }

  swap_texture_die_mage_4++;
  if(swap_texture_die_mage_4 < 4)
    glutTimerFunc(80,mage_4_Die,1);
}

void Mage_4_projetil_idle(){
  setTextureUse_Mage(1,5);

  if(swap_texture_projetil_idle_mage_4 == 0){
      mage_4_projetil_idle = loadTexture("./Mage_4/mage_4_projetil_idle_0.png");
  }else if(swap_texture_projetil_idle_mage_4 == 1){
      mage_4_projetil_idle = loadTexture("./Mage_4/mage_4_projetil_idle_1.png");
  }else if(swap_texture_projetil_idle_mage_4 == 2){
      mage_4_projetil_idle = loadTexture("./Mage_4/mage_4_projetil_idle_2.png");
  }else if(swap_texture_projetil_idle_mage_4 == 3){
      mage_4_projetil_idle = loadTexture("./Mage_4/mage_4_projetil_idle_3.png");
  }else if(swap_texture_projetil_idle_mage_4 == 4){
      mage_4_projetil_idle = loadTexture("./Mage_4/mage_4_projetil_idle_4.png");
  }else if(swap_texture_projetil_idle_mage_4 == 5){
      mage_4_projetil_idle = loadTexture("./Mage_4/mage_4_projetil_idle_5.png");
  }

  swap_texture_projetil_idle_mage_4++;
  if(swap_texture_projetil_idle_mage_4 != 5)
    glutTimerFunc(80,Mage_4_projetil_idle,1);
}

void Mage_4_projetil_colision(){
  setTextureUse_Mage(1,6);

  if(swap_texture_projetil_colision_mage_3 == 0){
      mage_4_projetil_colision = loadTexture("./Mage_4/mage_4_projetil_colision_1.png");
  }else if(swap_texture_projetil_colision_mage_3 == 1){
      mage_4_projetil_colision = loadTexture("./Mage_4/mage_4_projetil_colision_2.png");
  }else if(swap_texture_projetil_colision_mage_3 == 2){
      mage_4_projetil_colision = loadTexture("./Mage_4/mage_4_projetil_colision_3.png");
  }else if(swap_texture_projetil_colision_mage_3 == 3){
      mage_4_projetil_colision = loadTexture("./Mage_4/mage_4_projetil_colision_4.png");
  }else if(swap_texture_projetil_colision_mage_3 == 4){
      mage_4_projetil_colision = loadTexture("./Mage_4/mage_4_projetil_colision_5.png");
  }else if(swap_texture_projetil_colision_mage_3 == 5){
      mage_4_projetil_colision = loadTexture("./Mage_4/mage_4_projetil_colision_6.png");
      ativa_projetil=0;
  }

  swap_texture_projetil_colision_mage_4++;
  if(swap_texture_projetil_colision_mage_4 != 5)
    glutTimerFunc(80,Mage_4_projetil_colision,1);
}


void TimerFunc_1(int c){
  if (c == 0) {

      setTextureUse_Mage(0,0);
      glutTimerFunc(0,mage_3_Idle,0);
  }else if(c == 1){
      setTextureUse_Mage(0,1);
      glutTimerFunc(0,mage_3_Walk,0);
  }else if(c == 2){
      swap_texture_attack_mage_3=0;
      setTextureUse_Mage(0,2);
      glutTimerFunc(0,mage_3_Attack,0);
  }else if(c == 3){
      swap_texture_damage_mage_3 = 0;
      setTextureUse_Mage(0,3);
      glutTimerFunc(0,mage_3_Damage,0);
  }else if(c == 4){
      swap_texture_die_mage_3=0;
      setTextureUse_Mage(0,4);
      glutTimerFunc(0,mage_3_Die,0);
  }else if (c == 5){
      swap_texture_projetil_idle_mage_3=0;
      setTextureUse_Mage(0,5);
      glutTimerFunc(0,Mage_3_projetil_idle,0);
  }else if (c == 6){
      swap_texture_projetil_colision_mage_3 = 0;
      setTextureUse_Mage(0,6);
      glutTimerFunc(0,Mage_3_projetil_colision,0);
  }
}

void TimerFunc_2(int c){
  if (c == 0) {
      glutTimerFunc(0,mage_4_Idle,0);
  }else if(c == 1){
      glutTimerFunc(0,mage_4_Walk,0);
  }else if(c == 2){
      swap_texture_attack_mage_4=0;
      glutTimerFunc(0,mage_4_Attack,0);
  }else if(c == 3){
      swap_texture_damage_mage_4 = 0;
      glutTimerFunc(0,mage_4_Damage,0);
  }else if(c == 4){
      setTextureUse_Mage(1,4);
      glutTimerFunc(0,mage_4_Die,0);
  }else if (c == 5){
      glutTimerFunc(0,Mage_3_projetil_idle,0);
  }else if (c == 6){
      swap_texture_projetil_colision_mage_4 = 0;
      glutTimerFunc(0,Mage_3_projetil_colision,0);
  }
}
