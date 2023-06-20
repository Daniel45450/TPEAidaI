#include "Persona.h"

Persona::Persona(){};

Persona::Persona(string nombre, string apellido, string pais, int edad)
{
    this->nombre = nombre;
    this->apellido = apellido;
    this->pais = pais;
    this->edad = edad;
}

string Persona::getNombre() const
{
    return this->nombre;
}

string Persona::getApellido() const
{
    return this->apellido;
}

string Persona::getPais() const
{
    return this->pais;
}

int Persona::getEdad() const
{
    return this->edad;
}

void Persona::setNombre(string nombre)
{
    this->nombre = nombre;
}

void Persona::setApellido(string apellido)
{
    this->apellido = apellido;
}

void Persona::setPais(string pais)
{
    this->pais = pais;
}

Persona::~Persona() {};
