#ifndef LISTASEQ_H
#define LISTASEQ_H

#include <iostream>
using namespace std;

class ListaSeq {
    private:
        int *dados;
        int sizeMax;
        int sizeNow;
    public:
        ListaSeq(int num) {
            sizeMax = num;
            sizeNow = 0;
            dados = new int[sizeMax];
        }
        int vazia() {
            if(sizeMax == 0) {
                return 1;
            } else {
                return 0;
            }
        }
        bool cheia() {
            if(sizeNow == sizeMax) return true;
            else return false;
        }
        int tamanho() {
            return sizeNow;
        }
        int elemento(int pos) {
            int dado;
            if((pos > sizeNow) || (pos <= 0))
                    return -1;
                dado = dados[pos-1];
                return dado;
        }
        int posicao(int dado) {
            for(int i=0; i<sizeNow; i++) {
                if(dados[i] == dado) {
                        return(i+1);
                }
            }
            return -1;
        }
        bool insere(int pos, int dado) {
            if(cheia() || (pos > sizeNow+1) || (pos<=0)) {
                return false;
            }
            for (int i = sizeNow; i >= pos; i--) {
                dados[i] = dados[i-1];
            }
            dados[pos - 1] = dado;
            sizeNow++;
            return true;
        }
        int remove(int pos) {
            int dado;
            if ((pos > sizeNow) || (pos < 1 ))
                return -1;
            dado = dados[pos-1];
            for (int i = pos - 1; i < sizeNow - 1; i++){
                dados[i] = dados[i+1];
            }
            sizeNow--;
            return dado;
        }
        void mostraLista() {
            cout << "Vetor de dados: " << endl;
            for(int i=0; i<=sizeNow; i++) {
                cout << "posicao(" << i+1 << "): " << dados[i] <<endl;
            }
        }
};

#endif