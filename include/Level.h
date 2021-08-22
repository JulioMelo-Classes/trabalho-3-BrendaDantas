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
        vector<int>numeros;//vector c/ numeros de entrada

    public:
        void preencher_numeros(int num);
        void mostrar_numeros();
        void separar_numeros();
        //void mostra_num_separados();
        int validar_numeros();
        void preencher_mapa(string s);
        void mostrar_mapas();
        void interface_principal();
        void encontrar_posicao_cobra();
      

};

#endif