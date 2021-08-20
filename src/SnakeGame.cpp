#include "SnakeGame.h"
#include "Level.h"
#include "Player.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono> //por causa do sleep
#include <thread> //por causa do sleep

#include <sstream>
#include <stdlib.h>
#include <ctype.h>

#ifdef _WIN32
    #include <Windows.h>
#endif

using namespace std;

SnakeGame::SnakeGame(){
    choice = "";
    frameCount = 0;
    initialize_game();
}

void SnakeGame::initialize_game(){
    //carrega o nivel ou os níveis
    ifstream levelFile("./data/maze1.txt"); //só dá certo se o jogo for executado dentro da raíz do diretório (vc vai resolver esse problema pegando o arquivo da linha de comando)
    int lineCount = 0;
    string line;
    if(levelFile.is_open()){
        while(std::getline(levelFile, line)){ //pega cada linha do arquivo
            maze.push_back(line);
            lineCount++;
        }
    }

    state = RUNNING;
}



void SnakeGame::process_actions(){
    //processa as entradas do jogador de acordo com o estado do jogo
    //nesse exemplo o jogo tem 3 estados, WAITING_USER, RUNNING e GAME_OVER.
    //no caso deste trabalho temos 2 tipos de entrada, uma que vem da classe Player, como resultado do processamento da IA
    //outra vem do próprio usuário na forma de uma entrada do teclado.
    switch(state){
        case WAITING_USER:
            cin>>std::ws>>choice;
            break;
        default:
            //nada pra fazer aqui
            break;
    }
}

void SnakeGame::update(){
    //atualiza o estado do jogo de acordo com o resultado da chamada de "process_input"
    switch(state){
        case RUNNING:
            if(frameCount>0 && frameCount%10 == 0) //depois de 10 frames o jogo pergunta se o usuário quer continuar
                state = WAITING_USER;
            break;
        case WAITING_USER: //se o jogo estava esperando pelo usuário então ele testa qual a escolha que foi feita
            if(choice == "n"){
                state = GAME_OVER;
                game_over();
            }
            else{
                //pode fazer alguma coisa antes de fazer isso aqui
                state = RUNNING;
            }
            break;
        default:
            //nada pra fazer aqui
            break;
    }
}

/**
 * @brief função auxiliar para fazer o programa esperar por alguns milisegundos
 * @param ms a quantidade de segundos que o programa deve esperar
 */
void wait(int ms){
#if defined _WIN32
    Sleep(ms);
#else
    this_thread::sleep_for(chrono::milliseconds(ms));
#endif
}

/**
 * @brief função auxiliar para linpar o terminal
 */
void clearScreen(){
//some C++ voodoo here ;D
#if defined _WIN32
    system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
    system("clear");
#elif defined (__APPLE__)
    system("clear");
#endif
}

int linha = 0, coluna = 0, comidas = 0;
int aux = 0;


stringstream xy;
void SnakeGame::render(){
    Level obj;
    clearScreen();
    switch(state){
        int y, tam, tam2;
        case RUNNING:
        
            for(auto i = maze.begin(); i != maze.end(); i++){//pega os números
                string s = *i;
                for(int ii = 0; ii < s.size(); ii++){
                    if(isdigit(s[ii])){
                        //cout << s << endl;
                        xy << s << endl;//convert string para número
                        break;
                    }
                } 
            }
            while(xy >> y){
                obj.preencher_numeros(y);
            }
            obj.mostrar_numeros();//mostra os elementos de vector

            /*for(auto j = numeros.begin(); j != numeros.end(); j++){
                linha = numeros.at(0);
                coluna = numeros.at(1);
                comidas = numeros.at(2);
                j->setQuantidade_linhas(obj.linha);
                j->setQuantidade_colunas(obj.coluna);
                j->setQuantidade_comidas(obj.comidas);
                cout << "linha:" << j->getQuantidade_linhas() << endl;
                cout << "colunas: " << j->getQuantidade_colunas() << endl;
                cout << "comidas: " << j->getQuantidade_comidas() << endl;
            }*/


            /*for(int j = 0; j < numeros.size(); j++){
                if(j == 0){
                    linha = numeros.at(0);
                    coluna = numeros.at(1);
                    comida = numeros.at(2);
                    j->setQuantidade_linhas(linha);
                    j->setQuantidade_colunas(coluna);
                    j->setQuantidade_comidas(comida);
                    cout << "linha:" << j->getQuantidade_linhas() << endl;
                    cout << "colunas: " << j->getQuantidade_colunas() << endl;
                    cout << "comidas: " << j->getQuantidade_comidas() << endl;
                }
                if(j > 0){
                    linha = numeros.at(0)+3;
                    coluna = numeros.at(1)+3;
                    comida = numeros.at(2)+3;
                    j->setQuantidade_linhas(linha);
                    j->setQuantidade_colunas(coluna);
                    j->setQuantidade_comidas(comida);
                }
                cout << j << endl;
            }*/

            //desenha todas as linhas do labirinto            
            /*for(auto line : maze){
                cout<<line<<endl;
            }*/
            break;
        case WAITING_USER: //este método bloqueia aqui esperando o usuário digitar a escolha dele
            cout<<"Você quer continuar com o jogo? (s/n)"<<endl;
            break;
        case GAME_OVER:
            cout<<"O jogo terminou!"<<endl;
            break;
    }
    frameCount++;
}

void SnakeGame::game_over(){
}

void SnakeGame::loop(){
    while(state != GAME_OVER){
        process_actions();
        update();
        render();
        wait(3000);// espera 1 segundo entre cada frame
    }
}
