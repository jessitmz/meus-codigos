#include <iostream>
using namespace std;

int main() {
    int cha_certo, chute_cha, n_acertos=0;
    
    cout << "Digite um número para indicar o chá certo: ";
    cin >> cha_certo;

    for (int i=0; i<5; i++) {
        cout << "Chute um número para adivinhar o chá certo: ";
        cin >> chute_cha;

        if (chute_cha == cha_certo) {
            n_acertos++;
        }
    }

    cout << "Você acertou " << n_acertos << " vezes!";
}