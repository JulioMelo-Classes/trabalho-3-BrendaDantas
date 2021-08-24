#ifndef Level_h
#define Level_h

#include <vector>
#include <string>
using namespace std;

class Level {
    private:
        vector<int>quantidade_linhas_tot;//vector c/ as linhas
        vector<int>quantidade_colunas_tot;//vector c/ as colunas
        vector<int>quantidade_comidas_tot;//vector c/ as comidas
        std::vector<std::string> mapas_do_arquivo;//vector c/ todos os mapas
        vector<string> mapa_auxiliar;//vector q guarda os mapas por nível
        vector<int> numeros;//vector c/ numeros de entrada
        vector<int> posicao_cobra;//vector c/ posição da cobra
        vector<int> posicao_da_comida_linha;//vector q guarda a posição da comida sorteda
        vector<int> posicao_da_comida_coluna;

    public:
        void preencher_numeros(int num);
        void mostrar_numeros();
        void separar_numeros();
        int validar_numeros();
        void preencher_mapa(string s);
        void mostrar_mapa_um();
        void interface_principal();
        void encontrar_posicao_cobra(int num);
        void distribuindo_comida(int gatilho_comida);
        //void monitoramento(int num);
        void mostrar_cobra_mapa(int num);

};

#endif