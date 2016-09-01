void movimentoPersonagemDireita(int a){

      glPushMatrix();                 // Importante!!
      
      glTranslatef(5, 0);
      if(a==1){
      desenhaPersonagem(1);
      }else{
            desenhaPersonagem(0);
      }
      glPopMatrix();                  // Importante!!

}

void movimentoPersonagemDireita(int a){

      glPushMatrix();                 // Importante!!
      
      glTranslatef(-5, 0);
      if(a==1){
      desenhaPersonagem(1);
      }else{
            desenhaPersonagem(0);
      }
      glPopMatrix();                  // Importante!!

}
//http://www.inf.pucrs.br/~pinho/CG/Aulas/OpenGL/TransformacoesGL.html

