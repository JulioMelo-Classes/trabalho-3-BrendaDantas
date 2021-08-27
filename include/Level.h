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

    public:
        void preencher_mapa(string& mapa); // preencher um vetor com todos os mapas OK        
        void separar_mapa(); // separar os mapas por níveis OK
        void preencher_numeros(int numeros); //OK 
        void separar_numeros(); //OK
        void somando_comidas(); //OK
        int validar_numeros(); //OK
        //void gerar_comida(int nivel);
        void exibir_informacoes(int nivel);
        void mostrar_mapa_um(); //OK
        void interface_principal(); //OK
        void demais_interfaces(int nivel);
        void mostrar_andamento(int nivel);

};


#endif