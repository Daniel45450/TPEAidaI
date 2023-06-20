#include "Cancion.h"
#include <ListaGeneros.h>

Cancion::Cancion(int id, int anio, int duracion, int reproducciones, Lista<string> generos, string titulo)
{
        int i;
        this->id = id;
        this->anio = anio;
        this->duracion = duracion;
        this->reproducciones = reproducciones;
        this->generos = generos;
        this->titulo = titulo;
}

int Cancion::getId() const
{
    return this->id;
}

string Cancion:: getTitulo() const
{
    return this->titulo;
}

int Cancion::getAnio() const
{
    return this->anio;
}

int Cancion::getDuracion() const
{
    return this->duracion;
}

int Cancion::getReproducciones() const
{
    return this->reproducciones;
}

void Cancion::setId(int n)
{
    this->id = n;
}

void Cancion::setAnio(int n)
{
    this->anio = n;
}

void Cancion::setDuracion(int n)
{
    this->duracion = n;
}

void Cancion::setReproducciones(int n)
{
  this->reproducciones = n;
}

Lista<string> Cancion::getGeneros() const
{
    return this->generos;
}

Cancion::Cancion()
{
    //ctor
}

Cancion::~Cancion()
{
    //dtor
}
