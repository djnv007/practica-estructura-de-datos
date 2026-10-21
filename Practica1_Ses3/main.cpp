#include <iostream>
#include<ctime>
#include<cstdlib>
#include<cctype>
#include"pizzeria.h"
#define N_PEDIDOS_PASO 10
#define CAP_CAJA 6

using namespace std;

Cola Recibidos;
Cola Cocina;
Cola ExpedicionNorte;
Cola ExpedicionSur;
Cola ExpedicionEste;
Cola ExpedicionOeste;
Cola PreparacionEspecial;

//-----------------------------//
Pila CajaNorte;
Pila CajaSur;
Pila CajaEste;
Pila CajaOeste;
//----------------------------//

int CajasCompletasNorte=0;
int CajasCompletasSur=0;
int CajasCompletasEste=0;
int CajasCompletasOeste=0;

void meterEnCaja(Pila &Caja, Pedido p){
    if(Caja.getCapacidad()<CAP_CAJA){
        Caja.apilar(p);
        if(Caja.getCapacidad()==CAP_CAJA){
            CajasCompletasNorte++;
        }
    }
    else{
        Caja.vaciar();
        Caja.apilar(p);

    }
}


void avanzar_N_pedidos(int n)
{
    Pedido p;
    int contador=0;
    while(!ExpedicionNorte.esVacia()&&contador<n)
    {
        ExpedicionNorte.desencolar(p);
        meterEnCaja(CajaNorte,p);
        contador++;
    }
    contador=0;
    while(!ExpedicionSur.esVacia()&&contador<n)
    {
        ExpedicionSur.desencolar(p);
        contador++;
    }
    contador=0;
    while(!ExpedicionEste.esVacia()&&contador<n)
    {
        ExpedicionEste.desencolar(p);
        contador++;
    }
    contador=0;
    while(!ExpedicionOeste.esVacia()&&contador<n)
    {
        ExpedicionOeste.desencolar(p);
        contador++;
    }
    contador=0;
    while(!Cocina.esVacia()&&contador<n)
    {
        Cocina.desencolar(p);
        p.estado= Expedicion;
        if(p.zona_reparto==Norte)
        {
            ExpedicionNorte.encolar(p);
        }
        else if(p.zona_reparto==Sur)
        {
            ExpedicionSur.encolar(p);
        }
        else if(p.zona_reparto==Este)
        {
            ExpedicionEste.encolar(p);
        }
        else if(p.zona_reparto==Oeste)
        {
            ExpedicionOeste.encolar(p);
        }
        contador++;
    }
    contador=0;
    while(!PreparacionEspecial.esVacia()&&contador<n)
    {
        PreparacionEspecial.desencolar(p);
        p.estado=cocina;
        Cocina.encolar(p);
        contador++;
    }
    contador=0;
    while(!Recibidos.esVacia()&&contador<n)
    {
        Recibidos.desencolar(p);
        if(p.personalizada)
        {
            p.estado=Preparacion_especial;
            PreparacionEspecial.encolar(p);
        }
        else
        {
            p.estado=cocina;
            Cocina.encolar(p);
        }
        contador++;
    }



}


int main()
{
    srand(time(NULL));
    int opcion;
    bool abierto=true;
    while(abierto)
    {
        cout<<"Pizzeria\n"<<"-------------------------------------\n";
        cout<<"Opcion\t\t"<<"Funcion\n";
        cout<<"1\t\t"<<"Generar N pedidos"<<endl;
        cout<<"2\t\t"<<"Mostar pedidos recibidos"<<endl;
        cout<<"3\t\t"<<"Avanzar N pedidos un paso"<<endl;
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
            cin.ignore(1000,'\n');
            for(int i=0; i<pedidos; ++i)
            {
                Pedido nuevo= generar_pedido();
                Recibidos.encolar(nuevo);
            }
            break;
        }
        case 2:
        {
            Recibidos.mostrar("RECIBIDOS");
            PreparacionEspecial.mostrar("PREPARACION ESPECIAL");
            Cocina.mostrar("COCINA");
            ExpedicionNorte.mostrar("EXPEDICION NORTE");
            ExpedicionSur.mostrar("EXPEDICION SUR");
            ExpedicionEste.mostrar("EXPEDICION ESTE");
            ExpedicionOeste.mostrar("EXPEDICION OESTE");
            break;
        }

        case 3:
        {
            int num=0;
            cout<<"Cuantos pedidos vas a avanzar (Maximo 10)?: "<<endl;
            cin>>num;
            cin.ignore(1000,'\n');
            if(num>N_PEDIDOS_PASO)
            {
                num=10;
            }
            avanzar_N_pedidos(num);
            cout<<"Has avanzado "<<num<<" pedidos un paso"<<endl;
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
