#include "SnakeGame.h"
#include "Level.h"
#include "Player.h"
#include "Snake.h"

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

void wait(int ms){
#if defined _WIN32
    Sleep(ms);
#else
    this_thread::sleep_for(chrono::milliseconds(ms));
#endif
}

SnakeGame::SnakeGame(int argc, char *argv[]){
    choice = "";
    frameCount = 0;
    initialize_game(argc, argv);
}

void SnakeGame::initialize_game(int argc, char *argv[]){
    stringstream xy;
    //carrega o nivel ou os níveis
    //ifstream levelFile("./data/maze1.txt"); //só dá certo se o jogo for executado dentro da raíz do diretório (vc vai resolver esse problema pegando o arquivo da linha de comando)
    ifstream levelFile;
    int y, lineCount = 0, recebedora = 0;
    string line;
    levelFile.open(argv[1]);
    if(string(argv[2]) == "Snake"){
        estado_corpo = false;
    }
    if(string(argv[2]) == "Pacman") {
        estado_corpo = true;
    } 

    if(argc < 2){
        cout << "ERRO! NÃO FOI INSERIDO NENHUM ARQUIVO!";
    } else {
        if(levelFile.is_open()){
            while(std::getline(levelFile, line)){ //pega cada linha do arquivo
                maze.push_back(line);
                lineCount++;
            }
        }
    }
    for(auto i = maze.begin(); i != maze.end(); i++){//pega os números
        string s = *i;
        for(int ii = 0; ii < s.size(); ii++){
            if(isdigit(s[ii])){
                xy << s << endl;//convert string para número
                break;
            }else{
                objeto_level.preencher_mapa(s);//preenche um vector de string com os mapas
                break;
            }
        } 
    }
    while(xy >> y){
        objeto_level.preencher_numeros(y);//chama para preencher vector
    }
    objeto_level.separar_numeros();//separando comidas em seus devidos lugares
    objeto_level.somando_comidas();//somando o total de alimentos
    
    recebedora = objeto_level.validar_numeros();//verifica os números
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
        objeto_level.separar_mapa();
        objeto_level.gerar_comida(nivel);  
        state = START; 
    }   
}

void SnakeGame::process_actions(){
    //processa as entradas do jogador de acordo com o estado do jogo
    //nesse exemplo o jogo tem 3 estados, WAITING_USER, RUNNING e GAME_OVER.
    //no caso deste trabalho temos 2 tipos de entrada, uma que vem da classe Player, como resultado do processamento da IA
    //outra vem do próprio usuário na forma de uma entrada do teclado.
    switch(state){
        case WAITING_PLAYER:     
            //objeto_level.modificar_andamento(nivel);
            state = RUNNING;
            break;
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
        case START:
            taNoComeco = false;
            break;
        case RUNNING:      
            objeto_level.modificar_andamento(nivel);     
            if(taNoComeco){
                objeto_level.gerar_comida(nivel);
                taNoComeco = false;
            }      

            if(objeto_level.verificar_colisao_comida(estado_corpo, nivel)){
                taNoComeco = true;
            }

            if(objeto_level.checar_comida_por_nivel()){
                nivel++;
                state = WAITING_USER;
            }

            break;
        case WAITING_USER: 
            if(choice == "n"){
                state = GAME_OVER;
                game_over();
            }
            else{                
                state = RUNNING;
            }
            break;
        default:
            break;
    }
}

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
    clearScreen();
    switch(state){
        case START:      
        //condição para mostrar a interface principal
            objeto_level.somando_comidas();
            objeto_level.interface_principal(); 
            objeto_level.interface_nivel();
            
            state = RUNNING;
            break;
        case RUNNING:                 
        //metodo que desenha a cobra no mapa
            objeto_level.interface_nivel();
            objeto_level.desenhar_mapa(nivel);
            state = WAITING_PLAYER;
            break;
        case WAITING_USER: //este método bloqueia aqui esperando o usuário digitar a escolha dele
            cout<<"Você quer continuar com o jogo? (s/n)"<<endl;
            break;
        case GAME_OVER:
            cout<<"O jogo terminou!"<<endl;
            break;
    }
}

void SnakeGame::game_over(){
}

void SnakeGame::loop(){
    while(state != GAME_OVER){
        process_actions();
        update();
        render();
        wait(200);// espera 1 segundo entre cada frame
    }
   
}
