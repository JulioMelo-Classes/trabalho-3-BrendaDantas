#include "Level.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <time.h>
#include "SnakeGame.h"
using namespace std;

void Level::preencher_numeros(int num){//numeros de entrada guardados no vector
    numeros.push_back(num);
}

void Level::mostrar_numeros(){
    for(auto i = numeros.begin(); i != numeros.end(); i++){
        //cout << *i << endl;
    }
}
int numero_de_linhas = 0, quant_comida =0;;
void Level::separar_numeros(){//guardando numeros no vector e somando comidas
    int aux1 = 0, aux2 = 0, contador = 1, pos_coluna = 0, pos_comida = 0;
    int tamanho_de_linhas = numeros.size();//descobre a quantidade total de números existentes

    numero_de_linhas = tamanho_de_linhas/3;//descobre quantas linhas de números tem

    for(int i = 0; i < numeros.size(); i++){
        if(aux1 == 0){
            quantidade_linhas_tot.push_back(numeros[i]);
            quantidade_colunas_tot.push_back(numeros[i+1]);
            quantidade_comidas_tot.push_back(numeros[i+2]);

        } else if(aux1 > 0) {
            pos_coluna = i;
            pos_comida = i+1;
            i = 3;//posição de linhas
            quantidade_linhas_tot.push_back(numeros[i+aux2]);
            quantidade_colunas_tot.push_back(numeros[pos_coluna+3]);
            quantidade_comidas_tot.push_back(numeros[pos_comida+3]);
            aux2 = 3;
            contador++;
            if(contador == numero_de_linhas){
                break;
            }
        }
        aux1++;
    }
   
    int tt = quantidade_comidas_tot.size();//descobre a quantidade de comidas que existem
    for(int i =0; i < tt; i++){//somando comidas
        quant_comida = quant_comida + quantidade_comidas_tot[i];
    }
}

int Level::validar_numeros(){//valida números de entrada
    for(auto itr1 = quantidade_linhas_tot.begin(); itr1 != quantidade_linhas_tot.end(); itr1++){
        if(*itr1 <= 0 || *itr1 > 100){
            return 1;
        }
    }
    for(auto itr1 = quantidade_colunas_tot.begin(); itr1 != quantidade_colunas_tot.end(); itr1++){
        if(*itr1 <= 0 || *itr1 > 100){
            return 2;
        }
    }
    for(auto itr1 = quantidade_comidas_tot.begin(); itr1 != quantidade_comidas_tot.end(); itr1++){
        if(*itr1 <= 0){
            return 3;
        }
    }
    return 0;
}

void Level::preencher_mapa(string s){//preenche o mapa em vector da classe level
    mapas_do_arquivo.push_back(s);
}

void Level::mostrar_mapa_um(){//mostra o primeiro mapa na interface
    int mapa_um = 0, tamanho_dos_mapas = 0;
    tamanho_dos_mapas = mapas_do_arquivo.size();
    mapa_um = tamanho_dos_mapas/numero_de_linhas;
    
    for(int i = 0; i < mapa_um; i++){
        cout << mapas_do_arquivo[i]<< endl;    
    }
}

int qtdlinha = 0, qtdcoluna = 0, pos_final_linha = 0, pos_final_coluna = 0, encerramento_linha = 0, encerramento_coluna = 0;

void Level::encontrar_posicao_cobra(int num){
   
    if(num == 0){//pega posição primeiro nivel
        qtdlinha = quantidade_linhas_tot[0];
        qtdcoluna = quantidade_colunas_tot[0];

        for(int i = 0; i < qtdlinha; i++){
            mapa_auxiliar.push_back(mapas_do_arquivo[i]);//pegando mapa novamente
        }

        for(int i = 0; i <qtdlinha; i++){//pega a posição da cobra
            for(int j = 0; j < qtdcoluna; j++){
                if(mapa_auxiliar[i][j] == '*'){
                    posicao_cobra.push_back(i);//aqui é a linha
                    posicao_cobra.push_back(j);//aqui é a coluna
                }
            }
        }
        pos_final_linha = qtdlinha;
        pos_final_coluna = qtdcoluna;
    } else {
        posicao_cobra.clear();//limpa a posição antiga sempre que chega em uma nova para não acumular
        mapa_auxiliar.clear();//limpa o vector para o proximo nivel (RETIRAR MAIS TARDE)
        qtdlinha = quantidade_linhas_tot[num];
        qtdcoluna = quantidade_colunas_tot[num];

        encerramento_linha = (pos_final_linha+qtdlinha);
        encerramento_coluna = (pos_final_coluna+qtdcoluna)-1;

        for(int i = pos_final_linha; i <= encerramento_linha; i++){
            mapa_auxiliar.push_back(mapas_do_arquivo[i]);//pegando mapa novamente
        }

        for(int i = 0; i <qtdlinha; i++){//pega a posição da cobra
            for(int j = 0; j < qtdcoluna; j++){
                if(mapa_auxiliar[i][j] == '*'){
                    posicao_cobra.push_back(i);//aqui é a linha
                    posicao_cobra.push_back(j);//aqui é a coluna
                    cout << "Achei mais um * em " << i << " e " << j << endl;
                }
            }
        }
        pos_final_coluna = encerramento_coluna;
        pos_final_linha = encerramento_linha;
    }    
}

