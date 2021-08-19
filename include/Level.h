#ifndef Level_h
#define Level_h

#include <vector>
#include <string>

class Level {
    private:
        int quantidade_linhas, quantidade_colunas, quantidade_comidas;        
        std::vector<std::string> mapas_do_arquivo;

    public:

        int getQuantidade_linhas();
        void setQuantidade_linhas(int linhas);
        int getQuantidade_colunas();
        void setQuantidade_colunas(int colunas);
        int getQuantidade_comidas();
        void setQuantidade_comidas(int comidas);

};

#endif