#ifndef TEXTURA_H
#define TEXTURA_H
GLuint tex;
GLuint mage_3,mage_3_projetil;
GLuint mage_4, mage_4_projetil;
GLuint menu_texture,menu_hover,fundo,lua,vento_texture,vida_mage_3,vida_mage_4;
GLuint menu_texture_v[10],mage_3_texture[45],mage_4_texture[45],vento_texture_v[7],vida_texture_f[8];

int TimerFunc_1_constant_projetil,TimerFunc_1_constant,vento_set;
int TimerFunc_2_constant_projetil,TimerFunc_2_constant;

int texture_set_menu,texture_set_1,texture_set_2,texture_set_1_projetil,texture_set_2_projetil;

unsigned int loadTexture(char nometextura[]);

void inittext();
void carrega_textura();
void textura_vento();

void TimerFunc_1();
void TimerFunc_2();
void TimerFunc_1_Projetil();
void TimerFunc_2_Projetil();

void mage_3_Idle();
void mage_3_Walk();
void mage_3_Attack();
void mage_3_Damage();
void mage_3_Die();
void Mage_3_projetil_idle();
void Mage_3_projetil_colision();
void vidas_func();

void mage_4_Idle();
void mage_4_Walk();
void mage_4_Attack();
void mage_4_Damage();
void mage_4_Die();
void Mage_4_projetil_idle();
void Mage_4_projetil_colision();

void util_texture();

#endif
