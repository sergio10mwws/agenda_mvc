<?php
ob_start();
$j = count($datos);
?>

<?php
if (isset($eliminados)) {
?>
    <p id="eliminados"><?= $eliminados ?></p>
<?php
}
?>

<h1>Eliminar amigos</h1>
<?php
if ($j) {
    $cab = array_keys($datos[0]);
    $k = count($datos[0]) - 1;  //Para que no aparezca el id de la agenda
}
?>
<form action="" method="POST">
    <table>
        <thead>
            <tr>
                <?php for ($i = 0; $i < $k; $i++) { ?>
                    <th><?= $cab[$i] ?></th>
                <?php } ?>
            </tr>
        </thead>
        <tbody>
            <?php for ($i = 0; $i < $j; $i++) { ?>
                <tr>
                    <?php for ($l = 0; $l < $k; $l++) { ?>
                        <td><?= $datos[$i][$cab[$l]] ?></td>
                    <?php } ?>
                    <td><input type="checkbox" name="borrar[<?= $i ?>]" value="<?= $datos[$i][$cab[$l]] ?>"></td>
                    <!--Le damos el valor del idagenda !-->
                </tr>
            <?php } ?>
            <tr colspan="<?= $k ?>"> <input type="submit" name="ok" value="Eliminar"> </tr>
        </tbody>
    </table>
</form>

<?php $contenido = ob_get_clean() ?>

<?php include 'base.php' ?>