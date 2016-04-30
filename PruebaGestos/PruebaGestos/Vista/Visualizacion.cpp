#include "Visualizacion.h"

Visualizacion::Visualizacion()
{
    esferaDeformar = vtkSmartPointer<vtkSphereSource>::New();
    actor = vtkSmartPointer<vtkActor>::New();
    actorEsfera = vtkSmartPointer<vtkActor>::New();
    mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
    mapperEsfera = vtkSmartPointer<vtkPolyDataMapper>::New();
    ventana = vtkSmartPointer<vtkRenderWindow>::New();
    camera = vtkSmartPointer<vtkCamera>::New();
    renderer = vtkSmartPointer<vtkRenderer>::New();
    esferaDeformar->SetRadius ( 1 );
    camera->SetPosition ( 0, 0, 40 );
    ventana->SetSize ( 1366, 670 );
    interactor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    interactor->SetRenderWindow ( ventana );
    textActor = vtkSmartPointer<vtkTextActor>::New();
    textGesto = vtkSmartPointer<vtkTextActor>::New();
    textPrueba = vtkSmartPointer<vtkTextActor>::New();
    textActor->SetPosition ( 500, 640 );
    textActor->GetTextProperty()->SetFontSize ( 26 );
    textActor->GetTextProperty()->SetColor ( 0.0, 0.0, 0.0 );
    textGesto->SetPosition ( 0, 640 );
    textGesto->GetTextProperty()->SetBold ( 0 );
    textGesto->GetTextProperty()->SetFontSize ( 26 );
    textGesto->GetTextProperty()->SetColor ( 0.0, 0.0, 0.0 );
    textPrueba->SetPosition ( 1000, 640 );
    textPrueba->GetTextProperty()->SetBold ( 1 );
    textPrueba->GetTextProperty()->SetFontSize ( 26 );
    textPrueba->GetTextProperty()->SetColor ( 0.0, 0.0, 0.0 );
}

Visualizacion::~Visualizacion()
{
}

void Visualizacion::mostrarObjetoInicial ( vtkPolyData * polydata )
{
    this->polydata = polydata;
    mapper->SetInputData ( polydata );
    actor->SetMapper ( mapper );
    mapperEsfera->SetInputConnection ( esferaDeformar->GetOutputPort() );
    actorEsfera->SetMapper ( mapperEsfera );
    actorEsfera->GetProperty()->SetColor ( 0, 0.50196, 1 );
    actorEsfera->VisibilityOff();
    renderer->SetBackground ( 0.52941, 0.82745, 0.92157 );
    renderer->AddActor ( actor );
    renderer->AddActor ( actorEsfera );
    renderer->AddActor2D ( textActor );
    renderer->AddActor2D ( textGesto );
    renderer->AddActor2D ( textPrueba );
    renderer->SetActiveCamera ( camera );
    ventana->AddRenderer ( renderer );
    ventana->Render();
}

void Visualizacion::zoom ( bool accion )
{
    double factor = 0.8;
    if ( accion )
    {
        factor = 1.25;
    }
    renderer->GetActiveCamera()->Zoom ( factor );
    ventana->Render();
}

void Visualizacion::moverHorizontal ( bool direccion )
{
    double posicion[3];
    actor->GetPosition ( posicion );
    if ( direccion )
    {
        posicion[0] = posicion[0] + 2;
    }
    else
    {
        posicion[0] = posicion[0] - 2;
    }
    actor->SetPosition ( posicion );
    ventana->Render();
}

void Visualizacion::moverVertical ( bool direccion )
{
    double posicion[3];
    actor->GetPosition ( posicion );
    if ( direccion )
    {
        posicion[1] = posicion[1] + 2;
    }
    else
    {
        posicion[1] = posicion[1] - 2;
    }
    actor->SetPosition ( posicion );
    ventana->Render();
}
void Visualizacion::rotarVertical ( bool direccion )
{
    double factor = 45;
    if ( direccion )
    {
        factor = -45;
    }
    actor->RotateY ( factor );
    ventana->Render();
}
void Visualizacion::rotarHorizontal ( bool direccion )
{
    double factor = 45;
    if ( direccion )
    {
        factor = -45;
    }
    actor->RotateX ( factor );
    ventana->Render();
}

void Visualizacion::activarDeformacion ( bool activar )
{
    if ( activar )
    {
        actorEsfera->VisibilityOn();
    }
    else
    {
        actorEsfera->VisibilityOff();
    }
    ventana->Render();
}

void Visualizacion::ubicacionEsferaDeformacion ( double x, double y )
{
    esferaDeformar->SetCenter ( x, y, 3 );
    ventana->Render();
}

void Visualizacion::cambioDeformacion ( bool repeler )
{
    if ( repeler )
    {
        actorEsfera->GetProperty()->SetColor ( 0, 0.50196, 1 );
    }
    else
    {
        actorEsfera->GetProperty()->SetColor ( 0.8, 0, 0 );
    }
}

void Visualizacion::textoAccion ( std::string gesto )
{
    std::string g = "Accion: " + gesto;
    textActor->SetInput ( g.c_str() );
    ventana->Render();
}

void Visualizacion::textoGesto ( std::string gesto )
{
    std::string g = "Gesto: " + gesto;
    textGesto->SetInput ( g.c_str() );
    ventana->Render();
}

void Visualizacion::textoPrueba ( std::string prueba )
{
    std::string g = "Prueba: " + prueba;
    textPrueba->SetInput ( g.c_str() );
    ventana->Render();
}
double* Visualizacion::puntoCercano ( double x, double y )
{
    double d[3] = { x, y, 3 };
    double dist;
    vtkSmartPointer<vtkKdTree> kdtree = vtkSmartPointer<vtkKdTree>::New();
    kdtree->BuildLocatorFromPoints ( polydata );
    vtkIdType id = kdtree->FindClosestPoint ( d, dist );
    if ( dist <= 1.0 )
    {
        return polydata->GetPoint ( id );
    }
    return NULL;
}
void Visualizacion::actualizarVentana ( vtkPolyData* p )
{
    polydata->ShallowCopy ( p );
    ventana->Render();
}