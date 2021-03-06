#ifndef SnakeGame_h
#define SnakeGame_h
#include <iostream>
#include <vector>
#include <string>
#include "Level.h"
using namespace std;

class SnakeGame{
    public:
        /**
        * @brief descreve os possíveis estados do jogo, fique à vontade para adicionar outros se necessário
        **/
        enum GameStates{
            START,
            RUNNING, //<! quando o jogo está executando o estado é RUNNING
            GAME_OVER, //<! quando o jogo deve terminar o estado é GAME_OVER
            WAITING_USER, //<! quando o jogo deve esperar por uma entrada do usuário o estado é WAITING_USER
            WAITING_PLAYER //<! quando o jogo deve esperar por alguma ação da IA
        };

    private:
        //<! atributos adicione outros se quiser
        bool estado_corpo; //<! verdadeiro se for pacman e falso caso contrário
        bool taNoComeco; //<! verdadeiro está no inicio do jogo e falso caso contrário
        int nivel = 0;
        Snake objeto_snake;
        Level objeto_level;
        std::vector<std::string> maze; //<! vector contendo o labirinto atual, pode ser interpretado como uma matriz
        int frameCount; //<! contador de frames, usado apenas como exemplo
        std::string choice; //<! usado na função process_actions para guardar a escolha do usuário
        GameStates state; //<! guarda o estado do jogo

    public:
        /**
        * @brief construtor padrão, fique à vontade para adicionar parâmetros se desejar
        **/
        SnakeGame(int argc, char *argv[]);

        /**
        * @brief chamado no main, este loop executa o jogo indefinidamente até que o usuário escolha terminar!
        */
        void loop();

    private:
        /**
        * @brief realiza a inicialização geral do jogo, fique à vontade para adicionar parâmetros se achar que deve
        **/
        void initialize_game(int argc, char *argv[]);

        /**
        * @brief atualiza o estado do jogo, basicamente movendo os objetos, sorteando novas posições de comida
        **/
        void update();

        /**
        * @brief processa as entradas do jogador
        **/
        void process_actions();

        /**
        * @brief testa o estado do jogo e desenha a tela correspondente
        **/
        void render();

        /**
        * @brief é chamada quando o jogo termina a fim de destruir/resetar elementos do estado do jogo
        **/
        void game_over();
};

#endif //SnakeGame_h