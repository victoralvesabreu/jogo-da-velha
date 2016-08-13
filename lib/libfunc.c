#include "libfunc.h"

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
