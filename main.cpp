

/**********************************************************
 *                                                        *
 *        UNIVERSIDAD MARIANO GÁLVEZ DE GUATEMALA         *
 *                                                        *
 *                  PROYECTO FINAL                        *
 *                                                        *
 *  Curso       : Programación 1                          *
 *  Sección     : D                                       *
 *  Estudiante  : Cristian De León                        *
 *                                                        *
 *  Descripción:                                          *
 *  Sistema de biblioteca desarrollado en C++             *
 *  utilizando structs, punteros, pilas y menú            *
 *  interactivo.                                          *
 *                                                        *
 **********************************************************/

#include <iostream>
#include <string>

using namespace std;

struct Libro
{
    int codigo;
    string titulo;
    string autor;
    string anio;
    bool disponible;

    Libro *siguiente;
};

// REGISTRAR LIBRO
void push(Libro *&pila, int codigo, string titulo,
          string autor, string anio, bool disponible)
{
    Libro *nuevo = new Libro();

    nuevo->codigo = codigo;
    nuevo->titulo = titulo;
    nuevo->autor = autor;
    nuevo->anio = anio;
    nuevo->disponible = disponible;

    nuevo->siguiente = pila;

    pila = nuevo;

    cout << "\nLibro registrado correctamente\n";
}

// MOSTRAR LIBROS
void mostrar(Libro *pila)
{
    Libro *aux = pila;

    if(aux == NULL)
    {
        cout << "\nNo hay libros registrados\n";
        return;
    }

    while(aux != NULL)
    {
        cout << "\n==============================" << endl;
        cout << "Codigo: " << aux->codigo << endl;
        cout << "Titulo: " << aux->titulo << endl;
        cout << "Autor: " << aux->autor << endl;
        cout << "Anio: " << aux->anio << endl;

        if(aux->disponible)
        {
            cout << "Estado: Disponible" << endl;
        }
        else
        {
            cout << "Estado: Prestado" << endl;
        }

        aux = aux->siguiente;
    }
}

// BUSCAR LIBRO
void buscarLibro(Libro *pila, int codigoBuscar)
{
    Libro *aux = pila;

    bool encontrado = false;

    while(aux != NULL)
    {
        if(aux->codigo == codigoBuscar)
        {
            cout << "\n===== LIBRO ENCONTRADO =====" << endl;
            cout << "Codigo: " << aux->codigo << endl;
            cout << "Titulo: " << aux->titulo << endl;
            cout << "Autor: " << aux->autor << endl;
            cout << "Anio: " << aux->anio << endl;

            if(aux->disponible)
            {
                cout << "Estado: Disponible" << endl;
            }
            else
            {
                cout << "Estado: Prestado" << endl;
            }

            encontrado = true;
        }

        aux = aux->siguiente;
    }

    if(!encontrado)
    {
        cout << "\nLibro no encontrado\n";
    }
}

// PRESTAR LIBRO
void prestarLibro(Libro *pila, int codigoBuscar)
{
    Libro *aux = pila;

    bool encontrado = false;

    while(aux != NULL)
    {
        if(aux->codigo == codigoBuscar)
        {
            encontrado = true;

            if(aux->disponible)
            {
                aux->disponible = false;
                cout << "\nLibro prestado correctamente\n";
            }
            else
            {
                cout << "\nEl libro ya esta prestado\n";
            }
        }

        aux = aux->siguiente;
    }

    if(!encontrado)
    {
        cout << "\nLibro no encontrado\n";
    }
}

// DEVOLVER LIBRO
void devolverLibro(Libro *pila, int codigoBuscar)
{
    Libro *aux = pila;

    bool encontrado = false;

    while(aux != NULL)
    {
        if(aux->codigo == codigoBuscar)
        {
            encontrado = true;

            if(!aux->disponible)
            {
                aux->disponible = true;
                cout << "\nLibro devuelto correctamente\n";
            }
            else
            {
                cout << "\nEl libro ya estaba disponible\n";
            }
        }

        aux = aux->siguiente;
    }

    if(!encontrado)
    {
        cout << "\nLibro no encontrado\n";
    }
}

