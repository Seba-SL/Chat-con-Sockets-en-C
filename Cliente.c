#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include <stdbool.h>

#define MAX_BUFFER 4096
#define PORT 8000  

#define ERROR_GENERAL -1


typedef enum {OK ,ERROR}estado_t;

int conectar(char *hostname, int port, int debug);


int main(int argc, char **argv)
{
  int sock,bytes_recibidos;
  char buff[MAX_BUFFER] , msg[MAX_BUFFER];

  


while( strcmp(buff , "adios") != 0)
{
  sock =  conectar("localhost", 8000,0);
  bytes_recibidos = read(sock , buff , MAX_BUFFER );

  buff[bytes_recibidos] = 0;


  if( strlen(buff) > 0 )
 	printf("\nSe recibio del servidor : %s \n",buff);


  puts("Enviar msg\n");
  fgets(msg,MAX_BUFFER ,stdin);

  send(sock , msg , strlen(msg) , 0 );

  


}

  close(sock);

 return OK;

}

//debug es un parametro para mostrar o no los errores 
int conectar(char *hostname, int port, int debug)
{
	int sockfd;
	struct hostent *he;			   /* Se utiliza para convertir el nombre del host a su dirección IP */
	struct sockaddr_in su_direccion; /* dirección del server donde se conectará */

	// convertimos el nombre del host a su dirección IP
	if ((he = gethostbyname(hostname)) == NULL)
	{
		herror("Error en Nombre de Host");
		exit(1);
	}

	/* Creamos el socket con socket()
	  Parametros---> familia de direcciones INET  , tipo de socket SOCKET_STREAM = TCP   , protocolo , determina la capa de transporte 
	  devuelve un entero , si es -1 no se pudo crear  , de lo contrario devuelve un descriptor del archivo de socket 
	*/
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == ERROR_GENERAL)
	{
		perror("Error en creación de socket");
		exit(1);
	}
	if (debug)
		fprintf(stderr, "debug:: conectar() socket()=%d\t\t..........OK\n", sockfd);

	if (debug)
		fprintf(stderr, "debug:: conectar() dst port()=%d\t..........OK\n", port);

	port = (port == 0) ? htons(PORT) : htons(port);

	/* Establecemos su_direccion con la direccion del server */
	su_direccion.sin_family = AF_INET; //familia de direccion 
	su_direccion.sin_port = port;
	su_direccion.sin_addr = *((struct in_addr *)he->h_addr);
	bzero(&(su_direccion.sin_zero), 8);

	/* Intentamos conectarnos con el servidor
	
		parametros (socket , direccion , tanaño)
	 */
	if (connect(sockfd, (struct sockaddr *)&su_direccion, sizeof(struct sockaddr)) == ERROR_GENERAL)
	{
		perror("conectar():: error tratando de conectar al server");
		exit(1);
	}
	if (debug)
		fprintf(stderr, "debug:: conectar() connect()\t\t..........OK\n");

	return sockfd;



}