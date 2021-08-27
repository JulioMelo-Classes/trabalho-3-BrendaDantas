#include "Player.h"
#include "Level.h"
#include <iostream>

using namespace std;

void Player::posicao_da_cobra(vector<vector<string>>& mapa_atual, int nivel){

    for(int i = 0; i < mapa_atual.at(nivel).size(); i++){
        for(int j = 0; j < mapa_atual.at(nivel).at(i).size(); j++){
            if(mapa_atual.at(nivel).at(i).at(j) == '*'){
                posicao_cobra.push_back(make_pair(i, j));
                mapa_atual.at(nivel).at(i).at(j) = 'V';
            }
        }
    }
}

void Player::movimentando_cobra(vector<vector<string>>& mapa_atual, int nivel) {
    
    for(int i = 0; i < mapa_atual.at(nivel).size(); i++){
        for(int j = 0; j < mapa_atual.at(nivel).at(i).size(); j++){
            para_cima.push_back(make_pair(posicao_cobra.at(nivel).first-1, posicao_cobra.at(nivel).second));
            para_baixo.push_back(make_pair(posicao_cobra.at(nivel).first+1, posicao_cobra.at(nivel).second));
            para_esquerda.push_back(make_pair(posicao_cobra.at(nivel).first, posicao_cobra.at(nivel).second-1));
            para_direita.push_back(make_pair(posicao_cobra.at(nivel).first, posicao_cobra.at(nivel).second+1));

            if(para_cima.at(nivel).first != '#' && para_cima.at(nivel).first != '.' && para_cima.at(nivel).second != '#' && para_cima.at(nivel).second != '.'){
                //para_cima.at(nivel).first = posicao_cobra.at(nivel).first;
                //para_cima.at(nivel).second = posicao_cobra.at(nivel).second;
                //posicao_cobra.at(nivel).first = para_cima.at(nivel).first;                
                //posicao_cobra.at(nivel).second = para_cima.at(nivel).second;
                para_cima.at(nivel).first = '*';
                para_cima.at(nivel).second = '*';
            } else{
                cout << "ERRO"; 
            }

        }
    }   
}

void Player::mostrar_posicoes(vector<vector<string>>& mapa_atual, int nivel){
    cout << "POSIÇÕES" << endl;
    cout << para_cima.at(nivel).first << " e " << para_cima.at(nivel).second << endl;
    cout << para_baixo.at(nivel).first << " e " << para_baixo.at(nivel).second << endl;
    cout << para_esquerda.at(nivel).first << " e " << para_esquerda.at(nivel).second << endl;
    cout << para_direita.at(nivel).first << " e " << para_direita.at(nivel).second << endl;

}
