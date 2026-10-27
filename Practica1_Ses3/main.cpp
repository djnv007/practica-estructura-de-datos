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
Cola Finalizados;

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

void meterEnCaja(Pila &Caja, Pedido p, int &contadorCajas)
{
    Caja.apilar(p);

    if(Caja.getCapacidad() == CAP_CAJA)
    {
        contadorCajas++;

        Caja.vaciar();
    }
}


void avanzar_N_pedidos(int n)
{
    Pedido p;
    int contador=0;
    while(!ExpedicionNorte.esVacia()&&contador<n)
    {
        ExpedicionNorte.desencolar(p);

        p.estado = Caja;

        meterEnCaja(CajaNorte,p,CajasCompletasNorte);
        contador++;
    }
    contador=0;
    while(!ExpedicionSur.esVacia()&&contador<n)
    {
        ExpedicionSur.desencolar(p);

        p.estado = Caja;

        meterEnCaja(CajaSur,p,CajasCompletasSur);
        contador++;
    }
    contador=0;
    while(!ExpedicionEste.esVacia()&&contador<n)
    {
        ExpedicionEste.desencolar(p);

        p.estado = Caja;

        meterEnCaja(CajaEste,p,CajasCompletasEste);

        contador++;
    }
    contador=0;
    while(!ExpedicionOeste.esVacia()&&contador<n)
    {
        ExpedicionOeste.desencolar(p);

        p.estado = Caja;

        meterEnCaja(CajaOeste,p,CajasCompletasOeste);
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
bool retirarPedido(Pila &caja, char id[])
{
    Pila auxiliar;

    Pedido p;
    bool encontrado = false;

    while(caja.desapilar(p))
    {
        if(strcmp(p.id_pedido,id)==0)
        {
            encontrado = true;
            break;
        }

        auxiliar.apilar(p);
    }

    while(auxiliar.desapilar(p))
    {
        caja.apilar(p);
    }

    return encontrado;
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
        cout<<"4\t\t"<<"Ver caja activa"<<endl;
        cout<<"5\t\t"<<"Retirar pedido de una caja"<<endl;
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
            cout << "\n=========== CAJAS TERMICAS ===========" << endl;

            cout << "Zona Norte -> activa: "
                 << CajaNorte.getCapacidad()
                 << "/" << CAP_CAJA
                 << " enviadas: "
                 << CajasCompletasNorte
                 << endl;

            cout << "Zona Sur -> activa: "
                 << CajaSur.getCapacidad()
                 << "/" << CAP_CAJA
                 << " enviadas: "
                 << CajasCompletasSur
                 << endl;

            cout << "Zona Este -> activa: "
                 << CajaEste.getCapacidad()
                 << "/" << CAP_CAJA
                 << " enviadas: "
                 << CajasCompletasEste
                 << endl;

            cout << "Zona Oeste -> activa: "
                 << CajaOeste.getCapacidad()
                 << "/" << CAP_CAJA
                 << " enviadas: "
                 << CajasCompletasOeste
                 << endl;
                 int totalCajas =
    CajasCompletasNorte +
    CajasCompletasSur +
    CajasCompletasEste +
    CajasCompletasOeste;

cout << "\nTotal de cajas enviadas: "
     << totalCajas
     << endl;
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
        case 4:
        {
            int zona;

            cout << "Seleccione zona:\n";
            cout << "1 - Norte\n";
            cout << "2 - Sur\n";
            cout << "3 - Este\n";
            cout << "4 - Oeste\n";

            cin >> zona;

            switch(zona)
            {
            case 1:
                cout << "\n=== CAJA ACTIVA: ZONA NORTE ===\n";
                CajaNorte.mostrar();
                break;

            case 2:
                cout << "\n=== CAJA ACTIVA: ZONA SUR ===\n";
                CajaSur.mostrar();
                break;

            case 3:
                cout << "\n=== CAJA ACTIVA: ZONA ESTE ===\n";
                CajaEste.mostrar();
                break;

            case 4:
                cout << "\n=== CAJA ACTIVA: ZONA OESTE ===\n";
                CajaOeste.mostrar();
                break;

            default:
                cout << "Zona no valida\n";
            }

            break;

        }
        case 5:
        {
            int zona;
            char id[7];

            cout << "Seleccione zona:\n";
            cout << "1 - Norte\n";
            cout << "2 - Sur\n";
            cout << "3 - Este\n";
            cout << "4 - Oeste\n";

            cin >> zona;

            cout << "Introduzca el ID del pedido: ";
            cin >> id;

            bool eliminado = false;

            switch(zona)
            {
            case 1:
                eliminado = retirarPedido(CajaNorte,id);
                break;

            case 2:
                eliminado = retirarPedido(CajaSur,id);
                break;

            case 3:
                eliminado = retirarPedido(CajaEste,id);
                break;

            case 4:
                eliminado = retirarPedido(CajaOeste,id);
                break;

            default:
                cout << "Zona no valida\n";
                break;
            }

            if(eliminado)
            {
                cout << "Pedido retirado correctamente.\n";
            }
            else
            {
                cout << "Pedido no encontrado.\n";
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
