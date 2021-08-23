#include "Level.h"
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
        cout << *i << endl;
    }
}
int numero_de_linhas = 0, quant_comida =0;;
void Level::separar_numeros(){//guardando os numeros nos vectors
    int aux1 = 0, aux2 = 0;
    int contador = 1;
    int pos_coluna = 0, pos_comida = 0;

    int tamanho_de_linhas = numeros.size();

    numero_de_linhas = tamanho_de_linhas/3;
    //cout << "line number: " << numero_de_linhas << endl;

    for(int i = 0; i < numeros.size(); i++){
        if(aux1 == 0){
            quantidade_linhas_tot.push_back(numeros[i]);
            quantidade_colunas_tot.push_back(numeros[i+1]);
            quantidade_comidas_tot.push_back(numeros[i+2]);

        } else if(aux1 > 0) {
            cout << "entrou no else if\n";
            pos_coluna = i;
            pos_comida = i+1;
            i = 3;//posição de linhas
            quantidade_linhas_tot.push_back(numeros[i+aux2]);
            quantidade_colunas_tot.push_back(numeros[pos_coluna+3]);
            quantidade_comidas_tot.push_back(numeros[pos_comida+3]);
            aux2 = 3;
            contador++;
            if(contador == numero_de_linhas){
                cout << "entrou no if\n";
                break;
            }
        }
        aux1++;
    }
    //cout << "AUX1:" << aux1 << endl;
    for(int i=0; i<numero_de_linhas;i++){
        cout << "Quantidade de linhas:" << quantidade_linhas_tot[i] << endl;
        cout << "Quantidade de colunas:" << quantidade_colunas_tot[i] << endl;
        cout << "Quantidade de comidas:" << quantidade_comidas_tot[i] << endl;
    }   
    int tt = quantidade_comidas_tot.size();
    cout << "tamanho de quantidade de comidas= " << tt << endl;
    
    for(int i =0; i < tt; i++){
        quant_comida = quant_comida + quantidade_comidas_tot[i];
    }
    cout << "soma de comidas: " << quant_comida << endl;
}

int Level::validar_numeros(){
    //cout << "começou\n";
    for(auto itr1 = quantidade_linhas_tot.begin(); itr1 != quantidade_linhas_tot.end(); itr1++){
        if(*itr1 <= 0 || *itr1 > 100){
            //cout << "ERRO!! numero de linhas errado\n";
            return 1;
        }
    }
    for(auto itr1 = quantidade_colunas_tot.begin(); itr1 != quantidade_colunas_tot.end(); itr1++){
        if(*itr1 <= 0 || *itr1 > 100){
            //cout << "ERRO!! numero de colunas errado\n";
            return 2;
        }
    }
    for(auto itr1 = quantidade_comidas_tot.begin(); itr1 != quantidade_comidas_tot.end(); itr1++){
        if(*itr1 <= 0){
            //cout << "ERRO!! faltou comida\n";
            return 3;
        }
    }

    return 0;
}

void Level::preencher_mapa(string s){//preenche o mapa em vector da classe level
    mapas_do_arquivo.push_back(s);
}

void Level::mostrar_mapa_um(){//mostra o mapa 
    int mapa_um = 0, tamanho_dos_mapas = 0;
    tamanho_dos_mapas = mapas_do_arquivo.size();
    mapa_um = tamanho_dos_mapas/numero_de_linhas;
    cout << "Tamanho dos mapas: " << tamanho_dos_mapas << endl;
    cout << "Numero de linhas: " << numero_de_linhas << endl;
    cout << "Mapa um: " << mapa_um << endl;
    
    for(int i = 0; i < mapa_um; i++){
        cout << mapas_do_arquivo[i]<< endl;    
    }
}

