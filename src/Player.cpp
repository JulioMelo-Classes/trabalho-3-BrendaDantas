#include "Player.h"
#include "Level.h"
#include <iostream>

using namespace std;


/*bool Player::find_solution(int linha, int coluna, vector<int>& posicao_cobra, vector<string>& mapinha, int qtd_comida){    
    int posicao_linha_c = 0, posicao_coluna_c = 0;
    posicao_linha_c = posicao_cobra[0];
    posicao_coluna_c = posicao_cobra[1];

            /*if(mapinha[i--][j] == ' '){
                posicao_valida_lin.push_back(i--);
                posicao_valida_col.push_back(j);
                i--;
            } else if(mapinha[i--][j] == '#' || mapinha[i--][j] == '.'){
                posicao_nao_valida_lin.push_back(i--);
                posicao_nao_valida_col.push_back(j);
                if(mapinha[i][j--] == ' '){
                    posicao_valida_lin.push_back(i);
                    posicao_valida_col.push_back(j--);
                    j--;
                } else if(mapinha[i][j--] == '#' || mapinha[i][j--] == '.'){
                    posicao_nao_valida_lin.push_back(i);
                    posicao_nao_valida_col.push_back(j--);
                } else if(mapinha[i][j++] == ' '){
                    posicao_valida_lin.push_back(i);
                    posicao_valida_col.push_back(j++);
                    j++;
                }  else if(mapinha[i][j++] == '#' || mapinha[i][j++] == '.'){
                    posicao_nao_valida_lin.push_back(i);
                    posicao_nao_valida_col.push_back(j++);
                } else if(mapinha[i++][j] == ' '){
                    posicao_valida_lin.push_back(i++);
                    posicao_valida_col.push_back(j);
                    i++;
                }
            } else if(mapinha[i++][j] == '#' || mapinha[i++][j] == '.'){
                    posicao_nao_valida_lin.push_back(i++);
                    posicao_nao_valida_col.push_back(j);
                    
            }*/
       // }    
  //  }

   /* for(int i = posicao_linha_c; i < linha; i++ ){
        for(int j = posicao_coluna_c; j < coluna; j++){
            if(mapinha[i-1][j] == 'A'){//encontra comida
                //cout << "encontrei comida, na linha: "<< i-1 << " coluna:" << j << endl;
                qtd_comida = qtd_comida - 1;
                mapinha[i-1][j] == 'v';
                mapinha[i][j] == 'o';
                posicao_nao_valida_lin.push_back(i-1);
                posicao_nao_valida_col.push_back(j);
                if(qtd_comida == 0){
                    cout << "Comeu todas as comidas!!!!!\n";
                    return true;
                }
            } else if(mapinha[i-1][j] == '#' || mapinha[i-1][j] == '.'){//encontra parede
                posicao_nao_valida_lin.push_back(i-1);
                posicao_nao_valida_col.push_back(j);
                //cout << "parede encontrada\n";
            } else if(mapinha[i-1][j] == ' '){//encontra caminho livre
                posicao_valida_lin.push_back(i-1);
                posicao_valida_col.push_back(j);
               // cout << "posição valida: " << i-1 << " e " << j << endl;
            } else if(mapinha[i-1][j] == 'o' || mapinha[i-1][j] == 'v'){//encontrou a cabeça ou o corpo
                posicao_nao_valida_lin.push_back(i);
                posicao_nao_valida_col.push_back(j);
                posicao_nao_valida_lin.push_back(i-1);
                posicao_nao_valida_col.push_back(j);
               // cout << "tam corpo\n";
            } else if(mapinha[i+1][j] == 'A'){
               // cout << "encontrei comida, na linha: "<< i+1 << " coluna:" << j << endl;
                qtd_comida = qtd_comida - 1;
                mapinha[i+1][j] == 'v';
                mapinha[i][j] == 'o';
                posicao_nao_valida_lin.push_back(i-1);
                posicao_nao_valida_col.push_back(j);
            } else if(mapinha[i+1][j] == '#' || mapinha[i+1][j] == '.'){
                posicao_nao_valida_lin.push_back(i+1);
                posicao_nao_valida_col.push_back(j);
               // cout << "parede encontrada\n";
            } else if(mapinha[i+1][j] == ' '){//encontra caminho livre
                posicao_valida_lin.push_back(i+1);
                posicao_valida_col.push_back(j);
                //cout << "posição valida: " << i+1 << " e " << j << endl;
            } else if(mapinha[i+1][j] == 'o' || mapinha[i+1][j] == 'v'){//encontrou a cabeça ou o corpo
                posicao_nao_valida_lin.push_back(i);
                posicao_nao_valida_col.push_back(j);
                posicao_nao_valida_lin.push_back(i+1);
                posicao_nao_valida_col.push_back(j);
               // cout << "tam corpo\n";
            } else if(mapinha[i][j+1] == 'A'){
                cout << "encontrei comida, na linha: "<< i << " coluna:" << j+1 << endl;
                qtd_comida = qtd_comida - 1;
                mapinha[i][j+1] == 'v';
                mapinha[i][j] == 'o';
                posicao_nao_valida_lin.push_back(i);
                posicao_nao_valida_col.push_back(j+1);
            } else if(mapinha[i][j+1] == '#' || mapinha[i][j+1] == '.'){
                posicao_nao_valida_lin.push_back(i);
                posicao_nao_valida_col.push_back(j+1);
              //  cout << "parede encontrada\n";
            } else if(mapinha[i][j+1] == ' '){//encontra caminho livre
                posicao_valida_lin.push_back(i);
                posicao_valida_col.push_back(j+1);
               // cout << "posição valida: " << i << " e " << j+1 << endl;
            } else if(mapinha[i][j+1] == 'o' || mapinha[i][j+1] == 'v'){//encontrou a cabeça ou o corpo
                posicao_nao_valida_lin.push_back(i);
                posicao_nao_valida_col.push_back(j);
                posicao_nao_valida_lin.push_back(i);
                posicao_nao_valida_col.push_back(j+1);
              //  cout << "tam corpo\n";
            } else if(mapinha[i][j-1] == 'A'){
               // cout << "encontrei comida, na linha: "<< i << " coluna:" << j-1 << endl;
                qtd_comida = qtd_comida - 1;
                mapinha[i][j-1] == 'v';
                mapinha[i][j] == 'o';
                posicao_nao_valida_lin.push_back(i);
                posicao_nao_valida_col.push_back(j);
            } else if(mapinha[i][j+1] == '#' || mapinha[i][j-1] == '.'){
                posicao_nao_valida_lin.push_back(i);
                posicao_nao_valida_col.push_back(j-1);
              //  cout << "parede encontrada\n";
            } else if(mapinha[i][j+1] == ' '){//encontra caminho livre
                posicao_valida_lin.push_back(i);
                posicao_valida_col.push_back(j-1);
              //  cout << "posição valida: " << i+1 << " e " << j << endl;
            } else if(mapinha[i][j+1] == 'o' || mapinha[i][j-1] == 'v'){//encontrou a cabeça ou o corpo
                posicao_nao_valida_lin.push_back(i);
                posicao_nao_valida_col.push_back(j);
                posicao_nao_valida_lin.push_back(i);
                posicao_nao_valida_col.push_back(j-1);
             //   cout << "tam corpo\n";
            }
        }
    }*/
    

  //  return true;
