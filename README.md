# jogo-da-velha

Jogo feito em C usando a biblioteca allegro.h 

## instalação biblioteca allegro
Para compilar precisa ter instalado os pacote gcc e liballegro-dev e make
### no ubuntu
```
$   sudo apt install liballegro4-dev gcc make
```

## compilação
antes de compilar execute o comando no terminal
```
$ allegro-config --cflags --libs
copie a saida e substitua o valor da variavel ALLEGRO no arquivo makefile na primeira linha
```

execute este comando no terminal(linux) dentro do diretorio principal do jogo

```
$ make
ou
$ make -s 
para não exibir alertas
```
