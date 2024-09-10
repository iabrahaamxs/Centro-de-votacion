#ifndef Cola_H
#define Cola_H

template <class Tipo>
class Cola;

template <class Tipo>
class nodoCola
{
    Tipo info;
    nodoCola *prox;
    friend class Cola<Tipo>;
};

template <class Tipo>
class Cola
{
    nodoCola<Tipo> *Frente, *Final;

public:
    Cola();
    bool Vacia();
    bool Llena();
    bool Insertar(Tipo Valor);
    bool Remover(Tipo &Valor);
};

#include "Cola.cpp"
#endif
