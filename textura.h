#ifndef TEXTURA_H
#define TEXTURA_H
GLuint tex;
GLuint mage_3_idle_0,mage_3_idle_1,mage_3_idle_2,mage_3_idle_3,mage_3_idle_4,mage_3_idle_5;
GLuint mage_3_walk_0,mage_3_walk_1,mage_3_walk_2,mage_3_walk_3,mage_3_walk_4,mage_3_walk_5,mage_3_walk_6,mage_3_walk_7;
GLuint mage_3_attack_0,mage_3_attack_1,mage_3_attack_2,mage_3_attack_3,mage_3_attack_4,mage_3_attack_5,mage_3_attack_6;
GLuint mage_3_damage_0,mage_3_damage_1,mage_3_damage_2,mage_3_damage_3,mage_3_damage_4;
GLuint mage_3_die_0,mage_3_die_1,mage_3_die_2,mage_3_die_3,mage_3_die_4,mage_3_die_5;



int loadTexture(char nometextura[]);
void inittext();
void mage_3_Idle();
void mage_3_Walk();
void mage_3_Attack();
void mage_3_Damage();
void mage_3_Die();


#endif
