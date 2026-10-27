#include "Pedido.h"
char* tipoToString(Tipo_pizza t)
{
    switch(t)
    {
    case Margarita:
    {
        return "Margarita";
    }
    case Barbacoa:
    {
        return "Barbacoa";
    }
    case Vegetal:
    {
        return "Vegetal";
    }
    case Hawaiana:
    {
        return "Hawaiana";
    }
    case Romana:
    {
        return "Romana";
    }
    case Cuatro_quesos:
    {
        return "Cuatro Quesos";
    }
    }
    return "";
}
char *tamanoToString(Tamano tam)
{

    switch(tam)
    {
    case Mediano:
    {
        return "Mediano";
    }
    case Grande:
    {
        return "Grande";
    }
    }
    return "";
}
char* zonaToString(Zona_reparto zona)
{
    switch(zona)
    {
    case Norte:
    {
        return "Norte";
    }
    case Sur:
    {
        return "Sur";
    }
    case Este:
    {
        return "Este";
    }
    case Oeste:
    {
        return "Oeste";
    }
    }
    return "";
}
char* estadoToString(Estado estado)
{
    switch(estado)
    {
    case Recibido:
    {
        return "Recibido";
    }
    case Preparacion_especial:
    {
        return "Preparacion Especial";
    }
    case cocina:
    {
        return "Cocina";
    }
    case Expedicion:
    {
        return "Expedicion";
    }
    case Caja:
    {
        return "Caja";
    }
    case Enviado:
    {
        return "Enviado";
    }

    case Retirado:
    {
        return "Retirado";
    }
    }
    return "";
}


