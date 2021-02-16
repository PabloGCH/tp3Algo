#include "controladorAgua.h"



int ControladorAgua::evaluarDir(Casillero* dir){
    int valor = 0;
    int tipo = dir->getType();
    switch(tipo){
        case MOUNTAIN:
            valor = 1;
            break;
        case VOID:
            valor = 15;
            break;
        case ROAD:
            valor = 1;
            break;
        case PRECIPICE:
            valor = 1;
            break;
        case LAKE:
            valor = 0;
            break;
        case VOLCANO:
            valor = 2;
            break;
    }
    return valor; 
}

bool ControladorAgua::comprobarPosicon(int posicionAtacada[2]){
    if ( 1 <= posicionAtacada[0] <= NUM_FILAS or 1 <= posicionAtacada[1] <= NUM_COLUMNAS) {
        cout << "Posición fuera de rango, ingrese una posición válida: " << endl;
        return false;
    }
    Personaje* enemigo = tablero->returnItem(posicionAtacada)->getCharacter();
    if ( !enemigo ){
        cout << "No hay ningún personaje en al posición ingresada " << endl;
        return false;
    }
    return true;
}

void ControladorAgua::defensa(ControladorPersonaje** controladores) {
	bool seDefiende = personaje->defenderse();
	if(seDefiende) {
		for (int i = 0; i < 3, i++) {
			if (controladores[i]->nombre != nombre) {
				controladores[i]->se_curo();
			}
		}
	}
}

void ControladorAgua::atacar(ControladorPersonaje** ControladoresEnemigo){
    if (personaje -> obtenerEnergia() >= ATAQUE_AGUA){
        personaje->restarEnergia(ATAQUE_AGUA);
        int posicionAtacada[2];
        bool verificado = false;
        cout << "Ingrese una posición para atacar " << endl;
        while (!verificado){
            cout << "Fila: ";
            cin >> posicionAtacada[0];
            cout << "" << endl;
            cout << "Columna: ";
            cin >> posicionAtacada[1];
            cout << "" << endl;
            verificado = comprobarPosicon(posicionAtacada);
        }
        Personaje* enemigo = tablero->returnItem(posicionAtacada)->getCharacter();
        for(int i = 0; i < 3; i++){
            if(enemigo == ControladoresEnemigo[i]->devolverPersonaje()){
                enemigo -> recibirAtaque("agua", 0);
            }
        }
    }
    else{
        cout << "El personaje no cuenta con la energia necesaria para atacar " << endl;
    }
    
}

ControladorAgua::ControladorAgua(Personaje* personaje, Tablero* tablero) {
	this->personaje = personaje;
    this->tablero = tablero;
    for(int i = 0; i<2; i++){ubicacion[i] = 0;};
    ptrCasillero = 0;
}
