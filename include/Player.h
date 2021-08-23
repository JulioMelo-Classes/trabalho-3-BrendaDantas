#ifndef Player_h
#define Player_h

#include <vector>
#include <string>
using namespace std;

class Player{

    private:


    public:
        bool find_solution(int linha, int coluna, vector<int>& posicao_cobra, vector<string>& mapinha);

};

#endif