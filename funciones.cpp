#include <iostream>
#include "Cancion.h"
#include "ListaGeneros.h"
#include <fstream>
using namespace std;
void quickSort(Cancion *& arr, int posInicial, int posfinal);
void quickSortAnios(Cancion ** arr, int posInicial, int posfinal);

void quitarAcentos(string & cadena);
enum resultado {Menor, Coincide, Mayor};

resultado filtrar(string &cadena, string buscar)
{
    //string cadena = "Hola Chau Adios Buenas";
    //string buscar = "Hola * * * * *";
    quitarAcentos(cadena);
    quitarAcentos(buscar);
    resultado a = Coincide;
    int i=0, k=0;
    while(i< cadena.length() && k <  buscar.length() &&  (a == Coincide)) {
        if(cadena[i] == buscar[k]) {
            i++;
            k++;
        }
        else {
            if(buscar[k]== '?') {
                i++;
                k++;
            }
            else {
                if(buscar[k] == '*') {
                    while(cadena[i] != ' ')
                    {
                        i++;
                    }
                    k++;
                }
                else {
                    if (cadena[i] < buscar[k])
                        a = Mayor;
                    else if (cadena[i] > buscar[k])
                        a = Menor;
                }

            }
        }
    }
    return a;

}

Cancion * busquedaBinaria(Cancion * & arreglo, int inferior, int superior, string buscar)
{
    int mitad;
    resultado valor;
    bool encontrado = false;

    do {
     mitad = (inferior + superior)/2;
     string aux = arreglo[mitad].getTitulo();
     valor = filtrar(aux, buscar);


     if(valor == Mayor) {  //si es menor, me quedo con la mitad derecha
        inferior = mitad+1;
     }

     if(valor == Coincide) {
        encontrado = true;
     }

     if(valor == Menor) {
        superior = mitad -1;
     }
    }
    while(inferior <= superior && !encontrado);

    if(encontrado) {
        return &arreglo[mitad];
    }
    else
        return &arreglo[mitad];
}

void quitarAcentos(string & cadena)
{
    for(int i=0; i<cadena.length(); i++)
    {
        char caracter = cadena[i];
        switch (caracter)
        {
        case 'á':
            caracter = 'a';
            break;
        case 'é':
            caracter = 'e';
            break;
        case 'í':
            caracter = 'i';
            break;
        case 'ó':
            caracter = 'o';
            break;
        case 'ú':
            caracter = 'u';
            break;
        case 'Á':
            caracter = 'A';
            break;
        case 'É':
            caracter = 'E';
            break;
        case 'Í':
            caracter = 'I';
            break;
        case 'Ó':
            caracter = 'O';
            break;
        case 'Ú':
            caracter = 'U';
            break;
        }
        cadena[i] = caracter;
    }
}

Cancion * procesar_archivo_entrada(string origen, int &CantCanciones)
{
    ifstream archivo(origen);
    if (!archivo.is_open())
        cout << "No se pudo abrir el archivo: " << origen << endl;
    else {
        string linea;
        getline(archivo, linea);
        int cantidad_canciones = atoi(linea.c_str());
        //cout << "Se cargarán " << cantidad_canciones << " canciones." << endl;

        Cancion * canciones = new Cancion[cantidad_canciones];

       // Cancion * canciones[cantidad_canciones];

        //Leemos de una linea completa por vez (getline).
        int idCancion = 0;
        while (getline(archivo, linea)) {

            //Primer posición del separador ;
            int pos_inicial = 0;
            int pos_final = linea.find(',');


            //cout << idCancion << endl;

            //Informacion entre pos_inicial y pos_final
            string interprete = linea.substr(pos_inicial, pos_final);

            //Segunda posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            string nombreCancion = linea.substr(pos_inicial, pos_final - pos_inicial);

            //Tercera posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            int duracion = atoi(linea.substr(pos_inicial, pos_final - pos_inicial).c_str());

            //Cuarta posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            int anio = atoi(linea.substr(pos_inicial, pos_final - pos_inicial).c_str());

            //Quinta posición del separador ;
             //LISTA de GENEROS
            pos_inicial = pos_final + 1;
            pos_final = linea.find(',', pos_inicial);
            string lst_generos = linea.substr(pos_inicial, pos_final - pos_inicial);
            //Sexta posición del separador ;
            pos_inicial = pos_final + 1;
            pos_final = linea.find(';', pos_inicial);
            int reproducciones = atoi(linea.substr(pos_inicial, pos_final - pos_inicial).c_str());

            string generos = lst_generos.substr(1, lst_generos.size()-2);





            // el siguiente código de prueba separa los diferentes géneros en un arreglo de 10 posiciones


            Lista<string> Listita;
            //string listaGeneros[10];
            int pos_inicial_generos = 0, pos_final_generos = 0;
            int nroGenero = 0;
            while (pos_final_generos != -1) {
                pos_final_generos = generos.find('|', pos_inicial_generos);
                Listita.Agregar(generos.substr(pos_inicial_generos, pos_final_generos - pos_inicial_generos));
                //listaGeneros[nroGenero] = generos.substr(pos_inicial_generos, pos_final_generos - pos_inicial_generos);
                pos_inicial_generos = pos_final_generos + 1;
                nroGenero++;
            }

            //for (int i=0; i<10; i++){
            //  cout << "   GENERO " <<i<<": " << listaGeneros[i] <<endl;
            //}
            Cancion cancion(idCancion, anio, duracion, reproducciones, Listita, nombreCancion);
            canciones[idCancion] = cancion;
            //canciones[idCancion].getGeneros().ImprimirGeneros();
            idCancion++;
        }
        CantCanciones = cantidad_canciones;

        quickSort(canciones, 0, cantidad_canciones-1);
        return canciones;
    }

}

