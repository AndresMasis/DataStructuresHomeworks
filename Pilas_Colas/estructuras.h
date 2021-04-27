#include <cstdlib>
#include <iostream>

using namespace std;

// estructura nodo para lista simple
struct Nodo {
       string dato; // parte de datos
       Nodo* siguiente;// puntero para enlazar nodos
       // constructor

       Nodo(string d) {
           dato = d; // asigna los datos
           siguiente = NULL; // sig es null
       }

       void imprimir();
};


struct Pila {
       // Campos
       Nodo *tope; // solo con pN es suficiente

       // Constructor
       Pila(){
           tope = NULL;
       }
       
       // encabezados de funcion
       void push (string dato);
       Nodo* pop ();
       Nodo* peek();
       bool empty();
       void imprimir();
};


struct AlgoritmoTarea{
    //campos
    string entradaTeclado;
    Pila * pilaPrimerAlgoritmo;

    //Constructor
    AlgoritmoTarea(){
        entradaTeclado  = "";
        pilaPrimerAlgoritmo = new Pila();
    }

    //funciones
    void pedirDatosUsuario();
    bool esNumero(char dato);
    bool esOperador(char dato);
    bool encontrarCaracter(char dato);
    bool validarEntradaTeclado();
    short prioridadOperador(char dato);
    bool compararPrioridades(char operadorActual, char ultimoOperadorPila);
    char encontrarUltimoOperadorPila(Pila * pila);
    string armarNumero();
    void infijasPosfijas();
    double calcularResultado(Pila * posfija);
    void final();
};




