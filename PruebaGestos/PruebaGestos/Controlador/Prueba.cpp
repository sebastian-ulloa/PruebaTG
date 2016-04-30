#include "Prueba.h"


Prueba::Prueba()
{
}

Prueba::Prueba ( Visualizacion *v )
{
    actual = agregarGesto ( 2 );
    contador = 0;
    this->v = v;
    repeler = true;
    deformar = true;
}


Prueba::~Prueba()
{
}


bool Prueba::realizoGesto ( GESTO g )
{
    if ( g == actual )
    {
        contador++;
    }
    else
    {
        return false;
    }
    if ( contador == 3 )
    {
        tiempos.push_back ( clock() - inicio );
        contador = 0;
        if ( gestosRealizados.size() < 10 )
        {
            actual = agregarGesto ( generarGesto() );
            v->textoPrueba ( nombreGestoActual );
            inicio = clock();
        }
        else
        {
            v->textoPrueba ( "Acabo prueba" );
            guardarArchivo();
        }
    }
    return true;
}

bool Prueba::realizoGesto ( bool accion )
{
    if ( deformar )
    {
        if ( accion && repeler )
        {
            contador++;
        }
        else
        {
            if ( !accion && !repeler )
            {
                contador++;
            }
            else
            {
                return false;
            }
        }
        if ( contador == 3 )
        {
            contador = 0;
            tiempos.push_back ( clock() - inicio );
            if ( repeler )
            {
                repeler = false;
                actual = agregarGesto ( 2 );
                v->textoPrueba ( nombreGestoActual );
            }
            else
            {
                deformar = false;
                actual = agregarGesto ( generarGesto() );
                v->textoPrueba ( nombreGestoActual );
                inicio = clock();
            }
        }
        return true;
    }
    return false;
}

int Prueba::generarGesto()
{
    srand ( time ( NULL ) );
    int gesto;
    bool repetido = true;
    while ( repetido )
    {
        gesto = rand() % 11 + 3;
        if ( gesto != 7 )
        {
            repetido = false;
            for ( unsigned int i = 0; i < gestosRealizados.size(); i++ )
            {
                if ( gestosRealizados[i] == gesto )
                {
                    repetido = true;
                }
            }
        }
    }
    return gesto;
}

void Prueba::guardarArchivo()
{
    ofstream myfile;
    myfile.open ( "prueba.txt" );
    for ( unsigned int i = 0; i < gestosRealizados.size(); i++ )
    {
        myfile << gestosRealizados[i] << " " << tiempos[i] << "\n";;
    }
    myfile.close();
}

GESTO Prueba::agregarGesto ( int g )
{
    GESTO gesto;
    switch ( g )
    {
    case MANO_DERECHA_ARRIBA:
        gesto = MANO_DERECHA_ARRIBA;
        nombreGestoActual = "Deformar ";
        if ( !repeler )
        {
            nombreGestoActual += "atraer";
        }
        else
        {
            nombreGestoActual += "repeler";
        }
        break;
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
    gestosRealizados.push_back ( gesto );
    return gesto;
}

void Prueba::empezarGesto()
{
    inicio = clock();
    v->textoPrueba ( nombreGestoActual );
}