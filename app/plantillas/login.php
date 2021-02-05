<?php
    ob_start();
?>

<h1>Inicio de sesión</h1>
<br>
<br>
<form action="" method="POST">
<fieldset>
 <legend> Login </legend>
<br>
<label for="usuario"> Usuario: </label>
<input type="text" name="usuario" value="">
<br>
<br>
<label> Contraeña: </label>
<input type="pass" name="pass" value="">
<br>
<br>
<input type="submit" name="ok" value="ingresar">
</fieldset>
</form>
<?php $contenido = ob_get_clean(); ?>
<?=isset($error)? 'Usuario o contraseña incorrectos' : ''?>
<?php include 'base.php';?>