# Práctica 1 - Introducción a los Contenedores: Vectores Dinámicos (II)

## Descripción

Esta práctica consiste en la implementación de una estructura de datos genérica `VDinamico<T>` en C++, ampliando la funcionalidad de un vector básico para convertirlo en un vector dinámico capaz de gestionar automáticamente la memoria durante la ejecución del programa.

Además, se desarrolla un programa de prueba utilizando dicha estructura para gestionar información de aeropuertos almacenada en un fichero CSV.

---

# Objetivos

- Implementar una plantilla genérica `VDinamico<T>`.
- Gestionar memoria dinámica de forma eficiente.
- Utilizar constructores, destructores y sobrecarga de operadores.
- Implementar algoritmos de ordenación y búsqueda binaria.
- Manejar excepciones y errores correctamente.
- Aplicar la estructura desarrollada a un caso real de gestión de aeropuertos.

---

# Funcionalidades Implementadas

La clase `VDinamico<T>` incluye:

- Constructor por defecto.
- Constructor parametrizado.
- Constructor copia.
- Constructor de copia parcial.
- Operador de asignación.
- Operador `[]`.
- Inserción de elementos.
- Borrado de elementos.
- Redimensionamiento automático.
- Ordenación ascendente.
- Ordenación descendente.
- Búsqueda binaria.
- Consulta del tamaño lógico.
- Destructor.

---

# Gestión de Memoria

El vector dinámico trabaja con:

- **Tamaño lógico:** número real de elementos almacenados.
- **Tamaño físico:** capacidad reservada en memoria.

La memoria se redimensiona automáticamente:

- Se duplica cuando el vector se llena.
- Se reduce cuando el número de elementos es suficientemente pequeño.

El tamaño físico siempre será una potencia de 2.

---

# Clase Aeropuerto

La práctica utiliza una clase `Aeropuerto` para almacenar la información de cada aeropuerto cargado desde el fichero `aeropuertos.csv`.

## Atributos principales

- ID
- Identificador IATA/ICAO
- Nombre
- Ciudad
- País
- Continente
- Coordenadas
- Otros datos relevantes

Además, la clase implementa:

- Constructores
- Getters y setters
- Operadores de comparación
- Sobrecarga de operadores necesaria para ordenación y búsqueda

---

# Operaciones Realizadas

El programa de prueba realiza las siguientes operaciones:

## 1. Carga de datos

Se leen los datos del fichero:

```bash
aeropuertos.csv
