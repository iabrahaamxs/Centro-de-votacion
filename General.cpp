#include "General.h"

General::General()
{
}

void General::IngresarMesasDB(ifstream &Lec)
{
    string num, ced;
    Mesa m;
    Lec.open("mesas.txt", ios::in);
    Lec >> num;
    while (!Lec.eof())
    {
        Lec >> ced;
        m.setId(num);
        m.setTipo(ced);
        mesasAux.InsComienzo(m);

        Lec >> num;
    }
    Lec.close();

    mesas.pasarListaAux(mesasAux, mesas);
}

void General::ImprimirLista()
{
    system("color 07");
    Mesa m;
    cout << "\n ==============TODAS LAS MESAS==============\n"
         << endl;

    while (!mesas.Vacia())
    {
        mesas.EliComienzo(m);
        cout << "Mesa: " << m.getId() << endl
             << "Tipo: " << m.getTipo() << endl
             << endl;
        mesasAux.InsComienzo(m);
    }

    mesas.pasarListaAux(mesasAux, mesas);
}

bool General::Verificar(string n, string c)
{
    Mesa m;
    bool enco = false;
    while (!mesas.Vacia())
    {
        mesas.EliComienzo(m);
        int tamanio = m.getTipo().size();

        for (int i = 0; i < tamanio; i++)
        {
            size_t found = c.find(m.getTipo()[i]);
            if (m.getId() == n || found != string::npos)
            {
                enco = true;
            }
        }

        mesasAux.InsComienzo(m);
    }

    mesas.pasarListaAux(mesasAux, mesas);
    return !enco;

    /*
    // Validar con el txt
    ifstream leer("mesas.txt", ios::in);
    string num, ced;
    leer >> num;
    while (!leer.eof())
    {
        leer >> ced;
        if (num == n || ced == c)
        {
            system("color 0c");
            cout << "\n\nNo puede ingresarse el registro,\nLa mesa ya existente.\n\n";
            leer.close();
            return false;
        }

        leer >> num;
    }

    leer.close();
    system("color 0a");
    cout << "\n\nRegistro Ingresado con exito\n\n";
    return true;*/
}

bool General::Verificar2(string n, string c)
{
    Mesa m;
    bool enco = false;
    while (!mesas.Vacia())
    {
        mesas.EliComienzo(m);
        int tamanio = m.getTipo().size();

        for (int i = 0; i < tamanio; i++)
        {
            if (m.getId() != n)
            {
                size_t found = c.find(m.getTipo()[i]);
                if (found != string::npos)
                {
                    enco = true;
                }
            }
        }

        mesasAux.InsComienzo(m);
    }

    mesas.pasarListaAux(mesasAux, mesas);
    return !enco;

    /*
    // Validar con el txt
    ifstream leer("mesas.txt", ios::in);
    string num, ced;
    leer >> num;
    while (!leer.eof())
    {
        leer >> ced;
        if (num == n || ced == c)
        {
            system("color 0c");
            cout << "\n\nNo puede ingresarse el registro,\nLa mesa ya existente.\n\n";
            leer.close();
            return false;
        }

        leer >> num;
    }

    leer.close();
    system("color 0a");
    cout << "\n\nRegistro Ingresado con exito\n\n";
    return true;*/
}

bool General::EncabezadoCrearMesa()
{
    string ms1, ms2, msAux;
    Mesa mA;
    ms1 = "[Mesas Existentes:";
    ms2 = "[Terminales de cedula disponibles:";
    while (!mesas.Vacia())
    {
        mesas.EliComienzo(mA);
        ms1 += " " + mA.getId() + ",";
        msAux += mA.getTipo();
        mesasAux.InsComienzo(mA);
    }

    for (int i = 0; i < 10; i++)
    {
        size_t found = msAux.find(to_string(i));
        if (found == string::npos)
        {
            ms2 += " " + to_string(i) + ",";
        }
    }
    mesas.pasarListaAux(mesasAux, mesas);

    if (ms2 == "[Terminales de cedula disponibles:")
    {
        return false;
    }

    if (ms1 == "[Mesas Existentes:")
    {
        ms1 += " NINGUNA  ";
    }

    ms1.back() = ']';
    ms2.back() = ']';
    cout << ms1 << endl;
    cout << ms2 << endl
         << endl;

    return true;
}

