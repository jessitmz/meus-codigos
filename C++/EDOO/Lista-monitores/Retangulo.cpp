#include "Retangulo.h"
#include <iostream>
#include <stdexcept>

using namespace std;

Retangulo::Retangulo(const string& nome, double largura, double altura) : Forma(nome), largura(largura), altura(altura) {
    
        if (this->largura < 0 || this->altura < 0) {
            throw invalid_argument("A medida não deve ser um valor negativo");
        }
};

double Retangulo::area() const {
    return (this->largura * this->altura);
};

double Retangulo::perimetro() const {
    return (this->largura * 2) + (this->altura * 2);
};

bool Retangulo::quadrado() const {
    return (this->largura == this->altura);
};

string Retangulo::descricao() const {
    string descricao_base = Forma::descricao();
    return descricao_base + " | Largura: " + std::to_string(this->largura) + " | Altura: " + std::to_string(this->altura);
};

Retangulo Retangulo::operator+(const Retangulo& outro) const { 
    return Retangulo("novo_retangulo", (this->largura + outro.largura), (this->altura + outro.altura));
};

Retangulo Retangulo::operator*=(double escala) {  
    this->largura *= escala;
    this->altura *= escala;
    return *this;
}

Retangulo Retangulo::operator*(double escala) const {  
    Retangulo novo = *this;
    novo *= escala;
    return novo;
}

bool Retangulo::operator==(const Retangulo& outro) const {
    return (this->area() == outro.area());
}

bool Retangulo::operator<(const Retangulo& outro) const {
    return (this->area() < outro.area());
}

bool Retangulo::operator>(const Retangulo& outro) const {
    return (this->area() > outro.area());
}

// operator<<