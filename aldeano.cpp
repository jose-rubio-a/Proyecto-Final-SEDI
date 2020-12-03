#include "aldeano.h"

void Aldeano::setNombre(const string &nombre){
    this->nombre = nombre;
}

void Aldeano::setEdad(size_t edad){
    this->edad = edad;
}

void Aldeano::setGenero(const string &genero){
    this->genero = genero;
}

void Aldeano::setSalud(size_t salud){
    this->salud = salud;
}

string Aldeano::getNombre() const{
    return nombre;
}

size_t Aldeano::getEdad() const{
    return edad;
}

string Aldeano::getGenero() const{
    return genero;
}

size_t Aldeano::getSalud() const{
    return salud;
}
