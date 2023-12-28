# Sockets-en-C

![presentacion](https://github.com/Seba-SL/Sockets-en-C/assets/65742172/75557a66-510c-4730-9c20-1d5e3c3909da)

Para la comunicación por medio del protocolo TCP/UDP entre dos programas se puede hacer mediante diferentes API's , una de esas APIs es la conocida como Sockets (BSD: Berkeley sockets).

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
Servicios provistos usualmente por el sistema operativo, los cuales
brindan una interface entre componentes de software en la capa de
aplicación y protocolos de red específicos.




Fuentes:

https://cs.uns.edu.ar/~ldm/data/rc/apuntes/introduccion_al_uso_de_sockets.pdf

https://ocw.unican.es/pluginfile.php/2343/course/section/2300/PIR-Practica4_ManualSocketsC.pdf

https://blog.facialix.com/wp-content/uploads/2022/05/Programacion-de-Sockets-M3.pdf
