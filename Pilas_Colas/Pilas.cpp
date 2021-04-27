
#include "estructuras.h"

bool Pila::empty () {
    if (tope == NULL)
        return true;
    else
        return false;
}


void Pila::push (string dato) {
     // Revisa si hay elementos
     if (empty()) {
         tope = new Nodo(dato);

     } else {
         Nodo *nuevo = new Nodo(dato);
         nuevo->siguiente = tope;
         tope = nuevo;
     }
}


/* Funcion que elimina el primer elemento de las lista
   Retorna el puntero al primer nodo. No se libera memoria*/
Nodo* Pila::pop() {
      if (empty())
         return NULL;

      else{
          Nodo* borrado = tope;
          tope = tope->siguiente;
          borrado->siguiente = NULL;
          return borrado;
      }
}


Nodo * Pila::peek(){
     return tope;
}


void Pila::imprimir(){
    if(empty())
        cout<<endl<<"Pila vacia"<<endl<<endl<<endl;
    else {
        cout <<endl<< "tope = ";
        Nodo *tmp = tope;

        while (tmp != NULL) {
            cout << tmp->dato << " -> ";
            tmp = tmp->siguiente;
        }
        cout << "--fondo--" << endl << endl<<endl;
    }
}

