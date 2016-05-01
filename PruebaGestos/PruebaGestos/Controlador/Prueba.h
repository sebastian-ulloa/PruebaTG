#pragma once

#include <vector>
#include <ctime>
#include <fstream>
#include <iostream>

#include "../Vista/Visualizacion.h"

#ifndef _GESTO_
#define _GESTO_
typedef
enum _GESTO
{
    MANO_IZQUIERDA_ARRIBA = 1,
    MANO_DERECHA_ARRIBA = 2,

    ROTAR_DERECHA = 3,
    ROTAR_IZQUIERDA = 4,
    ROTAR_ARRIBA = 5,
    ROTAR_ABAJO = 6,

    MANOS_ARRIBA = 7,

    ZOOM_IN = 8,
    ZOOM_OUT = 9,

    MOVER_DERECHA = 10,
    MOVER_IZQUIERDA = 11,
    MOVER_ARRIBA = 12,
    MOVER_ABAJO = 13,
    NO_GESTO = 0
} 	GESTO;

#endif _GESTO_

class Prueba
{
public:
    Prueba();
    Prueba ( Visualizacion * v );
    ~Prueba();
    bool realizoGesto ( GESTO g );
    bool realizoGesto ( bool accion );
    void empezarGesto();
private:
	int npruebas;
    bool repeler;
    bool deformar;
    Visualizacion *v;
    GESTO actual;
    std::vector<GESTO> gestosRealizados;
    std::vector<float> tiempos;
    clock_t inicio;
    int contador;
    std::string nombreGestoActual;

    GESTO agregarGesto ( int g );
    int generarGesto();
    void guardarArchivo();
	void reiniciar();

};

