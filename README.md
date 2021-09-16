# Projeto 3: Snaze

* **Snake game:**
    - Do que se trata:
        Simulação do jogo clássico Snake arcade vídeo game
    com uma diferença: a cobra está presa dentro de um labirinto!
    A simulação do jogo Snaze carrega o nível do labirinto a partir de um arquivo texto de entrada,
    cujo nome é fornecido via argumento de linha de comando, e controla os movimentos da cobra.

* **Regras de início:**
    - Para inciar o jogo, é necessário adicionar a quantidade de linhas, colunas e de comida, logo após o mapa.
    - A quantidade de linhas e colunas não podem ser menores que 0 e maiores que 100.
    - A quantidade de comida não poder ser inferior a 1.

* **Arquivos teste:**
    - Os arquivos adicionados são teste para que o jogador possa olhar o resultado. Todos os arquivos podem ser encontrados no diretório data.
    - O arquivo maze1.txt não possui erros a ser apresentado, possui 3 níveis.
    - O arquivo maze2.txt possui um erro na quantidade de coluna, no nível 3 foi adicionado a coluna o valor -28, possui 4 níveis.
    - O arquivo maze3.txt possui um erro na quantidade de linha, no nível 3 foi adicionado a linha o valor 0, possui 3 níveis.
    - O arquivo maze4.txt possui um erro na quantidade de comida, no nível 2 foi adicionado a coluna o valor -1, possui 2 níveis.
    - O arquivo maze5.txt possui um erro, no qual o arquivo esta vazio.

* **Como compilar e executar projeto:**

    - Observação: 
        1. O jogo precisa ser executado dentro do diretório build.
        2. Na hora de escolher qual arquivo, atentar-se para escolher o correto diretório data.

    - No Linux:
        1. cmake ..
        2. cmake --build .
        3. ./Snaze ../data/maze1.txt Pacman/Snake (Pacman: cobra sem corpo, Snake: cobra com corpo).
    - No Windows:
        1. cmake ..
        2. cmake --build .
        3. .\Debug\Snaze ..\data\maze1.txt Pacman/Snake (Pacman: cobra sem corpo, Snake: cobra com corpo).


# Avaliação CP2

## FindSolution.pacman

O método find soluiton ou similar deve ser capaz de encontrar o conjunto de comandos que levam da posição atual da cobrinha até a posição da comida no modo pacman.

**Avaiação**

não implementado

## FindSolution.snake

O método find soluiton ou similar deve ser capaz de encontrar o conjunto de comandos que levam da posição atual da cobrinha até a posição da comida no modo snake.

**Avaliação**

não implementado

## Random start

Deveria ser implementado na execução do programa um comando que permita que a posição inicial seja sorteada aleatoriamente. A posição inicial precisa ser válida e não deve causar a cobrinha/pacman iniciar em uma posição encurralada.

**Avaliação**

não implementado

## Level Loop

Deveria se implementado na execução do programa um comando que permite que os níveis fiquem se repetindo infinitamente, com a transição de mapas indo do primeiro nível até o último nível e voltando para o primeiro, de forma que seja mantida a contagem de pontos bem como a contagem de nível.

**Avaliação**

não implementado

## Organização / Compilação automatizada / Casos de Teste

Para a entrega final a organização do código em scr/data/include e compilação automatizada de alguma forma deve ser feita.

**Avaliação**

ok

## Documentação do código / Readme / Documentação de Casos de Teste

**Avaliação**

80% algumas classes estão com a documentação incompleta

## Atualizações no CP1

- Eu havia considerando Render.ui então não mudei nada
- Atualizei render.snake para 75%
- Atualizei Logic.comida para 25% (faltou colisão com a parede)
