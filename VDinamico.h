//
// Created by Imora on 02/10/2023.
//

#ifndef PRIMERA_PRACTICA_B_VDINAMICO_H
#define PRIMERA_PRACTICA_B_VDINAMICO_H
#include <stdexcept>
#include <algorithm>
#include <math.h>

template<typename T>
class VDinamico{
private:
    int tam_fisico;
    int tam_logico;
    T *vector;

public:
    VDinamico();
    VDinamico(unsigned int tamlog);
    VDinamico(const VDinamico<T> &orig);
    VDinamico(const VDinamico<T> &orig, unsigned int posicionIncial, unsigned int numElementos);
    ~VDinamico();

    VDinamico &operator=(VDinamico &orig);
    T &operator[](int pos);

    void ordenar();
    void ordenarRev();
    int busquedaBin(T& dato);

    void aumenta();
    void disminuye();

    void insertar(T& dato, unsigned int pos = UINT_MAX);
    T borrar(unsigned int pos = UINT_MAX);

    unsigned int tamlog(){return tam_logico;}

};


//Constructor por defecto.
template<typename T>
VDinamico<T>::VDinamico() {
    tam_fisico = 1;
    tam_logico = 0;

    vector = new T[tam_fisico];
}

//Constructor parametrizo.
template<typename T>
VDinamico<T>::VDinamico(unsigned int tamlog) {
    tam_logico = tamlog;
    tam_fisico = tamlog;
    for (int i = 0; pow(2, i) <= tam_logico; i++) {
        tam_fisico = pow(2, i + 1);
    }

    vector = new T[tam_fisico];
}

//Constructor de copia.
template<typename T>
VDinamico<T>::VDinamico(const VDinamico<T>& orig) : tam_logico(orig.tam_logico),
                                                    tam_fisico(orig.tam_fisico) {
    vector = new T[tam_fisico];
    for (int i = 0; i < tam_logico; i++) {
        vector[i] = orig.vector[i];
    }
}

//Constructor de copia parcial.
template<typename T>
VDinamico<T>::VDinamico(const VDinamico<T> &orig, unsigned int posicionIncial, unsigned int numElementos) {

    tam_logico = numElementos;
    tam_fisico = numElementos;

    for (int i = 0; pow(2, i) <= tam_logico; i++) {
        tam_fisico = pow(2, i + 1);
    }

    vector = new T[tam_fisico];
    for (int i = posicionIncial; i < posicionIncial + numElementos; i++) {
        vector[i - posicionIncial] = orig.vector[i];
    }
}

//Destructor.
template<typename T>
VDinamico<T>::~VDinamico() {
    delete[] vector;
}


/**
 * @brief Copia los elementos de un objeto VDinamico en otro objeto VDinamico del mismo tipo.
 * @param orig El objeto VDinamico que va a ser copiado.
 * @return Referencia a el objeto VDinamico despues de la asignacion.
 */
template<typename T>
VDinamico<T> &VDinamico<T>::operator=(VDinamico<T> &orig) {
    if (&orig != this) {
        delete[] vector;
        tam_fisico = orig.tam_fisico;
        tam_logico = orig.tam_logico;

        vector = new T[tam_fisico];
        for (int i = 0; i < tam_logico; i++) {
            vector[i] = orig.vector[i];
        }
    }
    return *this;
}

/**
 *@brief Metodo para configurar los corchetes para usarlos para acceder a la posicion de un vector dinamico.
 * @param pos Posicion en la que se encuentra el elemento dentro del vector dinamico.
 * @throw std::out_of_range Si la posicion insertada es mayor que el numero de elementos del vector dinamico.
 * @return Devuelve el elemento que se encuentra en la posicion previamente dada.
 */
template<typename T>
T &VDinamico<T>::operator[](int pos) {
    if (pos >= tam_logico) {
        throw std::out_of_range("[VDinamico<T>::operator[]: La posicion introducida no es correcta.");
    }
    return vector[pos];
}


/**
 * @brief Metodo para ordenar todos los elementos de el vector dinamico de menor a mayor.
 */
template<typename T>
void VDinamico<T>::ordenar() {
    std::sort(vector, vector + tam_logico);
}

