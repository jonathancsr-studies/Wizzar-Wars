#ifndef TEXTURA_H
#define TEXTURA_H
GLuint tex;
GLuint mage_3_idle;
GLuint mage_3_walk;
GLuint mage_3_attack;
GLuint mage_3_damage;
GLuint mage_3_die;
unsigned int textureuse_mage3;



unsigned int loadTexture(char nometextura[]);
unsigned int loadTexture_2(char nometextura[]);
void inittext();
void mage_3_Idle();
void mage_3_Walk();
void mage_3_Attack();
void mage_3_Damage();
void mage_3_Die();

void setTextureUse_Mage3(int c);

#endif
