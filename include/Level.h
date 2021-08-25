#ifndef Level_h
#define Level_h

#include <vector>
#include <string>
using namespace std;

class Level {
    private:
        vector<string> todos_os_mapas;//recebe todos os mapas
        vector<int> todos_os_numeros;//recebe todos os numeros
        vector<int> so_linhas;//recebe apenas linhas
        vector<int> so_colunas;//recebe apenas colunas
        vector<int> so_comidas;//recebe apenas comidas
        int comidas_somadas;//guarda a soma total de comidas que a cobra tem de comer


    public:
        void preencher_mapa(string mapa);
        void preencher_numeros(int numeros);
        void separar_numeros();
        void somando_comidas();
        int validar_numeros();

};

#endif