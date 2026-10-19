#include "pizzeria.h"
#include <cstring>

NodoCola::NodoCola(Pedido p, NodoCola* sig){
    datos=p;
    siguiente=sig;
}

Cola::Cola(){
    primero = NULL;
    ultimo= NULL;
    longitud=0;
}
Cola::~Cola(){}
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
void Cola::mostrar(){
    if (esVacia()){
        cout<<"Cola vacia\n";
        return;
    }
    NodoCola* aux= primero;
    while(aux!=NULL){
        Pedido p= aux->datos;
        cout<<"\n ---------------------------------------\n";
        cout<<"Pedido: "<<p.id_pedido<<endl;
        cout<<"Cliente: "<<p.id_cliente<<endl;
        cout<<"Pizza: "<<p.tipo_pizza<<endl;
        cout<<"Tamanio: "<<p.tamano<<endl;
        cout<<"Zona: "<<p.zona_reparto<<endl;
        cout<<"Personalizado: "<<p.personalizada<<endl;
        cout<<"Estado: "<<p.estado<<endl;
        cout << "\n ------------------------------------\n";
        aux=aux->siguiente;
    }
}
Pedido generar_pedido(){
    Pedido p;
    char id_aux[7]= "P01234";
    for(int i=1;i<6;++i){
        char cifra= '0'+rand()%10;
        id_aux[i]=cifra;
    }
    strcpy(p.id_pedido, id_aux);

    int num=100+rand()%900;
    p.id_cliente=num;
    p.tipo_pizza = static_cast<Tipo_pizza>(rand()%6);
    p.tamano = static_cast <Tamano> (rand()%2);
    p.zona_reparto = static_cast<Zona_reparto> (rand()%4);
    p.personalizada= (rand()%100) < PROB_PERSOONALIZACION;
    p.estado = Recibido;
    return p;


}
