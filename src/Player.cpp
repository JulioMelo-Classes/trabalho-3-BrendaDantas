#include "Player.h"
#include "Level.h"
#include <iostream>

using namespace std;

void Player::posicao_da_cobra(vector<vector<string>>& mapa_atual, int nivel){

    for(int i = 0; i < mapa_atual.at(nivel).size(); i++){
        for(int j = 0; j < mapa_atual.at(nivel).at(i).size(); j++){
            if(mapa_atual.at(nivel).at(i).at(j) == '*'){
                posicao_cobra.push_back(make_pair(i, j));
            }
        }
    }
}

