#include <iostream>
#include <Cancion.h>
#include <Lista.h>
#include <ListaGeneros.h>
#include <fstream>
#include <clocale>


using namespace std;
void menu();
Cancion * servicio1(Cancion * &canciones, int CantCanciones);
Lista<Cancion*> servicio2(Cancion ** & ArregloPorAnio, int * ArregloIndices, int TamanioArregloIndices, Cancion * &canciones, int CantCanciones);
Cancion ** Servicio3(ListaGeneros &Lista_De_Generos);

int * CrearArregloIndices(Cancion ** &PorAnio, int CantCanciones, int &ArregloIndices);
Cancion ** CancionesPorAnio(Cancion * &canciones, int CantCanciones);
Cancion * procesar_archivo_entrada(string origen, int &CantCanciones);
Lista<Cancion*> busquedaNormal(Cancion ** & PorAnios, int * ArregloIndices, int TamanioArregloIndices, int CantCanciones, int rangoincio, int rangofin);
void imprimirArreglo(Cancion * & canciones, int tamano);
int filtrar(string &cadena, string buscar);
Cancion * busquedaBinaria(Cancion * & arreglo, int inferior, int superior, string buscar);




int main()
{
    int CantCanciones = 0;
    ListaGeneros Lista_De_Generos;
    Cancion * canciones = procesar_archivo_entrada("canciones.csv", CantCanciones);
    string buscar = "Walking in Memphis";
    Cancion * cancion = busquedaBinaria(canciones, 0,CantCanciones - 1,buscar);
    Cancion ** ArregloPorAnio = CancionesPorAnio(canciones, CantCanciones);
    int TamanioArregloIndices;
    int * ArregloIndices = CrearArregloIndices(ArregloPorAnio, CantCanciones, TamanioArregloIndices);

    for (int i=0; i<=CantCanciones-1; i++)
        {
        Lista_De_Generos.Agregar(canciones[i]);
        }
    int opcion;
    do{
        menu();
        cin >> opcion;
        switch(opcion){
        case 1:{
            Cancion * cancionServicio1 = servicio1(canciones, CantCanciones);
            if (cancionServicio1 == NULL)
                cout << "No se encontro la cancion, pruebe otro nombre" << endl;
            else
                cout << (cancionServicio1->getTitulo()) << endl;
        }break;
        case 2:{
            Lista<Cancion*> ListaServicio2 = servicio2(ArregloPorAnio, ArregloIndices, TamanioArregloIndices, canciones, CantCanciones);
            while (ListaServicio2.Vacia() == false){ //Esto es solo para debugging, no estaria en el release del programa
                cout << ListaServicio2.getRaiz()->getTitulo() << endl;
                ListaServicio2.Eliminar(ListaServicio2.getRaiz());
            }
        }break;
        case 3:{
            Cancion ** ArregloServicio3 = Servicio3(Lista_De_Generos);
        }break;
        }
    }
    while (opcion != 4);

    Lista<Cancion*> listaaaaa = busquedaNormal(ArregloPorAnio, ArregloIndices, TamanioArregloIndices, CantCanciones, 1990, 2000);



    //Lista_De_Generos.ImprimirGeneros();
    //Lista<Cancion *> ListaGeneros = CrearListaGenero(canciones);
   /* for (int i = 0; i<10; i++)
        {
        //ListaGeneros.ImprimirGeneros();
        }*/

    delete []ArregloPorAnio;
    delete []canciones;
    return 0;
}







