#ifndef PIZZERIA_H
#define PIZZERIA_H

#include "Pedido.h"
#include<iostream>
#include<cstring>
#define PROB_PERSONALIZACION 20
#define N_PEDIDOS_PASO 10
#define ZONAS 4
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
    int getLongitud();
    void encolar(Pedido p);

    Pedido frente();

    bool desencolar();
    void mostrar();
};
const char*textoPizza(Tipo_pizza pizza);
const char*textoTamano(Tamano tam);
const char*textoZona(Zona_reparto zona);
const char*textoEstado(Estado est);
void ejecutarPaso(
    Cola& recibidos,
    Cola& preparacion,
    Cola& cocina,
    Cola& norte,
    Cola& sur,
    Cola& este,
    Cola& oeste
);
Pedido generar_pedido();

#endif // PIZZERIA_H
