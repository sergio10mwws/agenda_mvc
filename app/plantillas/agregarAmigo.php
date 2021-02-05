<?php
ob_start();
?>

<form method="POST">
    <fieldset>
        <legend>Agregar amigo a la agenda</legend>
        <label>Ciudad
            <select name="datos[ciudad]" id="ciudad">
                <?php foreach ($provincias as $agenda) : ?>
                    <option value="<?= $agenda['nombre'] ?>"><?= $agenda['nombre'] ?></option>
                <?php endforeach ?>
            </select>
            <br>
        </label>
        <label>Nombre: <input type="text" name="datos[nombre]" value="<?php echo isset($datos['nombre']) ? "{$datos['nombre']}" : "" ?>"></label>
        <p class="mensaje"> <?= (isset($errores['nombre'])) ? "{$errores['nombre']}" : "" ?> </p>

        <label>Edad: <input type="number" name="datos[edad]"></label>
        <?= (isset($errores['edad'])) ? "<p class=\"mensaje\">{$errores['edad']}</p>" : ""  ?>

        <label>Teléfono: <input type="number" name="datos[telefono]"></label>
        <p class="mensaje"> <?= (isset($errores['telefono'])) ? "{$errores['telefono']}" : "" ?> </p>
        <br>
        <!--Hay que pones llaves para dejar claro el ámbito del elemento de Array-->
        <input type="submit" name="ok" value="Guardar">

    </fieldset>
</form>

<?php $contenido = ob_get_clean(); ?>

<?php include 'base.php'; ?>