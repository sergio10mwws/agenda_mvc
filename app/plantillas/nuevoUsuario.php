<?php
ob_start();
?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <form action="" method="POST">
        <fieldset>
            <legend>Datos personales</legend>
            <label>Nombre<input type="text" name="datos[nombre]" value="" require placeholder="Tu nombre"></label>

            <label>Apellidos<input type="text" name="datos[apes]" value="" require placeholder="Tus apellidos"></label>
        </fieldset>
        <fieldset>
            <legend>Dirección</legend>
            <label>Calle: <input type="text" name="datos[calle]" required size="60"></label>
            <?= isset($errores['calle']) ? 'Error en la calle' : ''   ?>
            <br>
            <label>Ciudad: <input type="text" name="datos[ciudad]" required></label>
            <label>Provincia <input type="text" name="datos[provincia]"></label>
            <label>CP: <input type="text" name="datos[cp]" required></label>
        </fieldset>
        <fieldset>
            <legend>Datos de contacto</legend>
            <label>Corre-e: <input type="email" name="datos[eCorreo]"></label>
            <label>Teléfono: <input type="tel" name="datos[tlfno]"></label>
        </fieldset>
        <fieldset>
            <legend>Información de registro</legend>
            <label>Usiario: <input type="text" name='reg[usu]' autocomplete="off" required></label>
            <label>Contraseña: <input type="password" name='reg[pass]' autocomplete="off" required></label>
        </fieldset>
        <input type="submit" value="Registrarme" value="ok">
        <input type="reset" value="Limpiar">
    </form>
</body>

</html>
<?php $contenido = ob_get_clean(); ?>
<?php include 'base.php'; ?>