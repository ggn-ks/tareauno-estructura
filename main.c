#include <stdio.h>
#include "TDAs/core.h"
#include "TDAs/ticket.h"
#include "TDAs/list.h"

int main()
{
    List* colaTickets = list_create();
    int opcion;
    do
    { 
        opcion = menu();
        switch(opcion)
        {
            case 1:
                registrarTicket(colaTickets);
                break;

            case 2:
                mostrarTicket(colaTickets);
                break;

            case 3:  
                procesarTicket(colaTickets);
                break;
            
            case 4:
                buscarTicket(colaTickets);
                break;
            
            case 0:
                printf("\n\nSaliendo del programa . . .\n");    
                break;

            default:
                printf("\033[1;31mOPCION INVALIDA!\033[1;31m\n");
                printf("\033[1;31mIntente nuevamente con una opcion valida\033[0m\n");
                printf(":)\n");
            }

            if(opcion != 0)
            {
                printf("\n Presione ENTER para volver al MENU . . .\n");
                getchar();
            }

    } while (opcion != 0);

    return 0;
}