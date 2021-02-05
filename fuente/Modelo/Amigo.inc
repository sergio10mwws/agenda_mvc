<?php
namespace miId\App\fuente\Modelo;

class Amigo
{
    private string $ciudad;
    private string $nombre;
    private int $edad; 
    private string $tlfno;

    public function __construct(array $datos, bool $nuevo=true)         //Para distinguir si tengo que hacer comprobaciones o no (nos e pueden sobrecargar los contructores)
    {
        //die(var_dump($datos));
        if($nuevo){
            if(!empty($error = $this->setCiudad(htmlspecialchars(trim(($datos['ciudad'])))))){  ///Preguntamos si el setter ha devuelto una cadena que noes vacia
                $errores['ciudad'] = $error;                                            //Vemos si el usuario nos ha metido un caracter especial y limpiamos la cadena
            }                                                                           //Hacer con todos, también s epuede hacer en los setters

            if(!empty($error = $this->setNombre(htmlspecialchars(trim($datos['nombre']))))){  ///Preguntamos si el setter ha devuelto una cadena que noes vacia
                $errores['nombre'] = $error;
            }

            if(!empty($error = $this->setEdad(htmlspecialchars(trim($datos['edad']))))){  ///Preguntamos si el setter ha devuelto una cadena que noes vacia
                $errores['edad'] = $error;
            }

            if(!empty($error =  $this->setTelefono(htmlspecialchars(trim($datos['telefono']))))){  ///Preguntamos si el setter ha devuelto una cadena que noes vacia
                $errores['telefono'] = $error;
            }

            if(isset($errores)){
                include 'AmigoException.inc';
                throw new AmigoException("Amigo con errores", $errores);
            }
        }
        
    }


    public function setCiudad(string $ciudad):string{
        if(empty($ciudad)){
            return "El campo es obligatorio";
            $this->ciudad=$ciudad;          
        }

        return '';
    }

    public function setEdad(string $edad):string{
        if(empty($edad)){
            return "El campo es obligatorio";
        }
        
        $expReg='/(1[89])|([2-9][0-9])/';

        if(!preg_match($expReg, $edad)){
            return 'Edad no es correcto';
        }

        $ed=intval($edad);

        if($ed>45){
            return 'Ese amigo es muy mayor';
        }
        $this->edad=$edad;
        return '';      
    }

    public function setNombre(string $nombre):string{
        if(empty($nombre)){
            return "El campo es obligatorio";
        }
        
        $expReg='/[A-Z][a-záéíóú]{0,15}[a-záéíóú] ([AZÑ][a-záéíóú]{0,15}[aeioudnzáéíóú])*/';   ///Lo último es el caracter con el que termina
        if(!preg_match($expReg, $nombre)){
            return 'Nombre no es correcto';        
        }
        $this->nombre=$nombre;
        return '';
    }

    public function setTelefono(string $telefono):string{
        if(empty($telefono)){
            return "El campo es obligatorio";
        }

        $expReg='/[976]{1}[0-9]{8}/';
        
        if(!preg_match($expReg, $telefono)){
            return 'Telefono no es correcto';
        }
        $this->tlfno=$telefono;
        return '';
    }

    public function getCiudad():string{
        return $this->ciudad;
    }

    public function getNombre():string{
        return $this->nombre;
    }

    public function getEdad():int{
        return $this->edad;
    }

    public function getTlfno():int{
        return $this->tlfno;
    }
}