#include "Level.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <time.h>
#include "SnakeGame.h"
using namespace std;



void Level::preencher_mapa(string& mapa){//preencher vector c/ todos os mapas
    todos_os_mapas.push_back(mapa);
}

void Level::preencher_numeros(int numero){//preenche vector com todos os numeros
    todos_os_numeros.push_back(numero);
}

void Level::separar_mapa(){
     
    for(int j = 0; j < so_linhas.size(); j++){
        vector<string> mapa;
        for(int i = 0; i < so_linhas.at(j); i++){
            mapa.push_back(todos_os_mapas.at(i));

        }
        for (int i = 0; i < so_linhas.at(j); i++){
            todos_os_mapas.erase(todos_os_mapas.begin());
        }
        mapa_atual.push_back(mapa);
    }

    numero_de_niveis = mapa_atual.size();

}

int numero_de_linhas = 0;
void Level::separar_numeros(){//separando numeros e guardando em cada lugar correto
    int aux1 = 0, aux2 = 0, contador = 1, pos_coluna = 0, pos_comida = 0;
    int tamanho_de_linhas = todos_os_numeros.size();//descobre quantidade de números existente

    numero_de_linhas = tamanho_de_linhas/3;//descobre quantas linhas de número tem

    for(int i = 0; i < todos_os_numeros.size(); i++){
        if(aux1 == 0){
            so_linhas.push_back(todos_os_numeros[i]);
            so_colunas.push_back(todos_os_numeros[i+1]);
            so_comidas.push_back(todos_os_numeros[i+2]);

        } else if(aux1 > 0) {
            pos_coluna = i;
            pos_comida = i+1;
            i = 3;//posição de linhas
            so_linhas.push_back(todos_os_numeros[i+aux2]);
            so_colunas.push_back(todos_os_numeros[pos_coluna+3]);
            so_comidas.push_back(todos_os_numeros[pos_comida+3]);
            aux2 = 3;
            contador++;
            if(contador == numero_de_linhas){
                break;
            }
        }
        aux1++;
    }

}

void Level::somando_comidas(){//soma as comidas   
    comidas_somadas = 0;
    for(int i = 0; i < so_comidas.size(); i++){
        comidas_somadas = comidas_somadas + so_comidas[i];
    }
}

int Level::validar_numeros(){//verifica a veracidade dos números

    for(auto itr1 = so_linhas.begin(); itr1 != so_linhas.end(); itr1++){
        if(*itr1 <= 0 || *itr1 > 100){//valida linhas
            cout << "ERRO!! quantidade de linhas não pode ser inferior a 1 ou superior a 100\n" << endl;
            return 1;
        }
    }
    for(auto itr1 = so_colunas.begin(); itr1 != so_colunas.end(); itr1++){
        if(*itr1 <= 0 || *itr1 > 100){//valida colunas
            cout << "ERRO!! quantidade de colunas não pode ser inferior a 1 ou superior a 100\n" << endl;
            return 2;
        }
    }
    for(auto itr1 = so_comidas.begin(); itr1 != so_comidas.end(); itr1++){
        if(*itr1 <= 0){//valida comidas
            cout << "ERRO!! quantidade de comidas não pode ser inferior a 1\n" << endl;
            return 3;
        }
    }
    return 0;
}

void Level::gerar_comida(int nivel){

    int i = 0;
    srand(time(NULL));
    vector<pair<int, int>> posicoes_validas;

    for(int i = 0; i < mapa_atual.at(nivel).size(); i++){
        for(int j = 0; j < mapa_atual.at(nivel).at(i).size(); j++){
            if(mapa_atual.at(nivel)[i][j] == ' '){
                posicoes_validas.push_back(make_pair(i,j));
            }

        }
    }    

    i = rand() % posicoes_validas.size();

    posicao_da_comida.first = posicoes_validas[i].first;
    posicao_da_comida.second = posicoes_validas[i].second;
    mapa_atual.at(nivel)[posicao_da_comida.first][posicao_da_comida.second] = 'A';

}

void Level::exibir_informacoes(int nivel){

    player.posicao_da_cobra(mapa_atual, nivel);
    player.movimentando_cobra(mapa_atual, nivel, comidas_ingeridas);
    //player.mostrar_posicoes(mapa_atual, nivel);
    
}

void Level::mostrar_mapa_um(){
    
    int linhas_mapa_um = 0;
    linhas_mapa_um = so_linhas.at(0);

    for(int i = 0; i < linhas_mapa_um; i++){
        cout << mapa_atual.at(0).at(i) << endl;
    }
}

void Level::interface_principal(){

    cout << "---> Welcome to the classic Snake Game <---\n";
    cout << "           copyright DIMAp/UFRN 2017" << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "Levels loaded: " << numero_de_linhas << " | " << " Snake lives: 5 " << " | " << " Apples to eat: " << comidas_somadas << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << ">>> Press <ENTER> to start the game!" << endl;   
}

void Level::interface_nivel(){
    cout << "\nLives: ♥♥♥♥♥ | Score: " << score << "    | Food eaten: " << comidas_ingeridas << " of " << comidas_somadas << endl;
    cout << "______________________________________________________________________\n";
    //mostrar_mapa_um();
    cout << "______________________________________________________________________\n";
}

void Level::desenhar_mapa(int nivel){
    int linhas_mapa_atual = 0;
    linhas_mapa_atual = so_linhas.at(nivel);
    cout << "Nível: " << nivel+1 << endl;
    for(int i = 0; i < linhas_mapa_atual; i++){
        cout << mapa_atual.at(nivel).at(i) << endl;
    }
}

void Level::modificar_andamento(int nivel){
    //player.mostrar_posicoes(mapa_atual, nivel);
    player.movimentando_cobra(mapa_atual, nivel, comidas_ingeridas);
    //player.crescer_cobra(mapa_atual, nivel);
}

int Level::get_quantidade_de_niveis(){
    return numero_de_niveis;
}

bool Level::verificar_colisao_comida(){
    if(posicao_da_comida == player.get_posicao_da_cobra()){
        comidas_ingeridas++;
        return true;
    }

    return false;
}