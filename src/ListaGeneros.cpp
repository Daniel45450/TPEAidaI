#include "ListaGeneros.h"
#include "Cancion.h"
#include <iostream>

ListaGeneros::ListaGeneros()
{
    this->Raiz = NULL;
}



void ListaGeneros::Agregar(Cancion &NuevaCancion)
{

    nodo * aux = this->Raiz;
    Lista<string> GenerosAux = NuevaCancion.getGeneros();

    while (aux != NULL)
        {
        if (NuevaCancion.getGeneros().ExisteElemento(aux->Genero)) //si el genero que representa este nodo de la lista es uno de los generos de la cancion, la tratamos
            {
            InsertarEnArreglo(NuevaCancion, aux->Arreglo);
            GenerosAux.Eliminar(aux->Genero);
            }
        aux = aux->Siguiente;
        }
    while (GenerosAux.Vacia() == false)
        {
        string GeneroAux = GenerosAux.getRaiz();
        nodo * aux2 = new nodo;
        aux2->Genero = GeneroAux;
        aux2->Arreglo[0] = &NuevaCancion;
        for (int i = 1; i<10; i++){
            aux2->Arreglo[i] = NULL;
        }
        aux2->Siguiente = this->Raiz;
        this->Raiz = aux2;
        GenerosAux.Eliminar(GeneroAux);
        }
}

void ListaGeneros::ImprimirGeneros()
{
    nodo * aux = this->Raiz;
    while (aux != NULL){
        cout << aux->Genero << endl;
        for(int i=0; i<=9; i++){
            if(aux->Arreglo[i] != NULL){
                cout << aux->Arreglo[i]->getReproducciones() << endl;
            }
        }
        aux = aux->Siguiente;
        }
    }

void ListaGeneros::InsertarEnArreglo(Cancion &NuevaCancion, Cancion * (&arreglo)[10])
{
    int i = 9;
    while ((i>=0) && ((arreglo[i] == NULL) or (arreglo[i]->getReproducciones() < NuevaCancion.getReproducciones()))){
        if (i != 0){
            arreglo[i] = arreglo[i-1];
        }
        i--;
    }
    if (i < 9)
        arreglo[i+1] = &NuevaCancion;
}

Cancion ** ListaGeneros::Buscar(string buscar){
    nodo * aux = this->Raiz;
    while (aux != NULL)
        {
        if (aux->Genero == buscar)
            {
            return aux->Arreglo;
            }
        aux = aux->Siguiente;
        }
    return NULL;
}

ListaGeneros::~ListaGeneros()
{
    //dtor
}
