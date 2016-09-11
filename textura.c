#include "include.h"

int swap_texture_idle_mage_3=0,
    swap_texture_walk_mage_3=0,
    swap_texture_attack_mage_3=0,
    swap_texture_damage_mage_3=0,
    swap_texture_die_mage_3=0;
void setTextureUse_Mage3(int c){
    if(c == 0)
      textureuse_mage3=mage_3_idle;
    else if(c == 1)
      textureuse_mage3=mage_3_walk;
    else if(c == 2)
      textureuse_mage3=mage_3_attack;
    else if(c == 3)
      textureuse_mage3=mage_3_damage;
    else if(c == 4)
      textureuse_mage3=mage_3_die;
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
}

void mage_3_Idle(){
  setTextureUse_Mage3(0);

	if(swap_texture_idle_mage_3 == 0){
		mage_3_idle = loadTexture("./Mage_3/mage_3_Idle_0.png");
  }
	else if(swap_texture_idle_mage_3 == 1){
		mage_3_idle = loadTexture("./Mage_3/mage_3_Idle_1.png");
  }
	else if(swap_texture_idle_mage_3 == 2){
		mage_3_idle = loadTexture("./Mage_3/mage_3_Idle_2.png");
	}else if(swap_texture_idle_mage_3 == 3){
		mage_3_idle = loadTexture("./Mage_3/mage_3_Idle_3.png");
  }else if(swap_texture_idle_mage_3 == 4){
		mage_3_idle = loadTexture("./Mage_3/mage_3_Idle_4.png");
  }else if(swap_texture_idle_mage_3 == 5){
		mage_3_idle = loadTexture("./Mage_3/mage_3_Idle_5.png");
	}
  swap_texture_idle_mage_3+=1;
  if(swap_texture_idle_mage_3 == 5)
      swap_texture_idle_mage_3 =0;
  glutTimerFunc(500,mage_3_Idle,1);
}

void mage_3_Walk(){
    setTextureUse_Mage3(1);
    if(swap_texture_walk_mage_3 == 0){
        mage_3_walk = loadTexture("./Mage_3/mage_3_Walk_0.png");
    }else if(swap_texture_walk_mage_3 == 1){
        mage_3_walk = loadTexture("./Mage_3/mage_3_Walk_1.png");
    }else if(swap_texture_walk_mage_3 == 2){
        mage_3_walk = loadTexture("./Mage_3/mage_3_Walk_2.png");
    }else if(swap_texture_walk_mage_3 == 3){
        mage_3_walk = loadTexture("./Mage_3/mage_3_Walk_3.png");
    }else if(swap_texture_walk_mage_3 == 4){
        mage_3_walk = loadTexture("./Mage_3/mage_3_Walk_4.png");
    }else if(swap_texture_walk_mage_3 == 5){
        mage_3_walk = loadTexture("./Mage_3/mage_3_Walk_5.png");
    }else if(swap_texture_walk_mage_3 == 6){
        mage_3_walk = loadTexture("./Mage_3/mage_3_Walk_6.png");
    }else if(swap_texture_walk_mage_3 == 7){
        mage_3_walk = loadTexture("./Mage_3/mage_3_Walk_7.png");
    }
    swap_texture_walk_mage_3++;
      if (swap_texture_walk_mage_3==7) {
        swap_texture_walk_mage_3=0;
      }
}
void mage_3_Walk_2(){
    setTextureUse_Mage3(1);
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
    setTextureUse_Mage3(2);
      if(swap_texture_attack_mage_3 ==0){
          mage_3_attack = loadTexture("./Mage_3/mage_3_Atack_0.png");
      }else if(swap_texture_attack_mage_3 == 1){
          mage_3_attack = loadTexture("./Mage_3/mage_3_Atack_1.png");
      }else if(swap_texture_attack_mage_3 == 2){
          mage_3_attack = loadTexture("./Mage_3/mage_3_Atack_2.png");
      }else if(swap_texture_attack_mage_3 == 3){
          mage_3_attack = loadTexture("./Mage_3/mage_3_Atack_3.png");
      }else if(swap_texture_attack_mage_3 == 4){
          mage_3_attack = loadTexture("./Mage_3/mage_3_Atack_4.png");
      }else if(swap_texture_attack_mage_3 == 5){
          mage_3_attack = loadTexture("./Mage_3/mage_3_Atack_5.png");
      }else if(swap_texture_attack_mage_3 == 6){
          mage_3_attack = loadTexture("./Mage_3/mage_3_Atack_6.png");
      }
      swap_texture_attack_mage_3++;
      if(swap_texture_attack_mage_3 != 7)
        glutTimerFunc(80,mage_3_Attack,1);
}

void mage_3_Damage(){
  setTextureUse_Mage3(3);
  if(swap_texture_damage_mage_3 ==0){
    mage_3_damage = loadTexture("./Mage_3/mage_3_Damage_0.png");
  }else if(swap_texture_damage_mage_3 == 1){
    mage_3_damage = loadTexture("./Mage_3/mage_3_Damage_1.png");
  }else if(swap_texture_damage_mage_3 == 2){
    mage_3_damage = loadTexture("./Mage_3/mage_3_Damage_2.png");
  }else if(swap_texture_damage_mage_3 == 3){
    mage_3_damage = loadTexture("./Mage_3/mage_3_Damage_3.png");
  }else if(swap_texture_damage_mage_3 == 4){
    mage_3_damage = loadTexture("./Mage_3/mage_3_Damage_4.png");
  }
  swap_texture_damage_mage_3++;
  if(swap_texture_damage_mage_3 != 5)
    glutTimerFunc(80,mage_3_Damage,1);
}

void mage_3_Die(){
  setTextureUse_Mage3(4);
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
