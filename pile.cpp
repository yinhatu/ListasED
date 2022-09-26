#include "pile.hpp"

int main() {
    // inserindo na pilha
    PileEnc p;
    PileEnc();
    p.push(1);
    p.push(10);
    p.printPile();

    //remover da pilha
    p.pop();

    //ver o topo
    cout << "Topo da pilha: " << p.topo() << endl;

    // verificar se esta vazia
    cout << "Verificando se pilha esta vazia..." << endl;
    if(p.clean()) cout << "Pilha Vazia!" << endl;
    else cout << "Topo da pilha: " << p.topo() << endl;

    // verificando tamanho
    cout << "Tamanho da pilha: " << p.sizePile() << endl;
    p.printPile();
    p.pop();
    p.pop();
    p.printPile();

    return 0;
}