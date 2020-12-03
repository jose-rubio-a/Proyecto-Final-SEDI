#ifndef ALDEANO_H
#define ALDEANO_H

#include <iostream>
#include <iomanip>
using namespace std;

class Aldeano{
    private:
        string nombre;
        size_t edad;
        string genero;
        size_t salud;
    public:
        Aldeano() {};
        Aldeano(const string &nombre, size_t edad, const string &genero, size_t salud = 100)
        : nombre(nombre), edad(edad), genero(genero), salud(salud) {}

        void setNombre(const string &nombre);
        void setEdad(size_t edad);
        void setGenero(const string &genero);
        void setSalud(size_t salud);

        string getNombre() const;
        size_t getEdad() const;
        string getGenero() const;
        size_t getSalud() const;

        friend ostream& operator<<(ostream &out, const Aldeano &a){
            out << left;
            out << setw(12) << a.nombre;
            out << setw(7) << a.edad;
            out << setw(12) << a.genero;
            out << setw(7) << a.salud;
            return out;
        }

        friend istream& operator>> (istream &in, Aldeano &a){
            cout << "Nombre del aldeano: ";
            getline(cin, a.nombre);
            cout << "Edad: ";
            cin >> a.edad; cin.ignore();
            cout << "Genero: ";
            getline(cin, a.genero);
            cout << "Salud: ";
            cin >> a.salud; cin.ignore();

            return in;
        }

        bool operator<(const Aldeano &a){
            return nombre < a.getNombre();
        }
        bool operator==(const Aldeano &a){
            return nombre == a.nombre;
        }
        bool operator==(const Aldeano &a) const{
            return nombre == a.nombre;
        }
};

#endif