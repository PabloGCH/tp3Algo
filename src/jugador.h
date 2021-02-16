#ifndef JUGADOR_H_
#define JUGADOR_H_
#include "controladorPersonaje.h"

class Jugador {
protected:
	ControladorPersonaje* controladores[3];
	Jugador* oponente;

public:
	Jugador();
	// PRE: se debe invocar cada vez que un personaje ataque
    // POS: revisa si hay personajes con 0 o menos de vida y fija el controlador
    void matarPersonajes();
	// PRE: recibe el controlador del personaje de agua
	// POS: cura a los personajes si un personaje de agua se defiende
	void curarPersonajes(ControladorPersonaje* cont);
	void asignar_controlador(ControladorPersonaje* controlador);
    void mostrarOpcionesPrimerEtapa(int jugadorActual, int personajeActual);
    void mostrarOpcionesSegudaEtapa(int jugadorActual, int personajeActual);
    int solicitarOpcion();
    void procesarOpcion(int opcionElegida, int etapa, int personajeActual);
    void turno(int actual);
	void asignar_rival(Jugador* rival);
	void sinEnergia();
	ControladorPersonaje** devolverControladores();
	~Jugador();
};



#endif /* JUGADOR_H_ */
