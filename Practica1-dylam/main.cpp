#include <iostream>
#include<ctime>
#include<cstdlib>
#include<cctype>
#include"pizzeria.h"

using namespace std;
int main()
{
    srand(time(NULL));
    Cola colaPedidos;
    Cola preparacionEspecial;
    Cola cocina;

    Cola expedicionNorte;
    Cola expedicionSur;
    Cola expedicionEste;
    Cola expedicionOeste;
    int opcion;
    bool abierto=true;
    while(abierto)
    {
        cout<<"Pizzeria\n"<<"-------------------------------------\n";
        cout<<"Opcion\t\t"<<"Funcion\n";
        cout<<"1\t\t"<<"Generar N pedidos"<<endl;
        cout<<"2\t\t"<<"Mostar pedidos recibidos"<<endl;
        cout<<"0\t\t"<<"salir"<<endl;
        cin>>opcion;
        cin.ignore(1000,'\n');
        switch(opcion)
        {
        case 1:
        {
            int pedidos=0;
            cout<<"cuantos pedidos quieres hacer: "<<endl;
            cin>>pedidos;
            for(int i=0; i<pedidos; ++i)
            {
                Pedido nuevo= generar_pedido();
                colaPedidos.encolar(nuevo);
            }
            break;
        }
        case 2:
        {
            colaPedidos.mostrar();
            break;
        }
        case 3:
        {
            if(colaPedidos.desencolar())
            {
                cout<< "Pedido quitado\n";
            }
            else
            {
                cout<<"No hay pedidos aun\n";
            }
            break;
        }
        case 0:
        {
            cout<<"cerrando\n";
            abierto=false;
            break;
        }
        }
    }
    return 0;
}
