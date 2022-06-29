# Diagrama de Voronoi
## Integrantes
* Julisa Lapa
* Jorge Castillo
* Sebastian Knell
* Massimo Imparato
* Luis Carbajal

## Compilación
```shell
mkdir build
cd build
cmake ..
make
./Voronoi
```

## Uso
Una vez ejecutado el programa se abrirá una ventana con puntos aleatorios (por defecto 5). La ventana responde a 7 teclas:
* **a:** Reduce el número de puntos
* **s:** Aumenta el número de puntos
* **z:** Dibuja el diagrama de Voronoi sobre los puntos actuales usando distancia **Euclidiana**
* **x:** Dibuja el diagrama de Voronoi sobre los puntos actuales usando distancia **Manhattan**
* **c:** Dibuja el diagrama de Voronoi sobre los puntos actuales usando distancia **Chebyshev**
* **ESPACIO:** Genera un nuevo conjunto de puntos aleatorios
* **q:** Cierra la ventana y finaliza el programa