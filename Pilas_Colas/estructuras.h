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
       void voltear();
       bool empty();
       void imprimir();
};


struct AlgoritmoTarea{
    //campos
    string entradaInfija;
    Pila * posfija;

    //Constructor
    AlgoritmoTarea(){
        entradaInfija  = "";
        posfija = new Pila();
    }

    //funciones
    void pedirDatosUsuario();
    bool esNumero(char dato);
    bool esOperador(char dato);
    bool encontrarCaracter(char dato);
    bool encontrarSiguiente(string parte);
    bool validarEntradaTeclado();
    short prioridadOperador(char dato);
    bool compararPrioridades(char operadorActual, char ultimoOperadorPila);
    string armarNumero();
    void infijasPosfijas();
    string calcularUltimo(string numero1, string numero2, char operador);
    double calcularResultado();
    void final();
};