bool General::TieneNoDigito(string nd)
{

    for (unsigned int i = 0; i < nd.length(); i++)
    {
        if (!isdigit(nd[i]))
        {
            system("color 0c");
            cout << "\nEl terminal de cedula solo puede ser numeros enteros\n\n";

            return true;
        }
    }

    return false;
}

void General::CrearMesa(ofstream &esc)
{
    system("cls");
    system("color 07");

    if (!EncabezadoCrearMesa())
    {
        cout << "NO PUEDES CREAR MAS MESAS PORQUE TODOS LOS TERMINALES DE CEDULA SE ENCUENTRAN ASIGNADOS\n\n";
        return;
    }

    string num, ced;

    cout << "Numero de mesa: ";
    cin >> num;
    cout << "Terminal de cedula: ";
    cin >> ced;

    if (TieneNoDigito(ced))
    {
        return;
    }

    esc.open("mesas.txt", ios::out | ios::app);

    if (Verificar(num, ced))
    {
        esc << num << " " << ced << "\n";
        system("color 0a");
        cout << "\n\nRegistro ingresado con exito\n\n";
        mesasAux.pasarListaAux(mesas, mesasAux);
        Mesa m;
        m.setId(num);
        m.setTipo(ced);
        mesasAux.InsComienzo(m);
        mesas.pasarListaAux(mesasAux, mesas);
    }
    else
    {
        system("color 0c");
        cout << "\n\nNo puede ingresarse el registro.\n\n";
    }

    esc.close();
}

void General::BuscarMesa()
{
    system("color 07");
    string num, ced, numAux;
    Mesa m;
    bool enc = false;
    string ms1 = "[Mesas Existentes:";
    while (!mesas.Vacia())
    {
        mesas.EliComienzo(m);
        ms1 += " " + m.getId() + ",";
        mesasAux.InsComienzo(m);
    }
    ms1.back() = ']';
    cout << ms1 << endl
         << endl;
    mesas.pasarListaAux(mesasAux, mesas);

    cout << "Digite el numero de la mesa que desea buscar: ";
    cin >> numAux;

    while (!mesas.Vacia())
    {
        mesas.EliComienzo(m);

        if (numAux == m.getId())
        {
            system("color 0a");
            cout << "\n\nMESA ENCONTRADA!\n\n";

            cout << "Mesa: " << m.getId() << endl
                 << "Tipo: " << m.getTipo() << endl
                 << endl;

            enc = true;
        }
        mesasAux.InsComienzo(m);
    }

    if (!enc)
    {
        system("color 0c");
        cout << "\n\nLA MESA NO EXISTE\n\n";
    }

    mesas.pasarListaAux(mesasAux, mesas);
}

bool General::VerificaColaMesa(string id)
{
    Mesa m;
    bool verifica = false;

    while (!mesas.Vacia())
    {
        mesas.EliComienzo(m);
        if (m.getId() == id && m.ColaVacia())
        {
            verifica = true;
        }
        mesasAux.InsComienzo(m);
    }
    mesas.pasarListaAux(mesasAux, mesas);

    return verifica;
}

void General::ModificarMesa(ifstream &Lec)
{
    system("cls");
    string num, ced, nAux, cAux;
    Mesa m;
    bool mod = false;

    system("color 07");
    ImprimirLista();
    cout << "Numero de Mesa a modificar: ";
    cin >> nAux;

    if (VerificaColaMesa(nAux))
    {
        Lec.open("mesas.txt", ios::in);
        ofstream aux("auxiliar.txt", ios::out);
        if (Lec.is_open())
        {
            cout << "Nuevo Tipo: ";
            cin >> cAux;

            // Modificar tipo de mesa en el mesas.txt
            Lec >> num;
            while (!Lec.eof())
            {
                Lec >> ced;
                if (num == nAux && Verificar2(nAux, cAux))
                {
                    aux << num << " " << cAux << "\n";
                }
                else
                {
                    aux << num << " " << ced << "\n";
                }
                Lec >> num;
            }

            // Modificar tipo de mesa en la Lista de mesas
            if (Verificar2(nAux, cAux))
            {
                mod = true;
                while (!mesas.Vacia())
                {
                    mesas.EliComienzo(m);
                    if (m.getId() == nAux)
                    {
                        m.setTipo(cAux);
                        system("color 0a");
                        cout << "\nTipo de Mesa actualizado con exito\n\n";
                    }
                    mesasAux.InsComienzo(m);
                }
            }

            if (mod)
            {
                mesas.pasarListaAux(mesasAux, mesas);
            }
            else
            {
                system("color 0c");
                cout << "\nNo se pudo modificar la mesa. Ingrese un valor valido\n\n";
            }

            Lec.close();
            aux.close();
            remove("mesas.txt");
            rename("auxiliar.txt", "mesas.txt");
        }
        else
        {
            system("color 0c");
            cout << "\nERROR\n";
        }
    }
    else
    {
        system("color 0c");
        cout << "\nNO SE PUEDE MODIFICAR LA MESA\n\n";
    }
}

