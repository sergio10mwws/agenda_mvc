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
                $objUsuarioRep = new UsuarioRepositorio();
                $hash = $objUsuarioRep->findPass($usuario);
                //require_once __DIR__ . '/../Modelo/Usuario.inc';
                //die(var_dump($hash));
                if(Usuario::isPassOk($pass, $hash)){
                    $infUsu=$objUsuarioRep->findNombreIdUsuarioByUsuario($_POST['usuario']);
                    $_SESSION['usuario'] = $infUsu['idUsuario'];
                    $_SESSION['nombre'] = $infUsu['nombre'];
                    header('Location: index.php');
                }else{
                    $error = true;
                }
            }
            include __DIR__ . '/../../app/plantillas/login.php';
        }

        public function cierraSesion(){
            if(isset($_SESSION['usuario'])){
                unset($_SESSION['usuario']);
                unset($_SESSION['nombre']);
                session_unset();
                session_destroy();
                header('Location: index.php');
            }
        }
    }

    






