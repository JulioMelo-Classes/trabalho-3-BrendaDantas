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
        3. .\Snaze .\data\maze1.txt Pacman/Snake (Pacman: cobra sem corpo, Snake: cobra com corpo).
