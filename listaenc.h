#ifndef LISTAENC_H
#define LISTAENC_H

#include <iostream>
using namespace std;

class No {
    private:
        int data;
        No* next;
        No* prev;

    public:
        No() {
            this->next = NULL;
            this->prev = NULL;
        }
        int getData() {
            return data;
        }
        No* getNext() {
            return next;
        }
        No* getPrev() {
            return prev;
        }
        void setData(int data) {
            this->data = data;
        }
        void setNext(No* n) {
            next = n;
        }
        void setPrev(No* p) {
            prev = p;
        } 
};

class Listaenc {
    private:
        No* head;
        No* tail;
        int size;

    public:
        Listaenc() {
            head = NULL;
            tail = NULL;
            size = 0;
        }
        Listaenc(int data) {
            head = new No();
            tail = head;
            size++;
        }
        virtual ~Listaenc() {
            delete head;
        }
        bool clean() {
            if(size==0 && head==NULL) return true;
            else return false;
        }
        int sizeList() {
            No* p = head;
            int cont = 0;
            while(p != NULL) {
                p = p->getNext();
                cont++;
            }
            if(cont == size) {
                return cont;
            } else {
                return -1;
            }
        }
        int element(int pos) {
            No* aux = head;
            int cont = 1;
            if(clean()) return -1; // Consulta falhou 

            if ((pos < 1) || (pos > size)) return -1; // Posicao invalida
            
            // Percorre a lista do 1o elemento até pos
            while (cont < pos){
                aux = aux->getNext();
                cont++;
            }
            return aux->getData();
        }
        int position(int data) {
            int cont = 1;
            No* aux;
            if (clean()) return 0;
            aux = head;
            while (aux != NULL) {
                if (aux->getData() == data)
                    return cont;
                aux = aux->getNext();
                cont++;
            }
            return -1;
        }
        bool insertStartList(int data) {
            // Aloca memoria para um novo no */
            No* newNo = new No();
                
            // Insere novo elemento na cabeca da lista
            newNo->setData(data);
            newNo->setNext(head);
            newNo->setPrev(NULL);
            if(clean()) tail = newNo;
            head = newNo;
            size++;
            return true;
        }
        bool insertMidList(int pos, int data){
            int cont = 1;
            No* newNo = new No(); // Aloca memoria para novo no
            newNo->setData(data);
            // Localiza a pos. onde será inserido o novo nó
            No* aux = head;
            while ((cont < pos-1) && (aux != NULL)){
                aux = aux->getNext();
                cont++;
            }
            if (aux == NULL) return false;
            newNo->setNext(aux->getNext());
            aux->setNext(newNo);
            size++;
            return true;
        }
        bool insertEndList(int data){
            No* newNo = new No(); 
            newNo->setData(data);
            // Procura o final da lista
            No* aux = tail;

            newNo->setNext(NULL);
            aux->setNext(newNo);
            newNo->setPrev(tail);
            tail->setNext(newNo);
            tail = newNo;
            this->size++;
            return true;
        }
        bool insert(int pos, int data) {
            if ((clean()) && (pos != 1)) return false; 
            if (pos == 1){ // insercao no inicio da lista
            return insertStartList(data);
            }
            else if (pos == size+1){ // inserção no fim
            return insertEndList(data);
            }
            else{  // inserção no meio da lista
            return insertMidList(pos, data);
            }
        }
        int remove(int pos) {
            int ret;
            if(clean()) return 0;
            if((pos == 1) && (sizeList() == 1)) {
                return removeStartListUnitary();
            } else if(pos==1) {
                return removeStartList();
            } else if(pos==sizeList()) {
                return removeEndList();
            } else {
                return removeMidList(pos);
            }
        }
        int removeStartListUnitary() {
            int data = head->getData();
            head = NULL;
            tail = NULL;
            size--;
            return data;
        }
        int removeStartList() {
            No* p = head;
            int data = p->getData();

            head = p->getNext();
            p->getNext()->setPrev(NULL);
            size--;

            delete(p);

            return data;
        }
        int removeEndList() {
            No* p = tail;
            int data= p->getData();

            tail->getPrev()->setNext(NULL);
            tail = tail->getPrev();
            size--;
            delete(p);
            return data;
        }
        int removeMidList(int pos) {
            No* p = head;
            int n = 1;

            while((n<=pos-1) && (p!=NULL)) {
                p = p->getNext();
                n++;
            } 
            if(p==NULL) return -1;
            int data = p->getData();
            p->getPrev()->setNext(p->getNext());
            p->getNext()->setPrev(p->getPrev());
            size--;
            delete(p);
            return data;
        }
        void printList() {
            cout << "Imprimindo todos elementos da lista..." << endl;
            No* h = head;
            if(clean()) {
                cout << "A lista NAO possui elementos!" << endl;
            } else {
                while(h) {
                    cout << h->getData() << endl;
                    h = h->getNext();
                }
                cout << endl;
            }
        }
};

#endif