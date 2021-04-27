//
// Created by Andrés on 22/4/2021.
//

#include "estructuras.h"

//Pide datos al usuario
void AlgoritmoTarea::pedirDatosUsuario() {
    cout<<"Dame una entrada de operacion (Entrada infija)"<<endl;
    getline(cin, entradaTeclado);
}


// Ve si un caracter es un operador
bool AlgoritmoTarea::esOperador(char dato) {
    string caracteresValidos = "()^*/+- ";
    if(caracteresValidos.find(dato) != std::string::npos)
        // Es un operador
        return true;
    else
        // No es un operador
        return false;
}


// Ve si un caracter es un numero
bool AlgoritmoTarea::esNumero(char dato) {
    string numeros = "1234567890";
    if(numeros.find(dato) != std::string::npos)
        // Es un numero
        return true;
    else
        // No es un numero
        return false;
}



// Ve si un caracter especifico es valido o no
bool AlgoritmoTarea::encontrarCaracter(char dato) {
    if (esOperador(dato) || esNumero(dato))
        // El caracter a comparar es valido
        return true;
    else
        // El caracter a comparar no es valido
        return false;
}


// Ve si la entrada del usuario es valido o ingresocaracteres invalidos
bool AlgoritmoTarea::validarEntradaTeclado() {
    for(int i = 0; i<entradaTeclado.length(); i++)
        // Recorre de caracter por caracter el string
        if (!encontrarCaracter(entradaTeclado[i])) {
            cout<<"Oops! El caracter "<<entradaTeclado[i]<<" no es valido"<<endl;
            return false;
        }

    return true;
}


short AlgoritmoTarea::prioridadOperador(char dato) {

    if(dato == '^')
        return 3;

    else if(dato == '*' || dato == '/')
        return 2;

    else if(dato == '+' || dato == '-')
        return 1;

    else if(dato == '(' || dato == ')')
        return 0;

    else
        return 4;
}


bool AlgoritmoTarea::compararPrioridades(char operadorActual, char ultimoOperadorPila){
    if(prioridadOperador(operadorActual) > prioridadOperador(ultimoOperadorPila))
        return true;
    else
        return false;
}

char AlgoritmoTarea::encontrarUltimoOperadorPila(Pila * pila) {
    if(pila->empty())
        return ' ';
    else {
        Nodo *temporal = pila->tope;
        while (temporal->siguiente != NULL) {
            if (esOperador(temporal->dato[0])) {
                return temporal->dato[0];
            }
            temporal = temporal->siguiente;
        }

        return ' ';
    }

}

string AlgoritmoTarea::armarNumero(){
    string numeroCreado = "";

    // Revisa los caracteres siguientes
    while(!entradaTeclado.empty()){
        if(!esNumero(entradaTeclado[0]))
            break;

        numeroCreado += entradaTeclado[0];
        // Evita que se encicle
        entradaTeclado.erase(0, 1); // Va disminuyendo el string de entrada
    }

    return numeroCreado;
}

void AlgoritmoTarea::infijasPosfijas() {
    Pila * pilaTemporal = new Pila();
    char primerCaracter;

    while(!entradaTeclado.empty()){
        primerCaracter = entradaTeclado.at(0); // Pone un nuevo primer caracter


        //Espacio
        if(primerCaracter == ' ')
            ; // Es como hacer pass, los espacios se ignoran


        //Parentesis izquierdo
        else if(primerCaracter == '(')
            pilaTemporal->push("(");


        //Parentesis derecho
        else if (primerCaracter == ')'){
            //Recorre toda la pila hasta encontrar un parentesis izquierdo
            while(pilaTemporal->tope->dato != "("){
                // Despliegua un caracter de la lista
                pilaPrimerAlgoritmo->push(pilaTemporal->pop()->dato);
            }
        }


        // Operador
        else if(esOperador(primerCaracter)){
            if(pilaTemporal->empty() || compararPrioridades(primerCaracter, encontrarUltimoOperadorPila(pilaTemporal))){
                pilaTemporal->push(string(1,primerCaracter));
            } else {
                // Despliegua un caracter de la lista
                pilaPrimerAlgoritmo->push(pilaTemporal->pop()->dato);
                continue;
            }


        // Operando
        } else {
            // Es un numero
            // Despliegua un caracter de la lista
            pilaPrimerAlgoritmo->push(armarNumero());
            continue;
        }


        // Evita que se encicle
        entradaTeclado.erase(0, 1); // Va disminuyendo el string de entrada
    }


    // Despliega todos los datos que hayan quedado en la pila
    while(!pilaTemporal->empty())
        pilaPrimerAlgoritmo->push(pilaTemporal->pop()->dato);


}


void AlgoritmoTarea::final(){
    pedirDatosUsuario();
    if(validarEntradaTeclado()){
        infijasPosfijas();

        pilaPrimerAlgoritmo->imprimir();
    }
}
