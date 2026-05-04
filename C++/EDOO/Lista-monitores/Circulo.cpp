#include "Circulo.h"
#include <cmath>
#include <iostream>

using namespace std;

Circulo::Circulo(const string& nome, double raio) : Forma(nome), raio(raio) {
    if (this->raio < 0) {
            throw invalid_argument("A medida não deve ser um valor negativo");
        }
};

double PI = M_PI;

double Circulo::area() const {
    return PI * raio * raio;
};

double Circulo::perimetro() const {
    return 2 * PI * raio;
};

string Circulo::descricao() const {
    string descricao_base = Forma::descricao();
    return descricao_base + " | Raio: " + std::to_string(raio);    
};

Circulo Circulo::operator+(const Circulo& outro) const { 
    return Circulo("novo_circulo", (this->raio + outro.raio));
};

Circulo& Circulo::operator*=(double escala) {  
    try {
        if (escala <= 0) {
            throw "valor inválido";
        }
    } catch (const string erro) {
        cout << "Valor de escala deve ser um número maior que 0";
    }

    this->raio *= escala;
    return *this;
}

Circulo Circulo::operator*(double escala) const {  
    Circulo novo = *this;
    novo *= escala;
    return novo;
}

bool Circulo::operator==(const Circulo& outro) const {
    return (this->area() == outro.area());
}

// ostream& 