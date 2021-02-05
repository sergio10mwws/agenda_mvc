<?php
namespace miId\App\fuente\Controlador;
use  miId\App\fuente\Repositorio\AgendaRepositorio;
use  miId\App\fuente\Repositorio\ProvinciaRepositorio;
use  miId\App\fuente\Modelo\Amigo;
use  miId\App\fuente\Modelo\AmigoException;

class AgendaController{
    public function verTodaAgenda()
    {
        if(isset($_SESSION['usuario'])){
            $usu = $_SESSION['usuario'];
            //require_once __DIR__ . '/../Repositorio/AgendaRepositorio.inc';
            if(isset($_POST['buscar'])){
                $datos=(new AgendaRepositorio())->findByNombreOrProvincia($_POST['buscador']);
            }else{
                $datos=(new AgendaRepositorio($usu))->findAllAmigosByUsu(true);
            }
            include __DIR__ . '/../../app/plantillas/mostrarAmigos.php';
        }else{
            header('Location: index.php?ctl=login');
        }
    }

    public function eliminarAmigo(){
        if(!isset($_POST['ok'])){
            //require_once __DIR__ . '/../Repositorio/AgendaRepositorio.inc';
            $datos=(new AgendaRepositorio())->findAllAmigosByUsu(true); 
            //die($var_dump($datos));
            include __DIR__ . '/../../app/plantillas/eliminarAmigos.php';
        }else{
            $aEliminar=$_POST['borrar'];
            //die(var_dump($aEliminar));
            //require_once __DIR__ . '/../Repositorio/AgendaRepositorio.inc';
            $agendaRepositorio = new AgendaRepositorio();
            $contador=0;
            foreach($aEliminar as $key => $value){
                //die(var_dump($value));
                $agendaRepositorio->deleteAmigo((int) $value);
                $contador++;
            }
            $datos=(new AgendaRepositorio())->findAllAmigosByUsu(true);
            $eliminados = $contador;
            include __DIR__ . '/../../app/plantillas/eliminarAmigos.php';
        }
    }

    function agregaAmigo(){
        if(isset($_POST['ok'])){
            //require_once __DIR__ . '/../Modelo/Amigo.inc';
            $datos = $_POST['datos'];
            try {
                $amigo=new Amigo($datos);
                //require_once __DIR__ . '/../Repositorio/AmigoRepositorio.inc';
                //diferenciar la no inserción que levanta excepcion de cuando
                //no inserta sin levantar excepción
                try {
                    if(!(new AgendaRepositorio())->addAmigo($amigo)){

                    }
                } catch (\PDOException $th) {
                    //throw $th;
                } catch (\Exception $th) {
                    //throw $th;
                }  
                unset($datos);
                unset($amigo); 
            } catch (AmigoException $ex) {
                $errores = $ex->getErrores();
            }
        }

        //require_once __DIR__ . '/../Repositorio/ProvinciaRepositorio.inc';
        $provincias = (new ProvinciaRepositorio())->findAllProvincias();
        include __DIR__ . '/../../app/plantillas/agregarAmigo.php';
        
    }

    


}



