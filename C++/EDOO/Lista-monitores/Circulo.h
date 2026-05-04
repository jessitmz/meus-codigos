#ifndef _CIRCULO_H
#define _CIRCULO_H

#include "Forma.h"
#include <string>

using namespace std;

class Circulo : public Forma {

    private:
        double raio;

    public:
        Circulo(const string& nome, double raio);
        double area() const;
        double perimetro() const;
        string descricao() const override;

        Circulo operator+(const Circulo& outro) const; // soma raios
        Circulo& operator*=(const double escala); // altera a escala do objeto original
        Circulo operator*(const double escala) const; // novo objeto a partir de outro com escala alterada
        bool operator==(const Circulo& outro) const; // checa se áreas são iguais
        friend ostream& operator<<(ostream& os, const Circulo& circulo); // para descrever o objeto no output
};

#endif