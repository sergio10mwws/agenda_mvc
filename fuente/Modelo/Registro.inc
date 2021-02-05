<?php

namespace miId\App\fuente\Modelo;


class Registro
{

    private string $nombre;
    private string $apellidos;
    private string $calle;
    private string $ciudad;
    private string $provincia;
    private string $cp;
    private string $correo;
    private string $tlfno;

    public function __construct(array $datos, $nuevo = true)
    {
        if ($nuevo) {
            require_once __DIR__ . '/../../app/utilidades/sanitiza.inc';
            if (!$this->setNombre(sanea($datos['nombre']))) {
                $error['nombre'] = 'Error en nombre';
            }
            if (!$this->setApellidos(sanea($datos['apellidos']))) {
                $error['apellidos'] = 'Un mensaje de error';
            }
            if (!$this->setCalle(sanea($datos['calle']))) {
                $error['calle'] = 'Error en la calle';
            }
            if (!$this->setCiudad(sanea($datos['ciudad']))) {
                $error['ciudad'] = 'Error en ciudad';
            }
            if (!$this->setProvincia(sanea($datos['provincia']))) {
                $error['ciudad'] = 'Error en provincia';
            }
            if (!$this->setCp(sanea($datos['cp']))) {
                $error['cp'] = 'Error en código postal';
            }
            if (!$this->setCorreo(sanea($datos['eCorreo']))) {
                $error['eCorreo'] = 'Error en correo';
            }
            if (!$this->setTlfno(sanea($datos['tlfno']))) {
                $error['tlfno'] = 'Error en teléfono';
            }
            if (isset($error)) {
                throw new AmigoException('Datos erróneos', $error);
            }
        }
    }


    /**
     * Get the value of nombre
     */
    public function getNombre(): string
    {
        return $this->nombre;
    }

    /**
     * Set the value of nombre
     *
     * @return  self
     */
    public function setNombre($nombre): bool
    {
        if (empty($nombre) || strpos('--', $nombre) === 0 || strlen(($nombre)) > 50) {
            return false;
        }
        $this->nombre = $nombre;
        return true;
    }

    /**
     * Get the value of apellidos
     */
    public function getApellidos(): string
    {
        return $this->apellidos;
    }

    /**
     * Set the value of apellidos
     *
     * @return  self
     */
    public function setApellidos($apellidos): bool
    {
        if (empty($apellidos) || strpos('--', $apellidos) === 0 || strlen(($apellidos)) > 100) {
            return false;
        }
        $this->apellidos = $apellidos;

        return $this;
    }

    /**
     * Get the value of calle
     */
    public function getCalle(): string
    {
        return $this->calle;
    }

    /**
     * Set the value of calle
     *
     * @return  self
     */
    public function setCalle($calle): bool
    {
        if (empty($calle) || strpos('--', $calle) === 0 || strlen(($calle)) > 150) {
            return false;
        }
        $this->calle = $calle;

        return $this;
    }

    /**
     * Get the value of ciudad
     */
    public function getCiudad(): string
    {
        return $this->ciudad;
    }

    /**
     * Set the value of ciudad
     *
     * @return  self
     */
    public function setCiudad($ciudad): bool
    {
        if (empty($ciudad) || strpos('--', $ciudad) === 0 || strlen(($ciudad)) > 50) {
            return false;
        }
        $this->ciudad = $ciudad;

        return $this;
    }

    /**
     * Get the value of provincia
     */
    public function getProvincia(): string
    {
        return $this->provincia;
    }

    /**
     * Set the value of provincia
     *
     * @return  self
     */
    public function setProvincia($provincia): bool
    {
        if (empty($provincia) || strpos('--', $provincia) === 0 || strlen(($provincia)) > 22) {
            return false;
        }
        $this->provincia = $provincia;

        return true;
    }

    /**
     * Get the value of cp
     */
    public function getCp(): string
    {
        return $this->cp;
    }

    /**
     * Set the value of cp
     *
     * @return  self
     */
    public function setCp($cp): bool
    {
        $expReg = '/^[0-5][0-9]{4}$/';

        if (!preg_match($expReg, $cp)) {
            return false;
        }

        $this->cp = $cp;

        return true;
    }

    /**
     * Get the value of correo
     */
    public function getCorreo(): string
    {
        return $this->correo;
    }

    /**
     * Set the value of correo
     *
     * @return  self
     */
    public function setCorreo($correo): bool
    {
        if (!filter_var($correo, FILTER_VALIDATE_EMAIL)) {
            return false;
        }

        $this->correo = $correo;

        return true;
    }

    /**
     * Get the value of tlfno
     */
    public function getTlfno(): string
    {
        return $this->tlfno;
    }

    /**
     * Set the value of tlfno
     *
     * @return  self
     */
    public function setTlfno($tlfno): bool
    {

        $expReg = '/^[0689][0-9]{8}$/';

        if (!preg_match($expReg, $tlfno)) {
            return false;
        }

        $this->tlfno = $tlfno;

        return true;
    }
}
