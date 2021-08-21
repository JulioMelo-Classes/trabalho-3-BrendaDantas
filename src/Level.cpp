#include "Level.h"
#include <iostream>
#include <string>
using namespace std;

int Level::getQuantidade_linhas() {
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
}

void Level::preencher_numeros(int num){//numeros de entrada guardados no vector
    numeros.push_back(num);
}

void Level::mostrar_numeros(){
    for(auto i = numeros.begin(); i != numeros.end(); i++){
        cout << *i << endl;
    }
}

void Level::separar_numeros(){
    int aux = 0, aux1 = 0, aux2 = 0, armazenadora = 0;
    int contador = 1;
    int pos_coluna = 0, pos_comida = 0, pos_linha =0;

    int numero_de_linhas = numeros.size();

    numero_de_linhas = numero_de_linhas/3;
    cout << "line number: " << numero_de_linhas << endl;

    for(int i = 0; i < numeros.size(); i++){
        if(aux1 == 0){
            quantidade_linhas_tot.push_back(numeros[i]);
            quantidade_colunas_tot.push_back(numeros[i+1]);
            quantidade_comidas_tot.push_back(numeros[i+2]);
            aux++;

        } else if(aux1 > 0) {
            cout << "entrou no else if\n";
            pos_coluna = i;
            pos_comida = i+1;
            i = 3;
            quantidade_linhas_tot.push_back(numeros[i+aux2]);
            quantidade_colunas_tot.push_back(numeros[pos_coluna+3]);
            quantidade_comidas_tot.push_back(numeros[pos_comida+3]);
            aux2 = 3;
            if(contador == numero_de_linhas){
                cout << "entrou no if\n";
                break;
            }
            contador++;
            //break;
        }
        //contador++;
        aux1++;
    }
    cout << "AUX1:" << aux1 << endl;
    cout << "AUX:" << aux << endl;
    for(int i=0; i<numero_de_linhas;i++){
        cout << "Quantidade de linhas:" << quantidade_linhas_tot[i] << endl;
    }
    for(int i=0; i<numero_de_linhas;i++){
        cout << "Quantidade de colunas:" << quantidade_colunas_tot[i] << endl;
    }
    for(int i=0; i<numero_de_linhas;i++){
        cout << "Quantidade de comidas:" << quantidade_comidas_tot[i] << endl;
    }
    
    /*cout << "Quantidade de linhas:" << quantidade_linhas << endl;
    cout << "Quantidade de colunas:" << quantidade_colunas << endl;
    cout << "Quantidade de comida:" << quantidade_comidas << endl;*/

    
}
