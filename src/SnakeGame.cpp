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
int recebedora = 0, y, gatilho_de_niveis = 0;
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
                //cout << s << endl;
                xy << s << endl;//convert string para número
                break;
            }else{
                objeto.preencher_mapa(s);
                break;
            }
        } 
    }
    while(xy >> y){
        objeto.preencher_numeros(y);//chama para preencher vector
    }
    objeto.mostrar_numeros();//mostra os elementos de vector
    objeto.separar_numeros();//separo os numeros em linha, coluna e comida
    wait(900);
    /*objeto.mostrar_mapas();//mostra mapa guardado no vector
    wait(5000);*/

    recebedora = objeto.validar_numeros();//faço a validação e retorna um inteiro
    cout << "recebedora: " << recebedora << endl;
    wait(100);
    if(recebedora == 1){//resultado da validação de números de entrada
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
    } else {//aqui é quando não tem erro de validação
        //cout << "entrei aqui" << endl;
        objeto.interface_principal();
        wait(6000);
        //objeto.separar_numeros();
        //objeto.mostra_num_separados();
        objeto.encontrar_posicao_cobra(gatilho_de_niveis);
        gatilho_de_niveis++;
        wait(6000);
        state = RUNNING;
    }
    
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
    //Level obj;
    //int num = 1;
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
                objeto.interface_principal();
                objeto.encontrar_posicao_cobra(gatilho_de_niveis);
                gatilho_de_niveis++;
                wait(6000);   
                cout << "COMEÇAMOS NOVAMENTE" << endl;
                wait(5000);              
                
                //obj.encontrar_posicao_cobra(num);
                //num++;
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
    clearScreen();
    switch(state){
        case RUNNING:   

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
        wait(500);// espera 1 segundo entre cada frame
    }
   
}
