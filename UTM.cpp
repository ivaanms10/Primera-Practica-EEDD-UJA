//
// Created by Imora on 02/10/2023.
//

#include "UTM.h"

//Constructor por defecto.
UTM::UTM() : _latitud(0.0),
             _longitud(0.0){

}

//Constructor parametrizado.
UTM::UTM(float latitud, float longitud) : _latitud(latitud),
                                          _longitud(longitud) {

}

//Constructor de copia.
UTM::UTM(const UTM &orig) : _latitud(orig._latitud),
                            _longitud(orig._longitud){

}

//Destructor.
UTM::~UTM() {

}


//Getter del atributo 'latitud'.
float UTM::getLatitud(){
    return _latitud;
}

//Setter del atributo 'latitud'.
void UTM::setLatitud(float latitud) {
    _latitud = latitud;
}

//Getter del atributo 'longitud'.
float UTM::getLongitud(){
    return _longitud;
}

//Setter del atributo 'longitud'.
void UTM::setLongitud(float longitud) {
    _longitud = longitud;
}

