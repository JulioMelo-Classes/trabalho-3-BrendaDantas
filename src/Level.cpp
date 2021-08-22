#include "Level.h"
#include <iostream>
#include <string>
#include "SnakeGame.h"
using namespace std;

/*int Level::getQuantidade_linhas() {
    return quantidade_linhas;
}

void Level::setQuantidade_linhas(int linhas) {
    quantidade_linhas = linhas;
}

int Level::getQuantidade_colunas() {
    return quantidade_colunas;
}

void Level::setQuantidade_colunas(int colunas) {
    quantidade_colunas = colunas;
}

int Level::getQuantidade_comidas() {
    return quantidade_comidas;
}

void Level::setQuantidade_comidas(int comidas) {
    quantidade_comidas = comidas;
}*/

void Level::preencher_numeros(int num){//numeros de entrada guardados no vector
    numeros.push_back(num);
}

void Level::mostrar_numeros(){
    for(auto i = numeros.begin(); i != numeros.end(); i++){
        cout << *i << endl;
    }
}
int numero_de_linhas = 0, quant_comida =0;;
void Level::separar_numeros(){//guardando os numeros nos vectors
    int aux1 = 0, aux2 = 0;
    int contador = 1;
    int pos_coluna = 0, pos_comida = 0;

    int tamanho_de_linhas = numeros.size();

    numero_de_linhas = tamanho_de_linhas/3;
    //cout << "line number: " << numero_de_linhas << endl;

    for(int i = 0; i < numeros.size(); i++){
        if(aux1 == 0){
            quantidade_linhas_tot.push_back(numeros[i]);
            quantidade_colunas_tot.push_back(numeros[i+1]);
            quantidade_comidas_tot.push_back(numeros[i+2]);

        } else if(aux1 > 0) {
            cout << "entrou no else if\n";
            pos_coluna = i;
            pos_comida = i+1;
            i = 3;//posição de linhas
            quantidade_linhas_tot.push_back(numeros[i+aux2]);
            quantidade_colunas_tot.push_back(numeros[pos_coluna+3]);
            quantidade_comidas_tot.push_back(numeros[pos_comida+3]);
            aux2 = 3;
            contador++;
            if(contador == numero_de_linhas){
                cout << "entrou no if\n";
                break;
            }
        }
        aux1++;
    }
    //cout << "AUX1:" << aux1 << endl;
    for(int i=0; i<numero_de_linhas;i++){
        cout << "Quantidade de linhas:" << quantidade_linhas_tot[i] << endl;
        cout << "Quantidade de colunas:" << quantidade_colunas_tot[i] << endl;
        cout << "Quantidade de comidas:" << quantidade_comidas_tot[i] << endl;
    }   
    int tt = quantidade_comidas_tot.size();
    cout << "tamanho de quantidade de comidas= " << tt << endl;
    
    for(int i =0; i < tt; i++){
        quant_comida = quant_comida + quantidade_comidas_tot[i];
    }
    cout << "soma de comidas: " << quant_comida << endl;
}

/*void Level::mostra_num_separados(){

    for(int i=0; i<numero_de_linhas; i++){
        cout << "ai\n";
        //cout << "Quantidade de linhas:" << quantidade_linhas_tot[i] << endl;
        //cout << "Quantidade de colunas:" << quantidade_colunas_tot[i] << endl;
        //cout << "Quantidade de comidas:" << quantidade_comidas_tot[i] << endl;
    }
}*/

int Level::validar_numeros(){
    cout << "começou\n";
    for(auto itr1 = quantidade_linhas_tot.begin(); itr1 != quantidade_linhas_tot.end(); itr1++){
        if(*itr1 <= 0 || *itr1 > 100){
            //cout << "ERRO!! numero de linhas errado\n";
            return 1;
        }
    }
    for(auto itr1 = quantidade_colunas_tot.begin(); itr1 != quantidade_colunas_tot.end(); itr1++){
        if(*itr1 <= 0 || *itr1 > 100){
            //cout << "ERRO!! numero de colunas errado\n";
            return 2;
        }
    }
    for(auto itr1 = quantidade_comidas_tot.begin(); itr1 != quantidade_comidas_tot.end(); itr1++){
        if(*itr1 <= 0){
            //cout << "ERRO!! faltou comida\n";
            return 3;
        }
    }

    return 0;
}

void Level::preencher_mapa(string s){//preenche o mapa em vector da classe level
    mapas_do_arquivo.push_back(s);
}


void Level::mostrar_mapas(){//mostra o mapa 
    int mapa_um = 0, tamanho_dos_mapas = 0;
    tamanho_dos_mapas = mapas_do_arquivo.size();
    mapa_um = tamanho_dos_mapas/numero_de_linhas;
    
    for(int i = 0; i < (mapa_um-1); i++){
        cout << mapas_do_arquivo[i]<< endl;
    }
   /* for(auto i = mapas_do_arquivo.begin(); i != mapas_do_arquivo.end(); i++){
        cout << mapas_do_arquivo.at(0) << endl;
    }*/
}

void Level::interface_principal(){
    int tot_alimento = 0;
    for(int i = 0; i < quantidade_comidas_tot.size(); i++){
        tot_alimento = quantidade_comidas_tot[i] + tot_alimento;
        cout << quantidade_comidas_tot[i] << endl;
    }
    //cout << "tot_alimento: " << tot_alimento << endl;

    cout << "---> Welcome to the classic Snake Game <---\n";
    cout << "           copyright DIMAp/UFRN 2017" << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "Levels loaded: " << numero_de_linhas << " | " << " Snake lives: 5 " << " | " << " Apples to eat: " << quant_comida << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << ">>> Press <ENTER> to start the game!" << endl;
    cout << "\nLives: ♥♥♥♥♥ | Score: 0    | Food eaten: 0 of " << quant_comida << endl;
    cout << "______________________________________________________________________\n";
    
    /*int x = mapas_do_arquivo.size();
    cout << "tamanho do mapa: " << x << endl;*/
    mostrar_mapas();
    /*for(auto i  = mapas_do_arquivo.begin(); i != mapas_do_arquivo.end(); i++){
        cout << *i << endl;
    }*/
}
