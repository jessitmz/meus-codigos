#include <iostream>
#include <string>
using namespace std;

int main() {

    string padrao = "I have learned something new again!";
    cout << padrao << endl;
    cout << "Length of the string: " << padrao.length() << endl;

    string entrada1, entrada2;
    cout << "Digite uma mensagem: ";
    getline(cin, entrada1);
    cout << "Digite outra mensagem: ";
    getline(cin, entrada2);
    string concat = entrada1 + " * " + entrada2;
    cout << concat << endl;

}