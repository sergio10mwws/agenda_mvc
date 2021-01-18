<?php


class AgendaController{
    public function verTodaAgenda()
    {
        require_once __DIR__ . '/../Repositorio/AgendaRepositorio.inc';
        $datos=(new AgendaRepositorio())->findAllAmigos();
        include __DIR__ . '/../../app/plantillas/mostrarAmigos.php';
    }

    public function eliminarAmigo(){
        if(!isset($_POST['ok'])){
            require_once __DIR__ . '/../Repositorio/AgendaRepositorio.inc';
            $datos=(new AgendaRepositorio())->findAllAmigos(true); 
            //die($var_dump($datos));
            include __DIR__ . '/../../app/plantillas/eliminarAmigos.php';
        }else{
            $aEliminar=$_POST['borrar'];
            //die(var_dump($aEliminar));
            require_once __DIR__ . '/../Repositorio/AgendaRepositorio.inc';
            $agendaRepositorio = new AgendaRepositorio();
            $contador=0;
            foreach($aEliminar as $key => $value){
                //die(var_dump($value));
                $agendaRepositorio->deleteAmigo((int) $value);
                $contador++;
            }
            $datos=(new AgendaRepositorio())->findAllAmigos();
            $eliminados = $contador;
            include __DIR__ . '/../../app/plantillas/eliminarAmigos.php';
        }
    }
}



