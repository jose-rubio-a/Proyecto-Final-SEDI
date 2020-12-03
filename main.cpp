#include <iostream>
#include "videogame.h"
using namespace std;

int main()
{
    VideoGame myVG;
    string op;
    while (true)
    {
        cout << "MENU PRINCIPAL " << endl;
        cout << "Usuario: " << myVG.getNombreUsuario() << endl
             << endl;
        cout << " 1) Nombre Usuario" << endl;
        cout << " 2) Agregar Civilizacion" << endl;
        cout << " 3) Insertar Civilizacion" << endl;
        cout << " 4) Inicializar Civilizaciones" << endl;
        cout << " 5) Primera Civilizacion" << endl;
        cout << " 6) Ultima Civilizacion" << endl;
        cout << " 7) Ordenar" << endl;
        cout << " 8) Eliminar Civilizacion" << endl;
        cout << " 9) Buscar" << endl;
        cout << "10) Modificar" << endl;
        cout << "11) Mostrar" << endl;
        cout << " 0) Salir" << endl;
        cout << "Opcion: ";
        getline(cin, op);
        if (op == "1")
        {
            string myStr;
            cout << "Dame el nombre de usuario: ";
            getline(cin, myStr);
            myVG.setNombreUsuario(myStr);
        }
        else if (op == "2")
        {
            Civilizacion c;
            cin >> c;
            myVG.agregarFinal(c);
        }
        else if (op == "3")
        {
            Civilizacion c;
            cin >> c;
            size_t p;
            cout << "Posicion: ";
            cin >> p;
            cin.ignore();
            if (p <= myVG.size())
            {
                myVG.insertar(c, p);
            }
            else
            {
                cout << "Posicion no valida" << endl;
            }
        }
        else if (op == "4")
        {
            Civilizacion c;
            cin >> c;
            size_t n;
            cout << "n: ";
            cin >> n;
            cin.ignore();
            myVG.inicializar(c, n);
        }
        else if (op == "5")
        {
            cout << left;
            cout << setw(15) << "Nombre";
            cout << setw(13) << "Ubicacion X";
            cout << setw(13) << "Ubicacion Y";
            cout << setw(10) << "Puntuacion";
            cout << endl;
            if (myVG.size() > 0)
            {
                cout << myVG.front() << endl;
            }
        }
        else if (op == "6")
        {
            cout << left;
            cout << setw(15) << "Nombre";
            cout << setw(13) << "Ubicacion X";
            cout << setw(13) << "Ubicacion Y";
            cout << setw(10) << "Puntuacion";
            cout << endl;
            if (myVG.size() > 0)
            {
                cout << myVG.back() << endl;
            }
        }
        else if (op == "7")
        {
            string opOrd;
            cout << "OPCION DE ORDENAMIENTO" << endl;
            cout << "1) Nombre" << endl;
            cout << "2) Ubicacion en X" << endl;
            cout << "3) Ubicacion en Y" << endl;
            cout << "4) Puntuacion" << endl;
            cout << "Opcion: ";
            getline(cin, opOrd);
            if (opOrd == "1")
            {
                myVG.ordenarNombre();
            }
            else if (opOrd == "2")
            {
                myVG.ordenarUbicacionX();
            }
            else if (opOrd == "3")
            {
                myVG.ordenarUbicacionY();
            }
            else if (opOrd == "4")
            {
                myVG.ordenarPuntuacion();
            }
            else
            {
                cout << "Opcion de ordenamiento no valida" << endl;
            }
        }
        else if (op == "8")
        {
            string myStr;
            cout << "Dame la civilizacion a eliminar: ";
            getline(cin, myStr);
            myVG.eliminar(myStr);
        }
        else if (op == "9")
        {
            string myStr;
            Civilizacion c;
            cout << "Dame la civilizacion a buscar: ";
            getline(cin, myStr);
            c.setNombre(myStr);
            Civilizacion *ptr = myVG.buscar(c);
            if (ptr == nullptr)
            {
                cout << "Civilizacion no encontrada" << endl;
            }
            else
            {
                cout << left;
                cout << setw(15) << "Nombre";
                cout << setw(13) << "Ubicacion X";
                cout << setw(13) << "Ubicacion Y";
                cout << setw(10) << "Puntuacion";
                cout << endl;
                cout << *ptr << endl;
            }
        }
        else if (op == "10")
        {
            string myStr;
            Civilizacion c;
            int myInt;
            float myFloat;
            string opMod;
            cout << "Dame la civilizacion a modificar: ";
            getline(cin, myStr);
            c.setNombre(myStr);
            Civilizacion *ptr = myVG.buscar(c);
            if (ptr != nullptr)
            {
                while (true)
                {
                    cout << left;
                    cout << setw(15) << "Nombre";
                    cout << setw(13) << "Ubicacion X";
                    cout << setw(13) << "Ubicacion Y";
                    cout << setw(10) << "Puntuacion";
                    cout << endl;
                    cout << *ptr << endl;
                    cout << "Que desea modificar: " << endl;
                    cout << "1) Nombre" << endl;
                    cout << "2) Ubicacion en X" << endl;
                    cout << "3) Ubicacion en Y" << endl;
                    cout << "4) Puntuacion" << endl;
                    cout << "0) Salir" << endl;
                    cout << "Opcion: ";
                    getline(cin, opMod);
                    if (opMod == "1")
                    {
                        cout << "Dame el nuevo nombre: ";
                        getline(cin, myStr);
                        ptr->setNombre(myStr);
                    }
                    else if (opMod == "2")
                    {
                        cout << "Dame la nueva posicion en X: ";
                        cin >> myFloat;
                        cin.ignore();
                        ptr->setUbicacionX(myFloat);
                    }
                    else if (opMod == "3")
                    {
                        cout << "Dame la nueva posicion en Y: ";
                        cin >> myFloat;
                        cin.ignore();
                        ptr->setUbicacionY(myFloat);
                    }
                    else if (opMod == "4")
                    {
                        cout << "Dame la nueva puntuacion: ";
                        cin >> myInt;
                        cin.ignore();
                        ptr->setPuntuacion(myInt);
                    }
                    else if (opMod == "0")
                    {
                        break;
                    }
                    else
                    {
                        cout << "Opcion de modificacion no valida" << endl;
                    }
                }
            }
            else
            {
                cout << "Civilizacion no encontrada" << endl;
            }
        }
        else if (op == "11")
        {
            myVG.mostrar();
        }
        else if (op == "0")
        {
            break;
        }
        else
        {
            cout << "Opcion no Valida" << endl;
        }
        cout << endl;
    }

    return 0;
}