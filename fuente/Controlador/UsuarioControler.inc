<?php

namespace miId\App\fuente\Controlador;
use miId\App\fuente\Modelo\AmigoException;
use miId\App\fuente\Modelo\Usuario;
use miId\App\fuente\Modelo\Registro;
class UsuarioController
{
    public function agregarUsuario()
    {
        if (isset($_POST['ok'])) {
            try {
                $datos=$_POST['datos'];
                $objDatos = new Registro($datos);
                header('Location: index.php');
            } catch (AmigoException $ex) {
                $ex->getErrores();
            }
        }
        include __DIR__ . '/../../app/plantillas/login.php';
    }
}
