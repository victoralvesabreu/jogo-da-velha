#ifndef LIBFUNC
#define LIBFUNC
#endif


#include "stdio.h"
#include "allegro.h"

#define BOLINHA 1
#define XISZINHO 2
#define NENHUM 0
#define TURNOB 0
#define TURNOX 1
#define EMPATE 3

typedef struct {
  int pos_x, pos_y, estado, id;
}Base;


Base base[3][3];


void escreverMatriz(int i, int u);
