#include "core.h"
#include "ticket.h"
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// funciones mini

//parametro 'mensaje' hace referencia al titulo que deseamos que tenga nuestro encabezado
// parametro 'largo' hace referencia a la cantidad de extension en la que desearemos nuestro borde superior e inferior
void mostrarEncabezados(const char* mensaje, int largo)
{
    printf("\n");
    
    // linea superior
    for(int i = 0; i < largo; i++) printf("=");
    printf("\n");

    // lines 20 - 27
    // en esta parte del codigo realizamos estas operaciones para lograr dejar el texto centrado
    int len = strlen(mensaje);
    int espacios = (largo - len) / 2;

    for(int k = 0; k < espacios; k++) printf(" ");
    printf("%s\n", mensaje);

    // linea inferior
    for(int j = 0; j < largo; j++) printf("=");
    printf("\n\n");
}

// funciones principales :)

int menu()
{
    int opcion;

    printf("\033[1;34m");
    mostrarEncabezados("MENU DE TICKETS", 51);

    printf("(1) Registrar ticket\n");
    printf("(2) Mostrar lista de tickets pendientes\n");
    printf("(3) Procesar ticket\n");
    printf("(4) Buscar ticket por ID\n");
    printf("(0) Salir del programa\n\n");

    printf("Seleccione una opcion : ");
    printf("\033[0m");
    scanf("%d", &opcion);

    return opcion;
}


void registrarTicket(List* cola)
{
    char ID[13];
    char descripcion[500];

    printf("\n");
    mostrarEncabezados("REGISTRO DE TICKET", 51);

    printf("Ingrese el ID de su ticket\n");
    printf("formato : 000XXXXXXXXX\n");
    scanf("%12s", ID);

    // Este bloque limpia el buffer de entrada después de usar scanf(), eliminando cualquier carácter sobrante (como '\n').
    // Lo hacemos para que la próxima lectura de texto, como con fgets(), funcione correctamente sin problemas.
    // Uno de estos problemas podría presentarse al momento de comparar dos cadenas porque leemos el '\n' 
    //En este caso en concreto podría afectar a las validaciónes de las ID, las descripciones o cualquier
    // lectura de texto que exista en esta funcion

    int variableTem;
    while ((variableTem = getchar()) != '\n' && variableTem != EOF);

    // En este if cuidamos que el usuario respete el formato de ingreso de la ID
    if(strncmp(ID, "000", 3) != 0)
    {
        printf("\033[1;31mID INVALIDO\033[1;31m\n");
        printf("\033[1;31mERROR: EL ID DEBE EMPEZAR CON 000\033[0m\n");
        return;
    }
    // en este if cuidamos que el usuario no pase el maximo de numeros de la ID
    if(strlen(ID) != 12)
    {
        printf("\033[1;31mID INVALIDO\033[1;31m\n");
        printf("\033[1;31mERROR : EL ID DEBE TENER 12 DIGITOS\033[0m\n");
        return;
    }

    // en esta parte validamos que no se este ingresando una ID ya registrada
    ticket* ticketAnterior = (ticket*) list_first(cola);
    while (ticketAnterior != NULL)
    {
        if((strcmp(ticketAnterior->ID, ID) == 0))
        {
            printf("\033[1;31mERROR : YA EXISTE UN TICKET CON ESA ID\033[1;31m\n");
            printf("\033[1;31mPruebe con otra ID\033[0m\n");
            return;
        }
        ticketAnterior = (ticket*) list_next(cola);
    }
    

    printf("Ingrese la descripcion del problema: \n");
    fgets(descripcion, sizeof(descripcion), stdin);

    int largo = strlen(descripcion);
    // En este bloque del codigo cuidamos que el usuario no deje la descripción vacía
    while(largo > 0 && (descripcion[largo - 1] == '\n' || descripcion[largo - 1] == ' '))
    {
        descripcion[--largo] = '\0';
    }

    if (largo == 0)
    {
        printf("\033[1;31mERROR: LA DESCRIPCION NO PUEDE ESTAR VACIA\033[0m\n");
        printf("\033[1;31mVUELVA A INTENTAR\033[0m\n");
        return; 
    }    

    // creamos y guardamos el ticket
    ticket* tickets = crearTicket(ID, descripcion); 
    tickets->prioridad = definePriority(descripcion);
    tickets->horaRegistrada = time(NULL);
    tickets->estadoTicket = false;

    list_pushBack(cola, tickets);
    
    printf("\n\033[0;34msu ticket ha sido registrado correctamente :D\033[0m\n");
    printf("\033[0;34mA continuacion el ticket registrado : \033[0m\n");

    printf("\n");
    printf("\n");
    printf("\033[1;34m");
    mostrarEncabezados("TICKET REGISTRADO !", 51);
    printf("\033[0m");

    // mostramos el ticket guardado
    mostrarTicketIndividual(tickets);
}

