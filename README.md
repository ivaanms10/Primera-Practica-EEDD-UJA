# Práctica 1: Introducción a los Contenedores Dinámicos mediante Vectores en C++

Este repositorio contiene la entrega de la **Práctica 1.b** de la asignatura **Estructuras de Datos** del **Grado en Ingeniería en Informática** (Curso 2023/24) en la **Universidad de Jaén**.

## 🎯 Objetivos de la Práctica
* Evolucionar el contenedor básico de la sesión anterior hacia un **vector dinámico** (`VDinamico<T>`) capaz de gestionar de forma eficiente el crecimiento o decrecimiento de la memoria a lo largo de la ejecución.
* Implementar algoritmos de ordenación y búsqueda optimizados mediante patrones de clase (*templates*) y control estructurado de excepciones.
* Evaluar y medir la eficiencia temporal en operaciones de ordenación, búsqueda y filtrado de datos masivos.

---

## 🛠️ Descripción de la Estructura de Datos (`VDinamico<T>`)

Se ha desarrollado la clase plantilla `VDinamico<T>` para emular la funcionalidad de un array dinámico automatizado en memoria, incorporando los siguientes constructores, operadores y métodos:

* **Gestión de Memoria y Ciclo de Vida:**
  * `VDinamico()`: Constructor por defecto. Inicializa el tamaño físico en 1 y el lógico en 0.
  * `VDinamico(unsigned int tamLogico)`: Constructor parametrizado que asigna un tamaño físico igual a la potencia de 2 inmediatamente superior o igual al tamaño lógico solicitado.
  * `VDinamico(const VDinamico<T>& origen)`: Constructor copia.
  * `VDinamico(const VDinamico<T>& origen, unsigned int posicionInicio, unsigned int numElementos)`: Constructor copia parcial que extrae una sub-secuencia del vector origen.
  * `~VDinamico()`: Destructor encargado de liberar adecuadamente la memoria asignada en el *heap*.
  * `operator=`: Operador de asignación sobrecargado para garantizar copias seguras.
* **Acceso y Consulta:**
  * `operator[]`: Operador de indexación para lectura/escritura de elementos con comprobación estricta de rangos mediante excepciones.
  * `tamLogico()`: Devuelve el número de elementos reales almacenados.
* **Mutadores Estructurales (Inserción y Borrado):**
  * `insertar(const T& dato, unsigned int pos)`: Inserta un dato en una posición intermedia o final. Si el tamaño lógico alcanza el físico, el contenedor duplica automáticamente su capacidad física.
  * `borrar(unsigned int pos)`: Elimina el dato de la posición indicada compactando el vector. Si el tamaño lógico cae por debajo de un cuarto de la capacidad física, el contenedor reduce su tamaño físico a la mitad para optimizar el consumo de memoria.
* **Algoritmia Avanzada:**
  * `ordenar()`: Clasifica los elementos de forma ascendente haciendo uso del algoritmo de ordenación por inserción (*Insertion Sort*).
  * `busquedaBinaria(const T& dato)`: Realiza una búsqueda dicotómica/logarítmica en tiempo $O(\log n)$ sobre el vector previamente ordenado. Devuelve la posición del elemento o `-1` si no existe.

---

## ✈️ Caso de Estudio: Carga y Procesamiento de Aeropuertos

El vector dinámico se valida en un escenario real procesando el archivo de datos masivos `aeropuertos_v2.csv`. Cada registro se instancia en un objeto de la clase `Aeropuerto`, la cual almacena campos como el ID unívoco, el código IATA, el nombre del aeropuerto, la ciudad, el país, el continente y sus coordenadas geográficas.

---

## 🧪 Casos de Prueba del Programa Principal

El programa conductor realiza un flujo de pruebas secuenciales para auditar la robustez y los tiempos de cómputo de la estructura:

1. **Carga Inicial:** Leer secuencialmente el archivo CSV e insertar cada aeropuerto al final de un objeto `VDinamico<Aeropuerto>`, observando cómo la estructura redimensiona su capacidad física de manera transparente.
2. **Ordenación:** Invocar al método `ordenar()` para clasificar la totalidad de los aeropuertos cargados según su ID numérico (requiriendo la sobrecarga previa del `operator<` en la clase `Aeropuerto`). Mostrar por pantalla la información de los primeros 30 aeropuertos ordenados.
3. **Búsqueda Dicotómica:** Ejecutar el método `busquedaBinaria()` para buscar los aeropuertos con los identificadores `345166`, `6640`, `6676`, `345364` y `6778`, imprimiendo su posición en el contenedor o reportando su ausencia si no existen en el fichero.
4. **Filtrado y Purga de Datos:** Localizar y extraer todos los aeropuertos pertenecientes al continente norteamericano (`"NA"`). El proceso traslada dichos elementos a un nuevo vector dinámico auxiliar y los remueve del vector original. Al finalizar, el programa muestra el tamaño lógico resultante de ambos contenedores y los primeros 20 registros del nuevo vector de filtrado.
5. **(Modalidad por Parejas):** Registro analítico y estudio de tiempos asociados a cada uno de los cuatro bloques anteriores utilizando librerías de medición temporal de C++ (como `<chrono>`).

---

## ⚙️ Requisitos de Estilo y Calidad
* **Formateo Limpio:** Código fuente estructurado bajo una indentación rigurosa que sigue el estándar profesional de la asignatura (basado en el modelo *Geosoft*).
* **Gestión de Excepciones:** Tratamiento y lanzamiento de excepciones lógicas ante situaciones de riesgo en tiempo de ejecución (punteros corruptos, desbordamientos de rango, o lecturas de archivos ausentes).
* **Eficiencia de Memoria:** Implementación de estrategias de contracción y expansión física eficientes para mitigar la fragmentación y el desperdicio de memoria dinámica.
