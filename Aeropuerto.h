//
// Created by Imora on 02/10/2023.
//
#ifndef PRIMERA_PRACTICA_B_AEROPUERTO_H
#define PRIMERA_PRACTICA_B_AEROPUERTO_H
#include <stdexcept>
#include <string>
#include "UTM.h"

class Aeropuerto {
private:
    std::string _id = "";
    std::string _ident = "";
    std::string _tipo = "";
    std::string _nombre = "";
    std::string _continente = "";
    std::string _iso_pais = "";

    UTM _posicion;

public:
    Aeropuerto();
    Aeropuerto(const std::string &id, const std::string &ident, const std::string &tipo, const std::string &nombre,
               const std::string &continente, const std::string &isoPais, UTM posicion);
    Aeropuerto(const Aeropuerto &orig);
    ~Aeropuerto();

    std::string &getId();
    void setId(const std::string &id);

    std::string &getIdent();
    void setIdent(const std::string &ident);

    std::string &getTipo();
    void setTipo(const std::string &tipo);

    std::string &getNombre();
    void setNombre(const std::string &nombre);

    std::string &getContinente();
    void setContinente(const std::string &continente);

    std::string &getIsoPais();
    void setIsoPais(const std::string &isoPais);

    UTM &getPosicion();
    void setPosicion(const UTM &posicion);

    bool operator<(const Aeropuerto &orig);
    bool operator==(const Aeropuerto &orig);
};


#endif //PRIMERA_PRACTICA_B_AEROPUERTO_H
