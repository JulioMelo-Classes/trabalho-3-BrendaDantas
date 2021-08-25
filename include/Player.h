#ifndef Player_h
#define Player_h

#include <vector>
#include <string>
using namespace std;

class Player{

    private:
        vector<int> posicao_nao_valida_lin;
        vector<int> posicao_nao_valida_col;

        vector<int> posicao_valida_lin;
        vector<int> posicao_valida_col;

        
    public:
        //bool find_solution(int linha, int coluna, vector<int>& posicao_cobra, vector<string>& mapinha, int qtd_comida);
        void next_move(int linha, int coluna, vector<int>& posicao_cobra, vector<string>& mapinha);
        void move_snake(char head, int linha_pos, int pos_coluna, int linha_mapa_atual, int coluna_mapa_atual, vector<string>& mapa_atual, int plc, int pcc);

};

#endif