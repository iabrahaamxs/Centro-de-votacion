/*ABRAHAN ALMAO -------28021547
  ALIRIO FREYTEZ ------28019240
  GUSTAVO LOZADA ------29587789
  FRANCISCO CASTILLO --27649229
  MIGUEL IGLESIAS -----28391672 */

#include <iostream>
#include "General.h"
#include "fstream" // Libreria para trabajar con los archivos de texto .txt
#include <windows.h>

using namespace std;

// Metodo para mostrar el menu principal
char menuPrincipal()
{
    char opMenuPrincipal;
    cout << " ===========================================" << endl;
    cout << " ============CENTRO DE VOTACION=============" << endl;
    cout << " ===========================================" << endl;
    cout << "1. Menu Mesas" << endl;    // Acceder al menu de mesas
    cout << "2. Menu Votantes" << endl; // Acceder al menu de votantes
    cout << "3. Proceso de votacion" << endl;
    cout << "4. Menu Reportes" << endl; // Acceder al menu de reportes
    cout << "5. Salir" << endl;         // Salir del sistema
    cout << "Elija una opcion: ";
    cin >> opMenuPrincipal;
    system("cls");
    return opMenuPrincipal;
}

// Metodo para mostrar el submenu de Mesas
char menuMesas()
{
    char opMenuMesas;
    cout << " ===========================================" << endl;
    cout << " ==============MENU DE MESAS================" << endl;
    cout << " ===========================================" << endl;
    cout << "1. Crear mesa" << endl;     // Create mesa
    cout << "2. Buscar mesa" << endl;    // Read mesa
    cout << "3. Modificar mesa" << endl; // Update mesa
    cout << "4. Eliminar mesa" << endl;  // Delete mesa
    cout << "5. Reportar mesas" << endl;
    cout << "6. Regresar" << endl; // Regresa al menu principal
    cout << "Elija una opcion: ";
    cin >> opMenuMesas;
    system("cls");
    return opMenuMesas;
}

// Metodo para mostrar el submenu de Votantes
char menuVotantes()
{
    char opMenuVotantes;
    cout << " ===========================================" << endl;
    cout << " =============MENU DE VOTANTES==============" << endl;
    cout << " ===========================================" << endl;
    cout << "1. Padron Electoral" << endl;
    cout << "2. Ingresar votante a la cola" << endl;
    cout << "3. Buscar votante en cola" << endl;
    cout << "4. Modificar votantes en cola" << endl;
    cout << "5. Eliminar Votante de la cola" << endl;
    cout << "6. Imprimir votantes en cola" << endl;
    cout << "7. Regresar" << endl;
    cout << "Elija una opcion: ";
    cin >> opMenuVotantes;
    system("cls");
    return opMenuVotantes;
}

// Metodo para mostrar el submenu de Padron electoral
char menuPadronElectoral()
{
    char opMenuPadronElectoral;
    cout << " ===========================================" << endl;
    cout << " =========MENU DE PADRON ELECTORAL==========" << endl;
    cout << " ===========================================" << endl;
    cout << "1. Inscribir votante" << endl;
    cout << "2. Buscar votante" << endl;
    cout << "3. Modificar datos del votante" << endl;
    cout << "4. Eliminar votante" << endl;
    cout << "5. Reportar votantes" << endl;
    cout << "6. Regresar" << endl;
    cout << "Elija una opcion: ";
    cin >> opMenuPadronElectoral;
    system("cls");
    return opMenuPadronElectoral;
}

// Metodo para mostrar el submenu Reportes
char menuReportes()
{
    char opMenuReportes;
    cout << " ===========================================" << endl;
    cout << " =============MENU DE REPORTES==============" << endl;
    cout << " ===========================================" << endl;
    cout << "1. Historico votaron" << endl;
    cout << "2. Historico en cola" << endl; // Tiene sentido solo si no se ha terminado el proceso de votacion
    cout << "3. Historico asistidos" << endl;
    cout << "4. Historico retirados" << endl;
    cout << "5. Historico asistidos en cola" << endl;     // Tiene sentido solo si no se ha terminado el proceso de votacion
    cout << "6. Historico asistidos que votaron" << endl; // No deberia existir, es la opcion 3
    cout << "7. Regresar" << endl;
    cout << "Elija una opcion: ";
    cin >> opMenuReportes;
    system("cls");
    return opMenuReportes;
}

