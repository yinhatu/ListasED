#include "listaenc.h"

int main() {
    // Criando lista vazia
    Listaenc l;
    Listaenc();

    // Verificar se a lista esta vazia
    if(l.clean()) {
        cout << "A lista NAO possui elementos!" << endl;
    }
    // Obter o tamanho da lista
    int s = l.sizeList();
    if(s != -1) {
        cout << "Tamanho da lista: " << s << endl;
    } else {
        cout << "ERRO no tamanho da lista!" << endl;
    }
    // inserindo 4 elementos
    l.insert(1,10);
    l.insert(2,20);
    l.insert(3,30);
    l.insert(4,40);
    l.printList();

    // obter/modificar elemento
    int e = l.element(1);
    if(e != -1) {
        cout << "Elemento na posicao 1: " << e << endl;
    } else {
        cout << "Lista vazia!" << endl;
    }
    
    // buscando posicao de elemnto
    int p = l.position(30);
    if(p != -1) {
        cout << "Posicao do elemento 30: " << p << endl;
    } else {
        cout << "ERRO posicao de elemento!" << endl;
    }
    
    // removendo elemento da posicao 1
    int aux = l.remove(1);
    if(aux) {
        cout << "Elemento removido: " << aux << endl;
    } else {
        cout << "ERRO na remocao!" << endl;
    }
    l.printList();

    return 0;
}