#include "libfunc.h"


void incrementa_ticks() {
  ticks++;
}
END_OF_FUNCTION(incrementa_ticks);

void fechar_programa(int exit_program) {
  exit_program = TRUE;
}
END_OF_FUNCTION(fechar_programa);

void escreverMatriz(int i, int u){
  while (i<3) {
    while(u<3){
      base[i][u].estado = NENHUM;
      base[i][u].pos_y = SCREEN_H / 4 + ((SCREEN_H / 6) * u);
      base[i][u].pos_x = SCREEN_W / 4 + ((SCREEN_W / 6) * i) + 20;
      u++;
    }
    i++;
    u = 0;
  }
}
