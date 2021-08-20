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
    int aux = 0, aux1 = 0, aux2 = 3, armazenadora = 0;
    int x = numeros[numeros.size() - 1];
    cout << "last number: " << x << endl;

    for(int i = 0; i < numeros.size(); i++){
        if(aux1 == 0){
            quantidade_linhas = numeros[i];
            quantidade_colunas = numeros[i+1];
            quantidade_comidas = numeros[i+2];
            aux++;
            //break;
        } else if(aux1 > 0){
            quantidade_linhas = numeros[i+2];
            quantidade_colunas = numeros[i+3];
            quantidade_comidas = numeros[i+4];
            aux2 = aux2 + 3;
            if(x == quantidade_comidas){
                break;
            }
            //break;
        }
        aux1++;
    }
    cout << "AUX1:" << aux1 << endl;
    cout << "AUX:" << aux << endl;
    cout << "Quantidade de linhas:" << quantidade_linhas << endl;
    cout << "Quantidade de colunas:" << quantidade_colunas << endl;
    cout << "Quantidade de comida:" << quantidade_comidas << endl;

    
}
