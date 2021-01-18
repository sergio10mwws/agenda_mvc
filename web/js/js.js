document.addEventListener('DOMContentLoaded', () => {
    if (eliminados_DOM = document.getElementById('eliminados')) {
        eliminados_DOM_texto = document.getElementById('eliminados').innerHTML;
        Swal.fire({
            type: 'success',
            title: `¡Perfecto!`,
            text: `Se han elminado ${eliminados_DOM_texto} con éxito`,
        })
        eliminados_DOM.parenNode.removeChilds()
    }
})