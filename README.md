# Projeto 3: Snaze

* **Snake game:**
    - Do que se trata:
        Simulação do jogo clássico Snake arcade vídeo game
    com uma diferença: a cobra está presa dentro de um labirinto!
    A simulação do jogo Snaze carrega o nível do labirinto a partir de um arquivo texto de entrada,
    cujo nome é fornecido via argumento de linha de comando, e controla os movimentos da cobra.

* **Como compilar e executar projeto:**

    - Observação: 
        1. O jogo precisa ser executado dentro da raíz do diretório.

    - No Linux:
        1. g++ src/*.cpp -o main -I./include
        2. ./main ./data/maze1.txt Pacman/Snake (Pacman: cobra sem corpo, Snake: cobra com corpo).
    - No Windows:
        1. g++ src/*.cpp -o main -I./include
        2. .\main .\data\maze1.txt Pacman/Snake (Pacman: cobra sem corpo, Snake: cobra com corpo).
