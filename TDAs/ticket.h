#ifndef TICKET_H
#define TICKET_H

#include "list.h"
#include <time.h>
#include <stdbool.h>

#define MAX 500

//numero de prioridad
typedef enum { ALTA = 1, MEDIO = 2, BAJA = 3 } priority;

// estructura empleada para el ticket
typedef struct ticket
{
    char ID[13];
    char descripcion[MAX];
    priority prioridad;
    time_t horaRegistrada;
    bool estadoTicket; // false para cunado este pendiente y true para cuando ya haya sido tratado "atendido"
} ticket;

// crea el ticket
ticket* crearTicket(const char* ID, const char* descripcion);

// muestra los tickets 1 a 1 
void mostrarTicketIndividual(ticket* ticke);

// define la prioridad del ticket
int definePriority(const char* mensaje);

#endif