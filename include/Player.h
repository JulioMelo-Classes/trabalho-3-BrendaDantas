#ifndef Player_h
#define Player_h

#include <vector>
#include <string>
using namespace std;


// Movimenta a cobra -- método que faz a cobra andar
// Comer comida -- método que faz a cobra comer a comida
// Morrer ou continuar viva 
// Crescimento da cobra -- método que aumenta o corpo da cobra
// Caminhos possíveis -- método que verifica e guarda os caminhos válidos
// Caminhos já visitados (/impossíveis) -- método que guarda todos os caminhos já verificados 

class Player{

    private:
        vector<pair<int,int>> posicao_cobra;

    public: 
        void posicao_da_cobra(vector<vector<string>>& mapa_atual, int nivel); // descobrir qual a posição da cobra
        void movimentando_cobra(vector<vector<string>>& mapa_atual, int nivel);

};

#endif