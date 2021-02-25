#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H
#include <iostream>

using namespace std;

class ListaEnlazada
{
    public: /*declaracion de metodos del a clase*/
        ListaEnlazada();
        void insertarInicio(int);
        void insertarFinal(int);
        int insertarAntesFinal();
        void insertarElemento(int, int);
        void buscarElemento(int);
        void imprimirLista();
        void eliminarElemento(int);
        void menu();
    private:
  
};

#endif /*LISTAENLAZADA_H*/