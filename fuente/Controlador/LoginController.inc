<?php
namespace miId\App\fuente\Controlador;
use miId\App\fuente\Modelo\Usuario;
use miId\App\fuente\Repositorio\UsuarioRepositorio;

    class LoginController{
        public function iniciaSesion()
        {
            if(isset($_POST['ok'])){
                $pass=$_POST['pass'];
                $usuario=$_POST['usuario'];
                
                //require_once __DIR__ . '/../Repositorio/UsuarioRepositorio.inc';
                $hash = ((new UsuarioRepositorio)->findPass($usuario));
                //require_once __DIR__ . '/../Modelo/Usuario.inc';
                //die(var_dump($hash));
                if(Usuario::isPassOk($pass, $hash)){
                    $_SESSION['login'] = true;
                    header('Location: index.php');
                }else{
                    $error = true;
                }
            }
            include __DIR__ . '/../../app/plantillas/login.php';
        }

        public function cierraSesion(){
            if(isset($_SESSION['login'])){
                unset($_SESSION['login']);
                header('Location: index.php');
            }
        }
    }

    






