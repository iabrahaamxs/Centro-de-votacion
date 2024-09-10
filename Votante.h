#ifndef Votante_H
#define Votante_H
#include <iostream>
#include "Libreria/Pila.h"
using namespace std;

class Votante
{

private:
    string cedula, nombre, apellido, genero, edad;
    Pila<string> status, statusAux;

public:
    Votante();
    void setCedula(string);
    string getCedula();
    void setNombre(string);
    string getNombre();
    void setApellido(string);
    string getApellido();
    void setGenero(string);
    string getGenero();
    void setEdad(string);
    string getEdad();
    // Metodos de la Pila
    void StatusDefault(string);
    string getStatus();
    void ModificarStatus(string);
    void StatusRetirado();
    void StatusVoto();

    bool VerificarStatus(string);
};

#include "Votante.cpp"

#endif