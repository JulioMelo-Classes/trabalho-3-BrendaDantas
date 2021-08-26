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
    //cout << todos_os_mapas.size() << endl;

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

void Level::gerar_comida(int nivel){

    int contador = 0, i = 0, j = 0;
    srand(time(NULL));
    
    if(nivel == 0){
        
    }
}

void Level::exibir_informacoes(int nivel){

    separar_mapa();

    cout << endl;
    for (int i = 0; i < so_linhas.size(); i++){
        cout << "Linhas: " << so_linhas.at(i) << " ";
    }
    cout << endl;
    for (int i = 0; i < so_colunas.size(); i++){
        cout << "Colunas: " << so_colunas.at(i) << " ";
    }
    cout << endl;
    for (int i = 0; i < so_comidas.size(); i++){
        cout << "Comidas: " << so_comidas.at(i) << " ";
    }
    cout << endl;
    /*for (int i = 0; i < todos_os_mapas.size(); i++){
        cout << todos_os_mapas.at(i) << endl;
    } tá ok*/

    for(int i = 0; i < mapa_atual.at(nivel).size(); i++){
        cout << mapa_atual.at(nivel).at(i) << endl;
    }
    
}

void Level::mostrar_mapa_um(){
    int mapa_um = 0, tamanho_dos_mapas = 0;
    tamanho_dos_mapas = todos_os_mapas.size();
    mapa_um = tamanho_dos_mapas/numero_de_linhas;
    
    for(int i = 0; i < mapa_um; i++){
        cout << todos_os_mapas[i]<< endl;    
    }
}

void Level::interface_principal(){

    cout << "---> Welcome to the classic Snake Game <---\n";
    cout << "           copyright DIMAp/UFRN 2017" << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "Levels loaded: " << numero_de_linhas << " | " << " Snake lives: 5 " << " | " << " Apples to eat: " << comidas_somadas << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << ">>> Press <ENTER> to start the game!" << endl;
    cout << "\nLifes: ♥♥♥♥♥ | Score: 0    | Food eaten: 0 of " << comidas_somadas << endl;
    cout << "______________________________________________________________________\n";
    mostrar_mapa_um();
    cout << "______________________________________________________________________\n";

}
