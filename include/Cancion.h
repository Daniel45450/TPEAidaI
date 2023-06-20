#ifndef CANCION_H
#define CANCION_H
#include <iostream>
#include <Lista.h>

using namespace std;

class Cancion
{
    public:
        Cancion();
        Cancion(int id, int anio, int duracion, int reproducciones, Lista<string> generos, string titulo);
        int getId() const;
        string getTitulo() const;
        int getAnio() const;
        int getDuracion() const;
        int getReproducciones() const;
        Lista<string> getGeneros() const;
        void setId(int n);
        void setAnio(int n);
        void setDuracion(int n);
        void setReproducciones(int n);
        virtual ~Cancion();

    protected:

    private:
        int id, anio, duracion, reproducciones;
        string titulo;
        Lista<string> generos;
        // interprete
};

#endif // CANCION_H

