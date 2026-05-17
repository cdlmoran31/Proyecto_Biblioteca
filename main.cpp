#include <iostream>
using namespace std;

struct Libro {
    int codigo;
    string titulo;
    string autor;
    string anio;
    string disponible;
};

int main () {
    int Menu;
    cout<<"1. Inserir Libro";
    cout<<"2. Mostrar Libros";
    cout<<"3. Prestar Libro";
    cout<<"4. devolver libro";
    cout<<"5. Devolver Libro";
    cout<<"6. Reportes";
    cout<<"7. Salir";
    cout<<endl;
    cin >> Menu;

    do {
        switch (Menu) {
            case 1 :
                cout<<"1. Registrar Libro";
                break;
            case 2:
                cout<<"2. Mostrar Libros";
                break;
            case 3:
                cout<<"4. Prestar Libro";
                break;
            case 4:
                cout<<"5. devolver libro";
                break;
            case 5:
                cout<<"6. Reportes";
                break;
            case 6:
                cout<<"7. Salir";
                break;
        }
    }
    while (Menu != 7);
}
