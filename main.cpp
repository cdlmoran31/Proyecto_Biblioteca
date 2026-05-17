#include <iostream>
using namespace std;

struct Libro {
    int codigo;
    string titulo;
    string autor;
    string anio;
    bool disponible;
    Libro *siguiente;
};


void push (Libro *&pila, int codigo, string titulo, string autor, string anio, bool disponible) {
    Libro *nuevo = new Libro();

    nuevo -> codigo = codigo;
    nuevo -> titulo = titulo;
    nuevo -> autor = autor;
    nuevo -> anio = anio;
    nuevo -> disponible = disponible;
    nuevo -> siguiente = pila;

    pila = nuevo;
}
void pop (Libro *&pila) {
    if (pila != NULL) {
        Libro *aux = pila;
        cout << "Eliminando: Libro..." << aux->codigo << aux->titulo << aux->autor << aux->anio  << aux-> disponible << endl;
        pila = aux -> siguiente;

        delete aux;
    }
}
void  mostrar (Libro *&pila) {

    while (pila != NULL) {
        cout << pila->codigo;
        cout << pila->titulo;
        cout << pila->autor;
        cout << pila->anio;
        cout << pila->disponible;
        cout << endl;
    }

}

int main () {

    int Menu;
    Libro *pila;

    do {
        cout<<"1. Registrar Libro"<<endl;
        cout<<"2. Mostrar Libros"<<endl;
        cout<<"3. Prestar Libro"<<endl;
        cout<<"4. devolver libro"<<endl;
        cout<<"5. Devolver Libro"<<endl;
        cout<<"6. Reportes"<<endl;
        cout<<"7. Salir"<<endl;
        cout<<endl;
        cin >> Menu;
        switch (Menu) {
            case 1  : {
                cout<<"1. Registrar Libro"<<endl;
                int codigo;
                string titulo;
                string autor;
                string anio;
                bool disponible = true;

                cout<< "Ingrese el codigo de Libro:  ";
                cin>>codigo;
                cout<< "Ingrese el titulo de Libro:  ";
                cin>>titulo;
                cout<< "Ingrese el autor de Libro:  ";
                cin>>autor;
                cout<< "Ingrese el anio de Libro:  ";
                cin>>anio;
                cout<< "Ingrese el disponible de Libro:  ";
                cout<<disponible<<endl;
                cout<< "Libro Ingresado correctamente " << endl;

                push (pila,codigo,titulo,autor,anio,disponible);
                    break;
                }

            case 2:
                cout<<"2. Mostrar Libros"<<endl;
                break;
            case 3:
                cout<<"4. Prestar Libro"<<endl;
                break;
            case 4:
                cout<<"5. devolver libro"<<endl;
                break;
            case 5:
                cout<<"6. Reportes"<<endl;
                break;
            case 6:
                cout<<"7. Salir";
                break;
        }
    }
    while (Menu != 7);
}
