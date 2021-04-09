#pragma once
#include "nodoBinario.h"

template <typename T>
struct arbinord
{
    //dato
    nodoBinario<T>* raiz;

    //constructor
    arbinord();
    
    //destructor
    ~arbinord();

    //obtencion y cambio de informacion
    T datoRaiz();

    //saber si es vacio 
    bool esVacio();

    //informacion numerica
    int A_tamano();
    int A_altura();

    //operaciones fundamentales
    bool A_buscar(T datob);
    bool A_insertar(T nuevoDato);
    bool A_eliminar(T dato_a_eliminar);

    //recorridos
    void A_preOrden();
    void A_inOrden();
    void A_posOrden();
    void A_niveles();
};

//esto sigue siendo muy extraño, revisar si se puede no hacer
#include "arbinord.hxx"