void General::EliminarMesa(ifstream &Lec)
{
    system("cls");
    system("color 07");

    if (mesas.Vacia())
    {
        cout << "NO HAY MESAS PARA ELIMINAR\n\n";
    }
    else
    {

        string num, ced, nAux, cAux;
        Mesa m;
        bool enco = false;

        string ms1 = "[Mesas Existentes:";
        while (!mesas.Vacia())
        {
            mesas.EliComienzo(m);
            ms1 += " " + m.getId() + ",";
            mesasAux.InsComienzo(m);
        }
        ms1.back() = ']';
        cout << ms1 << endl
             << endl;
        mesas.pasarListaAux(mesasAux, mesas);

        cout << "Numero de Mesa a Eliminar: ";
        cin >> nAux;

        if (VerificaColaMesa(nAux))
        {
            Lec.open("mesas.txt", ios::in);
            ofstream aux("auxiliar.txt", ios::out);
            if (Lec.is_open())
            {
                Lec >> num;
                while (!Lec.eof()) // Eliminar mesa desde el txt
                {
                    Lec >> ced;
                    if (num != nAux)
                    {
                        aux << num << " " << ced << "\n";
                    }
                    Lec >> num;
                }

                Lec.close();
                aux.close();

                while (!mesas.Vacia()) // Eliminar mesa de la Lista de mesas
                {
                    mesas.EliComienzo(m);
                    if (m.getId() != nAux)
                    {
                        mesasAux.InsComienzo(m);
                    }
                    else
                    {
                        enco = true;
                    }
                }

                mesas.pasarListaAux(mesasAux, mesas);

                if (enco)
                {
                    system("color 0a");
                    cout << "\nMesa eliminada correctamente!\n\n";
                }
                else
                {
                    system("color 0c");
                    cout << "\nLa mesa que desea Eliminar no existe\n\n";
                }
            }
            else
            {
                cout << "ERROR\n";
            }

            remove("mesas.txt");
            rename("auxiliar.txt", "mesas.txt");
        }
        else
        {
            system("color 0c");
            cout << "\nNO SE PUEDE ELIMINAR LA MESA\n\n";
        }
    }
}

// PADRON ELECTORAL

void General::CrearListaPadronDB(ifstream &Lec)
{

    string ced, nom, ape, gen, eda;
    Votante v;
    Lec.open("padron.txt", ios::in);
    Lec >> ced;
    while (!Lec.eof())
    {
        Lec >> nom;
        Lec >> ape;
        Lec >> gen;
        Lec >> eda;
        v.setCedula(ced);
        v.setNombre(nom);
        v.setApellido(ape);
        v.setGenero(gen);
        v.setEdad(eda);

        padronAux.InsComienzo(v);

        Lec >> ced;
    }
    Lec.close();

    padron.pasarListaAux(padronAux, padron);
}

bool General::VerificaPadron(string c)
{
    Votante v;
    bool existe = false;

    while (!padron.Vacia())
    {
        padron.EliComienzo(v);
        if (v.getCedula() == c)
        {
            existe = true;
        }
        padronAux.InsComienzo(v);
    }

    padron.pasarListaAux(padronAux, padron);

    return existe;
}

