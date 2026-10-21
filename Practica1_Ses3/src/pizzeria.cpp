#include "pizzeria.h"
#include <cstring>
#include <iomanip>

NodoCola::NodoCola(Pedido p, NodoCola* sig){
    datos=p;
    siguiente=sig;
}

Cola::Cola(){
    primero = NULL;
    ultimo= NULL;
    longitud=0;
}
Cola::~Cola()
{
    Pedido p;

    while(desencolar(p))
    {

    }
}
bool Cola::esVacia(){return ((primero==NULL)&&(ultimo==NULL));}
void Cola::encolar(Pedido p){
    NodoCola* nuevo= new NodoCola(p);
    if(esVacia()){
        primero= nuevo;
        ultimo= nuevo;
    }
    else{
        ultimo->siguiente= nuevo;
        ultimo= nuevo;
    }
    longitud++;
}
bool Cola::desencolar(Pedido &p){
    if(!esVacia()){
        p = primero->datos;
        NodoCola* aux= primero;
        if((primero==ultimo)&&(primero->siguiente==NULL)){
            primero= NULL;
            ultimo= NULL;
            aux->siguiente=NULL;
            delete(aux);
        }
        else{
            primero = primero->siguiente;
            aux->siguiente=NULL;
            delete(aux);
        }
        longitud--;
        return true;
    }
    return false;
}
void Cola::mostrar(const char* nombre)
{
    cout << "\n=========== " << nombre << " ===========\n";
    if(esVacia())
    {
        cout << "Cola vacia\n";
        return;
    }

    cout << left
         << setw(10) << "Pedido"
         << setw(10) << "Cliente"
         << setw(18) << "Pizza"
         << setw(12) << "Tamano"
         << setw(10) << "Zona"
         << setw(8)  << "Pers"
         << setw(20) << "Estado"
         << endl;

    cout << string(88, '-') << endl;

    NodoCola* aux = primero;

    while(aux != NULL)
    {
        Pedido p = aux->datos;

        cout << left
             << setw(10) << p.id_pedido
             << setw(10) << p.id_cliente
             << setw(18) << tipoToString(p.tipo_pizza)
             << setw(12) << tamanoToString(p.tamano)
             << setw(10) << zonaToString(p.zona_reparto)
             << setw(8)  << (p.personalizada ? "Si" : "No")
             << setw(20) << estadoToString(p.estado)
             << endl;

        aux = aux->siguiente;
    }
}
Pedido generar_pedido(){
    Pedido p;
    static int contador = 10000;

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
NodoPila::NodoPila(Pedido p,NodoPila* sig){
    pedido=p;
    siguiente=sig;
}

NodoPila::~NodoPila(){}

Pila::Pila(){cima=NULL;
    capacidad=0;}
Pila::~Pila()
{
    vaciar();
}
bool Pila::esVacia(){
    return cima==NULL;
}
Pedido Pila::cimaPila()
{
    return cima->pedido;
}
void Pila::apilar(Pedido p){
    NodoPila *nuevo= new NodoPila(p,cima);
    cima=nuevo;
    capacidad++;
}
bool Pila::desapilar(Pedido &p)
{
    if(!esVacia())
    {
        p = cima->pedido;

        NodoPila *nodo = cima;

        cima = cima->siguiente;

        delete nodo;

        capacidad--;

        return true;
    }

    return false;
}

void Pila::mostrar()
{
    if(esVacia())
{
    cout << "(caja vacia)\n";
    return;
}

    cout << "(cima)\n\n";

    NodoPila* aux = cima;

    while(aux != NULL)
    {
        cout << aux->pedido.id_pedido
             << " - "
             << tipoToString(aux->pedido.tipo_pizza)
             << endl;

        aux = aux->siguiente;
    }

    cout << "\n(fondo)\n";
}
int Pila::getCapacidad(){return capacidad;}
void Pila::vaciar()
{
    Pedido p;

    while(desapilar(p))
    {

    }
}
