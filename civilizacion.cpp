#include "civilizacion.h"

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