void General::IngrVotantePadron(ofstream &esc)
{
    system("color 07");
    string ced, nom, ape, gen, eda;
    Votante v;

    cout << "Cedula: ";
    cin >> ced;

    if (!VerificaPadron(ced))
    {
        esc.open("padron.txt", ios::out | ios::app);
        cout << "Nombre: ";
        cin >> nom;
        cout << "Apellido: ";
        cin >> ape;
        cout << "Edad: ";
        cin >> eda;
        cout << "Genero (F/M): ";
        cin >> gen;

        v.setCedula(ced);
        v.setNombre(nom);
        v.setApellido(ape);
        v.setGenero(gen);
        v.setEdad(eda);

        padronAux.pasarListaAux(padron, padronAux);
        padronAux.InsComienzo(v);
        padron.pasarListaAux(padronAux, padron);

        system("color 0a");
        cout << "\nVOTANTE INSCRITO CON EXITO\n\n";

        esc << ced << " " << nom << " " << ape << " " << gen << " " << eda << "\n";

        esc.close();
    }
    else
    {
        system("color 0c");
        cout << "\nEL VOTANTE YA EXISTE EN EL PADRON ELECTORAL\n\n";
    }
}

void General::BusVotantePadron()
{
    system("color 07");

    string ced;
    Votante v;
    bool enc = false;

    cout << "Digite el numero de cedula del votante que desea buscar: ";
    cin >> ced;

    while (!padron.Vacia())
    {
        padron.EliComienzo(v);

        if (ced == v.getCedula())
        {
            system("color 0a");
            cout << "\n\nVOTANTE ENCONTRADO!\n\n";

            cout << "Cedula: " << v.getCedula() << endl
                 << "Nombre: " << v.getNombre() << endl
                 << "Apellido: " << v.getApellido() << endl
                 << "Genero: " << v.getGenero() << endl
                 << "Edad: " << v.getEdad() << endl
                 << endl;

            enc = true;
        }

        padronAux.InsComienzo(v);
    }

    if (!enc)
    {
        system("color 0c");
        cout << "\n\nLA CEDULA INGRESADA NO EXISTE EN ESTE PADRON ELECTORAL\n\n";
    }

    padron.pasarListaAux(padronAux, padron);
}

void General::ModVotantePadron(ifstream &Lec)
{
    system("color 07");

    string c, n, a, g, e, c2, cAux, nAux, aAux, gAux, eAux;
    Votante v;

    cout << "Cedula del votante a modificar: ";
    cin >> cAux;

    if (VerificaPadron(cAux))
    {
        cout << "Cedula: ";
        cin >> c2;

        if (c2 == cAux || !VerificaPadron(c2))
        {
            Lec.open("padron.txt", ios::in);
            ofstream auxP("auxiliarP.txt", ios::out);

            if (Lec.is_open())
            {

                cout << "Nombre: ";
                cin >> nAux;
                cout << "Apellido: ";
                cin >> aAux;
                cout << "Edad: ";
                cin >> eAux;
                cout << "Genero (F/M): ";
                cin >> gAux;

                // Modificar votante en el padron.txt
                Lec >> c;
                while (!Lec.eof())
                {
                    Lec >> n;
                    Lec >> a;
                    Lec >> g;
                    Lec >> e;
                    if (c == cAux)
                    {
                        auxP << c2 << " " << nAux << " " << aAux << " " << gAux << " " << eAux << "\n";
                    }
                    else
                    {
                        auxP << c << " " << n << " " << a << " " << g << " " << e << "\n";
                    }
                    Lec >> c;
                }

                // Modificar Votante de la lista Padron
                while (!padron.Vacia())
                {
                    padron.EliComienzo(v);
                    if (v.getCedula() == cAux)
                    {
                        v.setCedula(c2);
                        v.setNombre(nAux);
                        v.setApellido(aAux);
                        v.setGenero(gAux);
                        v.setEdad(eAux);
                        system("color 0a");
                        cout << "\nLos datos del votante fueron actualizados con exito\n\n";
                    }
                    padronAux.InsComienzo(v);
                }

                padron.pasarListaAux(padronAux, padron);

                Lec.close();
                auxP.close();
                remove("padron.txt");
                rename("auxiliarP.txt", "padron.txt");
            }
            else
            {
                system("color 0c");
                cout << "\nERROR INESPERADO!! :( \n\n";
            }
        }
        else
        {
            system("color 0c");
            cout << "\nLA CEDULA INGRESADA YA EXISTE EN EL PADRON ELECTORAL\n\n";
        }
    }
    else
    {
        system("color 0c");
        cout << "\nLA CEDULA INGRESADA NO EXISTE EN EL PADRON ELECTORAL\n\n";
    }
}

