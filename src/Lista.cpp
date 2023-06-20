#include "Lista.h"
#include "Cancion.h"
#include <iostream>




template <typename T> Lista<T>::Lista()
{
    this->Raiz = NULL;
}



template <typename T> Lista<T>::~Lista()
{
    //dtor
}


template <typename T> void Lista<T>::Agregar(const T& Ele)
{
    nodo * Aux = new nodo;
    Aux->Elemento = Ele;
    Aux->Siguiente = Raiz;
    this->Raiz = Aux;
}

template <typename T> void Lista<T>::Imprimir()
{
    nodo * aux = this->Raiz;
    while (aux != NULL)
        {
        aux = aux->Siguiente;
        }
}

template <typename T> void Lista<T>::Eliminar(const T& Elemento)
{
    if (Vacia() == false)
        {
        nodo * aux = this->Raiz;
        if (this->Raiz->Elemento == Elemento)
            {
            nodo * aux2 = this->Raiz;
            this->Raiz = this->Raiz->Siguiente;
            delete aux2;
            }
        else
            {
            while(aux->Siguiente != NULL)
                {
                if (aux->Siguiente->Elemento == Elemento)
                    {
                    nodo * aux2 = aux->Siguiente;
                    aux->Siguiente = aux->Siguiente->Siguiente;
                    delete aux2;
                    }
                if (aux->Siguiente != NULL)
                    {
                    aux = aux->Siguiente;
                    }
                }
            }
        }
}

template <typename T> T Lista<T>::getRaiz()
{
    return (this->Raiz->Elemento);
}

template <typename T> bool Lista<T>::Vacia()
{
    if (this->Raiz == NULL)
        {
        return true;
        }
    else
        {
        return false;
        }
}


template <typename T> bool Lista<T>::ExisteElemento(const T& Elemento)
{
    nodo * aux = this->Raiz;
    while (aux != NULL)
        {
        if (aux->Elemento == Elemento)
            {
            return true;
            }
        aux = aux->Siguiente;
        }
    return false;
}

template class Lista<string>;
template class Lista<int>;
template class Lista<Cancion *>;
