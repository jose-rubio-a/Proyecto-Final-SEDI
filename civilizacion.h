#ifndef CIVILIZACION_H
#define CIVILIZACION_H

#include <iostream>
#include <iomanip>
using namespace std;

#include "aldeano.h"
#include <list>

class Civilizacion
{
private:
    string nombre;
    float ubicacionX;
    float ubicacionY;
    int puntuacion;
    list<Aldeano> aldeanos;
public:
    Civilizacion();
    Civilizacion(const string &nombre, float ubicacionX, float ubicacionY, int puntuacion);

    void setNombre(const string &v);
    void setUbicacionX(float v);
    void setUbicacionY(float v);
    void setPuntuacion(int v);

    string getNombre();
    float getUbicacionX();
    float getUbicacionY();
    int getPuntuacion();

    void agregarFinal(const Aldeano &a);
    void agregarInicio(const Aldeano &a);

    void eliminarNombre(const string &nombre);
    void eliminarSalud(size_t salud);
    void eliminarEdad();

    void clasificarNombre();
    void clasificarEdad();
    void clasificarSalud();

    void mostrar();

    Aldeano* buscar(const Aldeano &a);

   friend ostream& operator<<(ostream &out, const Civilizacion &c){
       out << left;
       out << setw(15) << c.nombre;
       out << setw(13) << c.ubicacionX;
       out << setw(13) << c.ubicacionY;
       out << setw(10) << c.puntuacion;
       out << endl;
       return out;
   }
   friend istream& operator>>(istream &in, Civilizacion &c){
       cout << "Nombre de la Civilizacion: ";
       getline(cin, c.nombre);
       cout << "Ubicacion en X: ";
       cin >> c.ubicacionX;
       cout << "Ubicacion en Y: ";
       cin >> c.ubicacionY;
       cout << "Puntuacion: ";
       cin >> c.puntuacion; cin.ignore();

       return in;
   }

    bool operator==(const Civilizacion &c){
        return nombre == c.nombre;
    }
    bool operator==(const Civilizacion &c) const{
        return nombre == c.nombre;
    }
};

#endif