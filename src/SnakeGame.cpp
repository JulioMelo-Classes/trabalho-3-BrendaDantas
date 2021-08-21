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
int recebedora = 0;
void SnakeGame::initialize_game(){
    Level objeto;
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


int aux = 0;
stringstream xy;
void SnakeGame::render(){
    Level obj;
    clearScreen();
    switch(state){
        int y;
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
                obj.preencher_numeros(y);//chama para preencher vector
            }
            obj.mostrar_numeros();//mostra os elementos de vector
            obj.separar_numeros();
            obj.validar_numeros();

            
        recebedora = obj.validar_numeros();
        cout << "recebedora: " << recebedora << endl;
        if(recebedora == 1){
            cout << "ERRO!! quantidade de linhas não pode ser inferior a 1 ou superior a 100\n" << endl;
            state = GAME_OVER;
            game_over();
        } else if(recebedora == 2){
            cout << "ERRO!! quantidade de colunas não pode ser inferior a 1 ou superior a 100\n" << endl;
            state = GAME_OVER;
            game_over();
        } else if(recebedora == 3){
            cout << "ERRO!! quantidade de comidas não pode ser inferior a 1\n" << endl;
            state = GAME_OVER;
            game_over();
        }


            //desenha todas as linhas do labirinto            
            /*for(auto line : maze){
                cout<<line<<endl;
            }*/
            break;
        //case VALIDAR:

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
    if(recebedora == 0){
        while(state != GAME_OVER){
        process_actions();
        update();
        render();
        wait(1000);// espera 1 segundo entre cada frame
        }
    }else{
        cout << "erros encontrados\n";
        game_over();
    }
        
    
    
   
}
