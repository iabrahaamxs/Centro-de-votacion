#include "Mesa.h"

Mesa::Mesa()
{
	id = "";
	tipo = "";
}
void Mesa::setId(string i)
{
	id = i;
}
string Mesa::getId()
{
	return id;
}
void Mesa::setTipo(string t)
{
	tipo = t;
}
string Mesa::getTipo()
{
	return tipo;
}

/*METODO DE LA COLA*/

Votante Mesa::CrearMarca()
{

	Votante v;
	string ce, no, ap, ge;

	ce = "-1";
	no = "$$$$$";
	ap = "$$$$$";
	ge = "$$$$$";

	v.setCedula(ce);
	v.setNombre(no);
	v.setApellido(ap);
	v.setGenero(ge);

	return v;
}

bool Mesa::VerificarVotante(string c)
{
	bool existe, encontrado;
	existe = false;
	Votante marca, v;

	marca = CrearMarca();

	if (!votantes.Vacia())
	{
		votantes.Insertar(marca);
		encontrado = false;

		while (!encontrado)
		{
			votantes.Remover(v);
			if (v.getCedula() == marca.getCedula())
			{
				encontrado = true;
			}
			else
			{
				if (v.getCedula() == c)
				{
					existe = true;
				}
				votantes.Insertar(v);
			}
		}
	}
	return existe;
}

void Mesa::InsertarVotante(Votante v)
{
	votantes.Insertar(v);
}

Votante Mesa::VotanteRetirado(string cd)
{

	Votante vAux, vRetirado, marca;
	bool encontrado = false;
	marca = CrearMarca();

	if (!votantes.Vacia())
	{
		votantes.Insertar(marca);

		while (!encontrado)
		{
			votantes.Remover(vAux);
			if (vAux.getCedula() == marca.getCedula())
			{
				encontrado = true;
			}
			else
			{
				if (vAux.getCedula() == cd)
				{
					vRetirado.setCedula(vAux.getCedula());
					vRetirado.setNombre(vAux.getNombre());
					vRetirado.setApellido(vAux.getApellido());
					vRetirado.setGenero(vAux.getGenero());
					vRetirado.StatusRetirado();
				}

				votantes.Insertar(vAux);
			}
		}
	}

	return vRetirado;
}

bool Mesa::ColaVacia()
{

	return votantes.Vacia();
}

Votante Mesa::VotanteVoto()
{
	Votante vAux;

	votantes.Remover(vAux);
	vAux.StatusVoto();

	return vAux;
}

bool Mesa::BuscarVotante(string cd)
{

	Votante vAux, marca;
	bool encontrado = false;
	bool vEnco = false;
	marca = CrearMarca();

	if (!votantes.Vacia())
	{
		votantes.Insertar(marca);

		while (!encontrado)
		{
			votantes.Remover(vAux);
			if (vAux.getCedula() == marca.getCedula())
			{
				encontrado = true;
			}
			else
			{
				if (vAux.getCedula() == cd)
				{
					system("color 0a");

					cout << "\nVOTANTE ENCONTRADO:\n";

					cout << "\nCedula: " << vAux.getCedula() << endl
						 << "Nombre: " << vAux.getNombre() << endl
						 << "Apellido: " << vAux.getApellido() << endl
						 << "Genero: " << vAux.getGenero() << endl
						 << "Edad: " << vAux.getEdad() << endl
						 << "Estado: " << vAux.getStatus() << endl
						 << endl;

					vEnco = true;
				}

				votantes.Insertar(vAux);
			}
		}
	}

	return vEnco;
}

bool Mesa::ModificarVotante(string cd)
{
	Votante vAux, marca;
	bool encontrado = false;
	bool vmod = false;
	marca = CrearMarca();

	if (!votantes.Vacia())
	{
		votantes.Insertar(marca);

		while (!encontrado)
		{
			votantes.Remover(vAux);
			if (vAux.getCedula() == marca.getCedula())
			{
				encontrado = true;
			}
			else
			{
				if (vAux.getCedula() == cd)
				{
					string r;

					cout << "El votante es asistido? (S/N): ";
					cin >> r;

					vAux.ModificarStatus(r);

					cout << "\nVOTANTE ACTUALIZADO CORRECTAMENTE\n\n";
					vmod = true;
				}

				votantes.Insertar(vAux);
			}
		}
	}

	return vmod;
}

bool Mesa::EliminarVotante(string cd)
{

	Votante vAux, marca;
	bool encontrado = false;
	bool vEli = false;
	marca = CrearMarca();

	if (!votantes.Vacia())
	{
		votantes.Insertar(marca);

		while (!encontrado)
		{
			votantes.Remover(vAux);
			if (vAux.getCedula() == marca.getCedula())
			{
				encontrado = true;
			}
			else
			{
				if (vAux.getCedula() == cd)
				{
					system("color 0a");
					cout << "\n\nVOTANTE ELIMINADO CORRECTAMENTE\n\n";
					vEli = true;
				}
				else
				{
					votantes.Insertar(vAux);
				}
			}
		}
	}

	return vEli;
}

void Mesa::ImprimirEnCola(string cond)
{

	Votante v, marca;
	bool enco;
	marca = CrearMarca();

	if (!votantes.Vacia())
	{
		votantes.Insertar(marca);
		enco = false;

		while (!enco)
		{
			votantes.Remover(v);
			if (v.getCedula() == marca.getCedula())
			{
				enco = true;
			}
			else if (v.VerificarStatus(cond))
			{
				cout << v.getCedula() << " " << v.getNombre() << endl;
				votantes.Insertar(v);
			}
			else
			{
				votantes.Insertar(v);
			}
		}
	}
}

void Mesa::ImprimirCola()
{

	Votante votAux, marca;
	bool encontrado;
	marca = CrearMarca();

	if (!votantes.Vacia())
	{
		votantes.Insertar(marca);
		encontrado = false;

		while (!encontrado)
		{
			votantes.Remover(votAux);
			if (votAux.getCedula() == marca.getCedula())
			{
				encontrado = true;
			}
			else
			{
				cout << votAux.getCedula() << " | " << votAux.getNombre() << " | " << votAux.getGenero() << " | ";
				cout << votAux.getEdad() << " | " << votAux.getStatus() << endl;
				votantes.Insertar(votAux);
			}
		}
	}
}