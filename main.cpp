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

        pila = pila ->siguiente;
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
        cout<<"Ingrese una Opcion: ";
        cin >> Menu;
        switch (Menu) {
            case 1  : {
                cout<<"1. Registrar Libro"<<endl;
                    int codigo;
                    cout<< "Ingrese Codigo: ";
                    cin >> codigo;
                    cin.ignore();
                    string titulo;
                    cout<< "Ingrese el titulo de Libro:  ";
                    //cin >> titulo;
                    getline(cin,titulo);
                    //cin.ignore();
                    string autor;
                    cout<< "Ingrese el autor de Libro:  ";
                    getline(cin,autor);
                    //cin >> autor;
                    //cin.ignore();
                    string anio;
                    cout<< "Ingrese el anio de Libro:  ";
                    getline(cin,anio);
                    //cin >> anio;
                    //cin.ignore();
                    bool disponible = true;
                    cout << "El Libro esta disponible: "<<disponible<<endl;;
                    push (pila,codigo,titulo,autor,anio,disponible);

                break;

                }

            case 2:
                cout<<"2. Mostrar Libros"<<endl;
                mostrar (pila);

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

            default: "<3";
                break;
        }
    }
    while (Menu != 7);
}
