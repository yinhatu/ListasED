#ifndef PILE_HPP
#define PILE_HPP

#include <iostream>
using namespace std;
/*
class PileSeq {
    public:
        int* data;
        int top;
        int sizeMax;
    private:
        PileSeq() {
            sizeMax = 5;
            data = new int[sizeMax];
            top = -1;
        }
        bool clean() {
            if(top == -1) return true;
            else return false;
        }
        bool full() {
            if(top == sizeMax-1) return true;
            else return false;
        }
        int sizePile() {
            return top+1;
        }
        int top() {
            if(clean()) {
                return -1;
            }
            return data[top];
        }
        bool push(int v) {
            if(full()) {
                return false; 
            }
            top++;
            data[top] = v;
            return true;
        }
        int pop() {
            if(clean()) {
                return -1;
            }
            int v = data[top];
            top--;
            return v;
        } 
};
*/

class No {
    private:
        int data;
        No* next;
    public:
        No() {
            this->next = NULL;
        }
        int getData() {
            return data;
        }
        No* getNext() {
            return next;
        }
        void setData(int data) {
            this->data = data;
        }
        void setNext(No* n) {
            next = n;
        }
};

class PileEnc {
    private:
        No* top;
        int size;

    public:
        No* getTop() {
            return top;
        }
        int getSize() {
            return size;
        }
        PileEnc() {
            top = NULL;
            size = 0;
        }
        bool clean() {
            if(size == 0) return true;
            else return false;
        }
        int sizePile() {
            return this->size;
        }
        int topo() {
            if(clean()) {
                return -1;
            }
            return top->getData();
        }
        bool push(int v) {
            No* newNo = new No();
            newNo->setData(v);

            newNo->setNext(top);

            top = newNo;
            size++;
            return true;
        }
        int pop() {
            if(clean()) {
                return -1;
            }
            No* p = top;
            int v = p->getData();
            top = p->getNext();
            size--;
            delete(p);
            return v;
        }
        void printPile() {
            cout << "Imprimindo todos elementos da pilha..." << endl;
            No* p = top;
            if(clean()) {
                cout << "A pilha NAO possui elementos!" << endl;
            } else {
                while(p) {
                    cout << p->getData() << endl;
                    p = p->getNext();
                }
                cout << endl;
            }
        }
};

#endif