/**
 * @brief Metodo para ordenar todos los elementos de el vector dinamico de mayor a menor.
 */
template<typename T>
void VDinamico<T>::ordenarRev() {
    ordenar();

    for (int i = 0; i < tam_logico / 2; i++) {
        T aux = vector[i];
        vector[i] = vector[tam_logico - 1 - i];
        vector[tam_logico - 1 - i] = aux;
    }
}

/**
 * @brief Metodo para buscar un elemento dentro de un vector dinamico.
 * @param dato Elemento que deseamos buscar entre todos los elementos del vector dinamico.
 * @return Posicion en la que se encuentra el elemento dentro del vector dinamico.
 */
template<typename T>
int VDinamico<T>::busquedaBin(T &dato) {
    int inferior = 0;
    int superior = tam_logico - 1;
    int aux = 0;
    while (inferior <= superior) {
        aux = (inferior + superior) / 2;
        if (vector[aux] == dato) {
            return aux;
        } else if (vector[aux] < dato) {
            inferior = aux + 1;
        } else {
            superior = aux - 1;
        }
    }
    return -1;
}


/**
 * @brief Metodo para aumentar el tamaño del vector a el doble..
 */
template<typename T>
void VDinamico<T>::aumenta() {
    T *vaux = new T[tam_fisico = tam_fisico * 2];
    for (int i = 0; i < tam_logico; i++)
        vaux[i] = vector[i];
    delete[] vector;
    vector = vaux;
}

/**
 * @brief Metodo para reducir el tamaño del vector a la mitad.
 */
template<typename T>
void VDinamico<T>::disminuye() {
    tam_fisico = tam_fisico / 2;
    T *vaux = new T[tam_fisico];
    for (int i = 0; i < tam_logico; i++) {
        vaux[i] = vector[i];
    }
    delete[] vector;
    vector = vaux;
}


/**
 * @brief Metodo para insertar un elemento dentro del vector dinamico.
 * @param dato Elemento que queremos insertar dentro del vector dinamico.
 * @param pos Posicion en la que queremos insertar el elemento.
 * @throw std::out_of_range Si la posicion introducida es mayor que el numero de elementos del vector.
 */
template<typename T>
void VDinamico<T>::insertar(T &dato, unsigned int pos) {
    if (pos >= tam_logico && pos != UINT_MAX) {
        throw std::out_of_range("[VDinamico<T>::insertar] : La posicion donde se intenta insertar el dato no es correcto.");
    }

    if (tam_logico == tam_fisico) {
       aumenta();
    }

    if (pos == UINT_MAX || tam_logico == 0) {
        vector[tam_logico] = dato;
        tam_logico++;
    } else {
        for (int i = tam_logico - 1; i >= pos; i--) {
            vector[i + 1] = vector[i];
        }
        vector[pos] = dato;
        tam_logico++;
    }
}

/**
 * @brief Metodo para borrar un elemento del vector dinamico.
 * @param pos Indica la posicion donde se encuentra el elemento que deseamos borrar del vector.
 * @throw std::out_of_range Si el vector no contiene ningun elemento y se intenta borrar un elemento.
 * @throw std::out_of_range Si la posicion introducida es mayor que el numero de elementos del vector.
 * @return Devuelve el objeto que ha sido eliminado de el vector dinamico.
 */
template<typename T>
T VDinamico<T>::borrar(unsigned int pos) {

    if (pos >= tam_logico && pos != UINT_MAX) {
        throw std::out_of_range("[VDinamico<T>::borrar]: La posicion que ha insertado es mayor al numero de elementos del vector.");
    }
    if (tam_logico == 0) {
        throw std::out_of_range("[VDinamico<T>::borrar]: No hay ningun elemento en el vector.");
    }
    if (tam_logico * 3 < tam_fisico) {
        disminuye();
    }

    T aux;
    if (pos == UINT_MAX) {
        aux = vector[tam_logico - 1];
        tam_logico--;
        return aux;
    } else {
        aux = vector[pos];
        for (int i = pos; i < tam_logico; i++) {
            vector[i] = vector[i + 1];
        };
        tam_logico--;
        return aux;
    }
}

#endif //PRIMERA_PRACTICA_B_VDINAMICO_H
