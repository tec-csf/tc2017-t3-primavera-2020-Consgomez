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

##### Subconjuntos

Se desea encontrar una solución, por medio de un algoritmo que use la técnica de vuelta atrás, que encuentre todos los posibles subconjuntos de *W* cuya suma sea exactamente *M*. 

La solución a este problema la podemos ver en el archivo *Subconjunto.cpp*. 
En el *main* del archivo se introduce un arreglo de *n* números y la suma a la que deseamos llegar. Una vez que tenemos esto, en la clase de *Subconjunto*, mandamos llamar la función *suma*, en la cual usamos la recursividad para llegar a la solución
La función *suma()* es tipo *bool*, lo que nos va a permitir finalizar la recursividad, una vez que ya encontremos uno de los subconjuntos deseados. En la función se va a empesar a recorrer el arreglo, empezando en la posición 0. Los valores se van a guardar en el vector solución, se va a entrar en la recursividad y si vemos que el valor recién insertado al vector nos puede llevar a la solución se queda y nos movemos una posición en el arreglo; si no nos va a llevar a la solución, se quita ese valor del vector y seguimos con la siguiente posición del arreglo. Esto se repite las veces necesarias hasta que encontremos todos los subconjuntos posibles.

La complejidad de este algoritmo es de 


##### Multiplicación de enteros grandes

Se desea encontrar una solución, por medio de un algoritmo que use la técnica de divide y vencerás, que multiplique dos números enteros grandes. 

La solución a este problema la podemos ver en el archivo *MultiEnteros.cpp*. 
En el *main* de este archivo se escriben los dos valores que deseamos multiplicar, hay que recordar que estos deben de ser enteros. Una vez que tenemos esto, de la clase *MultiEnteros*, mandamos llamar la función *tam()*, la cual obtiene la longitud de los números y obtiene la longitud en bits que vamos a estar usando en el programa. Ya que tenmos esto, llamamos la función *multiplicacion()* en donde se resuelve el problema.
Lo que hace la función *multiplicacion()* es, con ayuda de la recursividad, dividir los números enteros en 2, y así sucesivamente hasta que obtengamos números menores de 100 que nos sean más fáciles de multiplicar. Una vez que llegamos a dividir los números lo más posible, empezamos a juntarlos para, de esta manera, llegar al resultado de la multiplicación. 

La complejidad de este algoritmo es *#O(n^2)#*, siendo esta la más eficiente.

### 2.1 Pasos a seguir para utilizar la aplicación

Todos estos pasos se hacen por medio de la terminal. 

Antes de empezar, debemos de clonar el repositorio de GitHub a un directorio local. Para poder hacer esto, debemos de estar dentro de nuestro directorio local al cual deseamos clonar nuestro repositorio y debemos de escribir el siguiente comando en la terminal:
```
        https://github.com/tec-csf/tc2017-t3-primavera-2020-Consgomez.git
```

Una vez que ya hayamos clonado el repositoria, el usuario debe de acceder a el, igual que entrar a la carpeta *sources* para poder compilar los códigos. 

##### Subconjuntos

Para compilar este código debemos de hacer lo siguiente:
* Primero debemos de asegurarnos de que nuestras variables *int conjunto[]* e *int cant*, que se encuentran dentro del *main()* , contengan los valores deseados. 
* Ya que hayamos hecho esto, debemos de correr el siguiente comando en la terminal:
```
        g++ Subconjunto.cpp -std=c++17 -o check
```
* Por último, corremos el siguiente comando en la terminal:
```
        ./check
```

##### Multiplicación de enteros grandes

Para compilar este código debemos de hacer lo siguiente:
* Primero debemos de asegurarnos de que nuestras variables *int a* e *int b*, que se encuentran dentro del *main()* , contengan números que deseamos multiplicar.
* Ya que hayamos hecho esto, debemos de correr el siguiente comando en la terminal:
```
        g++ MultiEnteros.cpp -std=c++17 -o segundo
```
* Por último, corremos el siguiente comando en la terminal:
```
        ./segundo
```

## 3. Referencias

1. Rosa Guerequeta y Antonio Vallecillo. (1998). Divide y vencerás. En Técnicas de Diseño de Algoritmos(105 - 113). Málaga: Servicio de Publicaciones de la Universidad de Málaga.
2. Rosa Guerequeta y Antonio Vallecillo. (1998). Vuelta atrás. En Técnicas de Diseño de Algoritmos(211, 212). Málaga: Servicio de Publicaciones de la Universidad de Málaga.
3. Departamento de Ciencias de la Computación e I.A. (s.f). *Algoritmos "Divide y Vencerás"*. [Diapositiva de PowerPoint]. Recuperado 14 de abril de 2020, de: https://elvex.ugr.es/decsai/algorithms/slides/3%20DV.pdf
4. Campos, J. (s.f). *Esquemas Algorítmicos - Divide y Vencerás"*. Recuperado de: https://webdiis.unizar.es/asignaturas/EDA/ea/slides/3-Divide%20y%20venceras.pdf

