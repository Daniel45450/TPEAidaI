#ifndef LISTA_H
#define LISTA_H

#include<iostream>
using namespace std;
template <typename T>

class Lista
{
    public:
        Lista(); //O(1), Operacion de creacion
        virtual ~Lista(); //O(1) operacion de destruccion
        void Agregar(const T& Ele); //O(1), agrega el elemento en la raiz de la lista, no se recorre la lista
        void Imprimir(); //operacion de debugging
        void Eliminar(const T& Elemento); //O(N), se recorre la lista hasta hallar el elemento a eliminar
        T getRaiz(); //O(1), se accede a la raiz y se devuelve
        bool Vacia(); //O(1), se fija si la raiz esta vacia
        bool ExisteElemento(const T& Elemento); //O(N) se recorre la lista hasta hallar el elemento

    protected:

    private:
        struct nodo
        {
            T Elemento;
            nodo * Siguiente;
        };
        nodo * Raiz;
};

#endif // LISTA_H
