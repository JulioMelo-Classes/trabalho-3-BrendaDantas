#ifndef Level_h
#define Level_h

#include <vector>
#include <string>
using namespace std;

// Vai cuidar dos níveis do jogo:
// Criar interface principal -- método que mostra uma interface no início do jogo - ok(interface_principal)
// Mostrar o primeiro mapa na interface principal - ok(mostrar_mapa_um)
// Validar informações -- método que valida as informações acerca de cada mapa - ok(validar_numeros)
// "criar" o mapa -- método que guarda todos os mapas de todos os níveis - ok(preencher_mapa)
// Verificar qual o nível atual -- método que recebe o mapa(nível) atual - ok(separar_mapa)
// Colocar comida -- método que gera comidas no mapa atual

class Level {
    private:
        //vector<string> 
        vector<string> todos_os_mapas;//recebe todos os mapas
        vector<int> todos_os_numeros;//recebe todos os numeros
        vector<vector<string>> mapa_atual;
        vector<int> so_linhas;//recebe apenas linhas
        vector<int> so_colunas;//recebe apenas colunas
        vector<int> so_comidas;//recebe apenas comidas
        int comidas_somadas;//guarda a soma total de comidas que a cobra tem de comer
        vector<pair<int,int>> posicoes;


    public:
        void preencher_mapa(string& mapa); // preencher um vetor com todos os mapas
        //void posicao_da_cobra(int nivel); // descobrir qual a posição da cobra
        void separar_mapa(); // separar os mapas por níveis
        void preencher_numeros(int numeros);
        void separar_numeros();
        void somando_comidas();
        int validar_numeros();
        //void gerar_comida(int nivel);
        //void exibir_informacoes(int nivel);
        void mostrar_mapa_um();
        void interface_principal();

};


#endif