//}

void Player::next_move(int linha, int coluna, vector<int>& posicao_cobra, vector<string>& mapinha){
    int posicao_linha_c = 0, posicao_coluna_c = 0, x, y;
    posicao_linha_c = posicao_cobra[0];
    posicao_coluna_c = posicao_cobra[1];
    //string head;
    vector<string> mapa;
    /*for(auto i = mapinha.begin(); i != mapinha.end(); i++){
        mapa.push_back(mapinha);
    }*/
    for(int i = posicao_linha_c; i < linha;){
        for(int j = posicao_coluna_c; j < coluna;){
            if(mapinha[i--][j] == ' '){//olhou a direção a norte
                //x = i--;
                //y = j;
                cout << i-- << endl;
                cout << j << endl;
                move_snake('^', i--, j, linha, coluna, mapinha, posicao_linha_c, posicao_coluna_c);
                break;

                /*if(mapinha[i][j++] == ' '){
                    x = i--;
                    y = j;
                    move_snake('>', x, y, linha, coluna, mapinha, posicao_linha_c, posicao_coluna_c);
                    break;

                }*/ /*else if(mapinha[i][j--]){
                    cout << "ok";
                }*/
            } /*else if(mapinha[i++][j] == ' '){//olhou a direção a sul
                    cout << "ok";
            } */
        }
    }
}

void Player::move_snake(char head, int pos_linha_snake, int pos_coluna_snake, int linha_mapa_atual, int coluna_mapa_atual, vector<string>& mapa_atual, int plc, int pcc){

    for(int i = 0; i < linha_mapa_atual; i++){
        for(int j = 0; j < coluna_mapa_atual; j++){
            if(mapa_atual[pos_linha_snake][pos_coluna_snake] == ' '){
                mapa_atual[pos_linha_snake][pos_coluna_snake] = head;
                mapa_atual[plc][pcc] = ' ';
            }
        }
    }
    cout << "CABEÇA DA COBRA MOVENDO DE LUGAR\n";
    for(auto i = mapa_atual.begin(); i != mapa_atual.end(); i++){
        cout << *i << endl;
    }
}
