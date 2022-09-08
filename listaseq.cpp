#include "listaseq.h"

int main() {
    // criando lista com 5 espacos
    ListaSeq Lista1 = ListaSeq(5);

    // teste de lista vazia
    if(Lista1.vazia()) {
        cout << "Vetor de dados vazio!" << endl;
    }
    // teste de tamanho
    cout <<"Quantidade de dados no vetor: " << Lista1.tamanho() << endl;

    // teste de inserir 5 na posicao 1
    Lista1.insere(0, 5);
    // teste de inserir 10 na posicao 2
    Lista1.insere(1, 10);
    // teste de inserir 15 na posicao 3
    Lista1.insere(2, 15);
    // teste de inserir 20 na posicao 4
    Lista1.insere(3, 20);
    // teste de inserir 25 na posicao 5
    Lista1.insere(4, 25);
    Lista1.mostraLista();

    // teste de lista cheia
    if(Lista1.cheia()) {
        cout << "Vetor de dados cheio!" << endl;
    }

    // teste de remover dado da posicao 1
    cout <<"Quantidade de dados no vetor: " << Lista1.tamanho() << endl;
    Lista1.remove(5);
    Lista1.mostraLista();
    return 0;
}