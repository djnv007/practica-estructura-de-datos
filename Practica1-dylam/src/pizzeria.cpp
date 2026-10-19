#include "pizzeria.h"
#include <cstring>
#include<cstdio>

NodoCola::NodoCola(Pedido p, NodoCola* sig)
{
    datos=p;
    siguiente=sig;
}
Pedido Cola::frente()
{
    return primero->datos;
}
Cola::Cola()
{
    primero = NULL;
    ultimo= NULL;
    longitud=0;
}
Cola::~Cola()
{
    while(!esVacia())
    {
        desencolar();
    }

}
bool Cola::esVacia()
{
    return ((primero==NULL)&&(ultimo==NULL));
Pedido Cola::frente()
{
    return primero->datos;
}
}
int Cola::getLongitud()
{
    return longitud;
}
void Cola::encolar(Pedido p)
{
    NodoCola* nuevo= new NodoCola(p);
    if(esVacia())
    {
        primero= nuevo;
        ultimo= nuevo;
    }
    else
    {
        ultimo->siguiente= nuevo;
        ultimo= nuevo;
    }
    longitud++;
}
bool Cola::desencolar()
{
    if(!esVacia())
    {
        Pedido p = primero->datos;
        NodoCola* aux= primero;
        if((primero==ultimo)&&(primero->siguiente==NULL))
        {
            primero= NULL;
            ultimo= NULL;
            aux->siguiente=NULL;
            delete(aux);
        }
        else
        {
            primero = primero->siguiente;
            aux->siguiente=NULL;
            delete(aux);
        }
        longitud--;
        return true;
    }
    return false;
}
void Cola::mostrar()
{
    if (esVacia())
    {
        cout<<"Cola vacia\n";
        return;
    }

    NodoCola* aux = primero;

    cout << "Pedido\tCliente\tPizza\t\tTamano\tZona\tPers\tEstado\n";
    cout << "------------------------------------------------------------\n";

    while(aux != NULL)
    {
        Pedido p = aux->datos;

        cout << p.id_pedido << "\t";
        cout << p.id_cliente << "\t";
        cout << textoPizza(p.tipo_pizza) << "\t";
        cout << textoTamano(p.tamano) << "\t";
        cout << textoZona(p.zona_reparto) << "\t";
        cout << (p.personalizada ? "Si" : "No") << "\t";
        cout << textoEstado(p.estado) << endl;

        aux = aux->siguiente;
    }
}
Pedido generar_pedido()
{
    static int contador = 10000;
    Pedido p;
    sprintf(p.id_pedido, "P%05d", contador);
    contador++;

    int num=100+rand()%900;
    p.id_cliente=num;
    p.tipo_pizza = static_cast<Tipo_pizza>(rand()%6);
    p.tamano = static_cast <Tamano> (rand()%2);
    p.zona_reparto = static_cast<Zona_reparto> (rand()%4);
    p.personalizada= (rand()%100) < PROB_PERSONALIZACION;
    p.estado = Recibido;
    return p;


}
const char* textoPizza(Tipo_pizza pizza)
{
    switch(pizza)
    {
    case Margarita:
        return "Margarita";
    case Barbacoa:
        return "Barbacoa";
    case Vegetal:
        return "Vegetal";
    case Hawaiana:
        return "Hawaiana";
    case Romana:
        return "Romana";
    case Cuatro_quesos:
        return "Cuatro quesos";
    }

    return "";
}
const char* textoTamano(Tamano tam)
{
    switch(tam)
    {
    case Mediano:
        return "Mediano";
    case Grande:
        return "Grande";
    }

    return "";
}
const char* textoZona(Zona_reparto zona)
{
    switch(zona)
    {
    case Norte:
        return "Norte";
    case Sur:
        return "Sur";
    case Este:
        return "Este";
    case Oeste:
        return "Oeste";
    }

    return "";
}
const char* textoEstado(Estado est)
{
    switch(est)
    {
        case Recibido:
            return "Recibido";

        case PreparacionEspecial:
            return "Preparacion especial";

        case Cocina:
            return "Cocina";

        case Expedicion:
            return "Expedicion";
    }

    return "";
}
void ejecutarPaso(
    Cola& recibidos,
    Cola& preparacion,
    Cola& cocina,
    Cola& norte,
    Cola& sur,
    Cola& este,
    Cola& oeste
)
{

}