void Level::interface_principal(){
    
    cout << "---> Welcome to the classic Snake Game <---\n";
    cout << "           copyright DIMAp/UFRN 2017" << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "Levels loaded: " << numero_de_linhas << " | " << " Snake lives: 5 " << " | " << " Apples to eat: " << quant_comida << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << ">>> Press <ENTER> to start the game!" << endl;
    cout << "\nLifes: ♥♥♥♥♥ | Score: 0    | Food eaten: 0 of " << quant_comida << endl;
    cout << "______________________________________________________________________\n";
    mostrar_mapa_um();
    cout << "______________________________________________________________________\n";
}

int qtd_comida = 0;
void Level::distribuindo_comida(int gatilho_comida){//faz e distribui no mapa a comida
    int contador = 0, i = 0, j = 0;
    srand(time(NULL));

    if(gatilho_comida == 0){//1º nivel, distribuindo comida
        qtd_comida = quantidade_comidas_tot[0];
       
        while( contador < qtd_comida) {
		    i = rand() % quantidade_colunas_tot[0];
		    j = rand() % quantidade_colunas_tot[0];

		    if(mapa_auxiliar[i][j] == ' '){	
                posicao_da_comida_linha.push_back(i);//guardando posição da comida - linha
                posicao_da_comida_coluna.push_back(j);                         //   - coluna
                //cout << "linha = " << i << " e coluna = " << j << endl;
                //mapa_auxiliar[i][j] = 'A';
                contador++;
		    }
        }
       /*cout << "mapa com comida\n";
        for(auto i = mapa_auxiliar.begin(); i != mapa_auxiliar.end(); i++){
            cout << *i << endl;
        }*/
	
    }else if(gatilho_comida > 0){//nível 2 em diante
        qtd_comida = quantidade_comidas_tot[gatilho_comida];

        while( contador < qtd_comida) {
		    i = rand() % quantidade_colunas_tot[gatilho_comida];
		    j = rand() % quantidade_colunas_tot[gatilho_comida];

		    if(mapa_auxiliar[i][j] == ' '){	
                posicao_da_comida_linha.push_back(i);//guardando posição da comida
                posicao_da_comida_coluna.push_back(j);
                cout << "linha = " << i << " e coluna = " << j << endl;
                //mapa_auxiliar[i][j] = 'A';
                contador++;
		    }
        }
       /* cout << "\n";
        for(auto i = mapa_auxiliar.begin(); i != mapa_auxiliar.end(); i++){
            cout << *i << endl;
        }*/
    }
    
}

void Level::monitoramento(int num){//chama find_solution para monitorar possiveis posiloes da cobra
    Player jogo;
    if(num == 0){
        jogo.next_move(qtdlinha, qtdcoluna, posicao_cobra, mapa_auxiliar);
        //jogo.find_solution(qtdlinha, qtdcoluna, posicao_cobra, mapa_auxiliar, qtd_comida);
    } else if(num > 0){
        jogo.next_move(qtdlinha, qtdcoluna, posicao_cobra, mapa_auxiliar);
        //jogo.find_solution(qtdlinha, qtdcoluna, posicao_cobra, mapa_auxiliar, qtd_comida);
    }
}

void Level::mostrar_cobra_mapa(int nivel){//mostra inicialmente a cobra no mapa
    if(nivel == 0){
        for(int i = 0; i < qtdlinha; i++){
            for(int j = 0; j < qtdcoluna; j++){
                if(mapa_auxiliar[i][j] == '*'){
                    mapa_auxiliar[i][j] = 'v';
                }
            }
        }
    }else if(nivel > 0){
        for(int i = 0; i < qtdlinha; i++){
            for(int j = 0; j < qtdcoluna; j++){
                if(mapa_auxiliar[i][j] == '*'){
                    mapa_auxiliar[i][j] = 'v';
                }
            }
        }
    }

    cout << "-------------------------------------------------------------" << endl;
    cout << "=================== VIZUALIZANDO COBRA ======================\n";
    cout << "Level: " << nivel+1 << " |    Lifes: ♥♥♥♥♥" << endl; 
    for(auto i = mapa_auxiliar.begin(); i != mapa_auxiliar.end(); i++){
        cout << *i << endl;
    }
    cout << "-------------------------------------------------------------" << endl;

}
