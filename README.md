# Tarea *3*. *Técnicas de diseño de algoritmos*

---

##### Integrantes:
1. *Constanza Gómez Sánchez* - *A01026717* - *Campus Santa Fe*

---
## 1. Aspectos generales

Las orientaciones de la tarea se encuentran disponibles en la plataforma **Canvas**.

Este documento es una guía sobre qué información debe entregar como parte de la tarea, qué requerimientos técnicos debe cumplir y la estructura que debe seguir para organizar su entrega.


### 1.1 Requerimientos técnicos

A continuación se mencionan los requerimientos técnicos mínimos de la tarea, favor de tenerlos presente para que cumpla con todos.

* El código debe desarrollarse en C++, cumpliendo con el último estándar [C++17](https://isocpp.org/std/the-standard).
* Toda la programación debe realizarse utilizando Programación Genérica.
* Deben utilizarse las [C++ Core Guidelines](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md).
* Todo el código debe estar correctamente documentado, siguiendo los lineamientos que aparecen en [Documenting C++ Code](https://developer.lsst.io/cpp/api-docs.html).
* Todo el código de la tarea debe alojarse en este repositorio de GitHub.
* Debe configurar su repositorio para que utilice el sistema de Integración Continua [Travis CI](https://travis-ci.org/).

### 1.2 Estructura del repositorio

El proyecto debe seguir la siguiente estructura de carpetas:
```
- / 			        # Raíz del repositorio
    - README.md			# Archivo con la información general de la actividad (este archivo)
    - sources  			# Códigos fuente con la solución
    - examples			# Archivos de ejemplo que pueden utilizarse para verificar que la solución funciona.
```

## 2. Solución

### Subconjuntos

El primer problema a solucionar es encontrar el subconjunto, de un conjunto de enteros positivos, cuya suma sea exactamente el valor de un entero positivo. Esta solución se puede encontrar en mi archivo Subconjunto.cpp, aquí podemos observar que use la técnica de vuelta atrás para resolver el problema. El código ya tiene el conjunto y la cantidad deseada, lo que hace el código es ir recorriendo de uno en uno el conjunto, añadiendo a un vector las posibles soluciones y borrando las que no nos llevan al resultado deseado. Esto se logra por medio de recursividad que nos permite reccorrer el conjunto, las veces necesarias para poder encontrar todos los subconjuntos posibles.

### Multiplicación de enteros grandes

El segundo problema a solucionar es hacer la multiplicación de enteros grandes usando la técnica de divide y vencerás, para llegar al resultado deseado. Esta solución se puede encontrar en el archivo MultiEnteros.cpp, donde podremos observar el código implementado.
En el código debemos de poner los números que deseamos multiplicar. Estos números se arreglan para que puedan llegar a tener *n* bits, lo cual nos permite implementar el código. Los números que insertamos se dividen en *n/s* para poder reducirlo a números más pequeños, esto se hace hasta que los números sean menores a 100 y se puedan multiplicar facilmente para después juntarlos y obtener el resultado final.

### 2.1 Pasos a seguir para utilizar la aplicación

*[Incluya aquí una guía paso a paso para poder utilizar la aplicación, desde la clonación del repositorio, la compilación del código hasta la ejecución de los ejemplos para visualizar los resultados.]*

## 3. Referencias

*[Incluya aquí las referencias a sitios de interés y cualquier otra información que haya utilizado para realizar la actividad y que le puedan ser de utilidad a otras personas que quieran usarlo como referencia]*
