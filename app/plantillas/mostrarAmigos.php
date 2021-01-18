<?php
ob_start();
var_dump($datos);
$cabeceras = array_keys($datos[0]);
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <h1>Ver amigos</h1>
    <br>
    <table>
        <thead>
            <tr>
                <?php foreach ($cabeceras as $value) { ?>
                    <td><?= $value ?></td>
                <?php } ?>
            </tr>
        </thead>
        <tbody>
            <?php foreach ($datos as $key => $value) { ?>
                <tr>
                    <?php foreach ($value as $clave => $valor) { ?>
                        <td><?= $valor ?></td>
                    <?php } ?>
                </tr>
            <?php } ?>
        </tbody>
    </table>
</body>

</html>

<?php $contenido = ob_get_clean(); ?>

<?php include 'base.php'; ?>