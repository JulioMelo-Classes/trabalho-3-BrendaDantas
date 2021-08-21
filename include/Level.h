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
        int getQuantidade_linhas();
        void setQuantidade_linhas(int linhas);
        int getQuantidade_colunas();
        void setQuantidade_colunas(int colunas);
        int getQuantidade_comidas();
        void setQuantidade_comidas(int comidas);
        void preencher_numeros(int num);
        void mostrar_numeros();
        void separar_numeros();
        void validar_numeros();
      

};

#endif