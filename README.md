# **El juego de la vida**  
## Proyecto del curso de lenguje C  

## Integrantes:  
### Álvarez Gómez Rolando Miguel  
### Reynoso Gálvez Ana Laura  

#### Descripición  
##### Este programa simula "el juego de la vida" que es un juego matemático hecho por John Horton Conway en 1970. Su funcionamiento, a grandes rasgos, es en dos instancias primero verifica qué células mueren dada la primera configuración del arreglo, luego a partir de ese último estado y basándose en las células que quedan vivas verifica qué células pueden revivir, posterirmente verificará qué células mueren dada la nueva configuración y el ciclo se repetirá.

### Reglas del juego
#### Para que una célula siga viva, tiene que tener 2 o 3 vecinas.
#### Si tiene más de 3 vecinas MUERE por sobrepoblación.
#### Si tiene menos de 2, MUERE de soledad.
#### Si una célula está muerta y tiene 3 vecinas vivas. REVIVE.
#### Las células vivas se representan con el caracter "@"
#### Las células muertas re representan con el caracter "."
