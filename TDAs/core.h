#ifndef CORE_H
#define CORE_H

#include "list.h"

//da el formato de los encabezados
// esta funcion busca ser lo más generica posible para poder utilizarla cuando sea necesaria
void mostrarEncabezados(const char* mensaje, int largo);

// declaración del menú principal
int menu();

// funciones para manejar los tickets

// esta funcion registra los ticktes, leyendo y guardando información relevante como el ide, descripcion, etc
// esta relacionada directamente con el caso 1 del menu
void registrarTicket(List* cola);

// esta funcion muestra la lista de pendientes de la cola
// esta relacionada directamente con el caso 2 del menu
void mostrarTicket(List* cola);

// esta funcion va procesando uno a uno los ticktes segun su prioridad y los va sacando de la cola
// esta relacionada directamente con el caso 3 del menu
void procesarTicket(List* cola);


// esta funcion busca por ID el ticket
// esta relacionada directamente con el caso 4 del menu
void buscarTicket(List* cola);

#endif
