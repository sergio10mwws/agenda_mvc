<?php
//index.php
session_start();
error_reporting(E_ALL);

spl_autoload_register(function (string $clase) {
  if (strpos($clase, 'miId\\App\\') === 0) {
    $path = str_replace('miId\\App\\', '', $clase);
    require_once __DIR__ . '/' . $path . '.inc';
  }
});

//require_once __DIR__ . '/fuente/Controlador/defaultController.inc'; /*controladores */
//require_once __DIR__ . '/fuente/Controlador/AgendaController.inc'; /*controladores */
//require_once __DIR__ . '/fuente/Controlador/LoginController.inc'; /*Ubicación del archivo de rutas*/
require_once __DIR__ . '/app/conf/rutas.inc'; /*Ubicación del archivo de rutas*/


// Parseo de la ruta
if (isset($_GET['ctl'])) {
  if (isset($mapeoRutas[$_GET['ctl']])) {
    $ruta = $_GET['ctl'];
  } else {
    header('Status: 404 Not Found');
    echo '<html><body><h1>Error 404: No existe la ruta <i>' .
      $_GET['ctl'] .
      '</p></body></html>';
    exit;
  }
} else {
  $ruta = 'inicio';
}

$controlador = $mapeoRutas[$ruta];
// Ejecución del controlador asociado a la ruta

if (method_exists($controlador['controller'], $controlador['action'])) {
  call_user_func(array(new $controlador['controller'], $controlador['action']));
} else {
  header('Status: 404 Not Found');
  echo '<html><body><h1>Error 404: El controlador <i>' .
    $controlador['controller'] .
    '->' . $controlador['action'] .
    '</i> no existe</h1></body></html>';
}
