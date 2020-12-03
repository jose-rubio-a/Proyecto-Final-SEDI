#include "videogame.h"
#include <algorithm>
#include "menualdeano.h"


VideoGame::VideoGame() {}

void VideoGame::setNombreUsuario(const string &s)
{
    nombreUsuario = s;
}

string VideoGame::getNombreUsuario()
{
    return nombreUsuario;
}

void VideoGame::agregarFinal(const Civilizacion &c)
{
    civilizaciones.push_back(c);
}

void VideoGame::insertar(const Civilizacion &c, size_t p)
{
    civilizaciones.insert(civilizaciones.begin() + p, c);
}

void VideoGame::inicializar(const Civilizacion &c, size_t n)
{
    civilizaciones = vector<Civilizacion>(n, c);
}

Civilizacion VideoGame::front()
{
    return civilizaciones.front();
}

Civilizacion VideoGame::back()
{
    return civilizaciones.back();
}

void VideoGame::ordenarNombre()
{
    sort(civilizaciones.begin(), civilizaciones.end(), [](Civilizacion c1, Civilizacion c2) { return c1.getNombre() < c2.getNombre(); });
}
void VideoGame::ordenarUbicacionX()
{
    sort(civilizaciones.begin(), civilizaciones.end(), [](Civilizacion c1, Civilizacion c2) { return c1.getUbicacionX() < c2.getUbicacionX(); });
}
void VideoGame::ordenarUbicacionY()
{
    sort(civilizaciones.begin(), civilizaciones.end(), [](Civilizacion c1, Civilizacion c2) { return c1.getUbicacionY() < c2.getUbicacionY(); });
}
void VideoGame::ordenarPuntuacion()
{
    sort(civilizaciones.begin(), civilizaciones.end(), [](Civilizacion c1, Civilizacion c2) { return c1.getPuntuacion() > c2.getPuntuacion(); });
}

void VideoGame::eliminar(const string &v)
{
    for (size_t i = 0; i < civilizaciones.size(); i++)
    {
        if (v == civilizaciones[i].getNombre())
        {
            civilizaciones.erase(civilizaciones.begin() + i);
            return;
        }
    }
    cout << "Elemento no encontrado" << endl;
}

void VideoGame::mostrar()
{
    cout << "TABLA CIVILIZACIONES" << endl;
    cout << left;
    cout << setw(15) << "Nombre";
    cout << setw(13) << "Ubicacion X";
    cout << setw(13) << "Ubicacion Y";
    cout << setw(10) << "Puntuacion";
    cout << endl;
    for (size_t i = 0; i < civilizaciones.size(); i++)
    {
        Civilizacion &c = civilizaciones[i];
        cout << c;
    }
}

Civilizacion *VideoGame::buscar(const Civilizacion &c)
{
    auto it = find(civilizaciones.begin(), civilizaciones.end(), c);
    if (it == civilizaciones.end())
    {
        return nullptr;
    }
    else
    {
        return &(*it);
    }
}

void VideoGame::menuAldeano()
{
    if (civilizaciones.empty())
    {
        cout << "No hay Civilizaciones" << endl;
    }
    else
    {
        while (true)
        {
            cout << "CIVILIZACIONES DISPONIBLES" << endl;
            for (size_t i = 0; i < civilizaciones.size(); i++)
            {
                Civilizacion &civilizacion = civilizaciones[i];
                cout << i + 1 << ") ";
                cout << civilizacion.getNombre() << endl;
            }
            cout << "0) Salir" << endl;
            cout << "Opcion: ";
            size_t ops;
            cin >> ops;
            cin.ignore();
            if (ops > civilizaciones.size())
            {
                cout << "Opcion no valida" << endl;
            }
            else if (ops != 0)
            {
                Civilizacion &civilizacion = civilizaciones[ops - 1];
                menu(civilizacion);
            }
            else{
                break;
            }
            cout << endl;
        }
    }
}

size_t VideoGame::size()
{
    return civilizaciones.size();
}

void VideoGame::respaldar(){
    ofstream archivo("civilizaciones.txt");
    if(archivo.is_open()){
        for(size_t i = 0; i < civilizaciones.size(); i++){
            Civilizacion &c = civilizaciones[i];
            archivo << c.getNombre() << endl;
            c.respaldarAldeanos();
        }
    }
    archivo.close();
}

void VideoGame::recuperar(){
    ifstream archivo("civilizaciones.txt");
    if(archivo.is_open()){
        string temp;
        while(true){
            Civilizacion c;
            getline(archivo,temp);
            if(archivo.eof()){
                break;
            }
            c.setNombre(temp);
            c.recuperarAldeanos();
            agregarFinal(c);
        }
    }
    archivo.close();
}