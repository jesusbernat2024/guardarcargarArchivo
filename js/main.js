
document.getElementById('btnAnadir').onclick = async function (e) {
    e.preventDefault();

    n = document.getElementById('numero').value;
    orden = "anadir";
    
    response = await fetch(`/cgi-bin/funciones.cgi`,{
        method: 'POST',
        headers: {
            'Content-Type': 'application/x-www-form-urlencoded'
        },
        body: new URLSearchParams({
            'numero':n,
            'orden':orden
        })
    });
    data = await response.text();
    
    document.getElementById('resultado').innerHTML = data;
};


document.getElementById('btnResetear').onclick = async function (e) {
    e.preventDefault();

    orden = "resetear";
    
    response = await fetch(`/cgi-bin/funciones.cgi`,{
        method: 'POST',
        headers: {
            'Content-Type': 'application/x-www-form-urlencoded'
        },
        body: new URLSearchParams({
            'numero':'',
            'orden':orden
        })
    });
    data = await response.text();
    
    document.getElementById('resultado').innerHTML = data;
};


document.getElementById('bodyId').onload = async function (e) {
    e.preventDefault();

    orden = "cargar";
    
    response = await fetch(`/cgi-bin/funciones.cgi`,{
        method: 'POST',
        headers: {
            'Content-Type': 'application/x-www-form-urlencoded'
        },
        body: new URLSearchParams({
            'numero':'',
            'orden':orden
        })
    });
    data = await response.text();
    
    document.getElementById('resultado').innerHTML = data;
    
};