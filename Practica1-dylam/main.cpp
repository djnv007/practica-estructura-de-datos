#include <iostream>
#include<ctime>
#include<cstdlib>
#include<cctype>
#include"pizzeria.h"
#define N_PEDIDOS_PASO 10

using namespace std;

void avanzar_N_pedidos_aux(int n,Cola &Primero,Cola &Siguiente){
    if(n>Primero.longitud){n=Primero.longitud;}
    for(int i=0;i<n;++i){
        Pedido p =Primero.primero->datos;
        Primero.desencolar()
        Siguiente.encolar(p);
    }
}
void avanzar_N_pedidos(int n, Cola& Recibidos,Cola&PreparacionEspecial, Cola& Cocina, Cola&ExpedicionNorte, Cola&ExpedicionSur, Cola&ExpedicionEste, Cola&ExpedicionOeste){
        Cola aux;
        avanzar_N_pedidos_aux(n,ExpedicionEste,aux);
        avanzar_N_pedidos_aux(n,ExpedicionOeste,aux);
        avanzar_N_pedidos_aux(n,ExpedicionNorte,aux);
        avanzar_N_pedidos_aux(n,ExpedicionSur,aux);
        delete aux;
        Recibidos.primero->datos;

        avanzar_N_pedidos_aux(n,Cocina,ExpedicionNorte);
        avanzar_N_pedidos_aux(n,PreparacionEspecial,Cocina);


}


int main()
{
    srand(time(NULL));
    Cola Recibidos;
    Cola Cocina;
    Cola ExpedicionNorte;
    Cola ExpedicionSur;
    Cola ExpedicionEste;
    Cola ExpedicionOeste;
    Cola Preparacion especial;
    int opcion;
    bool abierto=true;
    while(abierto){
        cout<<"Pizzeria\n"<<"-------------------------------------\n";
        cout<<"Opcion\t\t"<<"Funcion\n";
        cout<<"1\t\t"<<"Generar N pedidos"<<endl;
        cout<<"2\t\t"<<"Mostar pedidos recibidos"<<endl;
        cout<<"3\t\t"<<"Avanzar N pedidos un paso"<<endl;
        cout<<"0\t\t"<<"salir"<<endl;
        cin>>opcion;
        cin.ignore(1000,'\n');
            switch(opcion){
                case 1:{
                    int pedidos=0;
                    cout<<"cuantos pedidos quieres hacer: "<<endl;
                    cin>>pedidos;
                    cin.ignore(1000,'\n');
                    for(int i=0;i<pedidos;++i){
                        Pedido nuevo= generar_pedido();
                        Recibidos.encolar(nuevo);}
                    break;
                }
                case 2:{
                    Recibidos.mostrar();
                    break;
                }

                case 3:{
                    int num=0;
                    cout<<"Cuantos pedidos vas a avanzar (Maximo 10)?: "<<endl;
                    cin>>num;
                    cin.ignore(1000,'\n');
                    if(num>N_PEDIDOS_PASO){num=10;}
                    cout<<"Has avanzado "<<num<<" pedidos un paso"<<endl;


                }
                case 0:{
                    cout<<"cerrando\n";
                    abierto=false;
                    break;
                }
            }
    }
    return 0;
}
