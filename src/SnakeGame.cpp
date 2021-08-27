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

SnakeGame::SnakeGame(){
    choice = "";
    frameCount = 0;
    initialize_game();
}

stringstream xy;
int recebedora = 0, y, gatilho_de_niveis = 0, gatilho_de_comida = 0;
int nivel = 0;
Level objeto;
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
    for(auto i = maze.begin(); i != maze.end(); i++){//pega os números
        string s = *i;
        for(int ii = 0; ii < s.size(); ii++){
            if(isdigit(s[ii])){
                xy << s << endl;//convert string para número
                break;
            }else{
                objeto.preencher_mapa(s);//preenche um vector de string com os mapas
                break;
            }
        } 
    }
    while(xy >> y){
        objeto.preencher_numeros(y);//chama para preencher vector
    }
    objeto.separar_numeros();//separando comidas em seus devidos lugares
    objeto.somando_comidas();//somando o total de alimentos
    
    recebedora = objeto.validar_numeros();//verifica os números
    if(recebedora>0){
        if(recebedora == 1){//verifica linhas
            state = GAME_OVER;
        }else if(recebedora == 2){//verifica colunas
            state = GAME_OVER;
        }else{//verifica comida
            state = GAME_OVER;
        }
    }else{
        nivel = 0;
        state = RUNNING;
    }

    /*for(auto line : maze){
        cout<<line<<endl;
        wait(600);
    }*/

    objeto.separar_mapa();
    objeto.exibir_informacoes(0);    
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
            //se começou agora(atributo de snake_game-estado), então chama método para por comida no mapa e a cobra
            //depois de comer todas as comidas, retornar uma variavel para ir para o proximo nivel

            
            //if(nivel >= 1){

            //}

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
                nivel++;
                state = RUNNING;
            }
            break;
        default:
            //nada pra fazer aqui
            break;
    }
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

void SnakeGame::render(){
    //clearScreen();
    switch(state){
        case RUNNING:  

            if(nivel == 0){
                objeto.interface_principal();
                
            }            
           
            //condição para mostrar a interface principal

            //metodo que desenha a cobra no mapa


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
        wait(7000);// espera 1 segundo entre cada frame
    }
   
}
