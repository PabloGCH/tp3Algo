#include "controladorTierra.h"



int ControladorTierra::evaluarDir(Casillero* dir){
    int valor = 0;
    int tipo = dir->getType();
    switch(tipo){
        case MOUNTAIN:
            valor = 0;
            break;
        case VOID:
            valor = 15;
            break;
        case ROAD:
            valor = 1;
            break;
        case PRECIPICE:
            valor = 2;
            break;
        case LAKE:
            valor = 1;
            break;
        case VOLCANO:
            valor = 0;
            break;
    }
    return valor; 
}

void ControladorTierra::atacar(ControladorPersonaje** ControladoresEnemigo){
    if (personaje -> obtenerEnergia() >= 6 ) {
        personaje->restarEnergia(6);
        for(int i = 0; i < 3; i++){
            ControladorPersonaje* contEnemigo = ControladoresEnemigo[i];
            Personaje* enemigo = contEnemigo->devolverPersonaje();
            if(enemigo != 0){
                int distanciaFila = ubicacion[0] - contEnemigo -> devolverUbicacion()[0];
                if(distanciaFila < 0){
                    distanciaFila *= -1;
                }
                int distanciaColumna = ubicacion[1] - contEnemigo -> devolverUbicacion()[1];
                if(distanciaColumna < 0){
                    distanciaColumna *= -1;
                }
                if ((distanciaFila <= 2) && (distanciaColumna <= 2)){
                    enemigo -> recibirAtaque( "tierra", 1);
                }
                else if ((2 < distanciaFila <= 4) && (2 < distanciaColumna <= 4)){
                    enemigo -> recibirAtaque( "tierra", 2);
                }
                else{
                    enemigo -> recibirAtaque( "tierra", 3);
                }
            }
        }
    }
    else{
        cout << "El personaje " << personaje -> obtenerNombre() << " no cuenta con la energía necesaria para atacar" << endl;
    }
}

bool ControladorTierra::defensa() {
	bool seDefiende = personaje->defender();
	if(seDefiende) {
		esta_defendiendo = true;
	}
    return 0;
}

ControladorTierra::ControladorTierra(Personaje* personaje, Tablero* tablero) {
	this->personaje = personaje;
    this->tablero = tablero;
    for(int i = 0; i<2; i++){ubicacion[i] = 0;};
    ptrCasillero = 0;
}
