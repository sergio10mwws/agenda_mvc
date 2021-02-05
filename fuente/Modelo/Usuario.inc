<?php
namespace miId\App\fuente\Modelo;
class Usuario{

  

    private string $usu;
    private string $pass;
    private array $errores;

    public function __construct($usu, $pass, $passre)
    {
        $this->errores = [];
        if (!empty($error = $this->setPass($pass, $passre))) {
            $this->errores['pass'] = $error;
        } else {
            $this->pass = password_hash($pass, PASSWORD_DEFAULT);
        }
        if (!empty($error = $this->setUsu($usu))) {
            $this->errores['usu'] = $error;
        } else {
            $this->usu = $usu;
        }
    }

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

    public function setUsu(string $usu)
    {
        if (strlen($usu) < 5) {
            return "El nombre de usuario de be tener al menos 5 caracteres";
        }
        return "";
    }
    public function getErrores()
    {
        return $this->errores;
    }

    public function getUsu()
    {
        return $this->usu;
    }
    public function getPass()
    {
        return $this->pass;
    }

}