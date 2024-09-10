#include "Votante.h"

Votante::Votante()
{
}

void Votante::setCedula(string c)
{

    cedula = c;
}

string Votante::getCedula()
{
    return cedula;
}

void Votante::setNombre(string n)
{

    nombre = n;
}

string Votante::getNombre()
{

    return nombre;
}

void Votante::setApellido(string a)
{

    apellido = a;
}

string Votante::getApellido()
{

    return apellido;
}

void Votante::setGenero(string g)
{

    genero = g;
}

string Votante::getGenero()
{

    return genero;
}

void Votante::setEdad(string ed)
{
    edad = ed;
}

string Votante::getEdad()
{
    return edad;
}

// Metodos de la Pila

void Votante::StatusDefault(string d)
{
    status.Insertar("En cola");

    if (d == "S" || d == "s")
    {
        status.Insertar("Asistido");
    }
}

string Votante::getStatus()
{

    string s;

    status.Remover(s);
    status.Insertar(s);

    return s;
}

void Votante::ModificarStatus(string r)
{

    string s;

    while (!status.Vacia())
    {
        status.Remover(s);
    }

    status.Insertar("En cola");

    if (r == "S" || r == "s")
    {
        status.Insertar("Asistido");
    }
}

void Votante::StatusRetirado()
{
    string e;

    while (!status.Vacia())
    {
        status.Remover(e);
        if (e != "En cola")
        {
            statusAux.Insertar(e);
        }
    }

    while (!statusAux.Vacia())
    {
        statusAux.Remover(e);
        status.Insertar(e);
    }

    status.Insertar("Retirado");
}

void Votante::StatusVoto()
{
    string e;

    while (!status.Vacia())
    {
        status.Remover(e);
        if (e != "En cola")
        {
            statusAux.Insertar(e);
        }
    }

    while (!statusAux.Vacia())
    {
        statusAux.Remover(e);
        status.Insertar(e);
    }

    status.Insertar("Voto");
}

bool Votante::VerificarStatus(string s)
{

    string e;
    bool r = false;

    while (!status.Vacia())
    {
        status.Remover(e);
        if (e == s)
        {
            r = true;
        }
        statusAux.Insertar(e);
    }

    while (!statusAux.Vacia())
    {
        statusAux.Remover(e);
        status.Insertar(e);
    }

    return r;
}