#include "ticket.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

// tic == tickets/ticket

// creamos el ticket
ticket* crearTicket(const char* IDe, const char* description)
{
    //pedimos y validamos la memoria que necesitamos para los tickets
    ticket* tic = (ticket*) malloc(sizeof(ticket));
    if(!tic) return NULL;

    strncpy(tic->ID, IDe, 12);
    tic->ID[12] = '\0';

    strncpy(tic->descripcion, description, MAX - 1);
    tic->descripcion[MAX - 1] = '\0';
    // prioridad baja por default que dependiendo de la descripción le asignara su verdadera prioridad automaticamente
    tic->prioridad = BAJA;
    tic->horaRegistrada = time(NULL);

    return tic;
} 

void mostrarTicketIndividual(ticket* ticke)
{
    if(!ticke) return;

    printf("\n---------------------------------------------------\n");
    printf("ID : %s\n", ticke->ID);
    printf("Descripcion problema : %s\n", ticke->descripcion);

    printf("Prioridad : ");
    switch(ticke->prioridad)
    {
        case ALTA: printf("\033[1;31mALTA\033[0m\n"); break;
        case MEDIO: printf("\033[1;33mMEDIA\033[0m\n"); break;
        case BAJA: printf("\033[0;32mBAJA\033[0m\n"); break;
    }
    


    struct tm* timeInf = localtime(&ticke->horaRegistrada);

    //char buffer[26];
    //strftime(buffer, 26, "%d/%m/%Y %H:%M:%S", timeInf);
    //printf("Hora registrada : %s\n", buffer);

    printf("Fecha registrada : %02d/%02d/%04d\n", 
           timeInf->tm_mday, timeInf->tm_mon + 1, timeInf->tm_year + 1900);
    printf("Hora registrada  : %02d:%02d:%02d\n", 
           timeInf->tm_hour, timeInf->tm_min, timeInf->tm_sec);

    printf("---------------------------------------------------\n\n");

}

//funcion para poner el texto en minucula
void tolowerCase(char* cadena)
{
    for(int i = 0; cadena[i]; i++)
    {
        cadena[i] = tolower((unsigned char) cadena[i]);
    }
}

// funcion que define la prioridad
int definePriority(const char* mensaje)
{
    char text[500];
    strncpy(text, mensaje, (sizeof(text) - 1));
    text[sizeof(text) - 1] = '\0';
    tolowerCase(text);

    //palabras definidas para ir comparando con las de la descripcion del usuario
    // y así asignares prioridad de manera 'justa'

    const char *alta[] = {
        "exploto","incendio","fuego","quemado","electrocut","urgente","peligro",
        "derrame","derramo","sangre","accidente","grave","colapso","choque",
        "derrumbre","explosion","critico","alarma","desmayo","paro","emergencia",
        "inundacion","no arranca","no funciona nada","humo","olor a quemado","falla grave", "agua"
    };

    const char *media[] = {
        "quebro","pantalla rota","pantalla negra","pantalla negro","pantalla congelada",
        "daño leve","error","lento","lentitud","bloqueo","bloqueos parciales",
        "ruido extraño","fallo en aplicacion","teclado no responde","raton no funciona",
        "no carga programa","problema conexion","internet intermitente","se reinicia solo",
        "no enciende bien","calienta mucho","pantalla azul","reinicio inesperado",
        "cuelgue","intermitente","bateria no carga","golpe fuerte","teclas pegadas"
    };

    // se realizan las operaciones correspondiente
    for (size_t i = 0; i < sizeof(alta)/sizeof(alta[0]); ++i)
        if (strstr(text, alta[i])) return ALTA;

    for (size_t i = 0; i < sizeof(media)/sizeof(media[0]); ++i)
        if (strstr(text, media[i])) return MEDIO;

        return BAJA;
}
