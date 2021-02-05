<?php

namespace miId\App\fuente\Controlador;
use miId\App\fuente\Modelo\AmigoException;
use miId\App\fuente\Modelo\Usuario;
use miId\App\fuente\Modelo\Registro;
use miId\App\fuente\Repositorio\UsuarioRepositorio;
use PDOException;

class UsuarioController
{
    public function agregarUsuario()
    {
        if (isset($_POST['ok'])) {
            try {
                $datos=$_POST['datos'];
                $objDatos = new Registro($datos);
                try {
                    $usuario = $_POST['reg'];
                    $pass = $_POST['reg']['pass'];
                    $hash=password_hash($pass,PASSWORD_DEFAULT);
                    $_POST['reg']['pass']=$hash;
                    $objUsuario = new Usuario($usuario);
                    $objUsuarioRep = new UsuarioRepositorio();
                    $objUsuarioRep->addInfUsuario($objDatos,$objUsuario);
                    $infUsu=$objUsuarioRep->findNombreIdUsuarioByUsuario($_POST['reg']['usu']);
                    $_SESSION['usuario'] = $infUsu['idUsuario'];
                    $_SESSION['nombre'] = $infUsu['nombre'];
                    
                    header('Location: index.php');
                } catch (AmigoException $ex) {
                    $errores = true;
                }
            } catch (AmigoException $ex) {
                $ex->getErrores();
            } catch (\PDOException $ex){
                die($ex->getMessage());
            } catch (\Exception $ex){
                die($ex->getMessage());
            }
        }
        include __DIR__ . '/../../app/plantillas/login.php';
    }
}