void General::EliVotantePadron(ifstream &Lec)
{
    system("color 07");

    string c, n, a, g, e, cAux;
    Votante v;

    cout << "Cedula del votante que desea eliminar: ";
    cin >> cAux;

    if (VerificaPadron(cAux))
    {
        Lec.open("padron.txt", ios::in);
        ofstream auxP("auxiliarP.txt", ios::out);

        if (Lec.is_open())
        {

            // Eliminar votante en el padron.txt
            Lec >> c;
            while (!Lec.eof())
            {
                Lec >> n;
                Lec >> a;
                Lec >> g;
                Lec >> e;
                if (c != cAux)
                {
                    auxP << c << " " << n << " " << a << " " << g << " " << e << "\n";
                }
                Lec >> c;
            }

            // Eliminar Votante de la lista Padron
            while (!padron.Vacia())
            {
                padron.EliComienzo(v);
                if (v.getCedula() != cAux)
                {
                    padronAux.InsComienzo(v);
                }
                else
                {
                    system("color 0a");
                    cout << "\nEl votante fue eliminado con exito\n\n";
                }
            }

            padron.pasarListaAux(padronAux, padron);

            Lec.close();
            auxP.close();
            remove("padron.txt");
            rename("auxiliarP.txt", "padron.txt");
        }
    }
    else
    {
        system("color 0c");
        cout << "\nLA CEDULA INGRESADA NO EXISTE EN EL PADRON ELECTORAL\n\n";
    }
}

void General::ImprimirPadron()
{
    system("color 07");

    int tamanio = (padron.Contar() + 1);
    int n = 1;
    char r;
    Votante v;

    cout << "\n[Pagina " << n << " ]\n";

    for (int i = 1; i < tamanio; i++)
    {

        padron.EliComienzo(v);

        cout << "Cedula: " << v.getCedula() << endl
             << "Nombre: " << v.getNombre() << endl
             << "Apellido: " << v.getApellido() << endl
             << "Genero: " << v.getGenero() << endl
             << "Edad: " << v.getEdad() << endl
             << endl;

        padronAux.InsComienzo(v);

        if ((i % 10 == 0) && ((i + 1) < tamanio))
        {
            cout << "\nDesea imprimir mas votantes? (S/N): ";
            cin >> r;

            if (r == 'S' || r == 's')
            {
                n++;
                cout << "\n[Pagina " << n << " ]\n";
            }
            else
            {
                i = tamanio;
            }
        }
    }

    while (!padronAux.Vacia())
    {
        padronAux.EliComienzo(v);
        padron.InsComienzo(v);
    }
}

// PROCESO DE VOTACION

bool General::VerificaVontanteEnCola()
{
    Mesa m;
    bool votante = false;

    while (!mesas.Vacia())
    {
        mesas.EliComienzo(m);
        if (!m.ColaVacia())
        {
            votante = true;
        }
        mesasAux.InsComienzo(m);
    }
    mesas.pasarListaAux(mesasAux, mesas);

    return votante;
}

void General::ProcesoVotacion()
{

    Mesa m;
    Votante v;
    char r = 's';
    bool votanteEnCola;

    votanteEnCola = VerificaVontanteEnCola();

    while ((r == 's' || r == 'S') && votanteEnCola)
    {

        while (!mesas.Vacia())
        {
            mesas.EliComienzo(m);
            if (!m.ColaVacia())
            {
                v = m.VotanteVoto();
                historico.InsComienzo(v);
                cout << "Proceso exitoso!!\n";
            }
            mesasAux.InsComienzo(m);
        }
        mesas.pasarListaAux(mesasAux, mesas);

        votanteEnCola = VerificaVontanteEnCola();

        if (votanteEnCola)
        {
            cout << "Desea continuar el proceso de votacion? (S/N): ";
            cin >> r;
        }
    }

    if (!votanteEnCola)
    {
        cout << "\nNO HAY VOTANTES EN NINGUNA COLA\n\n";
    }
}

// COLA DE VOTANTES

void General::ImprimirColas()
{
    system("color 07");

    Mesa m;
    cout << "Votantes en cola:\n\n";

    while (!mesas.Vacia())
    {
        mesas.EliComienzo(m);
        m.ImprimirCola();
        mesasAux.InsComienzo(m);
    }
    cout << endl;

    mesas.pasarListaAux(mesasAux, mesas);
}

