#pragma once
#include  <vtkDataSetMapper.h>
#include  <vtkRenderer.h>
#include  <vtkRenderWindow.h>
#include  <vtkActor.h>
#include  <vtkRenderWindowInteractor.h>
#include  <vtkSmartPointer.h>
#include  <vtkUnstructuredGrid.h>
#include  <vtkSphereSource.h>
#include  <vtkPolyData.h>
#include  <vtkPolyDataMapper.h>
#include  <vtkProperty.h>
#include  <vtkCamera.h>
#include <vtkSphereSource.h>
#include <vtkTransform.h>
#include <vtkKdTree.h>
#include <vtkTextActor.h>
#include <vtkTextProperty.h>

class Visualizacion
{
public:
    Visualizacion();
    ~Visualizacion();
    void mostrarObjetoInicial ( vtkPolyData * polydata );
    void zoom ( bool accion );
    void moverHorizontal ( bool direccion );
    void moverVertical ( bool direccion );
    void rotarVertical ( bool direccion );
    void rotarHorizontal ( bool direccion );
    void activarDeformacion ( bool activar );
    void ubicacionEsferaDeformacion ( double x, double y );
    void textoAccion ( std::string gesto );
    void textoGesto ( std::string gesto );
    void textoPrueba ( std::string prueba );
    void cambioDeformacion ( bool repeler );
    void actualizarVentana ( vtkPolyData* p );
    double* puntoCercano ( double x, double y );
private:
    int holguraX;
    int holguraY;
    vtkSmartPointer<vtkPolyData> polydata;
    vtkSmartPointer<vtkSphereSource> esferaDeformar;
    vtkSmartPointer<vtkRenderer> renderer;
    vtkSmartPointer<vtkPolyDataMapper> mapper;
    vtkSmartPointer<vtkActor> actor;
    vtkSmartPointer<vtkPolyDataMapper> mapperEsfera;
    vtkSmartPointer<vtkActor> actorEsfera;
    vtkSmartPointer<vtkRenderWindow> ventana;
    vtkSmartPointer<vtkRenderWindowInteractor> interactor;
    vtkSmartPointer<vtkCamera> camera;
    vtkSmartPointer<vtkTextActor> textActor;
    vtkSmartPointer<vtkTextActor> textGesto;
    vtkSmartPointer<vtkTextActor> textPrueba;
};
