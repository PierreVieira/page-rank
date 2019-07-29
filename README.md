# Algoritmo de Page Rank no Brasileirão de 2017

Programa escrito em C para auxiliar nas aulas de Page Rank em Matemática Discreta do curso de Engenharia de Computação (CEFET-MG) ministradas pelo professor Daniel Hasan. O código é uma remodelação do código implementado por Mônica Karine.

O objetivo dessa implementação foi limpar os memory leaks do código anterior e remodelar algumas partes do código para não ocorrer warnings. Além disso, o código foi reestruturado para que no arquivo `main.c` só tenha as funções que serão implementadas pelos alunos, evitando que eles fiquem perdidos com várias outras funções que nem serão implementadas por eles.

## Compilação e Execução
Basta clonar esse repositório ou baixar o .zip.
Dentro da pasta, execute:
```
make
./main
```
Os vértices serão mostrados em ordem decrescente de Page Rank.

## Documentação
Está incluido a pasta `documentation`. Dentro, é possível encontrar a pasta `html` que possui uma documentação interativa gerada pelo programa Doxygen. Para acessá-la basta abrir a pasta `html` e clicar em index.html.

Outra forma de acessar a documentação é pela pasta `latex` que possui um `Makefile` para gerar um .PDF com links sobre o código. Para acessar basta executar o comando `make` dentro da pasta `latex`. É necessário ter os arquivos necessários para utilizar o Latex para gerar o PDF.
