#ifndef LISTAGENEROS_H
#define LISTAGENEROS_H
#include <iostream>
#include<Cancion.h>

using namespace std;

class ListaGeneros
{
    public:
        ListaGeneros(); //O(1), es una operacion de creacion simple
        virtual ~ListaGeneros(); //O(1), es una operacion de destruccion simple
        void Agregar(Cancion &NuevaCancion); //O(1), agrega el elemento en la raiz de la lista, no se recorre la lista
        Cancion ** Buscar(string buscar); //O(N), en el peor de los casos se recorre hasta llegar al ultimo elemento
        void ImprimirGeneros(); //Operacion de debugging, no se usa en el programa final

    protected:

    private:
        struct nodo
        {
            string Genero;
            Cancion * Arreglo[10];
            nodo * Siguiente;
        };
        nodo * Raiz;
        void InsertarEnArreglo(Cancion &NuevaCancion, Cancion * (&arreglo)[10]); //O(M), se recorre el arreglo y se coloca en el lugar correspondiente
};

#endif // LISTAGENEROS_H
