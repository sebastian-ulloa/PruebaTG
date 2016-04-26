#include "Prueba.h"


Prueba::Prueba(){

}

Prueba::Prueba(Visualizacion *v)
{
	actual = agregarGesto(generarGesto());
	contador = 0;
	this->v = v;
}


Prueba::~Prueba()
{
}


bool Prueba::realizoGesto(GESTO g){
	if (g == actual){
		contador++;
	}
	else{
		return false;
	}
	if (contador == 3){
		tiempos.push_back(difftime(time(NULL), inicio));
		contador = 0;
		actual = agregarGesto(generarGesto());
		v->gestoActual(nombreGestoActual);
		inicio = time(NULL);
	}
	return true;
}

int Prueba::generarGesto(){

	srand(time(NULL));
	int gesto;
	bool repetido = true;
	while (repetido){
		gesto = rand() % 13 + 3;
		if (gesto != 7){
			repetido = false;
			for (unsigned int i = 0; i < gestosRealizados.size(); i++){
				if (gestosRealizados[i] == gesto){
					repetido = true;
				}
			}
		}
	}
	return gesto;
}

GESTO Prueba::agregarGesto(int g){
	GESTO gesto;
	switch (g){
	case MOVER_ARRIBA:
		gesto = MOVER_ARRIBA;
		nombreGestoActual = "Mover arriba";
		break;
	case MOVER_ABAJO:
		gesto = MOVER_ABAJO;
		nombreGestoActual = "Mover abajo";
		break;
	case MOVER_DERECHA:
		gesto = MOVER_DERECHA;
		nombreGestoActual = "Mover derecha";
		break;
	case MOVER_IZQUIERDA:
		gesto = MOVER_IZQUIERDA;
		nombreGestoActual = "Mover izquierda";
		break;
	case ROTAR_ARRIBA:
		gesto = ROTAR_ARRIBA;
		nombreGestoActual = "Rotar arriba";
		break;
	case ROTAR_ABAJO:
		gesto = ROTAR_ABAJO;
		nombreGestoActual = "Rotar abajo";
		break;
	case ROTAR_IZQUIERDA:
		gesto = ROTAR_IZQUIERDA;
		nombreGestoActual = "Rotar izquierda";
		break; 
	case ROTAR_DERECHA:
		gesto = ROTAR_DERECHA;
		nombreGestoActual = "Rotar derecha";
		break;
	case ZOOM_IN:
		gesto = ZOOM_IN;
		nombreGestoActual = "Acercar";
		break;
	case ZOOM_OUT:
		gesto = ZOOM_OUT;
		nombreGestoActual = "Alejar";
		break;
	}
	gestosRealizados.push_back(gesto);
	return gesto;
}

void Prueba::empezarGesto(){
	inicio = time(NULL);
	v->gestoActual(nombreGestoActual);
}