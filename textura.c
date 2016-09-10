#include "include.h"

void inittext(){

      textura_mago1 = SOIL_load_OGL_texture(
            "Mage_Parado_1.png",
            SOIL_LOAD_AUTO,
            SOIL_CREATE_NEW_ID,
            SOIL_FLAG_INVERT_Y
      );
      if (textura_mago1 == 0) {
        printf("Erro carregando textura: '%s'\n", SOIL_last_result());
      }
}
