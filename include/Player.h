#ifndef Player_h
#define Player_h

#include "Snake.h"
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
        pair<int, int> posicao_cobra;
        pair<int, int> nova_posicao_cobra;
        pair<int, int> para_cima;
        pair<int, int> para_baixo;
        pair<int, int> para_esquerda;
        pair<int, int> para_direita;
        pair<int, int> para_manter;
        vector<pair<int, int>> corpo;
        pair<int, int> posicao_antiga_cobra;

    public: 

        /*! 
		* @brief método implementado para descobrir a posição inicial da cobra no mapa e adicionar a sua "cabeça". 
		*
        * @param mapa_atual mapa do nivel atual.
        * @param nivel nivel atual do jogo.
		*/
        void posicao_da_cobra(vector<vector<string>>& mapa_atual, int nivel); // descobrir qual a posição da cobra
       
        /*! 
		* @brief método implementado para fazer a cobra andar pelo labirinto. 
		*
        * @param mapa_atual mapa do nivel atual.
        * @param nivel nivel atual do jogo.
		*/
        void movimentando_cobra(vector<vector<string>>& mapa_atual, int nivel);

        /*! 
		* @brief método implementado para acessar a posição da cobra. 
		*
        * @return retorna um pair contendo a posição da cobra.
		*/
        pair<int, int> get_posicao_da_cobra();

        /*! 
		* @brief método implementado para fazer crescer o corpo da cobra sempre que ela ingerir uma comida. 
		*
        * @param mapa_atual mapa do nivel atual.
        * @param nivel nivel atual do jogo.
		*/
        void crescer_cobra(vector<vector<string>>& mapa_atual, int nivel);

        /*! 
		* @brief método implementado para verificar o conteúdo faz parte do corpo da cobra.
		*
        * @param linha linhas do mapa.
        * @param coluna colunas do mapa.
        * 
        * @return true caso o par de linha e coluna faça parte e false caso contrário.
		*/
        bool faz_parte(int linha, int coluna);

};

#endif