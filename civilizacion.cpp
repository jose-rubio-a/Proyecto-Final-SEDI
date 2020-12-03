#include "civilizacion.h"
#include <algorithm>

Civilizacion::Civilizacion(){}

Civilizacion::Civilizacion(const string &nombre, float ubicacionX, float ubicacionY, int puntuacion){
    this->nombre = nombre;
    this->ubicacionX = ubicacionX;
    this->ubicacionY = ubicacionY;
    this->puntuacion = puntuacion;
}

void Civilizacion::setNombre(const string &v){
    nombre = v;
}
void Civilizacion::setUbicacionX(float v){
    ubicacionX = v;
}
void Civilizacion::setUbicacionY(float v){
    ubicacionY = v;
}
void Civilizacion::setPuntuacion(int v){
    puntuacion = v;
}
string Civilizacion::getNombre(){
    return nombre;
}
float Civilizacion::getUbicacionX(){
    return ubicacionX;
}
float Civilizacion::getUbicacionY(){
    return ubicacionY;
}
int Civilizacion::getPuntuacion(){
    return puntuacion;
}

void Civilizacion::agregarFinal(const Aldeano &a){
    aldeanos.push_back(a);
    puntuacion += 100;
}

void Civilizacion::agregarInicio(const Aldeano &a){
    aldeanos.push_front(a);
    puntuacion += 100;
}

void Civilizacion::eliminarNombre(const string &nombre){
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        Aldeano &a = *it;
        if(nombre == a.getNombre()){
            aldeanos.erase(it);;
            return;
        }
    }
    cout << "Aldeano no encontrado" << endl;
}

void Civilizacion::eliminarSalud(size_t salud){
    aldeanos.remove_if([salud](const Aldeano &a){return a.getSalud() < salud;});
}

bool comparador(const Aldeano &a){
    return a.getEdad() >= 60;
}
void Civilizacion::eliminarEdad(){
    aldeanos.remove_if(comparador);
}

void Civilizacion::clasificarNombre(){
    aldeanos.sort();
}

bool comparadorEdad(const Aldeano &a1, const Aldeano &a2){
    return a1.getEdad() > a2.getEdad();
}
void Civilizacion::clasificarEdad(){
    aldeanos.sort(comparadorEdad);
}

void Civilizacion::clasificarSalud(){
    aldeanos.sort([](const Aldeano &a1, const Aldeano &a2){return a1.getSalud() > a2.getSalud();});
}

void Civilizacion::mostrar(){
    cout << left;
    cout << setw(12) << "Nombre";
    cout << setw(7) << "Edad";
    cout << setw(12) << "Genero";
    cout << setw(7) << "Salud";
    cout << endl;
    for(auto it = aldeanos.begin(); it != aldeanos.end(); it++){
        cout << *it << endl;
    }
}

Aldeano* Civilizacion::buscar(const Aldeano &a){
    auto it = find(aldeanos.begin(),aldeanos.end(),a);
    if(it == aldeanos.end()){
        return nullptr;
    }
    else{
        return &(*it);
    }
}

void Civilizacion::respaldarAldeanos(){
    ofstream archivo(getNombre() + ".txt");
    if(archivo.is_open()){
        for(auto it = aldeanos.begin(); it != aldeanos.end(); it++){
            Aldeano &a = *it;
            archivo << a.getNombre() << endl;
            archivo << a.getEdad() << endl;
            archivo << a.getGenero() << endl;
            archivo << a.getSalud() << endl;
        }
    }
    archivo.close();
}

void Civilizacion::recuperarAldeanos(){
    ifstream archivo(getNombre() + ".txt");
    if(archivo.is_open()){
        string temp;
        size_t e;
        Aldeano a;
        while (true)
        {
            getline(archivo,temp);
            if(archivo.eof()){
                break;
            }
            a.setNombre(temp);
            getline(archivo, temp);
            e = stoi(temp);
            a.setEdad(e);
            getline(archivo, temp);
            a.setGenero(temp);
            getline(archivo, temp);
            e = stoi(temp);
            a.setSalud(e);
            agregarFinal(a);
        }
    }
    archivo.close();
}