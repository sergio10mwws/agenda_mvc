<?php


class AgendaController{
    public function verTodaAgenda()
    {
        require_once __DIR__ . '/../Repositorio/AgendaRepositorio.inc';
        $datos=(new AgendaRepositorio())->findAllAmigos();
        include __DIR__ . '/../../app/plantillas/mostrarTodas.php';
    }
}



