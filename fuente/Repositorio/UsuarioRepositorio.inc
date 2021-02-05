<?php

namespace miId\App\fuente\Repositorio;

use miId\App\fuente\nucleo\ConexionBd;
use miId\App\fuente\Modelo\Registro;

class UsuarioRepositorio
{
    public function findPass(string $usu)
    {
        $sql = "SELECT pass
            FROM ususario
            WHERE usuario= '" . $usu . "' ";

        //require_once __DIR__ . '/../nucleo/conexionBd.inc';

        try {
            $con = (new ConexionBd())->getConexion();
            $stn = $con->prepare($sql);
            //$stn->bindValue(':usuario',$usu);
            $stn->execute();
            $stn->bindColumn('pass', $hash);
            $stn->fetch(\PDO::FETCH_BOUND); //Casa vez que lo ejecuto me devuelve un valor de la coumna
            return $hash;
            //return $stn->fetchAll(PDO::FETCH_ASSOC);
        } catch (\PDOException $ex) {
            throw $ex;
            return false;
        } catch (\Exception $ex) {
            throw $ex;
            return false;
        } finally {
            unset($stn);
            unset($con);
        }
    }

    public function findNombreIdUsuarioByUsuario(string $usuario):array
    {
        $sql='SELECT u.Usuario, r.nombre 
        FROM registro r INNER JOIN ussuario u
            ON r.idUsuario= u.idUsuario
            WHERE u.usuario = :usu';
            $con=(new ConexionBd())->getConexion();
            $stn=$con->prepare($sql);
            $stn->bindValue(':usu', $usuario) ;
            $stn->execute();
            return $stn->fetchAll(\PDO::FETCH_ASSOC);
    }

    public function addInfUsuario(Registro $reg)
    {
        $sql = "exec addNewUser :nom,:ape,:call,:ciu,:prov,:cp,:corr,:tel";
        try {
            $con = (new ConexionBd())->getConexion();
            $stn = $con->prepare($sql);
            $stn->bindValue(':nom', $reg->getNombre());
            $stn->bindValue(':ape', $reg->getApellidos());
            $stn->bindValue(':call', $reg->getCalle());
            $stn->bindValue(':ciu', $reg->getCiudad());
            $stn->bindValue(':prov', $reg->getProvincia());
            $stn->bindValue(':cp', $reg->getCp());
            $stn->bindValue(':corr', $reg->getTlfno());
            $stn->bindValue(':tel', $reg->getTlfno());
            $stn->execute();
        } catch (\PDOException $ex) {
            throw $ex;
        } catch (\Exception $ex) {
            throw $ex;
        } finally {
            unset($stn);
            unset($con);
        }
    }
}