void mostrarTicket(List* cola)
{
    if(list_size(cola) == 0)
    {
        printf("\nNO HAY TICKETS PENDIENTES !\n\n");
        return;
    }

    printf("\n");
    mostrarEncabezados("MOSTRAR LISTA DE TICKETS PENDIENTES", 51);

    // contador para poder ir imprimiendo el numero del ticket
    int contador = 1;
    ticket* tic = (ticket*) list_first(cola);
   
    // tic es nuestra cola y verificamos que tenga datos
    while (tic != NULL)
    {
        // finalmente imprimios el ticket
        printf("\033[0;35mTICKET #%d\033[0m", contador);
        mostrarTicketIndividual(tic);
        tic = (ticket*) list_next(cola);
        contador++;
    }
}

void procesarTicket(List* cola)
{
    // nuevamente verificamos que la cola efectivamente tenga datos
    if(list_size(cola) == 0)
    {
        printf("No hay tickets para procesar . . .");
        return;
    }
    // si la cola efectivamente tiene datos procesamos el ticket
    ticket* ticke = (ticket*) list_first(cola);
    ticket* procesar = ticke;

    while(ticke != NULL)
    {
        // verificamos la prioridad para 'atender' al de mayor prioridad
        if(ticke->prioridad < procesar->prioridad)
        {
            procesar = ticke;
        }
        ticke = (ticket*) list_next(cola);
    }

    printf("\n");
    mostrarEncabezados("PROCESANDO TICKET", 51);
    printf("ID : %s\n", procesar->ID);
    printf("Descripcion : %s\n", procesar->descripcion);
    printf("Prioridad :");

    switch(procesar->prioridad)
    {
        case ALTA:  printf("\033[1;31mALTA\033[0m\n"); break;
        case MEDIO: printf("\033[1;33mMEDIA\033[0m\n"); break;
        case BAJA:  printf("\033[0;32mBAJA\033[0m\n"); break;
    }
    // usamos buffer solo como espacio temporal para convertir la fecha/hota en texto legible y asi poder mostrarlo por pantalla
    char buffer[26];
    struct tm* timeInfo = localtime(&procesar->horaRegistrada);
    strftime(buffer, 26, "%d/%m/%Y %H:%M:%S", timeInfo);
    printf("Hora registrada : %s\n",  buffer);
    printf("\n");
    
    ticke = (ticket*) list_first(cola);
    while ((ticke != NULL))
    {
        if(ticke == procesar)
        {
            // si el ticket ya esta procesado lo sacamos de la cola y pasamos al siguiente
            ticke->estadoTicket = true;
            list_popCurrent(cola);
            break;
        }
        ticke = (ticket*) list_next(cola);
    }
}

void buscarTicket(List* cola)
{
    if(list_size(cola) == 0)
    {
        printf("\nNO SE ENCONTRARON TICKETS\n");
        return;
    }
        char IDe[13];
        printf("FORMATO ID 000XXXXXXXXX\n");
        printf("Ingrese la ID del ticket a buscar :\n");
        scanf("%12s", IDe);

        int variableTem;
        while ((variableTem = getchar()) != '\n' && variableTem != EOF);

        ticket* ticketActual = (ticket*) list_first(cola);
        while(ticketActual != NULL)
        {
            // si encontramos el ticket lo mostramos y ademas señalamos si esta pendiente o no
            if(strcmp(ticketActual->ID, IDe) == 0)
            {
                printf("\n\nTicket encontrado : \n");
                mostrarTicketIndividual(ticketActual);
                if (ticketActual->estadoTicket)
                    printf("Estado: \033[\033[0;35mTICKET ATENDIDO\033[0m\n");
                else
                    printf("Estado: \033[1;33mTICKET PENDIENTE\033[0m\n");
        
                return;
            }
            ticketActual = (ticket*) list_next(cola);
        }
        printf("NO SE ENCONTRO NINGUN TICKET CON LA ID : %s\n", IDe);
        
        // aqui preguntamos al usuario si quiere registrar el ticket en caso de no encontrarlo y si sí se le llevara a la opcion 1
        char opcion;
        printf("Desea registrar este ticket ahora? (s = si / n = no)\n");
        scanf(" %c", &opcion);

        if(opcion == 's' || opcion == 'S') 
        {
            registrarTicket(cola);
        }

}