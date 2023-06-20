#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>

using namespace std;


class Persona
{
    public:
        Persona();
        Persona(string nombre, string apellido, string pais, int edad);
        string getNombre() const;
        string getApellido() const;
        string getPais() const;
        int getEdad() const;
        void setNombre(string nombre);
        void setApellido(string apellido);
        void setPais(string pais);

        virtual ~Persona();

    protected:

    private:
        string nombre,apellido,pais;
        int edad;
};

#endif // PERSONA_H
