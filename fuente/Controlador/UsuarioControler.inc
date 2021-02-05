<?php

namespace miId\App\fuente\Controlador;

use miId\App\fuente\Modelo\Usuario;

class UsuarioController
{

    public function agregarUsuario()
    {
        if (isset($_POST['ok'])) {
            try {
                //code...

                header('Location: index.php');
            } catch (\AmigoException $ex) {
                $errores->getErrores();
            }
        }
        include __DIR__ . '/../../app/plantillas/login.php';
    }
}
