<?php
namespace miId\App\fuente\Repositorio;
use miId\App\fuente\nucleo\ConexionBd;
class ProvinciaRepositorio{
    public function findAllProvincias():array{
        $sql="SELECT nombre
                FROM provincia";
        //require_once __DIR__ . '/../nucleo/conexionBd.inc';

        try {
            $con = (new ConexionBd())->getConexion();
            $stn = $con->query($sql);
            return $stn->fetchAll(\PDO::FETCH_ASSOC);
        } catch (\PDOException $ex) {
            throw $ex;
        } catch (\Exception $ex) {
            throw $ex;
        }finally{
            unset($stn);
            unset($con);
        }
    }
}
