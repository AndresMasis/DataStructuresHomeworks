#include "estructuras.h"

//Pide datos al usuario
void AlgoritmoTarea::pedirDatosUsuario() {
    cout<<"Dame una entrada de operacion (Entrada infija)"<<endl;
    getline(cin, entradaInfija);
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
    short cantidadIzquierdos = 0;
    short cantidadDerechos = 0;
    for (int i = 0; i < entradaInfija.length(); i++) {
        // Recorre de caracter por caracter el string
        if (!encontrarCaracter(entradaInfija[i])) {
            cout << "Oops! El caracter " << entradaInfija[i] << " no es valido" << endl;
            return false;
        } else if (entradaInfija[i] == '(')
            cantidadIzquierdos += 1;

        else if (entradaInfija[i] == ')')
            cantidadDerechos += 1;
    }

    if(cantidadDerechos != cantidadIzquierdos){
        cout<<"Oops! La cantidad de parentesis derechos e izquierdos no coincide"<<endl;
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
    if(prioridadOperador(operadorActual) <= prioridadOperador(ultimoOperadorPila))
        return true;
    else
        return false;
}



string AlgoritmoTarea::armarNumero(){
    string numeroCreado = "";

    // Revisa los caracteres siguientes
    while(!entradaInfija.empty()){
        if(!esNumero(entradaInfija[0]))
            break;

        numeroCreado += entradaInfija[0];
        // Evita que se encicle
        entradaInfija.erase(0, 1); // Va disminuyendo el string de entrada
    }

    return numeroCreado;
}

void AlgoritmoTarea::infijasPosfijas() {
    Pila * pila = new Pila();
    char primerCaracter;

    entradaInfija.append(")");
    pila->push("(");

    while(!entradaInfija.empty()) {
        primerCaracter = entradaInfija.at(0); // Pone un nuevo primer caracter


        //Espacio
        if (primerCaracter == ' '); // Es como hacer pass, los espacios se ignoran


        //Parentesis izquierdo
        else if (primerCaracter == '(')
            pila->push("(");


        //Parentesis derecho
        else if (primerCaracter == ')') {
            //Recorre toda la pila hasta encontrar un parentesis izquierdo
            while (pila->tope->dato != "(") {
                // Despliegua un caracter de la lista
                posfija->push(pila->pop()->dato);
            }

            pila->pop();
        }


        // Operador
        else if(esOperador(primerCaracter)) {
            while(compararPrioridades(primerCaracter, pila->tope->dato[0])){
                if (pila->tope->dato == "(")
                    break;
                posfija->push(pila->pop()->dato);
            }

            pila->push(string(1,primerCaracter));


        // Operando
        } else {
            // Es un numero
            // Despliegua un caracter de la lista
            posfija->push(armarNumero());
            continue;
        }


        // Evita que se encicle
        entradaInfija.erase(0, 1); // Va disminuyendo el string de entrada
    }


    // Despliega todos los datos que hayan quedado en la pila
    while(!pila->empty())
        posfija->push(pila->pop()->dato);


    posfija->voltear();
}


void AlgoritmoTarea::final(){
    pedirDatosUsuario();
    if(validarEntradaTeclado()){
        infijasPosfijas();

        posfija->imprimir();
    }
}