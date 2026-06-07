#include <iostream>
#include <string>

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

class Queue {

    private:
        int size;
        int maxSize;
        Link* front;
        Link* rear;
        Link* temp;

        void init() {
            temp = front = rear = new Link(nullptr);
            size = 0;
        }

        void destroy() {
            while (front != nullptr) {
                temp = front;
                front = front->next;
                delete temp;
            }
        }
    
    public:
        Queue() { init(); }
        ~Queue() { destroy(); }

        void enqueue(int element) {
            rear->next = new Link(element, nullptr);
            rear = rear->next;
            size++;
        }

        int dequeue() {
            if (size > 0) {
                Link* tempNode = front->next;
                int element = tempNode->element;

                front->next = front->next->next;

                if (front->next == nullptr) {
                    rear = front;
                }

                delete tempNode;
                size--;
                return element;
            }
            return -1;
        }

        bool isEmpty() { return (size == 0); }
        int first() {
            if (size > 0) {
                return front->next->element;
            }
            return -1;
        }
};

int main() {

    int cases;
    cin >> cases;
    for (int c=0; c<cases; c++) {
        int l, m;
        cin >> l >> m; // l: comprimento da balsa em metros, m: quantidade de carros
        
        Queue leftBank;
        Queue rightBank;
        int deckSize = (l * 100); // conversão metros para centímetros

        for (int i=0; i<m; i++) {
            int carLength;
            string position;
            cin >> carLength >> position;
            if (position == "left") { leftBank.enqueue(carLength); }
            else if (position == "right") { rightBank.enqueue(carLength); }
        }
        
        int trips = 0;
        bool isLeft = true;

        while (!leftBank.isEmpty() || !rightBank.isEmpty()) {
            int counter = 0;
            if (isLeft) { 
                while ((counter + leftBank.first()) < deckSize && !leftBank.isEmpty()) {
                    counter += leftBank.dequeue();
                }
            }
            else if (!isLeft) {
                while ((counter + rightBank.first()) < deckSize && !rightBank.isEmpty()) {
                    counter += rightBank.dequeue();
                }
            }

            isLeft = !isLeft; // muda de margem
            trips++; // contagem de viagens
        }
        cout << trips << "\n";
    }
    
    return 0;
}