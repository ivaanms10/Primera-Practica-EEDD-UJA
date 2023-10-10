#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "VDinamico.h"
#include "Aeropuerto.h"
#include "UTM.h"

/**
 * @author Iván Morales Sánchez ims00051@red.ujaen.es
 */
int main(int argc, const char * argv[]) {
    std::ifstream is;
    std::stringstream columnas;
    std::string fila;
    int contador = 0;

    std::string id = "", ident = "", tipo = "", nombre = "", latitud_str = "", longitud_str = "", continente = "", iso_pais = "";
    float latitud, longitud;

    VDinamico<Aeropuerto> list_aeropuertos;

    is.open("../aeropuertos.csv"); //carpeta de proyecto
    if (is.good()) {
        clock_t t_ini1 = clock();

        while (getline(is, fila)) {

            if (fila != "") {

                columnas.str(fila);

                getline(columnas, id, ';');
                getline(columnas, ident, ';');
                getline(columnas, tipo, ';');
                getline(columnas, nombre, ';');
                getline(columnas, latitud_str, ';');
                getline(columnas, longitud_str, ';');
                getline(columnas, continente, ';');
                getline(columnas, iso_pais, ';');

                latitud = std::stof(latitud_str);
                longitud = std::stof(longitud_str);

                fila = "";
                columnas.clear();
                try {
                    UTM utm1;
                    utm1.setLatitud(latitud);
                    utm1.setLongitud(longitud);

                    Aeropuerto ae1(id, ident, tipo, nombre, continente, iso_pais, utm1);
                    list_aeropuertos.insertar(ae1);
                } catch (std::out_of_range &e) {
                    std::cerr << "ERROR: " << e.what() << std::endl;
                }
            }
        }
        is.close();
        std::cout << "Tiempo de lectura: " << ((clock() - t_ini1) / (float) CLOCKS_PER_SEC) << " segs." << std::endl;
    } else {
        std::cout << "Error de apertura en archivo" << std::endl;
    }


//Ordenar el vector de mayor a menor y mostrar los id de los primeros 30 aeropuertos.
    clock_t t_ini2 = clock();
    list_aeropuertos.ordenarRev();
    std::cout << std::endl;
    std::cout << "Los 30 aeropuertos que tienen el id mayor son: " << std::endl;
    for (int i = 0; i < 30; i++) {
        std::cout << i + 1 << ".- " << list_aeropuertos[i].getId() << ", " << list_aeropuertos[i].getNombre() << ", "
                  << list_aeropuertos[i].getIdent() << ", " << list_aeropuertos[i].getContinente() << ", "
                  << list_aeropuertos[i].getIsoPais() << ", " << list_aeropuertos[i].getTipo() << ", "
                  << list_aeropuertos[i].getPosicion().getLatitud() << ", "
                  << list_aeropuertos[i].getPosicion().getLongitud()
                  << std::endl;
    }
    std::cout << "El tiempo que tarda en ordenar de mayor a menor y mostrar 30 aeropuertos es: "
              << ((clock() - t_ini2) / (float) CLOCKS_PER_SEC) << " segs." << std::endl;


//Ordenar el vector de menor a mayor y mostrar los id de los primeros 30 aeropuertos.
    clock_t t_ini3 = clock();
    list_aeropuertos.ordenar();
    std::cout << std::endl;
    std::cout << "Los 30 aeropuertos que tienen el id menor son: " << std::endl;
    for (int i = 0; i < 30; i++) {
        std::cout << i + 1 << ".- " << list_aeropuertos[i].getId() << ", " << list_aeropuertos[i].getNombre() << ", "
                  << list_aeropuertos[i].getIdent() << ", " << list_aeropuertos[i].getContinente() << ", "
                  << list_aeropuertos[i].getIsoPais() << ", " << list_aeropuertos[i].getTipo() << ", "
                  << list_aeropuertos[i].getPosicion().getLatitud() << ", "
                  << list_aeropuertos[i].getPosicion().getLongitud()
                  << std::endl;
    }
    std::cout << "El tiempo que tarda en ordenar de menor a mayor y mostrar 30 aeropuertos es: "
              << ((clock() - t_ini3) / (float) CLOCKS_PER_SEC) << " segs." << std::endl;
    std::cout << std::endl;


//Una vez ordenado el vector, buscar los aeropuertos con los id 345166, 6640, 6676, 345364 y 6778,
//mostrando su posición en el contenedor y teniendo en cuenta que pueden no existir.

    clock_t t_ini4 = clock();
    VDinamico<Aeropuerto> buscar(5);
    buscar[0].setId("345166");
    buscar[1].setId("6640");
    buscar[2].setId("6676");
    buscar[3].setId("345364");
    buscar[4].setId("6778");
    for (int i = 0; i < 5; i++) {
        int pos = list_aeropuertos.busquedaBin(buscar[i]);
        if (pos == -1) {
            std::cout << "El id " << buscar[i].getId() << " no ha sido encontrado entre los id de los list_aeropuertos."
                      << std::endl;
        } else {
            std::cout << "La posicion en la que se encuentra el avion con el id '" << buscar[i].getId()
                      << "' es la posicion "
                      << pos << std::endl;
        }
    }
    std::cout << "El tiempo que tarda en buscar los 5 id en el vector es: "
              << ((clock() - t_ini4) / (float) CLOCKS_PER_SEC) << " segs." << std::endl;


//Eliminar todos los aeropuertos cuyo continente sea “NA”. Para ello, pasar todos los aeropuertos que cumplan
//la condición a un nuevo vector dinámico y, tras esto, borrar los aeropuertos del vector dinámico original.
//Mostrar el tamaño lógico de ambos vectores y toda la información de los primeros 20 aeropuertos del nuevo vector.
// Si se usan vectores auxiliares,deberán declararse como VDinamico<T>.

    clock_t t_ini5 = clock();
    VDinamico<Aeropuerto> avionesNA;
    try {
        for (int i = 0; i < list_aeropuertos.tamlog(); i++) {
            while (list_aeropuertos[i].getContinente() == "NA") {
                avionesNA.insertar(list_aeropuertos[i]);
                list_aeropuertos.borrar(i);
            }
        }
    } catch (std::out_of_range &e) {
        std::cerr << "ERROR: " << e.what() << std::endl;
    }

    std::cout << std::endl;
    std::cout << "El tamanio logico del vector con todos los list_aeropuertos sin continente NA es: "
              << list_aeropuertos.tamlog()
              << std::endl;
    std::cout << "El tamanio logico del vector con todos los list_aeropuertos con continente NA es: "
              << avionesNA.tamlog()
              << std::endl;

    for (int i = 0; i < 20; i++) {
        std::cout << i + 1 << ".- " << avionesNA[i].getId() << ", " << avionesNA[i].getNombre() << ", "
                  << avionesNA[i].getIdent() << ", " << avionesNA[i].getContinente() << ", "
                  << avionesNA[i].getIsoPais() << ", " << avionesNA[i].getTipo() << ", "
                  << avionesNA[i].getPosicion().getLatitud() << ", " << avionesNA[i].getPosicion().getLongitud()
                  << std::endl;
    }
    std::cout << "Tiempo que tarda en borrar continentes NA, copiarlos en otro vector y mostrar los 20 primeros: "
              << ((clock() - t_ini5) / (float) CLOCKS_PER_SEC) << " segs." << std::endl;

    return 0;
}