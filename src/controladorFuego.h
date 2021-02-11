#ifndef CONTROLADORFUEGO_H
#define CONTROLADORFUEGO_H
#include "controladorPersonaje.h"

class ControladorFuego : public ControladorPersonaje{
    private:
    public:
        void atacar();
        int evaluarDir(Casillero* dir);
        ControladorFuego(Personaje* personaje, Tablero* tablero);
};

#endif