#include "Player.h"
#include "Level.h"
#include <iostream>

using namespace std;

void Player::posicao_da_cobra(vector<vector<string>>& mapa_atual, int nivel){

    for(int i = 0; i < mapa_atual.at(nivel).size(); i++){
        for(int j = 0; j < mapa_atual.at(nivel).at(i).size(); j++){
            if(mapa_atual.at(nivel).at(i).at(j) == '*'){                
                //posicao_cobra.(make_pair(i, j));
                mapa_atual.at(nivel).at(i).at(j) = 'V';
                posicao_cobra.first = i;
                posicao_cobra.second = j;
            }
        }
    }
}

void Player::movimentando_cobra(vector<vector<string>>& mapa_atual, int nivel) {
    para_cima.first = posicao_cobra.first-1;
    para_cima.second = posicao_cobra.second;
    para_baixo.first = posicao_cobra.first+1;
    para_baixo.second = posicao_cobra.second;
    para_esquerda.first = posicao_cobra.first;
    para_esquerda.second = posicao_cobra.second-1;
    para_direita.first = posicao_cobra.first;
    para_direita.second = posicao_cobra.second+1;
    

    if(mapa_atual.at(nivel)[para_cima.first][para_cima.second] != '#' && mapa_atual.at(nivel)[para_cima.first][para_cima.second] != '.'){
        mapa_atual.at(nivel)[para_cima.first][para_cima.second] = 'v';
        mapa_atual.at(nivel)[posicao_cobra.first][posicao_cobra.second] = ' ';
        posicao_cobra.first = para_cima.first;
        posicao_cobra.second = para_cima.second;

    }
    else if(mapa_atual.at(nivel)[para_baixo.first][para_cima.second] != '#' && mapa_atual.at(nivel)[para_baixo.first][para_baixo.second] != '.'){
        mapa_atual.at(nivel)[para_baixo.first][para_baixo.second] = '^';
        mapa_atual.at(nivel)[posicao_cobra.first][posicao_cobra.second] = ' ';
        posicao_cobra.first = para_baixo.first;
        posicao_cobra.second = para_baixo.second;
    } 
    else if(mapa_atual.at(nivel)[para_esquerda.first][para_esquerda.second] != '#' && mapa_atual.at(nivel)[para_esquerda.first][para_esquerda.second] != '.'){
        mapa_atual.at(nivel)[para_esquerda.first][para_esquerda.second] = '>';
        mapa_atual.at(nivel)[posicao_cobra.first][posicao_cobra.second] = ' ';
        posicao_cobra.first = para_esquerda.first;
        posicao_cobra.second = para_esquerda.second;
    } 
    else if(mapa_atual.at(nivel)[para_direita.first][para_direita.second] != '#' && mapa_atual.at(nivel)[para_direita.first][para_direita.second] != '.'){
        mapa_atual.at(nivel)[para_direita.first][para_direita.second] = '<';
        mapa_atual.at(nivel)[posicao_cobra.first][posicao_cobra.second] = ' ';    
        posicao_cobra.first = para_direita.first;
        posicao_cobra.second = para_direita.second;    
    }
}

void Player::mostrar_posicoes(vector<vector<string>>& mapa_atual, int nivel){
    cout << "POSIÇÕES" << endl;
    cout << para_cima.first << " e " << para_cima.second << endl;
    cout << para_baixo.first << " e " << para_baixo.second << endl;
    cout << para_esquerda.first << " e " << para_esquerda.second << endl;
    cout << para_direita.first << " e " << para_direita.second << endl;

}