int main()
{
    General gn;
    ofstream Esc;
    ifstream Lec;
    char op, opMenuMesas, opMenuVotantes, opMenuReportes, opMenuPadronElectoral;

    gn.IngresarMesasDB(Lec);
    gn.CrearListaPadronDB(Lec);

    do
    {

        op = menuPrincipal();

        switch (op)
        {
        // Opcion Menu Mesas
        case '1':
            do
            {
                opMenuMesas = menuMesas();

                switch (opMenuMesas)
                {
                case '1':
                    gn.CrearMesa(Esc);
                    break;
                case '2':
                    gn.BuscarMesa();
                    break;
                case '3':
                    gn.ModificarMesa(Lec);
                    break;
                case '4':
                    gn.EliminarMesa(Lec);
                    break;
                case '5':
                    gn.ImprimirLista();
                    break;
                case '6':
                    system("color 07");
                    break;
                default:
                    cout << "Opcion invalida. Seleccione una opcion valida." << endl;
                }

            } while (opMenuMesas != '6');
            break;

        // Opcion Menu Votantes
        case '2':
            do
            {
                opMenuVotantes = menuVotantes();

                switch (opMenuVotantes)
                {
                case '1':
                    do
                    {
                        opMenuPadronElectoral = menuPadronElectoral();
                        switch (opMenuPadronElectoral)
                        {
                        case '1':
                            gn.IngrVotantePadron(Esc);
                            break;
                        case '2':
                            gn.BusVotantePadron();
                            break;
                        case '3':
                            gn.ModVotantePadron(Lec);
                            break;
                        case '4':
                            gn.EliVotantePadron(Lec);
                            break;
                        case '5':
                            gn.ImprimirPadron();
                            break;
                        case '6':
                            system("color 07");
                            /* Regresar */
                            break;
                        default:
                            break;
                        }
                    } while (opMenuPadronElectoral != '6');

                    break;
                case '2':
                    gn.IngrVotanteCola();
                    break;
                case '3':
                    gn.BuscarVotanteCola();
                    break;
                case '4':
                    gn.ModificarVotanteCola();
                    break;
                case '5':
                    gn.EliminarVotanteCola();
                    break;
                case '6':
                    gn.ImprimirColas();
                    break;
                case '7':
                    system("color 07");
                    /* code */
                    break;
                default:
                    cout << "Opcion invalida. Seleccione una opcion valida." << endl;
                }
            } while (opMenuVotantes != '7');
            break;

        // Opcion proceso de votacion
        case '3':
            gn.ProcesoVotacion();
            break;
        // Opcion Menu Reportes
        case '4':
            do
            {
                opMenuReportes = menuReportes();

                switch (opMenuReportes)
                {
                case '1':
                    gn.ReporteVotaron();
                    break;
                case '2':
                    gn.ReporteEnCola();
                    break;
                case '3':
                    gn.ReporteAsistidos();
                    break;
                case '4':
                    gn.ReporteRetirados();
                    break;
                case '5':
                    gn.ReporteAsistidosEnCola();
                    break;
                case '6':
                    gn.ReporteAsistidosVotaron();
                    break;
                case '7':
                    system("color 07");
                    /* code */
                    break;
                default:
                    cout << "Opcion invalida. Seleccione una opcion valida." << endl;
                }
            } while (opMenuReportes != '7');
            break;

        // Opcion salir
        case '5':
            gn.LimpiarListas();
            cout << "Ha salido del sistema." << endl;
            break;
        default:
            cout << "Opcion invalida. Seleccione una opcion valida." << endl;
        }
    } while (op != '5');

    system("color 07");
    return 0;
}