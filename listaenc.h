#ifndef LISTAENC_H
#define LISTAENC_H

#include <iostream>
using namespace std;

class No {
    private:
        int data;
        No* next;

    public:
        No(int data) {
            this->data;
            this->next = NULL;
        }
        int getData() {
            return data;
        }
        No* getPos() {
            return next;
        }
        void setPos(No* next) {
            this->next = next;
        }

};

class ListaEnc {
    private:
        No* head;
        No* tail;
        int size;
    public:
        ListaEnc() {
            head = NULL;
            tail = NULL;
            size = 0;
        }
        ListaEnc(int data) {
            head = new No(data);
        }
        virtual ~ListaEnc() {
            delete head;
        }
        bool vazia() {
            if(size == 0) {
                return true;
            } else {
                return false;
            }
        }
        int tamanho() {
            return this->size;
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