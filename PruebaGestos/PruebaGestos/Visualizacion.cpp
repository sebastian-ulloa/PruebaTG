#include "Visualizacion.h"

Visualizacion::Visualizacion()
{
	object = vtkSmartPointer<vtkSphereSource>::New();
    esferaDeformar = vtkSmartPointer<vtkSphereSource>::New();

    actor = vtkSmartPointer<vtkActor>::New();
    actorEsfera = vtkSmartPointer<vtkActor>::New();

	mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
	mapperEsfera = vtkSmartPointer<vtkPolyDataMapper>::New();

    ventana = vtkSmartPointer<vtkRenderWindow>::New();
    camera = vtkSmartPointer<vtkCamera>::New();
    renderer = vtkSmartPointer<vtkRenderer>::New();

	object->SetRadius(5);
    esferaDeformar->SetRadius ( 1 );

    camera->SetPosition ( 0, 0, 40 );
    ventana->SetSize ( 1366, 670 );
    interactor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    interactor->SetRenderWindow ( ventana );

	textActor =	vtkSmartPointer<vtkTextActor>::New();
	textActor->SetInput("Hola");
	textActor->SetPosition2(10, 40);
	textActor->GetTextProperty()->SetFontSize(24);
	textActor->GetTextProperty()->SetColor(1.0, 0.0, 0.0);

}

Visualizacion::~Visualizacion()
{
}

void Visualizacion::mostrarObjetoInicial ( )
{

	mapper->SetInputConnection(object->GetOutputPort());
    actor->SetMapper ( mapper );    

    mapperEsfera->SetInputConnection ( esferaDeformar->GetOutputPort() );
    actorEsfera->SetMapper ( mapperEsfera );
    actorEsfera->GetProperty()->SetColor ( 0,0.50196,1 );
	actorEsfera->VisibilityOff();

	renderer->AddActor(actor);
	renderer->AddActor ( actorEsfera );
	renderer->AddActor2D(textActor);
	renderer->SetActiveCamera(camera);

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
    esferaDeformar->SetCenter ( x, y, 0 );
    ventana->Render();
}

void Visualizacion::gestoActual(std::string gesto){
	textActor->SetInput(gesto.c_str());
	ventana->Render();
}