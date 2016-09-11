#include "include.h"
int swap_texture_idle_mage_3=0,
    swap_texture_walk_mage_3=0,
    swap_texture_attack_mage_3=0,
    swap_texture_damage_mage_3=0,
    swap_texture_die_mage_3=0;
char textureuse[];
void setTextureUse(char ch[]){

  textureuse=ch;
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

void inittexture(){
  mage_3_Idle();
  mage_3_Walk();
  mage_3_Attack();
  mage_3_Damage();
  mage_3_Die();
}

void mage_3_Idle(){

	if(swap_texture_idle_mage_3 == 0){
		mage_3_idle = loadTexture("./Mage_3/mage_3_Idle_0.png");
  }
	else if(swap_texture_idle_mage_3 == 1){
		mage_3_idle = loadTexture("./Mage_3/mage_3_Idle_1.png");
    puts("entrou_2");
  }
	else if(swap_texture_idle_mage_3 == 2){
		mage_3_idle = loadTexture("./Mage_3/mage_3_Idle_2.png");
    puts("entrou_3");
	}else if(swap_texture_idle_mage_3 == 3){
		mage_3_idle = loadTexture("./Mage_3/mage_3_Idle_3.png");
      puts("entrou_4");
  }else if(swap_texture_idle_mage_3 == 4){
		mage_3_idle = loadTexture("./Mage_3/mage_3_Idle_4.png");
      puts("entrou_5");
  }else if(swap_texture_idle_mage_3 == 5){
		mage_3_idle = loadTexture("./Mage_3/mage_3_Idle_5.png");
    puts("entrou_6");
	}
printf("%d\n",swap_texture_idle_mage_3);
swap_texture_idle_mage_3+=1;
if(swap_texture_idle_mage_3 == 5)
    swap_texture_idle_mage_3 =0;
}

void mage_3_Walk(){
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

    puts("passoou_80");
    if(swap_texture_walk_mage_3 == 7)
        swap_texture_walk_mage_3=0;
}

void mage_3_Attack(){
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

      puts("passoou_81");
      if(swap_texture_attack_mage_3 == 6)
          swap_texture_attack_mage_3=0;
}

void mage_3_Damage(){

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

  puts("passoou_82");
  if(swap_texture_damage_mage_3 == 4)
      swap_texture_damage_mage_3=0;
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

    if(swap_texture_die_mage_3 == 5)
        swap_texture_die_mage_3=0;
}
