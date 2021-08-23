#include "Player.h"
#include "Level.h"
#include <iostream>

using namespace std;


bool Player::find_solution(int linha, int coluna, vector<int>& posicao_cobra, vector<string>& mapinha){
    
    int posicao_linha_c = 0, posicao_coluna_c = 0;
    posicao_linha_c = posicao_cobra[0];
    posicao_coluna_c = posicao_cobra[1];

    cout << "CONFIRMANDO POSIÇÕES DE LINHA E COLUNA: " << posicao_linha_c << " | " << posicao_coluna_c << endl;

    for(int i = posicao_linha_c; i < linha; i++ ){
        for(int j = posicao_coluna_c; j < coluna; j++){
            if(mapinha[i][j] == 'A'){
                cout << "encontrei comida, na linha: "<< i << " coluna:" << j << endl;
            }
        }
    }

    return true;
}