bool General::Verifica(string c, string msj)
{

    bool next = true;
    Mesa msa;

    while (!mesas.Vacia())
    {
        mesas.EliComienzo(msa);
        if (msa.VerificarVotante(c))
        {
            cout << endl
                 << msj << endl
                 << endl;
            next = false;
        }

        mesasAux.InsComienzo(msa);
    }

    mesas.pasarListaAux(mesasAux, mesas);

    return next;
}

bool General::VerificaVoto(string ced)
{

    Votante v;
    bool verifica = true;

    while (!historico.Vacia())
    {
        historico.EliComienzo(v);
        if (v.getCedula() == ced && v.VerificarStatus("Voto"))
        {
            verifica = false;
            cout << "El votante no puede ingresar a la cola porque ya voto\n";
        }
        historicoAux.InsComienzo(v);
    }
    historico.pasarListaAux(historicoAux, historico);

    return verifica;
}

void General::EliminaRetirado(string ced)
{
    Votante v;

    while (!historico.Vacia())
    {
        historico.EliComienzo(v);
        if (v.getCedula() == ced && v.VerificarStatus("Retirado"))
        {
        }
        else
        {
            historicoAux.InsComienzo(v);
        }
    }
    historico.pasarListaAux(historicoAux, historico);
}

bool General::VerificarMesas()
{
    Mesa m;
    string terminalesCompuesto;

    while (!mesas.Vacia())
    {
        mesas.EliComienzo(m);
        terminalesCompuesto += m.getTipo();
        mesasAux.InsComienzo(m);
    }

    mesas.pasarListaAux(mesasAux, mesas);

    sort(terminalesCompuesto.begin(), terminalesCompuesto.end());

    if (terminalesCompuesto == "0123456789")
    {
        return true;
    }

    return false;
}

void General::IngrVotanteCola()
{
    system("color 07");

    if (!VerificarMesas())
    {
        cout << "No hay suficientes mesas de votacion para cubrir todos los votantes. Asegure que hayan suficientes mesas antes de ingresar un votante." << endl;
        return;
    }

    string ced, asi;
    Mesa msa;
    Votante v, vAux;

    cout << "Cedula: ";
    cin >> ced;

    if (Verifica(ced, "EL VOTANTE YA SE ENCUENTRA EN LA COLA.") && VerificaPadron(ced) && VerificaVoto(ced))
    {
        EliminaRetirado(ced);

        cout << "Es asistido? (S/N): ";
        cin >> asi;

        while (!padron.Vacia())
        {
            padron.EliComienzo(vAux);
            if (vAux.getCedula() == ced)
            {
                v.setCedula(ced);
                v.setNombre(vAux.getNombre());
                v.setApellido(vAux.getApellido());
                v.setGenero(vAux.getGenero());
                v.setEdad(vAux.getEdad());
            }
            padronAux.InsComienzo(vAux);
        }

        padron.pasarListaAux(padronAux, padron);

        v.StatusDefault(asi);

        while (!mesas.Vacia())
        {
            mesas.EliComienzo(msa);

            size_t found = msa.getTipo().find(v.getCedula().back());
            if (found != string::npos)
            {
                system("color 0a");
                cout << "\nEl votante ingreso correctamente\n\n";
                msa.InsertarVotante(v);
            }

            mesasAux.InsComienzo(msa);
        }

        mesas.pasarListaAux(mesasAux, mesas);
    }

    if (!VerificaPadron(ced))
    {
        system("color 0c");
        cout << "\nESTA CEDULA NO ESTA INSCRITA EN EL PADRON ELECTORIAL\n\n";
    }
}

void General::BuscarVotanteCola()
{
    system("color 07");

    string c;
    Mesa m;
    bool existe = false;

    cout << "Digite el numero de cedula del votante que desea buscar: ";
    cin >> c;

    while (!mesas.Vacia())
    {
        mesas.EliComienzo(m);
        if (m.BuscarVotante(c))
        {
            existe = true;
        }

        mesasAux.InsComienzo(m);
    }

    mesas.pasarListaAux(mesasAux, mesas);

    if (!existe)
    {
        system("color 0c");
        cout << "\nEL VOTANTE NO SE ENCUENTRA EN NINGUNA COLA\n\n";
    }
}

