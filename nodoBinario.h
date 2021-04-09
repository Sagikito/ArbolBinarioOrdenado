#pragma once

#include <queue>
using namespace std;

template <typename T>
struct nodoBinario
{
    //dato
    T dato;
    nodoBinario<T>* izq;
    nodoBinario<T>* der;

    //constructor
    nodoBinario();
    
    //destructor
    ~nodoBinario();

    //operaciones

    //obtencion y cambio de informacion
    T obtenerDato();
    void cambiarDato(T nuevo);

    nodoBinario<T>* hijoIzq();
    nodoBinario<T>* hijoDer();
    
    void cambiarIzq(nodoBinario<T>* nuevoIzq);
    void cambiarDer(nodoBinario<T>* nuevoDer);

    //saber si es hoja
    bool esHoja();
    //informacion numerica
    int N_tamano();
    int N_altura();

    //operaciones fundamentales
    bool N_buscar(T dato_buscado);
    bool N_insertar(T nuevoDato);
    bool N_eliminar(T dato_a_eliminar);

    //recorridos
    void N_preOrden();
    void N_inOrden();
    void N_posOrden();
    void N_niveles();
};

//Esto se me hace muy muy extranno, revisar si se puede quitar
#include "nodoBinario.hxx"