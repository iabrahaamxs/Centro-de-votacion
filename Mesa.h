#ifndef Mesa_H
#define Mesa_H
#include <iostream>
#include "Libreria/Cola.h"
#include "Votante.h"
using namespace std;

class Mesa
{
private:
    string id, tipo;
    Cola<Votante> votantes;

public:
    Mesa();
    void setId(string);
    string getId();
    void setTipo(string);
    string getTipo();
    // Metodos de la cola
    Votante CrearMarca();
    bool VerificarVotante(string);
    void InsertarVotante(Votante);
    Votante VotanteRetirado(string);
    bool ColaVacia();
    Votante VotanteVoto();
    bool BuscarVotante(string);
    bool ModificarVotante(string);
    bool EliminarVotante(string);
    void ImprimirEnCola(string);
    void ImprimirCola();
};

#include "Mesa.cpp"

#endif