void General::ModificarVotanteCola()
{
    system("color 07");

    string c;
    Mesa m;
    bool mod = false;

    cout << "Digite el numero de cedula del votante que desea modificar: ";
    cin >> c;

    while (!mesas.Vacia())
    {
        mesas.EliComienzo(m);
        if (m.ModificarVotante(c))
        {
            mod = true;
        }
        mesasAux.InsComienzo(m);
    }

    mesas.pasarListaAux(mesasAux, mesas);

    if (!mod)
    {
        cout << "\nLA CEDULA INGRESADA NO ESTA ASOCIADA A NINGUN VOTANTE EN LA COLA\n\n";
    }
}

void General::EliminarVotanteCola()
{
    system("color 07");

    string c;
    Mesa m;
    Votante v;
    bool eli = false;

    cout << "Digite el numero de cedula del votante que desea eliminar: ";
    cin >> c;

    while (!mesas.Vacia())
    {
        mesas.EliComienzo(m);

        if (m.VerificarVotante(c))
        {
            v = m.VotanteRetirado(c);
            historico.InsComienzo(v);
        }

        mesasAux.InsComienzo(m);
    }

    mesas.pasarListaAux(mesasAux, mesas);

    while (!mesas.Vacia())
    {
        mesas.EliComienzo(m);
        if (m.EliminarVotante(c))
        {
            eli = true;
        }

        mesasAux.InsComienzo(m);
    }

    mesas.pasarListaAux(mesasAux, mesas);

    if (!eli)
    {
        system("color 0c");
        cout << "\nLA CEDULA INGRESADA NO ESTA ASOCIADA A NINGUN VOTANTE EN COLA\n\n";
    }
}

// REPORTES GENERALES

void General::ReporteVotaron()
{
    system("color 07");

    Votante v;

    while (!historico.Vacia())
    {
        historico.EliComienzo(v);
        if (v.VerificarStatus("Voto"))
        {
            cout << v.getCedula() << " " << v.getNombre() << endl;
        }
        historicoAux.InsComienzo(v);
    }

    historico.pasarListaAux(historicoAux, historico);
}

void General::ReporteEnCola()
{
    system("color 07");

    Mesa m;

    while (!mesas.Vacia())
    {
        mesas.EliComienzo(m);
        cout << "[MESA: " << m.getId() << " - "
             << "TERMINAL: " << m.getTipo() << "]" << endl
             << endl;
        cout << "VOTANTES: " << endl;

        m.ImprimirCola();

        cout << endl;

        mesasAux.InsComienzo(m);
    }

    mesas.pasarListaAux(mesasAux, mesas);
}

void General::ReporteAsistidos()
{
    system("color 07");

    Votante v;

    while (!historico.Vacia())
    {
        historico.EliComienzo(v);
        if (v.VerificarStatus("Asistido"))
        {
            cout << v.getCedula() << " " << v.getNombre() << endl;
        }
        historicoAux.InsComienzo(v);
    }

    historico.pasarListaAux(historicoAux, historico);

    ReporteAsistidosEnCola();
}

void General::ReporteRetirados()
{
    system("color 07");

    Votante v;

    while (!historico.Vacia())
    {
        historico.EliComienzo(v);
        if (v.VerificarStatus("Retirado"))
        {
            cout << v.getCedula() << " " << v.getNombre() << endl;
        }
        historicoAux.InsComienzo(v);
    }

    historico.pasarListaAux(historicoAux, historico);
}

void General::ReporteAsistidosEnCola()
{
    system("color 07");
    Mesa m;
    string condi = "Asistido";

    while (!mesas.Vacia())
    {
        mesas.EliComienzo(m);
        m.ImprimirEnCola(condi);
        mesasAux.InsComienzo(m);
    }

    mesas.pasarListaAux(mesasAux, mesas);
}

void General::ReporteAsistidosVotaron()
{
    system("color 07");

    Votante v;

    while (!historico.Vacia())
    {
        historico.EliComienzo(v);
        if (v.VerificarStatus("Asistido") && v.VerificarStatus("Voto"))
        {
            cout << v.getCedula() << " " << v.getNombre() << endl;
        }
        historicoAux.InsComienzo(v);
    }

    historico.pasarListaAux(historicoAux, historico);
}

void General::LimpiarListas()
{
    mesas.~Lista();
    padron.~Lista();
    historico.~Lista();
}
