# Recubrimiento de un Grafo no Dirigido
Programa muy básico implementado en c++, en el cual se resuelve el problema de recubrimiento de un grafo usando una técnica greedy.

El problema de recubrimiento de un grafo se puede describir de la siguiente forma:

Consideremos un grafo no dirigido G = (V, E). Un conjunto U ⊆ V se dice que
es un recubrimiento de G si cada arista en E incide en, al menos, un vértice o nodo de
U. Es decir ∀(x, y) ∈ E, bien x ∈ U o y ∈ U .

Uso del algoritmo:
1.Compilar el código fuente.
2.Ejecutar el archivo generado en la carpeta "bin" con nombre "recubrimiento" pasándole como parámetro un archivo 
válido para cargar el grafo sobre el que se quiere aplicar el algoritmo.
(Hay 3 grafos codificados dentro del directorio "datos", su representación visual se puede consultar dentro del directorio
"datos/representacion")

Ejemplo de ejecución: 
<raiz>$: ./bin/recubrimiento datos/p1.dat

Para compilar abrir la terminal en la ruta donde se encuentra el archivo "Makefile" y ejecutar la orden:
$: make

