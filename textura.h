#ifndef TEXTURA_H
#define TEXTURA_H
GLuint tex;
GLuint mage_3_idle, mage_3_walk, mage_3_attack, mage_3_damage, mage_3_die;
GLuint mage_4_idle, mage_4_walk, mage_4_attack, mage_4_damage, mage_4_die;
unsigned int textureuse_mage3;
unsigned int textureuse_mage4;



unsigned int loadTexture(char nometextura[]);
unsigned int loadTexture_2(char nometextura[]);

void inittext();

void mage_3_Idle();
void mage_3_Walk();
void mage_3_Attack();
void mage_3_Damage();
void mage_3_Die();

void mage_4_Idle();
void mage_4_Walk();
void mage_4_Attack();
void mage_4_Damage();
void mage_4_Die();

void setTextureUse_Mage3(int c);
void setTextureUse_Mage4(int c);

#endif
