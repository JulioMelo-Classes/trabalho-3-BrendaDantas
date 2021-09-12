#ifndef Level_h
#define Level_h
#include "Player.h"

#include <vector>
#include <string>
using namespace std;

// Vai cuidar dos níveis do jogo:
// Criar interface principal -- método que mostra uma interface no início do jogo - ok(interface_principal)
// Mostrar o primeiro mapa na interface principal - ok(mostrar_mapa_um)
// Validar informações -- método que valida as informações acerca de cada mapa - ok(separar_numeros e preencher_ numeros e validar_numeros)
// "criar" o mapa -- método que guarda todos os mapas de todos os níveis - ok(preencher_mapa)
// Verificar qual o nível atual -- método que recebe o mapa(nível) atual - ok(separar_mapa)
// Colocar comida -- método que gera comidas no mapa atual - (somando_comidas)
// Localização da cobra -- atributo que contém a posição da cobra
// Localização de comida -- atributo com a posição da comida

class Level {
    private:
        Player player;
        vector<string> todos_os_mapas;//recebe todos os mapas
        vector<int> todos_os_numeros;//recebe todos os numeros
        vector<vector<string>> mapa_atual;        
        vector<int> so_linhas;//recebe apenas linhas
        vector<int> so_colunas;//recebe apenas colunas
        vector<int> so_comidas;//recebe apenas comidas
        int comidas_somadas;//guarda a soma total de comidas que a cobra tem de comer     
        pair<int, int> posicao_da_comida; 
        int numero_de_niveis; 
        int score = 0;
        int comidas_ingeridas = 0;
        int qtd_comidas_por_nivel = 0;

    public:

		/*! 
		* @brief método implementado para preencher um vetor com todos os mapas.
        *
        * @param mapa passada com os argumentos para poder ser guardada.
		*/
        void preencher_mapa(string& mapa); // preencher um vetor com todos os mapas OK        
        

		/*! 
		* @brief método implementado para separar os mapas. 
		*
		*/
        void separar_mapa(); // separar os mapas por níveis OK
        

		/*! 
		* @brief método implementado para preencher um vetor de inteiros com todos os números passados pelo jogados. 
		*
		* @param números é a variável, na qualcontém os números que seram guardados.
		*/
        void preencher_numeros(int numeros); //OK 


		/*! 
		* @brief método implementado para separar os números de largura e altura do mapa,e a comida em um vetor indivudal. 
		*
		*/
        void separar_numeros(); //OK


		/*! 
		* @brief método implementado para somar a quantidade total de comidas que a cobra deve comer. 
		*
		*/
        void somando_comidas(); //OK


		/*! 
		* @brief método implementado para verificar se os números passado pelo jogador são válidos. 
		*
        * @return retorna valor inteiro, no qual define a validade dos números passados.
		*/
        int validar_numeros(); //OK

        
		/*! 
		* @brief método implementado para gerar alimento para a cobra, todo momento que ela come. 
		*
		* @param nivel é a variável inteira que define o nivel atual do jogo.
		*/
        void gerar_comida(int nivel);


		/*! 
		* @brief método implementado para acessar mostrar o mapa de cada nivel quando for solicitado. 
		*
		*/
        void mostrar_mapa_um(); //OK


		/*! 
		* @brief método implementado para mostrar a interface principal do jogo. 
		*
		*/
        void interface_principal(); //OK


        /*! 
		* @brief método implementado para mostrar a interface de cada nivel quando estiver jogando. 
		*
		*/
        void interface_nivel();

        /*! 
		* @brief método implementado para mostrar o nível e o mapa do nível atual.
		*
        * @param nivel corresponde ao nível atual.
		*/
        void desenhar_mapa(int nivel);

        /*! 
		* @brief método implementado para chamar os métodos de player que pegam as posições da cobra e a faz andar.
		*
        * @param nivel corresponde ao nível atual.
		*/
        void modificar_andamento(int nivel);

        /*! 
		* @brief método implementado para pegar a quantidade de niveis.
		*
        * @return retorna a quantidade de niveis.
		*/
        int get_quantidade_de_niveis();

        /*! 
		* @brief método implementado para verificar se a cobra come a comida.
		*
        * @param estado_corpo verifica se a cobra terá corpo ou não.
        * @param nivel representa o nivel atual.
        * 
        * @return true caso achou a comida e falso caso contrário.
		*/
        bool verificar_colisao_comida(bool estado_corpo, int nivel);

        /*! 
		* @brief método implementado para verificar se no nivel atual, a cobra comeu todas as comidas. 
		*
        * @return true caso tenha comido todas e false caso contrário.
		*/
        bool checar_comida_por_nivel();
};


#endif