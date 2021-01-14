<?php

class AgendaRepositorio
{
    public function findAllAmigos():array
    {
        $sql='SELECT a.Nombre, Edad, Telefono, p.nombre as Provincia
            FROM agenda AS a 
                INNER JOIN provincia AS p on a.codProvincia = p.codProvincia';
        require_once require __DIR__ . '/../../core/conexionBd.inc';

        try {
            $con= (new ConexionBd())->getConexion();
            $stm = $con->prepare($sql);
            $stm->execute();
        return $stm->fetchAll(PDO::FETCH_ASSOC);
        } catch (PDOException $ex) {
            throw $ex;
        } catch (Exception $ex){
            throw $ex;
        } finally{
            $stm=null;
            $con=null;
        }
    }

    public function findAllByProvincia(string $provincia):array
    {
        $sql='SELECT a.Nombre, Edad, Telefono, p.nombre as Provincia
            FROM agenda AS a 
                INNER JOIN provincia AS p on a.codProvincia = p.codProvincia
            WHERE p.nombre = :provincia';
        return [];
    }

    public function addAmigo(array $amigo):bool{
        $sql = 'INSERT INTO agenda (nombre,edad,tlfno,p.codProvincia)
        SELECT :nombre, :edad, :tefno, codProvincia
        FROM provincia as p
        WHERE p.nombre = :provincia';

        return true;
    }

}