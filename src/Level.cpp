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
    cout << numero << endl;
    /*for(auto i = todos_os_numeros.begin(); i != todos_os_numeros.end(); i++){
        cout << *i << endl;
    }*/
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
    int x = 1, y = 1, z = 1;
    int tam_linhas = so_linhas.size();
    int tam_colunas = so_colunas.size();
    int tam_comidas = so_comidas.size();

    //pega último número para descobrir qual o número
    for(int i = 0; i < so_linhas.size(); i++){
        x = so_linhas[i];
    }
    for(int i = 0; i < so_colunas.size(); i++){
        y = so_colunas[i];
    }
    for(int i = 0; i < so_comidas.size(); i++){
        z = so_comidas[i];
    }

    //faz verificação de linhas
    if(tam_linhas == 0 && tam_colunas == 0 && tam_comidas == 0){
        cout << "ERRO!! arquivo inserido está vazio.\n";
        cout << "Lembre-se que o número de linhas e colunas não podem ser maiores que 100 e menor que 1,\ne a comida não pode ser menor que 1.\n";
        return 1;
    }
    if(tam_linhas == 2 && x == 0 && y == 0 && z == 0){//arquivo com 1 nivel
        for(int i = 0; i < so_linhas.size()-1; i++){
            if(so_linhas[i] <= 0 || so_linhas[i] > 100){//valida linhas
                cout << "ERRO!! quantidade de linhas não pode ser inferior a 1 ou superior a 100." << endl;
                cout << "No nivel " << i+1 << " você adicionou " << so_linhas[i] << " na linha" << endl;
                return 1;
            }
        }
    } else if(tam_linhas > 1) {//arquivo contém mais de 1 nível
        for(int i = 0; i < so_linhas.size(); i++){
            if(so_linhas[i] <= 0 || so_linhas[i] > 100){
                cout << "ERRO!! quantidade de linhas não pode ser inferior a 1 ou superior a 100." << endl;
                cout << "No nivel " << i+1 << " você adicionou " << so_linhas[i] << " na linha." << endl;
                return 1;
            }
        }
    }
    //validação de colunas
    if(tam_colunas == 2 && x == 0 && y == 0 && z == 0){//arquivo com 1 nivel
        for(int j = 0; j < so_colunas.size()-1; j++){
            if(so_colunas[j] <= 0 || so_colunas[j] > 100){
                cout << "ERRO!! quantidade de colunas não pode ser inferior a 1 ou superior a 100." << endl;
                cout << "No nivel " << j+1 << " você adicionou " << so_colunas[j] << " na coluna." << endl;
                return 2;
            }
        }
    } else if(tam_colunas > 1) {
        for(int j = 0; j < so_colunas.size(); j++){//arquivo acima de 1 nivel
            if(so_colunas[j] <= 0 || so_colunas[j] > 100){
                cout << "ERRO!! quantidade de colunas não pode ser inferior a 1 ou superior a 100." << endl;
                cout << "No nivel " << j+1 << " você adicionou " << so_colunas[j] << " na coluna." << endl;
                return 2;
            }
        }
    }
    //validação de comidas
    if(tam_comidas == 2 && x == 0 && y == 0 && z == 0){//arquivo com 1 nivel
        for(int k = 0; k < so_comidas.size()-1; k++){
            if(so_comidas[k] <= 0){
                cout << "ERRO!! quantidade de comidas não pode ser inferior a 1." << endl;
                cout << "No nivel " << k+1 << " você adicionou " << so_comidas[k] << " na comida." << endl;
                return 1;
            }
        }
    } else if(tam_comidas > 1) {//arquivo com mais de um nivel
        for(int k = 0; k < so_comidas.size(); k++){
            if(so_comidas[k] <= 0){
                cout << "ERRO!! quantidade de comidas não pode ser inferior a 1." << endl;
                cout << "No nivel " << k+1 << " você adicionou " << so_comidas[k] << " na comida." << endl;
                return 1;
            }
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
    player.posicao_da_cobra(mapa_atual, nivel);
    player.movimentando_cobra(mapa_atual, nivel);
    //player.crescer_cobra(mapa_atual, nivel);
}

int Level::get_quantidade_de_niveis(){
    return numero_de_niveis;
}

bool Level::verificar_colisao_comida(bool estado_corpo, int nivel){

    qtd_comidas_por_nivel = so_comidas[nivel];

    if(posicao_da_comida == player.get_posicao_da_cobra()){
        comidas_ingeridas++;
        score = score+10;
        if(!estado_corpo){
            player.crescer_cobra(mapa_atual, nivel);
        }
        
        return true;
    }

    return false;
}

bool Level::checar_comida_por_nivel(){
    if(comidas_ingeridas == qtd_comidas_por_nivel){
        return true;
    }
    
    return false;
}
