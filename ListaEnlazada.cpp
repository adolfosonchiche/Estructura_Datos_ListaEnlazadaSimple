
#include <iostream>
#include <stdlib.h>
#include "ListaEnlazada.h"
using namespace std;

/*estructura de mi lista*/
struct nodo{
       int nro;        // en este caso es un numero entero
       struct nodo *sgte;
};
 
typedef struct nodo *Tlista;

static Tlista lista = NULL; 

/*Constructor vacio de mi clase Lista Enlazada*/
ListaEnlazada::ListaEnlazada() {
    
}

/*metodo del que imprime menu de opciones*/
void ListaEnlazada::menu() 
{
    cout<<"\n\t\tLISTA ENLAZADA SIMPLE\n\n";
    cout<<" 1. INSERTAR ELEMENTO AL INICIO               "<<endl;
    cout<<" 2. INSERTAR ELEMENTO AL FINAL                "<<endl;
    cout<<" 3. INSERTAR ELEMENTO EN UNA POSICION         "<<endl;
    cout<<" 4. IMPRIMIR VALORES DE LA LISTA              "<<endl;
    cout<<" 5. BUSCAR ELEMENTO  EN LA LISTA              "<<endl;
    cout<<" 6. ELIMINAR ELEMENTO EN LA LISTA 'V'            "<<endl;
    cout<<" 7. SALIR                            "<<endl;
 
    cout<<"\n INGRESE OPCION: ";
}

/*metodo para insertar un valor al inicio de la lista*/
void ListaEnlazada::insertarInicio(int valor)
{
    Tlista q;
    q = new(struct nodo);
    q->nro = valor;
    q->sgte = lista;
    lista  = q;
}

/*metodo para insertar un valor al final de la lista*/
void ListaEnlazada::insertarFinal(int valor)
{
    Tlista t, q = new(struct nodo);
 
    q->nro  = valor;
    q->sgte = NULL;
 
    if(lista==NULL)
    {
        lista = q;
    }
    else
    {
        t = lista;
        while(t->sgte!=NULL)
        {
            t = t->sgte;
        }
        t->sgte = q;
    }
}

/*metodo que retorna posicion especifica de la lista a insertar un elemento*/
int ListaEnlazada::insertarAntesFinal()
{
    int _op, band;
    cout<<endl;
    cout<<"\t 1. Antes de la posicion           "<<endl;
    cout<<"\t 2. Despues de la posicion         "<<endl;
 
    cout<<"\n\t Opcion : "; cin>> _op;
 
    if(_op==1)
        band = -1;
    else
        band = 0;
 
    return band;
}

/*metod para inssertar elemento en algun lugar especifico de la lista*/
void ListaEnlazada::insertarElemento(int valor, int pos)
{
    Tlista q, t;
    int i;
    q = new(struct nodo);
    q->nro = valor;
 
    if(pos==1)
    {
        q->sgte = lista;
        lista = q;
    }
    else
    {
        int x = insertarAntesFinal();
        t = lista;
 
        for(i=1; t!=NULL; i++)
        {
            if(i==pos+x)
            {
                q->sgte = t->sgte;
                t->sgte = q;
                return;
            }
            t = t->sgte;
        }
    }
    cout<<"   Error...Posicion no encontrada..!"<<endl;
}

/*metodo para buscar en valor en la lista la poscicion odel valor*/
void ListaEnlazada::buscarElemento(int valor)
{
    Tlista q = lista;
    int i = 1, band = 0;
 
    while(q!=NULL)
    {
        if(q->nro==valor)
        {
            cout<<endl<<" Encontrada en posicion "<< i <<endl;
            band = 1;
        }
        q = q->sgte;
        i++;
    }
    delete(q);
    if(band==0)
        cout<<"\n\n Numero no encontrado..!"<< endl;
}

/*metodo que imprime todo los valores de la lista enlazada*/
void ListaEnlazada::imprimirLista()
{
    Tlista q = lista;
     int i = 0;
 
     while(q != NULL)
     {
          cout <<' '<< i+1 <<") " << q->nro << endl;
          q = q->sgte;
          i++;
     }
}

/*metodo para eliminar un valor especifico en la lista*/
void ListaEnlazada::eliminarElemento(int valor)
{
    Tlista p, ant;
    p = lista;
 
    if(lista!=NULL)
    {
        while(p!=NULL)
        {
            if(p->nro==valor)
            {
                if(p==lista)
                    lista = lista->sgte;
                else
                    ant->sgte = p->sgte;
 
                delete(p);
                return;
            }
            ant = p;
            p = p->sgte;
        }
    }
    else
        cout<<" Lista vacia..!";
}

