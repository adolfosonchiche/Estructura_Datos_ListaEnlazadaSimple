 /*importamos librerias a utilizar*/
#include <iostream>
#include <stdlib.h>
#include "ListaEnlazada.h"

typedef ListaEnlazada* Enlazada;
using namespace std;
 
 static Enlazada listaEnlazada; 
/*  Funcion Principal--*/

int main()
{
    listaEnlazada = new ListaEnlazada(); 
    int op;     // opcion del menu
    int _dato;  // elemenento a ingresar
    int pos;    // posicion a insertar
 
 
    do
    {
        listaEnlazada->menu();  cin>> op;
 
        switch(op)
        {
            case 1:
 
                 cout<< "\n NUMERO A INSERTAR: "; cin>> _dato;
                 listaEnlazada->insertarInicio(_dato);
            break;
 
 
            case 2:
 
                 cout<< "\n NUMERO A INSERTAR: "; cin>> _dato;
                 listaEnlazada->insertarFinal(_dato );
            break;
 
 
            case 3:
 
                 cout<< "\n NUMERO A INSERTAR: ";cin>> _dato;
                 cout<< " Posicion : ";       cin>> pos;
                 listaEnlazada->insertarElemento(_dato, pos);
            break;
 
 
            case 4:
 
                 cout << "\n\n IMPRIMIENDO LISTA\n\n";
                 listaEnlazada->imprimirLista();
            break;
 
 
            case 5:
 
                 cout<<"\n VALOR A BUSCAR: "; cin>> _dato;
                 listaEnlazada->buscarElemento(_dato);
            break;
 
            case 6:
 
                cout<<"\n VALOR A ELIMINAR: "; cin>> _dato;
 
                listaEnlazada->eliminarElemento(_dato);
            break;

            default:
                if(op!= 7 ){
                    cout<<"\n OPCION INCORRECTA, INTENTE DE NUEVO!! "; 
                }
            break;
 
                    }
 
        cout<<endl<<endl;
 
    }while(op!=7);
 
   return 0;
}