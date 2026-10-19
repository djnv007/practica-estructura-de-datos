#ifndef PIZZERIA_H
#define PIZZERIA_H

#include "Pedido.h"
#include<iostream>
#include<cstring>
#define PROB_PERSOONALIZACION 20
using namespace std;

class NodoCola
{
    friend class Cola;
private:
    NodoCola *siguiente;
    Pedido datos;
public:
    NodoCola(Pedido pedido,NodoCola*sig = NULL);
};
class Cola
{
private:
    NodoCola *primero;
    NodoCola *ultimo;
    int longitud;
public:
    Cola();
    ~Cola();
    bool esVacia();
    void encolar(Pedido p);
    bool desencolar(Pedido &p);
    void mostrar();
};
Pedido generar_pedido();

#endif // PIZZERIA_H
