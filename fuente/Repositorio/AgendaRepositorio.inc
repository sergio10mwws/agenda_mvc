<?php
namespace miId\App\fuente\Repositorio;

use miId\App\fuente\nucleo\ConexionBd;
use miId\App\fuente\Modelo\Amigo;

class AgendaRepositorio
{
    public function findAllAmigos(bool $conId=false):array
    {
        if($conId){
            $sql='SELECT a.nombre, edad, tlfno, p.nombre as Provincia, idAgenda
            FROM agenda AS a 
                INNER JOIN provincia AS p on a.codProvincia = p.codProvincia';
            
        }else{
            $sql='SELECT a.nombre, edad, tlfno, p.nombre as Provincia
            FROM agenda AS a 
                INNER JOIN provincia AS p on a.codProvincia = p.codProvincia';
        }
        //require_once __DIR__ . '/../nucleo/conexionBd.inc';

        try {
            $con= (new ConexionBd())->getConexion();
            $stm = $con->prepare($sql);
            $stm->execute();
            return $stm->fetchAll(\PDO::FETCH_ASSOC);
        } catch (\PDOException $ex) {
            throw $ex;
        } catch (\Exception $ex){
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

    public function addAmigo(Amigo $amigo):bool{
        $sql = 'INSERT INTO agenda (nombre,edad,tlfno,p.codProvincia)
        SELECT :nombre, :edad, :tfno, codProvincia
        FROM provincia as p
        WHERE p.nombre = :provincia';
        
        //require_once __DIR__ . '/../nucleo/conexionBd.inc';

        try {
            $con= (new ConexionBd())->getConexion();
            $stn = $con->prepare($sql);
            $stn -> bindValue (':nombre', $amigo->getNombre());
            $stn -> bindValue (':edad', $amigo->getEdad());
            $stn -> bindValue (':tfno', $amigo->getTlfno());
            $stn -> bindValue (':provincia', $amigo->getCiudad());
            return $stn -> execute();
        } catch (\PDOException $ex) {
            throw $ex;
            return false;
        } catch (\Exception $ex){
            throw $ex;
            return false;
        }finally{
            unset($stn);
            unset($con);
        }

    }

    public function deleteAmigo(int $id):bool{
        $sql = 'DELETE FROM agenda WHERE idAgenda = :id';
        try {
            //require_once __DIR__ . '/../nucleo/conexionBd.inc';
            $con= (new ConexionBd())->getConexion();
            $con->beginTransaction();
            $stn=$con->prepare($sql);
            $stn->bindParam(':id',$id);
            $v=$stn->execute();
            $con->commit();
        } catch (\PDOException $ex) {
            throw $ex;
        } catch (\Exception $ex){
            throw $ex;
        } finally{
            $stn=null;
            $con=null;
        }

        return $v;
    }

    public function findByNombreOrProvincia(string $dato):array{
        $sql="SELECT a.nombre, edad, tlfno, p.nombre as Provincia, idAgenda
        FROM agenda AS a 
            INNER JOIN provincia AS p on a.codProvincia = p.codProvincia
            WHERE   p.nombre LIKE '%'+:dato+'%'
            OR      a.nombre LIKE '%:dato+'%'";
            //require_once __DIR__ . '/../nucleo/conexionBd.inc';
            try {
                $con= (new ConexionBd())->getConexion();
                $stm = $con->prepare($sql);
                $stm->execute();
                return $stm->fetchAll(\PDO::FETCH_ASSOC);
            } catch (\PDOException $ex) {
                throw $ex;
            } catch (\Exception $ex){
                throw $ex;
            } finally{
                $stm=null;
                $con=null;
            }
    }
}


