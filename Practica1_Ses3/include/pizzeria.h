#ifndef PIZZERIA_H
#define PIZZERIA_H

#include "Pedido.h"
#include<iostream>
#include<cstring>
#define PROB_PERSONALIZACION 20
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
    void mostrar(const char* nombre);
};
Pedido generar_pedido();
class NodoPila
{
private:
    NodoPila *siguiente;
    Pedido pedido;
    friend class Pila;
public:
    NodoPila(Pedido pedido,NodoPila*sig=NULL);
    ~NodoPila();
};

class Pila
{
private:
    NodoPila *cima;
    int capacidad;
public:
    Pila();
    ~Pila();
    bool esVacia();
    void apilar(Pedido p);
    bool desapilar(Pedido &p);
    Pedido cimaPila();
    void mostrar();
    int getCapacidad();
    void vaciar();
};

#endif // PIZZERIA_H
