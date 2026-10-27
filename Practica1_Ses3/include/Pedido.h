#ifndef PEDIDO_H
#define PEDIDO_H
#include <iostream>
#include<cstring>

using namespace std;

const int LON_ID=7;
enum Tipo_pizza {Margarita,Barbacoa,Vegetal,Hawaiana,Romana,Cuatro_quesos};
enum Tamano {Mediano,Grande};
enum Zona_reparto {Norte,Sur,Este,Oeste};
enum Estado {Recibido, Preparacion_especial, cocina, Expedicion, Caja, Enviado, Retirado};
struct Pedido
{
    char id_pedido[LON_ID];
    int id_cliente;
    Tipo_pizza tipo_pizza;
    Tamano tamano;
    Zona_reparto zona_reparto;
    bool personalizada;
    Estado estado;
};
char* tipoToString(Tipo_pizza t);
char* tamanoToString(Tamano tam);
char* zonaToString(Zona_reparto zona);
char* estadoToString(Estado estado);
#endif // PEDIDO_H
