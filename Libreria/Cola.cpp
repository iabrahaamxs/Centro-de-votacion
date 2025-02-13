#include "Cola.h"

template <class Tipo>
Cola<Tipo>::Cola()
{
     Frente = NULL;
     Final = NULL;
};

template <class Tipo>
bool Cola<Tipo>::Vacia()
{
     return Frente == NULL;
};

template <class Tipo>
bool Cola<Tipo>::Llena()
{
     nodoCola<Tipo> *p;
     p = new nodoCola<Tipo>;
     if (p == NULL)
          return true;
     else
     {
          delete p;
          return false;
     }
};

template <class Tipo>
bool Cola<Tipo>::Insertar(Tipo Valor)
{
     nodoCola<Tipo> *nuevo;
     if (!Llena())
     {
          nuevo = new nodoCola<Tipo>;
          nuevo->info = Valor;
          nuevo->prox = NULL;
          if (Final == NULL)
               Frente = nuevo;
          else
               Final->prox = nuevo;
          Final = nuevo;
          return true;
     }
     else
          return false;
};

template <class Tipo>
bool Cola<Tipo>::Remover(Tipo &Valor)
{
     nodoCola<Tipo> *primero;
     if (!Vacia())
     {
          primero = Frente;
          Valor = primero->info;
          Frente = primero->prox;
          if (Frente == NULL)
               Final = NULL;
          delete primero;
          return true;
     }
     else
          return false;
};
