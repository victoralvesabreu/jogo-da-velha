/*
* Autor: victor alves
* Project Name: Incrivel Jogo da Velha
* Versão: 0.1
* Git repository: https://github.com/victoralvesabreu/Jogo-da-velha-allegro
*/
#include "allegro.h"
#include <stdio.h>
#include "lib/libfunc.h"


volatile int exit_program = FALSE;

volatile int ticks;

void fechar_programa() {
  exit_program = TRUE;
}
END_OF_FUNCTION(fechar_programa);

void incrementa_ticks() {
  ticks++;
}
END_OF_FUNCTION(incrementa_ticks);

int main() {

  allegro_init();
  install_timer();
  install_keyboard();
  set_color_depth(32);
  set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0);
  set_window_title("O Incrivel Jogo da Velha");

  LOCK_VARIABLE(exit_program);
  LOCK_FUNCTION(fechar_programa);
  set_close_button_callback(fechar_programa);

  //Declaração de variaves comuns

  int jogar = FALSE;
  int i = 0, u = 0, aux_x = 0, aux_y = 0, vencedor = 0, cont;
  int coresMatriz = makecol(0, 255, 255), turno = TURNOB, partida = TRUE;
  int estadoTeclaDireita, estadoTeclaEsquerda, estadoTeclaSubir;
  int estadoTeclaDescer, estadoTeclaEspaco, estadoTeclaEnter1, estadoTeclaEnter2;
  //fim Declaração de variaves comuns


  escreverMatriz(i, u);



  ticks = 0;
  LOCK_FUNCTION(incrementa_ticks);
  LOCK_VARIABLE(ticks);
  install_int_ex(incrementa_ticks, BPS_TO_TIMER(60));


  //BITMAPS
  BITMAP* buffer = create_bitmap(SCREEN_W, SCREEN_H);
  BITMAP* titulo = load_bitmap("img/titulo.bmp",NULL);
  BITMAP* xiszinho = load_bitmap("img/Xiszinho.bmp", NULL);
  BITMAP* bolinha = load_bitmap("img/Bolinha.bmp", NULL);


  while (!exit_program) {

    while (ticks > 0 && !exit_program) {

      if (key[KEY_ENTER]) {
        jogar = TRUE;
      }

      if (key[KEY_ESC]){
        exit_program = TRUE;
      }
      draw_sprite(buffer, titulo, 0, 0);


      if(jogar == TRUE){
        if(partida == TRUE){
          rect(buffer, SCREEN_W/4, SCREEN_H/4, SCREEN_W - SCREEN_W/4, SCREEN_H - SCREEN_H/4, makecol(255, 255, 255));
          line(buffer, SCREEN_W/4 + 20, SCREEN_H/4 + SCREEN_H/6, SCREEN_W - SCREEN_W/4 - 20, SCREEN_H/4 + SCREEN_H/6, coresMatriz);
          line(buffer, SCREEN_W/4 + 20, SCREEN_H/4 + SCREEN_H/6 + SCREEN_H/6, SCREEN_W - SCREEN_W/4 - 20, SCREEN_H/4 + SCREEN_H/6 + SCREEN_H/6, coresMatriz);
          line(buffer, SCREEN_W/2 - SCREEN_W/14, SCREEN_H/4 + 20, SCREEN_W/2 - SCREEN_W/14, SCREEN_H - SCREEN_H/4 - 20, coresMatriz);
          line(buffer, SCREEN_W/2 + SCREEN_W/14, SCREEN_H/4 + 20, SCREEN_W/2 + SCREEN_W/14, SCREEN_H - SCREEN_H/4 - 20, coresMatriz);



          rect(buffer, base[aux_y][aux_x].pos_x, base[aux_y][aux_x].pos_y + 10, base[aux_y][aux_x].pos_x + 100 + 10, base[aux_y][aux_x].pos_y + 95, makecol(255, 0, 0));


          //as configurações das teclas ficam aqui
          if (key[KEY_RIGHT] && estadoTeclaDireita == 0) {
            if(aux_y < 2){
              aux_y += 1;
            }
          }
          estadoTeclaDireita = key[KEY_RIGHT];

          if (key[KEY_DOWN] && estadoTeclaDescer == 0) {
            if (aux_x < 2) {
              aux_x += 1;
            }
          }
          estadoTeclaDescer = key[KEY_DOWN];

          if (key[KEY_LEFT] && estadoTeclaEsquerda == 0) {
            if (aux_y > 0) {
              aux_y -= 1;
            }
          }
          estadoTeclaEsquerda = key[KEY_LEFT];

          if (key[KEY_UP] && estadoTeclaSubir == 0) {
            if (aux_x > 0) {
              aux_x -= 1;
            }
          }
          estadoTeclaSubir = key[KEY_UP];

          if (key[KEY_SPACE] && base[aux_y][aux_x].estado == NENHUM && estadoTeclaEspaco == 0) {
            if (turno == TURNOB) {
              base[aux_y][aux_x].estado = BOLINHA;
              turno = TURNOX;
            }else if (turno == TURNOX){
              base[aux_y][aux_x].estado = XISZINHO;
              turno = TURNOB;
            }
          }
          estadoTeclaEspaco = key[KEY_SPACE];
          //as configurações das teclas terminam aqui

          if (turno == TURNOB){
            textout(buffer, font, "Jogador 1: Bolinha", SCREEN_W/2, SCREEN_H/5, makecol(255, 255, 255));
          }else {
            textout(buffer, font, "Jogador 2: Xiszinho", SCREEN_W/2, SCREEN_H/5,makecol(255, 255, 255));
          }

          i = 0;
          u = 0;

          while (i<3) {
            while(u<3){
              switch (base[i][u].estado) {
                case NENHUM:
                //não faz nada
                break;
                case BOLINHA:
                draw_sprite(buffer, bolinha, base[i][u].pos_x, base[i][u].pos_y);

                break;
                case XISZINHO:
                draw_sprite(buffer, xiszinho, base[i][u].pos_x, base[i][u].pos_y);
                break;
                default:
                printf("erro ao montar matriz!!\n");
                return 0;
              }
              u++;
            }
            i++;
            u = 0;
          }

          for (i = 1; i < 3; i++) {
            if (base[0][0].estado == i && base[1][0].estado == i && base[2][0].estado == i) {
              partida = FALSE;
              vencedor = i;
            }else if (base[0][1].estado == i && base[1][1].estado == i && base[2][1].estado == i){
              partida = FALSE;
              vencedor = i;
            }else if (base[0][2].estado == i && base[1][2].estado == i && base[2][2].estado == i){
              partida = FALSE;
              vencedor = i;
            }else if (base[0][0].estado == i && base[0][1].estado == i && base[0][2].estado == i){
              partida = FALSE;
              vencedor = i;
            }else if (base[1][0].estado == i && base[1][1].estado == i && base[1][2].estado == i){
              partida = FALSE;
              vencedor = i;
            }else if (base[2][0].estado == i && base[2][1].estado == i && base[2][2].estado == i){
              partida = FALSE;
              vencedor = i;
            }else if (base[0][0].estado == i && base[1][1].estado == i && base[2][2].estado == i){
              partida = FALSE;
              vencedor = i;
            }else if (base[2][0].estado == i && base[1][1].estado == i && base[0][2].estado == i){
              partida = FALSE;
              vencedor = i;
            }

          }
          cont = 0;
          for (i = 0; i < 3; i++) {
            for (u = 0; u < 3; u++) {
              if (base[i][u].estado != 0) {
                cont++;
              }
              if (cont == 9 && vencedor == 0) {
                vencedor = EMPATE;
                partida = FALSE;

              }
            }
          }

        }
        //processamento inteligencia do jogo

        if (vencedor == BOLINHA) {
          textout_centre(buffer, font, "Jogador 1 é o Vencedor", SCREEN_W/2, SCREEN_H/2, makecol(255, 255, 255));
          textout_centre(buffer, font, "Aperte ENTER para jogar novamente!!", SCREEN_W/2, SCREEN_H/2+20, makecol(255, 255, 255));
          if (key[KEY_ENTER]) {
            i = 0;
            u = 0;
            aux_x = 0;
            aux_y = 0;
            escreverMatriz(i, u);
            vencedor = 0;
            partida = TRUE;
          }

        }else if (vencedor == XISZINHO){
          textout_centre(buffer, font, "Jogador 2 é o Vencedor", SCREEN_W/2, SCREEN_H/2, makecol(255, 255, 255));
          textout_centre(buffer, font, "Aperte ENTER para jogar novamente!!", SCREEN_W/2, SCREEN_H/2+20, makecol(255, 255, 255));

          if (key[KEY_ENTER]) {
            i = 0;
            u = 0;
            aux_x = 0;
            aux_y = 0;
            escreverMatriz(i, u);
            vencedor = 0;
            partida = TRUE;
          }

        }else if (vencedor == EMPATE){
          textout_centre(buffer, font, "Empate!!", SCREEN_W/2, SCREEN_H/2, makecol(255, 255, 255));
          textout_centre(buffer, font, "Aperte ENTER para jogar novamente!!", SCREEN_W/2, SCREEN_H/2+20, makecol(255, 255, 255));

          if (key[KEY_ENTER]) {
            i = 0;
            u = 0;
            aux_x = 0;
            aux_y = 0;
            escreverMatriz(i, u);
            vencedor = 0;
            partida = TRUE;
        }
      }

        //fim processamento inteligencia do jogo

      }else{
        textout_centre(buffer, font, "Aperte Enter", SCREEN_W/2, SCREEN_H/2, makecol(255, 0, 0));
      }



      textout_right(buffer, font, "Build by Victor Alves Abreu", SCREEN_W - 20, SCREEN_H - 40, makecol(255, 255, 255));
      textout_right(buffer, font, "copyright © 2016 - GNU GENERAL PUBLIC LICENSE", SCREEN_W - 20, SCREEN_H - 20, makecol(255, 255, 255));
      draw_sprite(screen, buffer, 0, 0);
      //clear_to_color(screen, makecol(0, 0, 0));
    }
  }

  //FINALIZAÇÂO
  destroy_bitmap(buffer);

  allegro_exit();

  return (EXIT_SUCCESS);
}
END_OF_MAIN();
