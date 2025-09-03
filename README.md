# Conway's Game of Life em C com Raylib
Este projeto é uma implementação do "Jogo da Vida" de John Conway, desenvolvido em C utilizando a biblioteca Raylib para a renderização gráfica.

## Descrição
O Jogo da Vida é um autômato celular que consiste em uma grade de células que podem estar "vivas" ou "mortas". O estado de cada célula na próxima geração é determinado por um conjunto de regras simples, baseadas no número de vizinhos vivos.

As regras, inspiradas no livro "The Nature of Code", são as seguintes:

1.  Uma célula morta com exatamente 3 vizinhos vivos torna-se viva.
2.  Uma célula viva com menos de 2 ou mais de 3 vizinhos vivos morre.
3.  Nos demais casos, a célula mantém seu estado atual.

## Funcionalidades
  * Geração de um tabuleiro inicial com células em estados aleatórios.
  * Visualização da evolução do Jogo da Vida em tempo real.
  * Implementação das regras clássicas do Jogo da Vida de Conway.
  * Utilização da biblioteca Raylib para uma renderização simples e eficiente.

## Como Compilar e Executar

### Pré-requisitos

Para compilar e executar este projeto, você precisará ter o compilador `gcc` e a biblioteca `Raylib` instalados no seu sistema.

### Compilação

Você pode compilar o projeto utilizando o `makefile` fornecido. Basta executar o seguinte comando no terminal:

```bash
make
```

Este comando irá compilar os arquivos `main.c` e `engine.c`, gerando um executável chamado `main`, e em seguida, irá executá-lo.

Ou se desejar compilar diretamente com o comando:
```bash
gcc main.c engine.c -o main
```
para rodar:
```bash
./main
```

## Estrutura do Projeto

  * `main.c`: Ponto de entrada do programa.
  * `engine.c`: Contém toda a lógica do jogo, incluindo a criação e atualização do tabuleiro, e a renderização gráfica.
  * `engine.h`: Arquivo de cabeçalho para o motor do jogo.
  * `makefile`: Facilita a compilação e execução do projeto.

## Agradecimentos

Este projeto foi desenvolvido como parte de um esforço de aprendizado e criação de portfólio. A inspiração para as regras do Jogo da Vida veio do livro "The Nature of Code" de Daniel Shiffman.
