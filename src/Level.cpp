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
    int linha = 0, coluna = 0, comida = 0;
    int aux = 0;
    for(auto i = numeros.begin(); i != numeros.end(); i++){
        *i.quantidade_linhas =  numeros.begin() + 1;
        cout << "linha: " << quantidade_linhas << endl;
        aux = aux + 3;
    }
    
}
