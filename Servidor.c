#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<netdb.h>
#include <stdbool.h>

#define MAX_BUFFER 4096
#define PORT 5000  
#define BACKLOG 10 /* Tamaño de la cola de conexiones recibidas */
#define DIRECCION_IP_SERVIDOR "local_host"
#define ERROR_GENERAL -1

typedef enum {OK ,ERROR}estado_t;

int abrir_conexion(int port, int backlog, int debug);
int aceptar_pedidos(int sockfd, int debug);


// ./cliente "puerto"

int main(int argc, char **argv)
{

  int sock = 0,sockup ,bytes_recibidos = 0 ,puerto ;
  char msg[MAX_BUFFER],buff[MAX_BUFFER];
   char direccion_ip[MAX_BUFFER];
	
	if(argc != 2)
	{
		printf("Por defecto se conecta al puerto %d \n",PORT);
		puerto = PORT;
		
	}else{
		
		puerto = (int) strtol(argv[1], NULL, 10);
		
	}



  sock = abrir_conexion(puerto ,10, 1);

		
  if(sock == ERROR_GENERAL)
	{
		return ERROR_GENERAL;
	}

  printf("\nSe establecio el servidor correctamente en el puerto %d , esperando clientes \n", puerto);

sockup = aceptar_pedidos(sock, 1);


while( strcmp(buff , "adios") != 0 )
{	
	 
  		

        printf("\nEsperando mensaje del cliente...\n");

        // Recibe el mensaje del cliente
        bytes_recibidos = recv(sockup, buff, sizeof(buff), 0);

        if (bytes_recibidos > 0) {
            buff[bytes_recibidos] = '\0'; // Asegúrate de terminar la cadena
            printf("\nSe recibió del cliente: %s\n", buff);
        }

		fflush(stdin);
        printf("\nEnviar mensaje al cliente: ");
        fgets(msg, MAX_BUFFER, stdin);

        // Envía el mensaje de vuelta al cliente
        write(sockup , msg , strlen(msg));

      
}	

  close(sockup);
  close(sock);

  return OK;

}

int abrir_conexion(int port, int backlog, int debug)
{
	int sockaux; /*socket auxiliar*/
	int aux;	 /*variable auxiliar*/
	struct sockaddr_in mi_direccion;

	/*Crea un socket y verifica si hubo algún error*/
	if ((sockaux = socket(PF_INET, SOCK_STREAM, 0)) == ERROR_GENERAL)
	{
		fprintf(stderr, "Error en función socket(). Código de error %s\n", strerror(sockaux));
		return ERROR_GENERAL;
	}
	if (debug)
		fprintf(stderr, "debug:: abrir_conexion() socket()=%d\t..........OK\n", sockaux);

	// reuso por timeout inmediato
	int optval = 1;
	if (setsockopt(sockaux, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0)
	{
		fprintf(stderr, "Error en función setsockopt()\n");
		return ERROR_GENERAL;
	}
	if (debug)
		fprintf(stderr, "debug:: abrir_conexion() setsockopt()\t..........OK\n");

	/* Asignamos valores a la estructura mi_direccion */

	if (port == 0)
		port = PORT;

	mi_direccion.sin_family = PF_INET;		  /* familia de sockets INET para UNIX*/
	mi_direccion.sin_port = htons(port);		  /* convierte el entero formato PC a entero formato network*/
	mi_direccion.sin_addr.s_addr = INADDR_ANY; /* automaticamente usa la IP local */
	bzero(&(mi_direccion.sin_zero), 8);		  /* rellena con ceros el resto de la estructura */

	/* Con la estructura sockaddr_in completa, se declara en el Sistema que este proceso escuchará pedidos por la IP y el port definidos*/
	if ((aux = bind(sockaux, (struct sockaddr *)&mi_direccion, sizeof(struct sockaddr))) == ERROR_GENERAL)
	{
		fprintf(stderr, "Error en función bind. Código de error %s\n", strerror(aux));
		return ERROR_GENERAL;
	}
	if (debug)
		fprintf(stderr, "debug:: abrir_conexion() bind()\t\t..........OK\n");

	/* Habilitamos el socket para recibir conexiones, con una cola de conexiones en espera que tendrá como máximo el tamaño especificado en BACKLOG*/

	if (backlog == 0)
		backlog = BACKLOG;

	if ((aux = listen(sockaux, backlog)) == ERROR_GENERAL)
	{
		fprintf(stderr, "Error en función listen. Código de error %s\n", strerror(aux));
		return ERROR_GENERAL;
	}
	if (debug)
		fprintf(stderr, "debug:: abrir_conexion() listen()\t..........OK\n");

	return sockaux;
}



int aceptar_pedidos(int sockfd, int debug)
{
	int newfd;					   /* Por este socket duplicado del inicial se transaccionará*/
	struct sockaddr_in su_direccion; /* Contendra la direccion IP y número de puerto del cliente */
	unsigned int sin_size = sizeof(struct sockaddr_in);

	/*Se espera por conexiones ,*/
	if ((newfd = accept(sockfd, (struct sockaddr *)&su_direccion, &sin_size)) == ERROR_GENERAL)
	{
		fprintf(stderr, "Error en función accept. Código de error %s\n", strerror(newfd));
		return ERROR_GENERAL;
	}
	else
	{
		if (debug)
			fprintf(stderr, "debug:: aceptar_pedidos() conexión desde: %s\n", inet_ntoa(su_direccion.sin_addr));

		return newfd;
	}
}