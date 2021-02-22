#ifndef CONTROLADORAIRE_H
#define CONTROLADORAIRE_H
#include "controladorPersonaje.h"

class ControladorAire : public ControladorPersonaje{
    private:
    public:
        // POS: Utiliza su defensa, retorna true si tiene exito o false
        // si falla
        bool defensa();
        // PRE: Recibe un vector con los controladores de personaje del oponente
        // POS: realiza su ataque, si tiene exito devuelve true, si falla devuelve false
        bool atacar(ControladorPersonaje** ControladoresEnemigo);
        // PRE: Recibe un puntero a casillero
        // POS: Retorna el costo que supondria moverse a ese casillero
        int evaluarDir(Casillero* dir);
        ControladorAire(Personaje* personaje, Tablero* tablero);

};

#endif
