#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Nodo
{
public:
    string dato;
    Nodo *der;
    Nodo *izq;

public:
    Nodo *crearNodo(string n)
    {
        Nodo *nuevoNodo = new Nodo();

        nuevoNodo->dato = n;
        nuevoNodo->der = nullptr;
        nuevoNodo->izq = nullptr;

        return nuevoNodo;
    }

    void insertar(Nodo *&ar, string n);
    void mostrarArbol(Nodo *);
    void mostrarArbolEntero(Nodo *);
    void llenarArbol();
};

// Creamos el arbol
Nodo *arbol = NULL;

void Nodo::insertar(Nodo *&arbol, string n)
{
    Nodo *nuevoNodo = crearNodo(n);
    arbol = nuevoNodo;
}

void Nodo::mostrarArbol(Nodo *arbol)
{
    system("cls");
    if (arbol == NULL)
    {
        return;
    }

    int opc;
    string nuevoDato, nuevaPregunta;

    if (arbol->izq == NULL && arbol->der == NULL) // si el nodo es hoja
    {
        cout << "Estas pensando en " << arbol->dato << "?" << endl;
        cout << "1. Si" << endl;
        cout << "2. No" << endl;
        cout << "3. Reiniciar" << endl;
        cout << "Opcion: " << endl;

        cin >> opc;

        if (opc == 1) // Adivino al personaje
        {
            system("cls");
            cout << "Lo sabia!!" << endl;
        }
        else if (opc == 2) // Fallo al adivinar
        {
            system("cls");
            cout << "Maldicion!!" << endl;
            cout << "En que estabas pensado?: " << endl;
            fflush(stdin);
            getline(cin, nuevoDato); // Ingresa el personaje en el que estaba pensando

            cout << "En que se diferencia " << nuevoDato << " de " << arbol->dato << endl
                 << endl;
            cout << "Ejemplos: es piloto, es hombre, es cantante, es mexicano" << endl
                 << endl;
            cout << "Respuesta: ";
            fflush(stdin);
            getline(cin, nuevaPregunta); // Ingresa la pregunta que los diferencia

            string temp;
            temp = arbol->dato; // Almacenamos tempolamente el valor de la hoja

            arbol->dato = nuevaPregunta;

            insertar(arbol->izq, nuevoDato); // Agregamos canelo como nodo izquierdo de la pregunta: es boxeador?
            insertar(arbol->der, temp);      // Agregamos a checo perez como hijo derecho de la pregunta: es boxeador?
        }
        else if (opc == 3)
        {
            // vuelve
        }
    }
    else // si el nodo es rama
    {
        system("cls");
        cout << arbol->dato << " ?" << endl; // es "diferenciador"?
        cout << "1. Si" << endl;
        cout << "2. No" << endl;
        cout << "3. Reiniciar" << endl;
        cout << "Opcion: " << endl;
        cin >> opc;
        if (opc == 1) // Si cumple con la pregunta
        {
            mostrarArbol(arbol->izq);
        }
        else if (opc == 2) // Si no cumple
        {
            mostrarArbol(arbol->der);
        }
        else if (opc == 3)
        {
            // volver
        }
    }
}

void Nodo::mostrarArbolEntero(Nodo *arbol)
{
    if (arbol == NULL)
    {
        cout << "Hijo vacio" << endl;
        return;
    }
    else
    {
        mostrarArbolEntero(arbol->der);
        cout << arbol->dato << endl;
        mostrarArbolEntero(arbol->izq);
    }
}

void Nodo::llenarArbol()
{
    insertar(arbol, "Es real?");
    insertar(arbol->izq, "checo perez");
    insertar(arbol->der, "bart simpson");
}

class Program
{
private:
public:
    void menu()
    {
        system("cls");
        int opc = 0;
        do
        {
            cout << "1. Jugar" << endl;
            cout << "2. Mostrar arbol entero" << endl;
            cout << "3. Salir" << endl;
            cout << "Opcion:";
            fflush(stdin);
            cin >> opc;

            inputManager(opc);

        } while (opc != 3);
    }

    void inputManager(int opc)
    {
        string dato;
        int contador;
        Nodo n;

        switch (opc)
        {
        case 1:
            n.mostrarArbol(arbol);
            cout << "\n";
            system("pause");
            menu();
            break;
        case 2:
            n.mostrarArbolEntero(arbol);
            system("pause");
            menu();
            break;
        case 3:
            exit(1);
            break;
        default:
            cout << "La opcion ingresada es incorrecta" << endl;
            system("pause");
            menu();
        }
    }
};

int main()
{
    Nodo n;
    n.llenarArbol();
    Program p;
    p.menu();
    delete arbol;
    return 0;
}