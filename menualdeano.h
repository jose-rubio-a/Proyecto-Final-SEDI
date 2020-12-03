#include "civilizacion.h"

void menu(Civilizacion &c)
{
    while (true)
    {
        string op;
        cout << endl;
        cout << left;
        cout << setw(15) << "Nombre";
        cout << setw(13) << "Ubicacion X";
        cout << setw(13) << "Ubicacion Y";
        cout << setw(10) << "Puntuacion";
        cout << endl;
        cout << c << endl;
        cout << "MENU ALDEANO" << endl;
        cout << "1) Agregar aldeano" << endl;
        cout << "2) Eliminar aldeano" << endl;
        cout << "3) Clasificar aldenos" << endl;
        cout << "4) Buscar un aldeano" << endl;
        cout << "5) Modificicar aldeano" << endl;
        cout << "6) Mostrar aldeanos" << endl;
        cout << "0) Salir" << endl;
        cout << "Opcion: ";
        getline(cin, op);
        if (op == "1")
        {
            string addAld;
            Aldeano ald;
            cout << "AGREGAR ALDEANO" << endl;
            cin >> ald;
            cout << "Opciones para agregar:" << endl;
            cout << "1) Agregar al inicio" << endl;
            cout << "2) Agregar al Final" << endl;
            cout << "Opcion: ";
            getline(cin, addAld);
            if (addAld == "1")
            {
                c.agregarInicio(ald);
            }
            else if (addAld == "2")
            {
                c.agregarFinal(ald);
            }
            else
            {
                cout << "Opcion no valida" << endl;
            }
        }
        else if (op == "2")
        {
            string delAld;
            cout << "ELIMINAR ALDEANO" << endl;
            cout << "1) Eliminar por nombre" << endl;
            cout << "2) Eliminar por salud" << endl;
            cout << "3) Eliminar por edad" << endl;
            cout << "Opcion: ";
            getline(cin, delAld);
            if (delAld == "1")
            {
                string nombre;
                cout << "Dame el aldeano a eliminar: ";
                getline(cin, nombre);
                c.eliminarNombre(nombre);
            }
            else if (delAld == "2")
            {
                size_t salud;
                cout << "Dame el limite de salud: ";
                cin >> salud;
                cin.ignore();
                c.eliminarSalud(salud);
            }
            else if (delAld == "3")
            {
                c.eliminarEdad();
            }
            else
            {
                cout << "Opcion no valida" << endl;
            }
        }
        else if (op == "3")
        {
            string ClasAld;
            cout << "CLASIFICAR ALDEANOS" << endl;
            cout << "1) Clasificar por nombre" << endl;
            cout << "2) Clasificar por edad" << endl;
            cout << "3) Clasificar por salud" << endl;
            cout << "Opcion: ";
            getline(cin, ClasAld);
            if (ClasAld == "1")
            {
                c.clasificarNombre();
            }
            else if (ClasAld == "2")
            {
                c.clasificarEdad();
            }
            else if (ClasAld == "3")
            {
                c.clasificarSalud();
            }
            else
            {
                cout << "Opcion no Valida" << endl;
            }
        }
        else if (op == "4")
        {
            string nombre;
            Aldeano a;
            cout << "Dame el aldeano a buscar: ";
            getline(cin, nombre);
            a.setNombre(nombre);
            Aldeano *ptr = c.buscar(a);
            if (ptr == nullptr)
            {
                cout << "Aldeano no encontrado" << endl;
            }
            else
            {
                cout << left;
                cout << setw(12) << "Nombre";
                cout << setw(7) << "Edad";
                cout << setw(12) << "Genero";
                cout << setw(7) << "Salud";
                cout << endl;
                cout << *ptr << endl;
            }
        }
        else if (op == "5")
        {
            string nombre;
            Aldeano a;
            cout << "Dame el aldeano a modificar: ";
            getline(cin, nombre);
            a.setNombre(nombre);
            Aldeano *ptr = c.buscar(a);
            if (ptr != nullptr)
            {
                while (true)
                {
                    string opMod;
                    cout << left;
                    cout << setw(12) << "Nombre";
                    cout << setw(7) << "Edad";
                    cout << setw(12) << "Genero";
                    cout << setw(7) << "Salud";
                    cout << endl;
                    cout << *ptr << endl;
                    cout << "Que desea modificar:" << endl;
                    cout << "1) Nombre" << endl;
                    cout << "2) Edad" << endl;
                    cout << "3) Genero" << endl;
                    cout << "4) Salud" << endl;
                    cout << "0) Salir" << endl;
                    cout << "Opcion: ";
                    getline(cin, opMod);
                    if (opMod == "1")
                    {
                        string nombre;
                        cout << "Dame el nuevo nombre: ";
                        getline(cin, nombre);
                        ptr->setNombre(nombre);
                    }
                    else if (opMod == "2")
                    {
                        size_t edad;
                        cout << "Dame la nueva edad: ";
                        cin >> edad;
                        cin.ignore();
                        ptr->setEdad(edad);
                    }
                    else if (opMod == "3")
                    {
                        string genero;
                        cout << "Dame el genero: ";
                        getline(cin, genero);
                        ptr->setGenero(genero);
                    }
                    else if (opMod == "4")
                    {
                        size_t salud;
                        cout << "Dame la salud: ";
                        cin >> salud;
                        cin.ignore();
                        ptr->setSalud(salud);
                    }
                    else if (opMod == "0")
                    {
                        break;
                    }
                    else
                    {
                        cout << "Opcion no valida" << endl;
                    }
                }
            }
            else
            {
                cout << "Aldeano no encontrado" << endl;
            }
        }
        else if (op == "6")
        {
            c.mostrar();
        }
        else if (op == "0")
        {
            break;
        }
        else
        {
            cout << "Opcion no valida!" << endl;
        }
    }
}
