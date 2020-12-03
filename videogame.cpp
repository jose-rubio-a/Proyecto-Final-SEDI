#include "videogame.h"
#include <algorithm>

VideoGame::VideoGame() {}

void VideoGame::setNombreUsuario(const string &s){
    nombreUsuario = s;
}

string VideoGame::getNombreUsuario(){
    return nombreUsuario;
}

void VideoGame::agregarFinal(const Civilizacion &c){
    civilizaciones.push_back(c);
}

void VideoGame::insertar(const Civilizacion &c, size_t p){
    civilizaciones.insert(civilizaciones.begin()+p,c);
}

void VideoGame::inicializar(const Civilizacion &c, size_t n){
    civilizaciones = vector<Civilizacion>(n,c);
}

Civilizacion VideoGame::front(){
    return civilizaciones.front();
}

Civilizacion VideoGame::back(){
    return civilizaciones.back();
}

void VideoGame::ordenarNombre(){
    sort(civilizaciones.begin(),civilizaciones.end()
    ,[](Civilizacion c1, Civilizacion c2){return c1.getNombre() < c2.getNombre();});
}
void VideoGame::ordenarUbicacionX(){
    sort(civilizaciones.begin(),civilizaciones.end()
    ,[](Civilizacion c1, Civilizacion c2){return c1.getUbicacionX() < c2.getUbicacionX();}); 
}
void VideoGame::ordenarUbicacionY(){
    sort(civilizaciones.begin(),civilizaciones.end()
    ,[](Civilizacion c1, Civilizacion c2){return c1.getUbicacionY() < c2.getUbicacionY();}); 
}
void VideoGame::ordenarPuntuacion(){
    sort(civilizaciones.begin(),civilizaciones.end()
    ,[](Civilizacion c1, Civilizacion c2){return c1.getPuntuacion() > c2.getPuntuacion();}); 
}

void VideoGame::eliminar(const string &v){
    for(size_t i = 0; i < civilizaciones.size(); i++){
        if(v == civilizaciones[i].getNombre()){
            civilizaciones.erase(civilizaciones.begin()+i);
            return;
        }
    }
    cout << "Elemento no encontrado" << endl;
}

void VideoGame::mostrar(){
    cout << "TABLA CIVILIZACIONES" << endl;
    cout << left;
    cout << setw(15) << "Nombre";
    cout << setw(13) << "Ubicacion X";
    cout << setw(13) << "Ubicacion Y";
    cout << setw(10) << "Puntuacion";
    cout << endl;
    for(size_t i=0; i < civilizaciones.size();i++){
        Civilizacion &c = civilizaciones[i];
        cout << c;
    }
}

Civilizacion* VideoGame::buscar(const Civilizacion &c){
    auto it = find(civilizaciones.begin(),civilizaciones.end(),c);
    if(it == civilizaciones.end()){
        return nullptr;
    }
    else{
        return &(*it);
    }
}

size_t VideoGame::size(){
    return civilizaciones.size();
}