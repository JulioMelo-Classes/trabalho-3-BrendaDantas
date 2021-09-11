#include "Player.h"
#include "Level.h"
#include "Snake.h"
#include <iostream>

using namespace std;

pair<int, int> Player::get_posicao_da_cobra(){
    return posicao_cobra;
}

void Player::posicao_da_cobra(vector<vector<string>>& mapa_atual, int nivel){

    for(int i = 0; i < mapa_atual.at(nivel).size(); i++){
        for(int j = 0; j < mapa_atual.at(nivel).at(i).size(); j++){
            if(mapa_atual.at(nivel).at(i).at(j) == '*'){
                mapa_atual.at(nivel).at(i).at(j) = 'v';
                posicao_cobra.first = i;
                posicao_cobra.second = j;
                corpo.push_back(make_pair(i, j));
            }
        }
    }
}

void Player::movimentando_cobra(vector<vector<string>>& mapa_atual, int nivel, int comidas_ingeridas) {
    if(mapa_atual.at(nivel)[posicao_cobra.first][posicao_cobra.second] == '<'){
        para_manter.first = posicao_cobra.first;
        para_manter.second = posicao_cobra.second+1;
        para_esquerda.first = posicao_cobra.first-1;
        para_esquerda.second = posicao_cobra.second;
        para_direita.first = posicao_cobra.first+1;
        para_direita.second = posicao_cobra.second;
        
        if(mapa_atual.at(nivel)[para_esquerda.first][para_esquerda.second] != '#' && mapa_atual.at(nivel)[para_esquerda.first][para_esquerda.second] != '.'){
            mapa_atual.at(nivel)[para_esquerda.first][para_esquerda.second] = 'v';
            mapa_atual.at(nivel)[posicao_cobra.first][posicao_cobra.second] = ' ';
            posicao_cobra.first = para_esquerda.first;
            posicao_cobra.second = para_esquerda.second;
        } else if(mapa_atual.at(nivel)[para_direita.first][para_direita.second] != '#' && mapa_atual.at(nivel)[para_direita.first][para_direita.second] != '.'){
            mapa_atual.at(nivel)[para_direita.first][para_direita.second] = '^';
            mapa_atual.at(nivel)[posicao_cobra.first][posicao_cobra.second] = ' ';    
            posicao_cobra.first = para_direita.first;
            posicao_cobra.second = para_direita.second; 
        } else if(mapa_atual.at(nivel)[para_manter.first][para_manter.second] != '#' && mapa_atual.at(nivel)[para_manter.first][para_manter.second] != '.'){
            mapa_atual.at(nivel)[para_manter.first][para_manter.second] = '<';
            mapa_atual.at(nivel)[posicao_cobra.first][posicao_cobra.second] = ' ';
            posicao_cobra.first = para_manter.first;
            posicao_cobra.second = para_manter.second;
        }
    }
    else if(mapa_atual.at(nivel)[posicao_cobra.first][posicao_cobra.second] == '>'){
        para_manter.first = posicao_cobra.first;
        para_manter.second = posicao_cobra.second-1;
        para_esquerda.first = posicao_cobra.first+1;
        para_esquerda.second = posicao_cobra.second;
        para_direita.first = posicao_cobra.first-1;
        para_direita.second = posicao_cobra.second;   

        if(mapa_atual.at(nivel)[para_esquerda.first][para_esquerda.second] != '#' && mapa_atual.at(nivel)[para_esquerda.first][para_esquerda.second] != '.'){
            mapa_atual.at(nivel)[para_esquerda.first][para_esquerda.second] = '^';
            mapa_atual.at(nivel)[posicao_cobra.first][posicao_cobra.second] = ' ';
            posicao_cobra.first = para_esquerda.first;
            posicao_cobra.second = para_esquerda.second;
        } else if(mapa_atual.at(nivel)[para_direita.first][para_direita.second] != '#' && mapa_atual.at(nivel)[para_direita.first][para_direita.second] != '.'){
            mapa_atual.at(nivel)[para_direita.first][para_direita.second] = 'v';
            mapa_atual.at(nivel)[posicao_cobra.first][posicao_cobra.second] = ' ';    
            posicao_cobra.first = para_direita.first;
            posicao_cobra.second = para_direita.second; 
        } else if(mapa_atual.at(nivel)[para_manter.first][para_manter.second] != '#' && mapa_atual.at(nivel)[para_manter.first][para_manter.second] != '.'){
            mapa_atual.at(nivel)[para_manter.first][para_manter.second] = '>';
            mapa_atual.at(nivel)[posicao_cobra.first][posicao_cobra.second] = ' ';
            posicao_cobra.first = para_manter.first;
            posicao_cobra.second = para_manter.second;
        }       
    }
    else if(mapa_atual.at(nivel)[posicao_cobra.first][posicao_cobra.second] == 'v') {
        para_manter.first = posicao_cobra.first-1;
        para_manter.second = posicao_cobra.second;
        para_esquerda.first = posicao_cobra.first;
        para_esquerda.second = posicao_cobra.second-1;
        para_direita.first = posicao_cobra.first;
        para_direita.second = posicao_cobra.second+1;   

        if(mapa_atual.at(nivel)[para_esquerda.first][para_esquerda.second] != '#' && mapa_atual.at(nivel)[para_esquerda.first][para_esquerda.second] != '.'){
            mapa_atual.at(nivel)[para_esquerda.first][para_esquerda.second] = '>';
            mapa_atual.at(nivel)[posicao_cobra.first][posicao_cobra.second] = ' ';
            posicao_cobra.first = para_esquerda.first;
            posicao_cobra.second = para_esquerda.second;
        } else if(mapa_atual.at(nivel)[para_direita.first][para_direita.second] != '#' && mapa_atual.at(nivel)[para_direita.first][para_direita.second] != '.'){
            mapa_atual.at(nivel)[para_direita.first][para_direita.second] = '<';
            mapa_atual.at(nivel)[posicao_cobra.first][posicao_cobra.second] = ' ';    
            posicao_cobra.first = para_direita.first;
            posicao_cobra.second = para_direita.second; 
        } else if(mapa_atual.at(nivel)[para_manter.first][para_manter.second] != '#' && mapa_atual.at(nivel)[para_manter.first][para_manter.second] != '.'){
            mapa_atual.at(nivel)[para_manter.first][para_manter.second] = 'v';
            mapa_atual.at(nivel)[posicao_cobra.first][posicao_cobra.second] = ' ';
            posicao_cobra.first = para_manter.first;
            posicao_cobra.second = para_manter.second;
        }
    }
    else if (mapa_atual.at(nivel)[posicao_cobra.first][posicao_cobra.second] == '^'){
        para_manter.first = posicao_cobra.first+1;
        para_manter.second = posicao_cobra.second;
        para_esquerda.first = posicao_cobra.first;
        para_esquerda.second = posicao_cobra.second+1;
        para_direita.first = posicao_cobra.first;
        para_direita.second = posicao_cobra.second-1;

        if(mapa_atual.at(nivel)[para_esquerda.first][para_esquerda.second] != '#' && mapa_atual.at(nivel)[para_esquerda.first][para_esquerda.second] != '.'){
            mapa_atual.at(nivel)[para_esquerda.first][para_esquerda.second] = '<';
            mapa_atual.at(nivel)[posicao_cobra.first][posicao_cobra.second] = ' ';
            posicao_cobra.first = para_esquerda.first;
            posicao_cobra.second = para_esquerda.second;
        } else if(mapa_atual.at(nivel)[para_direita.first][para_direita.second] != '#' && mapa_atual.at(nivel)[para_direita.first][para_direita.second] != '.'){
            mapa_atual.at(nivel)[para_direita.first][para_direita.second] = '>';
            mapa_atual.at(nivel)[posicao_cobra.first][posicao_cobra.second] = ' ';    
            posicao_cobra.first = para_direita.first;
            posicao_cobra.second = para_direita.second; 
        } else if(mapa_atual.at(nivel)[para_manter.first][para_manter.second] != '#' && mapa_atual.at(nivel)[para_manter.first][para_manter.second] != '.'){
            mapa_atual.at(nivel)[para_manter.first][para_manter.second] = '^';
            mapa_atual.at(nivel)[posicao_cobra.first][posicao_cobra.second] = ' ';
            posicao_cobra.first = para_manter.first;
            posicao_cobra.second = para_manter.second;
        }
    }
}

void Player::crescer_cobra(vector<vector<string>>& mapa_atual, int nivel) {
    corpo.push_back(make_pair(posicao_cobra.first, posicao_cobra.second));
    for(int i = 1; i < corpo.size()-1; i++){
        mapa_atual.at(nivel)[corpo[i].first][corpo[i].second] = 'o';
    }
}
