
#include <list>

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
    int tamano();
    int altura();

    //operaciones fundamentales
    bool buscar(T dato_buscado);
    bool insertar(T nuevoDato);
    bool eliminar(T dato_a_eliminar);

    //recorridos
    list<nodoBinario<T>> preOrden();
    list<nodoBinario<T>> inOrden();
    list<nodoBinario<T>> posOrden();
    list<nodoBinario<T>> niveles();
};