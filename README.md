## Datos estudiante
- **NOMBRE :** Ignacia Curaqueo González
- **RUN :** 22.025.464-K

# SISTEMA DE GESTIÓN DE TICKETS SOPORTE TÉCNICO

### descripción
*Este programa tienen como objetivo principal el administrar los **tickets de un soporte tecnico** siguiendo el sistema de una cola con prioridad donde el ticket representa una solicitud ingresada por el usuario.El programa busca que la gestión de tickets sea directa y sencilla, ofreciendo herramientas para registrar y buscar tickets, establecer su prioridad (alta, media o baja), mostrar los pendientes y procesar primero aquellos con alta prioridad o mayor urgencia.*


## Tabla de contenidos
1. [Instalación y requerimientos](#Instalación-y-requerimientos)
2. [Compilación del programa](#Compilación-del-programa)
3. [Funciones del programa](#Funciones-del-programa)
4. [Posibles fallas](#Posibles-fallas)
5. [Ejemplos de ejecución](#Ejemplos-de-ejecución)


## Instalación y requerimientos
Para lograr ejecutar el programa necesitará:
1. Tener instalado Visual Studio Code, junto a la extensión C/C++ de Microsoft
2. Tener un compilador de C instalado. Para windows, es recomendable utilizar MinGW

> NOTA : Si por alguna razón no puede ejecutar el programa porque no reconce `programa.exe`, asegúrese de que su antivirus no esté bloqueando la ejecución.

Una consideración adicional a tener en cuenta, si por alguna razon no le es posible ejecutar el programa porque no reconce 'programa.exe' deberia considerar el  otorgar los permisos necesarios de su antivirus para lograr la ejecución del programa.

## Compilación del programa

1. Descargar el repositorio como archivo `.zip` y descomprimirlo
tutorial de descargar el repositorio :
2. Abrir la carpeta descomprimida en visual studio code
3. Abrir la terminal **Git Bash** dentro de visual studio code
4. Compilar con el siguiente comando:
```gcc main.c TDAs/core.c TDAs/ticket.c TDAs/list.c -o programa```
5. Ejecutar el programa:
```./programa.exe```

***Ejemplo de ejecución :***

![Mi gif](https://media4.giphy.com/media/v1.Y2lkPTc5MGI3NjExNmNvMGZoYjRjdGwxaGxrbWZocDRpdGtiZmt4eWFraDl0NnNza2JyeiZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/jIeJeFzTf8Y7sr9fTT/giphy.gif)

## Funciones del programa

el programa cuenta con 4 funciones principales : 

- `void registrarTicket(List* cola)`
Permite ingresar un nuevo ticket con ID y descripción.

- `void mostrarTicket(List* cola)`
Permite mostrar la lista de ticktes pendientes

- `void procesarTicket(List* cola)`
Permite procesar los tickes segun prioridad

- `void buscarTicket(List* cola)`
Permite buscar el ticket por la ID de este

## Posibles fallas

El programa puede fallar en distintos aspectos 2 de esos son lo siguientes:

1. *Mostrar los tickets por prioridad*
El programa si bien procesa los tickets por prioridad al momento de mostrarlos en el listado de tickets pendientes estos estarán por orden de llegada y no por el de prioridad

2. *Mostrar el estado del ticket*
Si el ticket no ha sido procesado al momento de buscarlo saldrá pendiente; sin embargo, si el ticket ya fue procesado no.
El programa al procesar los tickets los saca de la cola por lo que no tenemos una copia del ticket para mostrarlo como "ATENDIDO"

> ¿Comó podríamos solucionar esto?
> Teniendo dos colas, la principal y una auxiliar donde se vaya ordenando por prioridad y según el orden de llegada en caso de tener la misma prioridad. Tenemos un respaldo de los tickets por lo que podriamos asignar con mayor facilidad el estado del ticket.

3. *Al momento de ingresar una ID*
Si la ID no tiene los '000' solicitados te indica que no es posible; sin embargo, al ingresar más de 12 numeros no pasa nada.


## Ejemplos de ejecución 

### *MENU 1*
![funcion menu 1](https://media4.giphy.com/media/v1.Y2lkPTc5MGI3NjExb28yZnQwd3VqMXZvaHg0Z2Ewa2ZscXducWYxNWV4bnN5czh6bTFtOSZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/6C2HLZLrVTiVi4b00e/giphy.gif)

***para descripción vacía***

![Mi gif](https://media1.giphy.com/media/v1.Y2lkPTc5MGI3NjExbmZpMmV3ZnJneGZyY3p5Mmh1anJ6dnJ0dWZ3Y3Nyczhqa2F6bmphNSZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/YVmmBnsKpJzxx4gijS/giphy.gif)

***para ID ya existente***

![Mi gif](https://media1.giphy.com/media/v1.Y2lkPTc5MGI3NjExcnlpdGJ4Z29sdnk1ZGRhNXBoYTZhYmw1OGY3cndzYjFuMW9rb3Z6biZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/IUINvTiznJCF30QwC9/giphy.gif)

### *MENU 2*
![Mi gif](https://media2.giphy.com/media/v1.Y2lkPTc5MGI3NjExNWNic3p6cm5lMXY3dWk5NTBjZTl1a2gxcmZ4ZzF3d3FubXRqMm14cCZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/0IzrAIXdR8oaKm4rXR/giphy.gif)

### *MENU 3*
![Mi gif](https://media2.giphy.com/media/v1.Y2lkPTc5MGI3NjExZGprbTMwdzBlcnlkaWYzdTNsdThodzFnbHVuejdjc2htNDBhY3NyayZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/iNFWROGJ14Wlf0blAd/giphy.gif)

### *MENU 4*
![Mi gif](https://media0.giphy.com/media/v1.Y2lkPTc5MGI3NjExNjB2ZXRqYmo3ODh1aDEyMjM5bThtZGlndDU4bjdyZjJlZjIxbzdneiZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/VOvhsFmw3JiCsUirZF/giphy.gif)

***para ID no encontrada - opción s***

![Mi gif](https://media1.giphy.com/media/v1.Y2lkPTc5MGI3NjExZ3Q1emhwa3FmeDhjdG5hemVyYWxqZWQyZ2JsNnJtOXoyamMxd2psdCZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/cxCRupv57c9ESdBblI/giphy.gif)

***para ID no encontrada - opción n***

![Mi gif](https://media4.giphy.com/media/v1.Y2lkPTc5MGI3NjExMnZ0aDd1OG0zY2ZkYW54dHpqOWhnOWp5ano0NWszMTF6bnV4b2NjOCZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/MfpQDjzzvbM5L1KhIe/giphy.gif)

### *MENU 0*

![Mi gif](https://media2.giphy.com/media/v1.Y2lkPTc5MGI3NjExeWZ0YjE5bzNiMmRhczd2Y2RxNmNrdjdpNTdtMXhvejMwbXp5YnJvayZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/Pr5bBIIPBJ6gBor362/giphy.gif)




