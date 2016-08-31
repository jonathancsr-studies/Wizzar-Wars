void teclaPresionada(unsigned char key, int x, int y){

  switch (key) {
// P
    case 80:
      //pause();
      break;
// R
    case 82:
      //reiniciaJogo();
      break;
// ESC
    case 27:
      exit(0);
      break;
    default:
      break;
  }

}
