#ifndef VIDEOGAME_H
#define VIDEOGAME_H

#include "civilizacion.h"
#include <vector>

class VideoGame{
    private:
        string nombreUsuario;
        vector<Civilizacion> civilizaciones;
    public:
        VideoGame();

        void setNombreUsuario(const string &s);
        string getNombreUsuario();
        void agregarFinal(const Civilizacion &c);
        void insertar(const Civilizacion &c, size_t p);
        void inicializar(const Civilizacion &c, size_t n);
        Civilizacion front();
        Civilizacion back();
        void ordenarNombre();
        void ordenarUbicacionX();
        void ordenarUbicacionY();
        void ordenarPuntuacion();
        void eliminar(const string &v);
        Civilizacion* buscar(const Civilizacion &c);
        void menuAldeano();
        size_t size();
        void mostrar();
        void respaldar();
        void recuperar();
        friend VideoGame& operator<< (VideoGame &vg, Civilizacion &c){
            vg.agregarFinal(c);
            return vg;
        }
};

#endif