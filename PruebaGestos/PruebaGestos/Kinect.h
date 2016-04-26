#pragma once

#include "ole2.h"
#include <Windows.h>
#include <NuiApi.h>
#include <math.h>
#include <vector>

#include "ManejadorGestos.h"
#include "Prueba.h"


class Kinect
{
public:
    Kinect();
    ~Kinect();
    void inicializar();
private:
	Prueba p;
    int empezarGesto;
    GESTO gesto;
    INuiSensor* sensor;
    HANDLE m_hNextSkeletonEvent;
    Visualizacion *visualizacion;
    bool identificador;
    float distanciaInicial;
    float inicialDerechaY;
    float inicialIzquierdaY;
    bool inicializarKinect();
    float redondear ( float n );
    void deteccion();
    void procesarGestos();
    float distancia ( float x1, float x2, float y1, float y2 );
    std::vector<ManejadorGestos> valoresGestos;
    void asignarValoresGestos();
    void reiniciarGestos();
    void convertirCoordenadas ( double x, double y );

};

