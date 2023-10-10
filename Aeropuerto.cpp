//
// Created by Imora on 02/10/2023.
//

#include "Aeropuerto.h"

//Constructor por defecto.
Aeropuerto::Aeropuerto() : _id(""), _ident(""),_tipo(""),_nombre(""),
                           _continente(""), _iso_pais(""),_posicion(UTM()){

}

//Constructor parametrizado.
Aeropuerto::Aeropuerto(const std::string &id, const std::string &ident, const std::string &tipo,const std::string &nombre,
                       const std::string &continente, const std::string &isoPais, UTM posicion) : _id(id),
                                                                                                   _ident(ident),
                                                                                                   _tipo(tipo),
                                                                                                   _nombre(nombre),
                                                                                                   _continente(continente),
                                                                                                   _iso_pais(isoPais),
                                                                                                   _posicion(posicion) {

}

//Constructor de copia.
Aeropuerto::Aeropuerto(const Aeropuerto &orig) : _id(orig._id),
                                                 _ident(orig._ident),
                                                 _tipo(orig._tipo),
                                                 _nombre(orig._nombre),
                                                 _continente(orig._continente),
                                                 _iso_pais(orig._iso_pais),
                                                 _posicion(orig._posicion){

}

//Destructor.
Aeropuerto::~Aeropuerto() {

}


//Getter del atributo 'id'.
std::string &Aeropuerto::getId(){
    return _id;
}

//Setter del atributo 'id'.
void Aeropuerto::setId(const std::string &id) {
    _id = id;
}

//Getter del atributo 'ident'.
std::string &Aeropuerto::getIdent(){
    return _ident;
}

//Setter del atributo 'ident'.
void Aeropuerto::setIdent(const std::string &ident) {
    _ident = ident;
}

//Getter del atributo 'tipo'.
std::string &Aeropuerto::getTipo(){
    return _tipo;
}

//Setter del atributo 'tipo'.
void Aeropuerto::setTipo(const std::string &tipo) {
    _tipo = tipo;
}

//Getter del atributo 'nombre'.
std::string &Aeropuerto::getNombre(){
    return _nombre;
}

//Setter del atributo 'nombre'.
void Aeropuerto::setNombre(const std::string &nombre) {
    _nombre = nombre;
}

//Getter del atributo 'continente'.
std::string &Aeropuerto::getContinente(){
    return _continente;
}

//Setter del atributo 'continente'.
void Aeropuerto::setContinente(const std::string &continente) {
    _continente = continente;
}

//Getter del atributo 'IsoPais'.
std::string &Aeropuerto::getIsoPais(){
    return _iso_pais;
}

//Setter del atributo 'IsoPais'.
void Aeropuerto::setIsoPais(const std::string &isoPais) {
    _iso_pais = isoPais;
}

//Getter del atributo 'Posicion'.
UTM &Aeropuerto::getPosicion(){
    return _posicion;
}

//Setter del atributo 'Posicion'.
void Aeropuerto::setPosicion(const UTM &posicion) {
    _posicion = posicion;
}


//Operator menor que.
bool Aeropuerto::operator<(const Aeropuerto &orig) {
    int id1 = stoi(_id);
    int id2 = stoi(orig._id);

    return id1 < id2;
}

//Operator de comparación.
bool Aeropuerto::operator==(const Aeropuerto &orig) {
    bool son_iguales = false;
    if (_id == orig._id) {
        son_iguales = true;
    }
    return son_iguales;
}