int qtdlinha = 0, qtdcoluna = 0;
int pos_final_linha = 0, pos_final_coluna = 0;
int encerramento_linha = 0, encerramento_coluna = 0;
void Level::encontrar_posicao_cobra(int num){
    cout << "ENTREI NO COMEÇO DO MÉTODO" << endl;
    
    int tam_linhas = quantidade_linhas_tot.size();
    int tam_colunas = quantidade_colunas_tot.size();
    int tam_mapa_totoal = mapas_do_arquivo.size();
    
    cout << "TAMANHO TOTAL ============== " << tam_mapa_totoal << endl;
    cout << "TOTAL DE LINHAS DO ARQUIVO: " << tam_linhas << endl;
    cout << "TOTAL DE COLUNAS DO ARQUIVO: " << tam_colunas << endl;

    if(num == 0){//pega posição primeiro nivel
        qtdlinha = quantidade_linhas_tot[0];
        qtdcoluna = quantidade_colunas_tot[0];
        cout << "NIVEL ATUAL: " << num << endl;
        cout << "ENTREI NO IF DO MÉTODO" << endl;
        for(int i = 0; i < qtdlinha; i++){
            cout << "linhas i: " << i << endl;
            mapa_auxiliar.push_back(mapas_do_arquivo[i]);//pegando mapa novamente
        }
        cout << "MAPA DO NIVEL 1\n";
        for(auto i = mapa_auxiliar.begin(); i != mapa_auxiliar.end(); i++){//mostra o mapa de cada nivel
            cout << *i << endl;
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
       
        pos_final_linha = qtdlinha;
        pos_final_coluna = qtdcoluna;
        cout << "posição final da linha é: " << pos_final_linha << endl;
        cout << "posição final da coluna é: " << pos_final_coluna << endl;
        
    } else {
        posicao_cobra.clear();
        mapa_auxiliar.clear();//limpa o vector para o proximo nivel (RETIRAR MAIS TARDE)
        qtdlinha = quantidade_linhas_tot[num];
        qtdcoluna = quantidade_colunas_tot[num];
        cout << "entrei no else com a posição linha: " << pos_final_linha << endl;
        cout << "entrei no else com a posição coluna: " << pos_final_coluna << endl;
        cout << "NIVEL ATUAL: " << num << endl;

        encerramento_linha = (pos_final_linha+qtdlinha);
        encerramento_coluna = (pos_final_coluna+qtdcoluna)-1;
        cout << "encerramento da coluna: " << encerramento_coluna << endl;
        cout << "encerramento da linha : " << encerramento_linha << endl;

        for(int i = pos_final_linha; i <= encerramento_linha; i++){
            mapa_auxiliar.push_back(mapas_do_arquivo[i]);//pegando mapa novamente
        }
        for(auto i = mapa_auxiliar.begin(); i != mapa_auxiliar.end(); i++){//mostra o mapa de cada nivel
            cout << *i << endl;
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
        cout << "linha encerrou na posição: " << pos_final_linha << endl;
        cout << "coluna encerrou na posição: " << pos_final_coluna << endl;
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
}


void Level::distribuindo_comida(int gatilho_comida){//faz e distribui no mapa a comida
    cout << "Mostrando comida: \n";
    int qtd_comida = 0, contador = 0, i = 0, j = 0;
    srand(time(NULL));
    //string vazio = {""};

    if(gatilho_comida == 0){//1º nivel, distribuindo comida
        cout << "Cheguei no nivel: " << gatilho_comida+1 << endl;
        qtd_comida = quantidade_comidas_tot[0];
        cout << "--->COMIDA TOTAL:: " << qtd_comida << endl;
       
        while( contador < qtd_comida) {
		    i = rand() % quantidade_colunas_tot[0];
		    j = rand() % quantidade_colunas_tot[0];

		    if(mapa_auxiliar[i][j] == ' '){	
                cout << "linha = " << i << " e coluna = " << j << endl;
                mapa_auxiliar[i][j] = 'A';
                contador++;
		    }
        }
        cout << "\n";
        for(auto i = mapa_auxiliar.begin(); i != mapa_auxiliar.end(); i++){
            cout << *i << endl;
        }
	
    }else if(gatilho_comida > 0){//nível 2 em diante
        qtd_comida = quantidade_comidas_tot[gatilho_comida];
        cout << "Cheguei no nivel: " << gatilho_comida+1 << endl;
        cout << "--->COMIDA TOTAL:: " << qtd_comida << endl;

        while( contador < qtd_comida) {
		    i = rand() % quantidade_colunas_tot[gatilho_comida];
		    j = rand() % quantidade_colunas_tot[gatilho_comida];

		    if(mapa_auxiliar[i][j] == ' '){	
                cout << "linha = " << i << " e coluna = " << j << endl;
                mapa_auxiliar[i][j] = 'A';
                contador++;
		    }
        }
        cout << "\n";
        for(auto i = mapa_auxiliar.begin(); i != mapa_auxiliar.end(); i++){
            cout << *i << endl;
        }
    }
    
}

