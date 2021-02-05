<!-- Vista común a la mayoría (sino todas) las vistas de la aplicación
     Suele contener la imagen corporativa de la apliación Web
     Concretamente esta página contiene el nombre de la empresa
     "Cadena Tiendas Media" y una barra de hiperenlaces con un enalace a la
     página home, llamado "inicio"
     El nombre del archivo es indiferente: layout, comun, etc.
-->
<!DOCTYPE html>
<html>

<head>
  <title></title>
  <meta charset="utf-8">

  <meta name="viewport" content="width=device-width, initial-scale=1.0">

  <?php include  __DIR__ . '/../../web/include/css_js.inc' ?>
  <style>
    header {
      background-color: orange;
    }

    .headerBase h1 {
      font-family: Verdana, Geneva, Tahoma, sans-serif;
      font-style: 2rem;
      text-align: center;
    }
  </style>
</head>

<body>
  <header>
    <h1 id="headerBase">Agenda de Amigos de Sergio</h1>
  </header>
  <nav>
    <hr>
    <!-- Observa cómo el enlace agrega el valor de la variable GET 'ctl'
           que será analizado en la página index.php, en este caso le da el
           valor 'inicio' para que la vista cambie a la página home de la
           aplicación
       -->
    <a href="index.php?ctl=inicio">Inicio</a> |
    <?php if (isset($_SESSION['login'])) :   ?>
      <a href="index.php?ctl=agregar">Agregar Amigo</a> |
      <a href="index.php?ctl=ver">Ver la agenda</a> |
      <a href="index.php?ctl=quitar">Quitar un amigo</a> |
      <a href="index.php?ctl=logOut">Cerrar sesión</a>
    <?php else :   ?>
      <a href="index.php?ctl=login">Iniciar sesión</a>
    <?php endif;   ?>

    <!-- En general, la mayoría de los enlaces serán a la página index.php
           y una asignación a la variable 'ctl'. El valor de la variable deberá
           ser analizada en la página index.php de cara a encontrar la ruta del
           controlador (y método) que debe procesar la petición
      -->
    <hr>
  </nav>
  <div id="contenido">
    <!-- el id css facilita (si se define) la definición del aspecto visual
           de su contenido
           La variable $contenido hará que se muestre la plantilla concreta, el
           contenido concreto, según la solicitud realizada por el usuario
      -->
    <?= $contenido ?>
  </div>
  <footer>
    <hr>
    <p align="center">- Pie de página -</p>
    <address>
      Juan Nadie
      <br>
      Escríbeme a <a href="Malito: juan@gmail.com">juan@gmail.com</a>
    </address>
  </footer>
</body>

</html>