<?php
// Ejemplo de controlador para página home de la aplicación
namespace miId\App\fuente\Controlador;
class DefaultController
{ public function inicio()
  { 
    $datos = ['mensaje'=>'Bienvenido a la aplicación',
    'dia'=>date('d-m-Y'),
    'hora'=> date('h:i:s')
  ];
    require __DIR__ . '/../../app/plantillas/inicio.php';
  }
}