// REPORTES
void reportes(Libro *pila)
{
    int opcion;

    do
    {
        cout << "\n===== REPORTES =====" << endl;
        cout << "1. Mostrar libros disponibles" << endl;
        cout << "2. Mostrar libros prestados" << endl;
        cout << "3. Cantidad total de libros" << endl;
        cout << "4. Libro mas antiguo" << endl;
        cout << "5. Regresar" << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        Libro *aux = pila;

        switch(opcion)
        {
            case 1:
            {
                cout << "\n===== LIBROS DISPONIBLES =====\n";

                while(aux != NULL)
                {
                    if(aux->disponible)
                    {
                        cout << aux->codigo << " - ";
                        cout << aux->titulo << endl;
                    }

                    aux = aux->siguiente;
                }

                break;
            }

            case 2:
            {
                cout << "\n===== LIBROS PRESTADOS =====\n";

                while(aux != NULL)
                {
                    if(!aux->disponible)
                    {
                        cout << aux->codigo << " - ";
                        cout << aux->titulo << endl;
                    }

                    aux = aux->siguiente;
                }

                break;
            }

            case 3:
            {
                int contador = 0;

                while(aux != NULL)
                {
                    contador++;
                    aux = aux->siguiente;
                }

                cout << "\nCantidad total de libros: " << contador << endl;

                break;
            }

            case 4:
            {
                if(aux == NULL)
                {
                    cout << "\nNo hay libros registrados\n";
                    break;
                }

                Libro *antiguo = aux;

                while(aux != NULL)
                {
                    if(aux->anio < antiguo->anio)
                    {
                        antiguo = aux;
                    }

                    aux = aux->siguiente;
                }

                cout << "\n===== LIBRO MAS ANTIGUO =====\n";
                cout << "Codigo: " << antiguo->codigo << endl;
                cout << "Titulo: " << antiguo->titulo << endl;
                cout << "Autor: " << antiguo->autor << endl;
                cout << "Anio: " << antiguo->anio << endl;

                break;
            }

            case 5:
                cout << "\nRegresando al menu principal...\n";
                break;

            default:
                cout << "\nOpcion invalida\n";
        }

    }while(opcion != 5);
}

int main()
{
    Libro *pila = NULL;

    int menu;

    do
    {
        cout << "\n==================================" << endl;
        cout << "      SISTEMA DE BIBLIOTECA       " << endl;
        cout << "==================================" << endl;

        cout << "1. Registrar Libro" << endl;
        cout << "2. Mostrar Libros" << endl;
        cout << "3. Buscar Libro" << endl;
        cout << "4. Prestar Libro" << endl;
        cout << "5. Devolver Libro" << endl;
        cout << "6. Reportes" << endl;
        cout << "7. Salir" << endl;

        cout << "Ingrese una opcion: ";
        cin >> menu;

        switch(menu)
        {
            case 1:
            {
                int codigo;
                string titulo;
                string autor;
                string anio;

                cout << "\nIngrese codigo: ";
                cin >> codigo;

                cin.ignore();

                cout << "Ingrese titulo: ";
                getline(cin, titulo);

                cout << "Ingrese autor: ";
                getline(cin, autor);

                cout << "Ingrese anio: ";
                getline(cin, anio);

                bool disponible = true;

                push(pila, codigo, titulo, autor, anio, disponible);

                break;
            }

            case 2:
            {
                mostrar(pila);
                break;
            }

            case 3:
            {
                int codigoBuscar;

                cout << "\nIngrese codigo del libro: ";
                cin >> codigoBuscar;

                buscarLibro(pila, codigoBuscar);

                break;
            }

            case 4:
            {
                int codigoBuscar;

                cout << "\nIngrese codigo del libro a prestar: ";
                cin >> codigoBuscar;

                prestarLibro(pila, codigoBuscar);

                break;
            }

            case 5:
            {
                int codigoBuscar;

                cout << "\nIngrese codigo del libro a devolver: ";
                cin >> codigoBuscar;

                devolverLibro(pila, codigoBuscar);

                break;
            }

            case 6:
            {
                reportes(pila);
                break;
            }

            case 7:
            {
                cout << "\nSaliendo del sistema...\n";
                break;
            }

            default:
            {
                cout << "\nOpcion invalida\n";
            }
        }

    }while(menu != 7);

    return 0;
}


