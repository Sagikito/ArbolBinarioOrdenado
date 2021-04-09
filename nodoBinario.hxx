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
    //return (izq==NULL && der ==NULL)
}


//retorna el tamano del arbol cuya raiz es el nodo actual
template <typename T>
int nodoBinario<T>::N_tamano()
{
    if(esHoja)
        return 1;
    else
    {
        int tamhijos = 0;
        if(izq!=NULL)
            tamhijos += izq->N_tamano();
        if(der!=NULL)
            tamhijos += der->N_tamano();
        return 1 + tamhijos;
    }
}


//altura del subarbol con raiz en el nodo actual
template <typename T>
int nodoBinario<T>::N_altura()
{
    if(esHoja())
        return 0;

    //si no es hoja tiene al menos 1 hijo
    else
    {
        //si no tiene hijo izq tomamos el derecho
        if(izq==NULL)   
            return 1 + der->N_altura();
        
        //si no tiene hijo der tomamos el izquierdo
        else if(der == NULL)
            return 1 + izq->N_altura();

        //si tiene ambos hijos tomamos al de mayor altura
        else
        {
            if(izq->N_altura() > der->N_altura())
                return 1 + izq->N_altura();
            else
                return 1 + der->N_altura();
        }
    }
}


//OJO REVISAR PORQUE POR AHORA SOLO SIRVE CON NUMEROS Y LETRAS
//retorna verdadero si el dato buscado se encuentra
template <typename T>
bool nodoBinario<T>::N_buscar(T dato_buscado)
{
    if(this->dato == dato_buscado)
        return true;
    else
    {
        if(dato_buscado > dato && der != NULL)
            return der->N_buscar(dato_buscado);
        if(dato_buscado < dato && izq != NULL)
            return izq->N_buscar(dato_buscado);
        return false;
    }
}


//inserta un elemento, retorna falso si ya estaba en el árbol
template <typename T>
bool nodoBinario<T>::N_insertar(T nuevoDato)
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
            der->N_insertar(nuevoDato)
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
            izq->N_insertar(nuevoDato);
    }
    //REVISAR 2 COSAS: 1-CREO QUE NO TENGO QUE PONER OTRO RETURN FALSE PORQUE SIEMPRE SERIA VERDADERA LA INSERCION
    //y el unico caso en el que no es posible es en el que ya esta el dato en el arbol
    //2- lo de si hay que poner izq=NULL y der=NULL (que creo que no porque el constructor ya hace eso)    
}


//??????????????? FALTA!

//elimina un dato dentro del arbol, verdadero si estaba y lo elimino, falso si no estaba.
template <typename T>
bool nodoBinario<T>::N_eliminar(T dato_a_eliminar)
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
    else
    {
    //FALTA esta mas demorado de lo que esperaba
    }
}



//-----------------RECORRIDOS-----------------------------------------


//preorden del Arbol
template <typename T>
void nodoBinario<T>::N_preOrden()
{
    cout<<dato<<" ";
    if(izq != NULL)
        izq->N_preOrden();
    if(der != NULL)
        der->N_preOrden();
}


//inorden del Arbol
template <typename T>
void nodoBinario<T>::N_inOrden()
{
    if(izq != NULL)
        izq->N_inOrden();
    cout<<dato<<" ";
    if(der != NULL)
        der->N_inOrden();
}


//posorden del Arbol
template <typename T>
void nodoBinario<T>::N_posOrden()
{
    if(izq != NULL)
        izq->N_posOrden();
    if(der != NULL)
        der->N_posOrden();
    cout<<dato<<" ";
}


//para el de niveles la idea es trabajar con una fila que de el orden correcto de los nodos

// recorrido por niveles del Arbol
template <typename T>
void nodoBinario<T>::N_niveles()
{
    queue<nodoBinario<T>*> fila;
    //insertamos el nodo actual a la fila (como apuntador)
    fila.push(this);

    nodoBinario<T>* actual;

    while(!fila.empty())
    {
        actual = fila.front();
        cout<<actual->dato<<" ";
        if(actual->izq != NULL)
            fila.push(actual->izq)
        if(actual->der != NULL)
            fila.push(actual->der)
        fila.pop();
    }
}