<?php
namespace miId\App\fuente\Modelo;
class Usuario{

    private string $usu;
    private string $pass;


    public function setPass(string $pass)
    {
        $expReg = '(?:[A-Z].*)(?:[a-z].*)(?:[0-9].*)(?:\W.*{8,16})';
        if(!preg_match($expReg,$pass)){
            return 'No cumple las condiciones de contraseña segura';
        }
    }

    public static function isPassOk(string $pass,string $hash):bool{
        return password_verify($pass, $hash);
    }
}