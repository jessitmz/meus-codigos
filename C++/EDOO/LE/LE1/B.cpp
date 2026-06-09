#include <iostream>

using namespace std;

class Link {
    public:
    int element;
    Link* next;
    
    Link(int elemvalue, Link* nextvalue) {
        this->element = elemvalue;
        this->next = nextvalue;
    }
    
    Link(Link* nextvalue) {
        this->next = nextvalue;
    }  
};

class Stack {
    private:
        Link* top;
        Link* temp;
        int size;

    public:
        Stack() {
            this->temp = this->top = nullptr;
            this->size = 0;
        }
        ~Stack() {
            while (top != nullptr) {
                temp = top;
                top = top->next;
                delete temp;
            }
            delete top;
        }

        void push(int element) {
            top = new Link(element, top);
            size++;
        }

        int pop() {
            if (top != nullptr) {
                int element = top->element;
                Link* deletado = top;
                top = top->next;
                size--;
                delete deletado;
                return element;
            }
            return -1;
        }
        
        int topValue() { 
            if (isEmpty()) return -1;
            return top->element; 
        }

        bool isEmpty() {
            if (top == nullptr) return true;
            else return false;
        }

};

int main() {

    int vagoes;
   
    while (cin >> vagoes && vagoes != 0) {
        int primeiroVagao;
       
        while (cin >> primeiroVagao && primeiroVagao != 0) {
            int permutacaoEsperada[1000];
            permutacaoEsperada[0] = primeiroVagao;
            for (int i = 1; i < vagoes; i++) cin >> permutacaoEsperada[i];
            
            Stack estacao;
            int vagaoA = 1;
            bool possivel = true;
            
            for (int i = 0; i < vagoes; i++) {
                int esperado = permutacaoEsperada[i];

                while (vagaoA <= vagoes && (estacao.isEmpty() || estacao.topValue() != esperado)) {
                    estacao.push(vagaoA);
                    vagaoA++;
                }

                if (!estacao.isEmpty() && estacao.topValue() == esperado) {
                    estacao.pop();
                }
                else {
                    possivel = false;
                    i = vagoes;
                }

            }

            if (possivel) cout << "Yes\n";
            else cout << "No\n";
        }

        cout << "\n";
    }
       
    return 0;
}