void imprimirArreglo(Cancion * & canciones, int tamano)
{
    for(int i=0; i< tamano; i++) {
        cout << canciones[i].getTitulo() << endl;
    }
}

Cancion ** CancionesPorAnio(Cancion * &canciones, int CantCanciones){
    Cancion ** PorAnio = new Cancion*[CantCanciones];
    for (int i = 0; i<CantCanciones; i++){
        PorAnio[i] = &canciones[i];
    }
    quickSortAnios(PorAnio, 0, CantCanciones-1);
    return PorAnio;
}


int * CrearArregloIndices(Cancion ** &PorAnio, int CantCanciones, int &TamanioArregloIndices){
    int aniosdistintos = 0;
    Lista<int> ListaIndices;
    ListaIndices.Agregar(0);
    for (int i = 0; i<CantCanciones-1; i++){
        if (PorAnio[i]->getAnio() != PorAnio[i+1]->getAnio()){
            aniosdistintos++;
            ListaIndices.Agregar(i+1);
        }

    }
    int * ArregloIndices = new int[aniosdistintos+1];
    int i = aniosdistintos;

    while (ListaIndices.Vacia() == false){
        ArregloIndices[i] = ListaIndices.getRaiz();
        ListaIndices.Eliminar(ArregloIndices[i]);
        i--;
    }

    TamanioArregloIndices = aniosdistintos;
    return ArregloIndices;
}



Lista<Cancion*> busquedaNormal(Cancion ** & PorAnios, int * ArregloIndices, int TamanioArregloIndices, int CantCanciones, int rangoincio, int rangofin)
{
    Lista<Cancion *> listaReturn;
    int i = 0;
    while ((i <= TamanioArregloIndices) && (PorAnios[ArregloIndices[i]]->getAnio() <= rangofin)){
        if (PorAnios[ArregloIndices[i]]->getAnio() >= rangoincio){
            if (i != TamanioArregloIndices)
                for (int a = ArregloIndices[i]; a < ArregloIndices[i+1]; a++){
                    listaReturn.Agregar(PorAnios[a]);
                }

            else
                for (int a = ArregloIndices[i]; a < CantCanciones; a++){
                    listaReturn.Agregar(PorAnios[a]);
        }
        }
        i++;
    }
    return listaReturn;
}

void menu() {
    cout << "|--------------------------------------------------|" << endl;
    cout<< "|---------- Plataforma de musica digital ----------| " << endl;
    cout << "|                                                  |" << endl;
    cout << "|Servicios incluidos                               |" <<endl;
    cout << "| 1) Buscar cancion                                |" << endl;
    cout << "| 2) Buscar canciones por rango de anios           |" <<endl;
    cout << "| 3) Las 10 canciones mas escuchada de un genero   |" << endl;
    cout << "| 4) Salir                                         |"<< endl;
    cout << "|                                                  |" << endl;
    cout << "|--------------------------------------------------|" << endl;
    cout << "\n";
    cout << "Ingresa una opcion: ";
}

Cancion * servicio1(Cancion * &canciones, int CantCanciones){
    string buscar;
    cout << "Intoduzca el nombre de la cancion que desea buscar" << endl;
    cin.ignore();
    std::getline(cin, buscar);
    Cancion * cancion = busquedaBinaria(canciones, 0,CantCanciones - 1,buscar);
    return cancion;
}

Lista<Cancion*> servicio2(Cancion ** & ArregloPorAnio, int * ArregloIndices, int TamanioArregloIndices, Cancion * &canciones, int CantCanciones){
    int rangoinicio;
    int rangofin;
    cout << "introduzca el valor inicial" << endl;
    cin >> rangoinicio;
    cout << "introduzca el valor final" << endl;
    cin >> rangofin;
    if (rangoinicio > rangofin){
        int aux = rangoinicio;
        rangoinicio = rangofin;
        rangofin = aux;
    }
    Lista<Cancion*> ListaDeCanciones = busquedaNormal(ArregloPorAnio, ArregloIndices, TamanioArregloIndices, CantCanciones, rangoinicio, rangofin);

    return ListaDeCanciones;
}


Cancion ** Servicio3(ListaGeneros &Lista_De_Generos){
    string genero; //O(1)
    cout << "Usted desea hallar el top 10 de canciones de: " << endl; //O(1)
    cin >> genero; //O(1)

    Cancion ** CancionesServicio3 = Lista_De_Generos.Buscar(genero); //O(N)
    if (CancionesServicio3 != NULL){ //O(1)
        int i = 0; //O(1)
        while ((i < 10) && (CancionesServicio3[i] != NULL)){ //O(10)
            cout << CancionesServicio3[i]->getTitulo() << endl; //O(1)
            i++; //O(1)
        }
        return CancionesServicio3; //O(1)
    }
    else //O(1)
        cout << "no se encontraron canciones que contengan el genero especificado" << endl; //O(1)
}
