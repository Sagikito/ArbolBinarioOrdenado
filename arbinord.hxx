#include "arbinord.h"


//constructor, inicializa la raiz en nulo
template <typename T>
arbinord<T>::arbinord()
{
    raiz = NULL;
}


//destructor
template <typename T>
arbinord<T>::arbinord()
{
    delete raiz;
    raiz = NULL;
}


//retorna el dato de la raiz
template <typename T>
T arbinord<T>::datoRaiz()
{
    return raiz->dato;
}


//retorna verdadero si el arbol esta vacio
template <typename T>
bool arbinord<T>::esVacio()
{
    return raiz==NULL;
}


//retorna el numero de nodos en el arbol 
template <typename T>
int arbinord<T>::A_tamano()
{
    if(esVacio())
        return 0;
    else
        return raiz->N_tamano;
}


//retorna la altura del arbol
template <typename T>
int arbinord<T>::A_altura()
{
    if(esVacio())
        return -1;
    else
        return raiz->N_altura;
}


//busqueda de un dato en el arbol
template <typename T>
bool arbinord<T>::A_buscar(T datob)
{
    if(esVacio())
        return false;
    else
        return raiz->N_buscar(datob);
}


//insercion de un dato en el arbol
template <typename T>
bool arbinord<T>::A_insertar(T nuevoDato)
{
    return raiz->N_insertar(nuevoDato);
}


//SOLO FALTA ELIMINAR!

//preorden del arbol
template <typename T>
void arbinord<T>::A_preOrden()
{
    if(esVacio())
        cout<<"el arbol esta vacio!\n";
    else
        raiz->N_preOrden();
}


//inorden del arbol
template <typename T>
void arbinord<T>::A_inOrden()
{
    if(esVacio())
        cout<<"el arbol esta vacio!\n";
    else
        raiz->N_inOrden();
}


//posorden del arbol
template <typename T>
void arbinord<T>::A_posOrden()
{
    if(esVacio())
        cout<<"el arbol esta vacio!\n";
    else
        raiz->N_posOrden();
}


//impresion por niveles del arbol
template <typename T>
void arbinord<T>::A_niveles()
{
    if(esVacio())
        cout<<"el arbol esta vacio!\n";
    else
        raiz->N_niveles();
}