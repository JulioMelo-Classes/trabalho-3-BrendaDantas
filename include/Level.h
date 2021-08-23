#ifndef Level_h
#define Level_h

#include <vector>
#include <string>
using namespace std;

class Level {
    private:
        vector<int>quantidade_linhas_tot;
        vector<int>quantidade_colunas_tot;
        vector<int>quantidade_comidas_tot;
        //int quantidade_linhas, quantidade_colunas, quantidade_comidas;        
        std::vector<std::string> mapas_do_arquivo;
        vector<string> mapa_auxiliar;
        vector<int> numeros;//vector c/ numeros de entrada
        vector<int> posicao_cobra;


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

};

#endif