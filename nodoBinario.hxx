#include "nodoBinario.h"


//constructor de un nodoBinario
template <typename T>
nodoBinario<T>::nodoBinario()
{
    izq = NULL;
    der = NULL;
}


//destructor de un nodoBinario
template <typename T>
nodoBinario<T>::~nodoBinario()
{
    delete izq;
    //izq = NULL;?????????????????
    delete der;
    //der = NULL;??????????????????
}


//retorna el dato del nodoBinario
template <typename T>
T nodoBinario<T>::obtenerDato()
{
    return dato;
}


//cambia el dato del nodoBinario
template <typename T>
void nodoBinario<T>::cambiarDato(T nuevo)
{
    dato = nuevo;
}


//devuelve el hijo izquierdo
template <typename T>
nodoBinario<T>* nodoBinario<T>::hijoIzq()
{
    return izq;
}


//devuelve el hijo derecho
template <typename T>
nodoBinario<T>* nodoBinario<T>::hijoDer()
{
    return der;
}


//cambia a donde apunta el hijo izquierdo
template <typename T>
void nodoBinario<T>::cambiarIzq(nodoBinario<T>* nuevoIzq)
{
    //delete izq;????
    izq = nuevoIzq;
}


//cambia a donde apunta el hijo derecho 
template <typename T>
void nodoBinario<T>::cambiarDer(nodoBinario<T>* nuevoDer)
{
    //delete der;????
    der = nuevoDer;
}

//retorna verdadero si el nodo es hoja
template <typename T>
bool nodoBinario<T>::esHoja()
{
    if(izq != NULL || der != NULL)
        return false;
    return true;
}


//retorna el tamano del arbol cuya raiz es el nodo actual
template <typename T>
int nodoBinario<T>::tamano()
{
    if(esHoja)
        return 1;
    else
    {
        int tamhijos = 0;
        if(izq!=NULL)
            tamhijos += izq->tamano();
        if(der!=NULL)
            tamhijos += der->tamano();
        return 1 + tamhijos;
    }
}


//altura del subarbol con raiz en el nodo actual
template <typename T>
int nodoBinario<T>::altura()
{
    if(esHoja())
        return 0;

    //si no es hoja tiene al menos 1 hijo
    else
    {
        //si no tiene hijo izq tomamos el derecho
        if(izq==NULL)   
            return 1 + der->altura();
        
        //si no tiene hijo der tomamos el izquierdo
        else if(der == NULL)
            return 1 + izq->altura();

        //si tiene ambos hijos tomamos al de mayor altura
        else
        {
            if(izq->altura() > der->altura())
                return 1 + izq->altura();
            else
                return 1 + der->altura();
        }
    }
}


//OJO REVISAR PORQUE POR AHORA SOLO SIRVE CON NUMEROS Y LETRAS
//retorna verdadero si el dato buscado se encuentra
template <typename T>
bool nodoBinario<T>::buscar(T dato_buscado)
{
    if(this->dato == dato_buscado)
        return true;
    else
    {
        if(dato_buscado > dato && der != NULL)
            return der->buscar(dato_buscado);
        if(dato_buscado < dato && izq != NULL)
            return izq->buscar(dato_buscado);
        return false;
    }
}


//inserta un elemento, retorna falso si ya estaba en el árbol
template <typename T>
bool nodoBinario<T>::insertar(T nuevoDato)
{
    if(dato == nuevoDato)
        return false;
    
    if(nuevoDato > dato)
    {
        if(der == NULL)
        {
            nodoBinario<T>* nuevoNodo = new nodoBinario<T>; //revisar
            //nuevoNodo->izq = NULL; creo que estas dos lineas no hacen falta
            //nuevoNodo->der = NULL;
            nuevoNodo->dato = nuevoDato;
            der = nuevoNodo;
            return true;
        }
        else
            der->insertar(nuevoDato)
    }

    if(nuevoDato < dato)
    {
        if(izq == NULL)
        {
            nodoBinario<T>* nuevoNodo = new nodoBinario<T>;
            nuevoNodo->dato = nuevoDato;
            izq = nuevoNodo;
            return true;
        }
        else
            izq->insertar(nuevoDato);
    }
    //REVISAR 2 COSAS: 1-CREO QUE NO TENGO QUE PONER OTRO RETURN FALSE PORQUE SIEMPRE SERIA VERDADERA LA INSERCION
    //y el unico caso en el que no es posible es en el que ya esta el dato en el arbol
    //2- lo de si hay que poner izq=NULL y der=NULL (que creo que no porque el constructor ya hace eso)    
}


//elimina un dato dentro del arbol, verdadero si estaba y lo elimino, falso si no estaba.
template <typename T>
bool nodoBinario<T>::eliminar(T dato_a_eliminar)
{
    if(esHoja())
    {
        if(dato == dato_a_eliminar)
        {
            delete(this);
            return true;
        }
        else
            return false;
    }

}
