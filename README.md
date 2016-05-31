# jogo-da-velha
Jogo feito em C usando a biblioteca allegro.h 
# compilação
Para compilar precisa ter instalado os pacote "gcc" e liballegro-dev ou -devel dependendo do SO
rode esse comando no terminal(linux)

gcc main.c -o main $(allegro-config --libs --cflags)
