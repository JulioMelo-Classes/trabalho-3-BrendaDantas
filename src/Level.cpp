#include "Level.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <time.h>
#include "SnakeGame.h"
using namespace std;

void Level::preencher_mapa(string mapa){//preencher vector c/ todos os mapas
    todos_os_mapas.push_back(mapa);
}

void Level::preencher_numeros(int numero){//preenche vector com todos os numeros
    todos_os_numeros.push_back(numero);
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
    
    for(int i = 0; i < so_comidas.size(); i++){
        comidas_somadas = comidas_somadas + so_comidas[i];
    }
    //cout << "QUANTIDADE SOMADA DE COMIDAS: "  << comidas_somadas << endl;
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

