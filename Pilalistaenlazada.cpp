#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

class pila {
private:
    Nodo* top;

public:
    pila() {
        top = NULL;
    }

    bool estaVacia() {
        return top == NULL;
    }

    void push(int valor) {
        Nodo* nuevo = new Nodo();
        nuevo->dato = valor;
        nuevo->siguiente = top;
        top = nuevo;
        cout << "se agrego: " << valor << endl;
    }

    int pop() {
        if (estaVacia()) {
            cout << "Error: La pila esta vacia." << endl;
            return -1;
        }

        Nodo* auxiliar = top;
        int valor = auxiliar->dato;
        top = top->siguiente;

        delete auxiliar;
        return valor;
    }

    int peek() {
        if (estaVacia()) {
            cout << "La pila esta vacia." << endl;
            return -1;
        }
        return top->dato;
    }

    ~pila() {
        while (!estaVacia()) {
            pop();
        }
    }
};

int main() {
    pila miPila;
    miPila.push(100);
    miPila.push(200);
    miPila.push(300);

    cout << "Elemento en la cima de la pila: " << miPila.peek() << endl;
    cout << "Elemento eliminado de la pila: " << miPila.pop() << endl;
    cout << "Elemento en la cima de la pila: " << miPila.peek() << endl;

    return 0;
}
