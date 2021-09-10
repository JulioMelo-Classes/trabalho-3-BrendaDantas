# Projeto 3: Snaze

* **Como compilar e executar projeto:**

    - Observação: 
        1. O jogo precisa ser executado dentro da raíz do diretório.

    - No Linux:
        1. g++ src/*.cpp -o main -I./include
        2. ./main
    - No Windows:
        1. g++ src/*.cpp -o main -I./include
        2. .\main.exe


## Avaliação CP1

### Snake/Pacman
O jogo deveria conter o modo snake/pacman. Em ambos os modos não é possível andar pra trás. No modo snake deve ser desenhado o corpo.

**Avaliação**

50% apenas o modo pacman foi feito

### Render.ui
O jogo deveria desenhar a UI corretamente, mostrando ao menos as vidas, o nível e o score.

**Avaliação**

Vou considerar OK, pois vocês desenharam alguma parte da UI.

### Render.mapa
O jogo deveria desenhar o mapa corretamente, com base no arquivo passado como argumento. Ok

**Avaliação**

70% o programa lê um arquivo porém não usa os argumentos passados.

### Render.snake
O jogo deveria desenhar a snake corretamente.

**Avaliação**
Vou considerar 20%, aparentemente está um trabalho incompleto, a snake inicia o movimento mas anda muito pouco no mapa e depois fica em loop. Além disso a snake não deve ser capaz de "voltar" no trajeto.

### Logic.colisão e Logic.comida
O jogo deve se comportar corretamente quando ocorre uma colisão com comida e com paredes.

**Avaliação**

Não implementado

### Transição de mapas
O jogo deve ter transição de mapa uma vez que um mapa é terminado.

**Avaliação**

Não implementado.

### Interação com o usuário
O jogo deve perguntar ao usuário se quer continuar/reiniciar o nível/reiniciar o jogo a cada transição de mapa

**Avaliação**

Não implementado

### Classe Level ou similar
O software deve encapsular as funcionalidades do nível em uma classe.

**Avaliação**

Ok

### Classe Player ou similar
O software deve encapsular as decisões do jogo em uma classe.

**Avaliação**

Ok

### Classe Snake ou similar
O software deve encapsular as funcionalidades relacionadas à snake em uma classe. 

**Avaliação**

Não vou considerar este quesito, pois vocês não conseguiram imaginar como encapsular funcionalidades numa classe para modelar a snake.

## Comentários gerais CP1

- O trabalho está bastante incompleto. Sugiro que vocês deem ênfase ao CP1 na entrega. Especialmente em melhorar a integração das classes player e level, já que vocês não conseguiram pensar em alguma utilidade para a classe snake.
- A ideia princpial é que a classe player use o objeto snake e o mapa para tormar as decisões de controle. Vocês podem pensar como se o objeto snake estivesse dentro do level. O player tem acesso ao level e usando a posição da snake no level ele tem como decidir se vai virar para algum dos lados de forma que não mate a snake. Uma forma facil de fazer essa decisão é não usar o formato "vire à direita/esquerda" mas sim comandos globais como MOVE_CIMA/BAIXO. Nesse caso, o player vê a snake no level e decide se ele pode usar os comandos MOVE_CIMA/MOVE_BAIXO/MOVE_DIREITA/MOVE_ESQUERDA de forma que não mate a cobra, vocês põe os comandos que não matam a cobra em um vetor e sorteia um deles aleatoriamente. No método update, vocês perguntam a classe player qual foi a ação tomada e movem a cobrinha para a direção escolhida.
- Fazendo o que eu sugeri no ponto anterior vocês devem conseguir mover a cobra no mapa de forma aleatória, aí ficaria faltando implementar as demais coisas do CP1 que faltaram.