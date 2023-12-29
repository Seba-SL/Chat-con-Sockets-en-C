# Sockets-en-C

![presentacion](https://github.com/Seba-SL/Sockets-en-C/assets/65742172/75557a66-510c-4730-9c20-1d5e3c3909da)

En este proyecto se crea una conexion por medio de sockets en lenguaje C , para enviar y recibir mensajes a traves de un cliente y un servidor.

- Para compilar:

```bash
gcc -o Servidor Servidor.c
```

- Para ejecutar:

```bash
./Servidor "puerto"
```

```bash
gcc -o Cliente Cliente.c
```

- Para ejecutar:

```bash
./Cliente "Direccion-ip" "puerto"
```

Para la comunicación por medio del protocolo TCP/UDP entre dos programas se puede hacer mediante diferentes API's , una de esas APIs es la conocida como Sockets (BSD: Berkeley sockets).

TCP : Transmission Control Protocol

El rol de TCP es garantizar que los paquetes se entreguen de forma confiable y sin errores. TCP tiene control de concurrencia, lo que significa que las solicitudes iniciales serán pequeñas, aumentando de tamaño a los niveles de ancho de banda que los ordenadores, servidores y redes puedan soportar.

UDP : User Datagram Protocol

se utiliza en Internet para transmisiones sujetas a limitaciones temporales, como la reproducción de vídeo o las búsquedas en DNS. Acelera las comunicaciones al no establecer formalmente una conexión antes de transferir los datos. Esto permite que los datos se transfieran muy rápido, pero también puede hacer que los paquetes se pierdan en tránsito 

![image](https://github.com/Seba-SL/Sockets-en-C/assets/65742172/9a60897c-0a11-44e1-bc60-9deeae34beb2)


En este caso se hara uso del protocolo TCP.

Los sockets son una de las herramientas que ofrecen los Sistemas Operativos para la comunicación entre diferentes procesos. La particularidad que tienen frente a otros
mecanismos de comunicación entre procesos (IPC – Inter-Process Communication) es que posibilitan la comunicación aún cuando ambos procesos estén corriendo en distintos 
sistemas unidos mediante una red. De hecho, el API de sockets es la base de cualquier aplicación que funcione en red puesto que ofrece una librería de funciones
básicas que el programador puede usar para desarrollar aplicaciones en red.

Definición de Socket : Representación abstracta de un punto de comunicación , que permite establecer un canal de comunicación entre dos rutinas o programas.

• Los podemos considerar como archivos, que se crean de manera especial.

• Los sockets trabajan con los servicios de entrada/salida de sistemas operativos del tipo Unix.

•Diversos programas corriendo en computadoras diferentes dentro de una red, pueden comunicarse a través del uso de sockets.

![Sockets_presentacion drawio (2)](https://github.com/Seba-SL/Sockets-en-C/assets/65742172/957dd693-97b5-45a1-88dc-e84529bcdfef)

NAPI (Network Application Programming Interface):
Servicios provistos usualmente por el sistema operativo, los cuales brindan una interface entre componentes de software en la capa de aplicación y protocolos de red específicos.


Los Sockets para TCP/IP en cada máquina pueden estar ejecutándose múltiples procesos simultáneamente. Cada uno de estos procesos se asocia con un número de puerto, para poder así diferenciar los
distintos paquetes que reciba la máquina (proceso de multiplexación).Un socket se identifica unívocamente por la dupla dirección IP + número de puerto.

Una comunicación entre dos procesos se identifica mediante la asociación de los sockets que estos emplean para enviar y recibir información hacia y desde la red:
identificador de socket origen + identificador de socket destino

![estructura](https://github.com/Seba-SL/Sockets-en-C/assets/65742172/4bba6823-10c7-4757-be41-66360792e02c)



Fuentes:

https://cs.uns.edu.ar/~ldm/data/rc/apuntes/introduccion_al_uso_de_sockets.pdf

https://ocw.unican.es/pluginfile.php/2343/course/section/2300/PIR-Practica4_ManualSocketsC.pdf

https://blog.facialix.com/wp-content/uploads/2022/05/Programacion-de-Sockets-M3.pdf
