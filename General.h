#ifndef CRUDMesa_H
#define CRUDMesa_H
#include "fstream"
#include "Libreria/Lista.h"
#include "Mesa.h"
#include <bits/stdc++.h>

using namespace std;

class General
{
private:
    Lista<Mesa> mesas, mesasAux;
    Lista<Votante> padron, padronAux, historico, historicoAux;

public:
    General();
    void IngresarMesasDB(ifstream &);
    void ImprimirLista();
    bool Verificar(string, string);  // Crear una mesa
    bool Verificar2(string, string); // Modificar una mesa
    bool EncabezadoCrearMesa();
    bool TieneNoDigito(string);
    void CrearMesa(ofstream &);
    void BuscarMesa();
    bool VerificaColaMesa(string);
    void ModificarMesa(ifstream &);
    void EliminarMesa(ifstream &);

    void CrearListaPadronDB(ifstream &);
    bool VerificaPadron(string); // Ingresar un votante al padron
    void IngrVotantePadron(ofstream &);
    void BusVotantePadron();
    void ModVotantePadron(ifstream &);
    void EliVotantePadron(ifstream &);
    void ImprimirPadron();

    bool VerificaVontanteEnCola();
    void ProcesoVotacion();

    void ImprimirColas();
    bool Verifica(string, string); // Verifica que la cedula no exista en todas las colas de las mesas, si existe retorna false y imprime el mensaje estrito en el segundo parametro
    bool VerificaVoto(string);
    void EliminaRetirado(string);
    bool VerificarMesas();
    void IngrVotanteCola();
    void BuscarVotanteCola();
    void ModificarVotanteCola();
    void EliminarVotanteCola();

    // REPPORTES GENERALES

    void ReporteVotaron();
    void ReporteEnCola();
    void ReporteAsistidos();
    void ReporteRetirados();
    void ReporteAsistidosEnCola();
    void ReporteAsistidosVotaron();

    void LimpiarListas();
};

#include "General.cpp"

#endif