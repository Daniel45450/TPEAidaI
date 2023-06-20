
#include<stdio.h>
#include "Cancion.h"

//Intercambiar 2 elementos, en este caso canciones
void intercambiar(Cancion *& arreglo, int a , int b)
{
    Cancion aux = arreglo[a];
    arreglo[a]= arreglo[b];
    arreglo[b] = aux;
}

void intercambiarAnio(Cancion **& arreglo, int a , int b)
{
    Cancion * aux = arreglo[a];
    arreglo[a]= arreglo[b];
    arreglo[b] = aux;
}


int particion (Cancion *& arr, int posInicial, int posfinal)
{
    string pivote = arr[posInicial].getTitulo(); //Tomo como pivote el primer elemento
    int i = (posInicial + 1); // posInicial +1  para no comparar el pivote con el pivote.

    for (int j = i; j <= posfinal; j++)
    {
        //si mi arreglo en j es menor igual a mi pivote
        if (arr[j].getTitulo() < pivote)
        {
            intercambiar(arr, i, j);
            i++;
        }
    }
    intercambiar(arr, posInicial, i-1);
    return i-1;
}


int particionAnio (Cancion **& arr, int posInicial, int posfinal)
{
    int pivote = arr[posInicial]->getAnio(); //Tomo como pivote el primer elemento
    int i = (posInicial + 1); // posInicial +1  para no comparar el pivote con el pivote.

    for (int j = i; j <= posfinal; j++)
    {
        //si mi arreglo en j es menor igual a mi pivote
        if (arr[j]->getAnio() < pivote)
        {
            intercambiarAnio(arr, i, j);
            i++;
        }
    }
    intercambiarAnio(arr, posInicial, i-1);
    return i-1;
}

void quickSort(Cancion *& arr, int posInicial, int posfinal)
{
    if (posInicial < posfinal)
    {
        int pivote = particion(arr, posInicial, posfinal);
        quickSort(arr, posInicial, pivote - 1);
        quickSort(arr, pivote + 1, posfinal);
    }
}


void quickSortAnios(Cancion ** arr, int posInicial, int posfinal)
{
    if (posInicial < posfinal)
    {
        int pivote = particionAnio(arr, posInicial, posfinal);
        quickSortAnios(arr, posInicial, pivote - 1);
        quickSortAnios(arr, pivote + 1, posfinal);
    }
}
