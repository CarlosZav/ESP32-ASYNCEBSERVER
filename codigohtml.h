const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html lang="es">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>Cliente ESP32</title>
</head>
<body>

  <header>
    <h1>ESTACIONAMIENTO NO INTELIGENTE</h1>
  </header>

  <img src = "https://cdn.rinnovabili.it/wp-content/uploads/2021/08/Depositphotos_125943316_l-2015-1068x677.jpg.webp" height = "250"/>

  <br>
  <div id="estadoCajon1", style="color: green;">CAJON 1</div>
  <button id="apartar1", onclick='apartar1()'>Apartar</button>
  <br>
  <div id="estadoCajon2", style="color: green;">CAJON 2</div>
  <button id="apartar2", onclick='apartar2()'>Apartar</button>
  <br>
  <div id="estadoCajon3", style="color: green;">CAJON 3</div>
  <button id="apartar3", onclick='apartar3()'>Apartar</button>
  <br>
  <div id="estadoCajon4", style="color: green;">CAJON 4</div>
  <button id="apartar4", onclick='apartar4()'>Apartar</button>
  <br>
  <div id="estadoCajon5", style="color: green;">CAJON 5</div>
  <button id="apartar5", onclick='apartar5()'>Apartar</button>
  <br>
  <div id="estadoCajon6", style="color: green;">CAJON 6</div>
  <button id="apartar6", onclick='apartar6()'>Apartar</button>
  <br>
  <div id="estadoCajon7", style="color: green;">CAJON 7</div>
  <button id="apartar7", onclick='apartar7()'>Apartar</button>
  <br>
  <div id="estadoCajon8", style="color: green;">CAJON 8</div>
  <button id="apartar8", onclick='apartar8()'>Apartar</button>
  <br>
  <div id="estadoCajon9", style="color: green;">CAJON 9</div>
  <button id="apartar9", onclick='apartar9()'>Apartar</button>
  <br>
  <div id="estadoCajon10", style="color: green;">CAJON 10</div>
  <button id="apartar10", onclick='apartar10()'>Apartar</button>
  <br>
  <div id="estadoCajon11", style="color: green;">CAJON 11</div>
  <button id="apartar11", onclick='apartar11()'>Apartar</button>
  <br>
  <div id="estadoCajon12", style="color: green;">CAJON 11</div>
  <button id="apartar12", onclick='apartar12()'>Apartar</button>
  <br>
  <br>


  <fieldset>
    <legend> TIEMPO RESTANTE DE APARTADO </legend>
    <h2 id="temporeg"></h2>
  </fieldset>

  <br>
  <br>

  <script>

    var confirmacion = "";
    var confirmacionc = "";
    var variable1 = "";
    var variable2 = "";
    var variable3 = "";
    var variable4 = "";
    var variable5 = "";
    var variable6 = "";
    var variable7 = "";
    var variable8 = "";
    var variable9 = "";
    var variable10 = "";
    var variable11 = "";
    var variable12 = "";
    var parametros = "";
    var precio = "$1,000 MXN"

    setInterval(actualizar, 1000);

    function apartar1(){
      
        variable1 = parametros.get('Variable1');
        confirmacion = parametros.get('Confirmacion');
        console.log('Confirmacion:', confirmacion);
        // Hacer algo con las variables
        console.log('Variable1:', variable1);

        fetch('/apartar1',{method:'POST'});

          let mostrarTempo = document.getElementById('temporeg');
          let numero = 60;
          let lanzamiento = setInterval (() => {
            numero--;
            if(numero <= 0){
              clearInterval(lanzamiento);
            } 
            else{
              if (confirmacion == 'ok'){
                numero = -1;
                mostrarTempo.innerText= "INGRESO DETECTADO!";
                mostrarTempo.style.color = "purple";

                alert("Ticket: " + precio);


              }
              else if(numero ==1){
                mostrarTempo.innerText= "TIEMPO AGOTADO!";
                mostrarTempo.style.color = "red";
                fetch('/desapartar1', {method:'POST'});
              }
              else if(variable1=='ocupado'){
                mostrarTempo.innerText= "TOMARON TU LUGAR! HABLA CON LA SEGURIDAD";
                mostrarTempo.style.color = "red";
                numero = -1;
              }
              else{         
                mostrarTempo.innerHTML = numero;
              }
            }
          }, 1000);  
    }


    function apartar2(){
      
        variable2 = parametros.get('Variable2');
        confirmacion = parametros.get('Confirmacion');
        console.log('Confirmacion:', confirmacion);
        // Hacer algo con las variables
        console.log('Variable2:', variable2);

        fetch('/apartar2',{method:'POST'});

          let mostrarTempo = document.getElementById('temporeg');
          let numero = 60;
          let lanzamiento = setInterval (() => {
            numero--;
            if(numero <= 0){
              clearInterval(lanzamiento);
            } 
            else{
              if (confirmacion == 'ok'){
                numero = -1;
                mostrarTempo.innerText= "INGRESO DETECTADO!";
                mostrarTempo.style.color = "purple";
              }
              else if(numero ==1){
                mostrarTempo.innerText= "TIEMPO AGOTADO!";
                mostrarTempo.style.color = "red";
                fetch('/desapartar2', {method:'POST'});
              }
              else if(variable2=='ocupado'){
                mostrarTempo.innerText= "TOMARON TU LUGAR! HABLA CON LA SEGURIDAD";
                mostrarTempo.style.color = "red";
                numero = -1;
              }
              else{         
                mostrarTempo.innerHTML = numero;
              }
            }
          }, 1000);  
    }


    function apartar3(){
      
        variable3 = parametros.get('Variable3');
        confirmacion = parametros.get('Confirmacion');
        console.log('Confirmacion:', confirmacion);
        // Hacer algo con las variables
        console.log('Variable3:', variable3);

        fetch('/apartar3',{method:'POST'});

          let mostrarTempo = document.getElementById('temporeg');
          let numero = 60;
          let lanzamiento = setInterval (() => {
            numero--;
            if(numero <= 0){
              clearInterval(lanzamiento);
            } 
            else{
              if (confirmacion == 'ok'){
                numero = -1;
                mostrarTempo.innerText= "INGRESO DETECTADO!";
                mostrarTempo.style.color = "purple";
              }
              else if(numero ==1){
                mostrarTempo.innerText= "TIEMPO AGOTADO!";
                mostrarTempo.style.color = "red";
                fetch('/desapartar3', {method:'POST'});
              }
              else if(variable3=='ocupado'){
                mostrarTempo.innerText= "TOMARON TU LUGAR! HABLA CON LA SEGURIDAD";
                mostrarTempo.style.color = "red";
                numero = -1;
              }
              else{         
                mostrarTempo.innerHTML = numero;
              }
            }
          }, 1000);  
    }


    function apartar4(){
      
        variable4 = parametros.get('Variable4');
        confirmacion = parametros.get('Confirmacion');
        console.log('Confirmacion:', confirmacion);
        // Hacer algo con las variables
        console.log('Variable2:', variable2);

        fetch('/apartar4',{method:'POST'});

          let mostrarTempo = document.getElementById('temporeg');
          let numero = 60;
          let lanzamiento = setInterval (() => {
            numero--;
            if(numero <= 0){
              clearInterval(lanzamiento);
            } 
            else{
              if (confirmacion == 'ok'){
                numero = -1;
                mostrarTempo.innerText= "INGRESO DETECTADO!";
                mostrarTempo.style.color = "purple";
              }
              else if(numero ==1){
                mostrarTempo.innerText= "TIEMPO AGOTADO!";
                mostrarTempo.style.color = "red";
                fetch('/desapartar4', {method:'POST'});
              }
              else if(variable4=='ocupado'){
                mostrarTempo.innerText= "TOMARON TU LUGAR! HABLA CON LA SEGURIDAD";
                mostrarTempo.style.color = "red";
                numero = -1;
              }
              else{         
                mostrarTempo.innerHTML = numero;
              }
            }
          }, 1000);  
    }


    function apartar5(){
      
        variable5 = parametros.get('Variable5');
        confirmacion = parametros.get('Confirmacion');
        console.log('Confirmacion:', confirmacion);
        // Hacer algo con las variables
        console.log('Variable5:', variable5);

        fetch('/apartar5',{method:'POST'});

          let mostrarTempo = document.getElementById('temporeg');
          let numero = 60;
          let lanzamiento = setInterval (() => {
            numero--;
            if(numero <= 0){
              clearInterval(lanzamiento);
            } 
            else{
              if (confirmacion == 'ok'){
                numero = -1;
                mostrarTempo.innerText= "INGRESO DETECTADO!";
                mostrarTempo.style.color = "purple";
              }
              else if(numero ==1){
                mostrarTempo.innerText= "TIEMPO AGOTADO!";
                mostrarTempo.style.color = "red";
                fetch('/desapartar5', {method:'POST'});
              }
              else if(variable5=='ocupado'){
                mostrarTempo.innerText= "TOMARON TU LUGAR! HABLA CON LA SEGURIDAD";
                mostrarTempo.style.color = "red";
                numero = -1;
              }
              else{         
                mostrarTempo.innerHTML = numero;
              }
            }
          }, 1000);  
    }


    function apartar6(){
      
        variable6 = parametros.get('Variable2');
        confirmacion = parametros.get('Confirmacion');
        console.log('Confirmacion:', confirmacion);
        // Hacer algo con las variables
        console.log('Variable6:', variable2);

        fetch('/apartar6',{method:'POST'});

          let mostrarTempo = document.getElementById('temporeg');
          let numero = 60;
          let lanzamiento = setInterval (() => {
            numero--;
            if(numero <= 0){
              clearInterval(lanzamiento);
            } 
            else{
              if (confirmacion == 'ok'){
                numero = -1;
                mostrarTempo.innerText= "INGRESO DETECTADO!";
                mostrarTempo.style.color = "purple";
              }
              else if(numero ==1){
                mostrarTempo.innerText= "TIEMPO AGOTADO!";
                mostrarTempo.style.color = "red";
                fetch('/desapartar6', {method:'POST'});
              }
              else if(variable6=='ocupado'){
                mostrarTempo.innerText= "TOMARON TU LUGAR! HABLA CON LA SEGURIDAD";
                mostrarTempo.style.color = "red";
                numero = -1;
              }
              else{         
                mostrarTempo.innerHTML = numero;
              }
            }
          }, 1000);  
    }


    function apartar7(){
      
        variable7 = parametros.get('Variable7');
        confirmacion = parametros.get('Confirmacion');
        console.log('Confirmacion:', confirmacion);
        // Hacer algo con las variables
        console.log('Variable7:', variable7);

        fetch('/apartar7',{method:'POST'});

          let mostrarTempo = document.getElementById('temporeg');
          let numero = 60;
          let lanzamiento = setInterval (() => {
            numero--;
            if(numero <= 0){
              clearInterval(lanzamiento);
            } 
            else{
              if (confirmacion == 'ok'){
                numero = -1;
                mostrarTempo.innerText= "INGRESO DETECTADO!";
                mostrarTempo.style.color = "purple";
              }
              else if(numero ==1){
                mostrarTempo.innerText= "TIEMPO AGOTADO!";
                mostrarTempo.style.color = "red";
                fetch('/desapartar7', {method:'POST'});
              }
              else if(variable7=='ocupado'){
                mostrarTempo.innerText= "TOMARON TU LUGAR! HABLA CON LA SEGURIDAD";
                mostrarTempo.style.color = "red";
                numero = -1;
              }
              else{         
                mostrarTempo.innerHTML = numero;
              }
            }
          }, 1000);  
    }


    function apartar8(){
      
        variable8 = parametros.get('Variable8');
        confirmacion = parametros.get('Confirmacion');
        console.log('Confirmacion:', confirmacion);
        // Hacer algo con las variables
        console.log('Variable8:', variable8);

        fetch('/apartar8',{method:'POST'});

          let mostrarTempo = document.getElementById('temporeg');
          let numero = 60;
          let lanzamiento = setInterval (() => {
            numero--;
            if(numero <= 0){
              clearInterval(lanzamiento);
            } 
            else{
              if (confirmacion == 'ok'){
                numero = -1;
                mostrarTempo.innerText= "INGRESO DETECTADO!";
                mostrarTempo.style.color = "purple";
              }
              else if(numero ==1){
                mostrarTempo.innerText= "TIEMPO AGOTADO!";
                mostrarTempo.style.color = "red";
                fetch('/desapartar8', {method:'POST'});
              }
              else if(variable8=='ocupado'){
                mostrarTempo.innerText= "TOMARON TU LUGAR! HABLA CON LA SEGURIDAD";
                mostrarTempo.style.color = "red";
                numero = -1;
              }
              else{         
                mostrarTempo.innerHTML = numero;
              }
            }
          }, 1000);  
    }


    function apartar9(){
      
        variable9 = parametros.get('Variable9');
        confirmacion = parametros.get('Confirmacion');
        console.log('Confirmacion:', confirmacion);
        // Hacer algo con las variables
        console.log('Variable9:', variable9);

        fetch('/apartar9',{method:'POST'});

          let mostrarTempo = document.getElementById('temporeg');
          let numero = 60;
          let lanzamiento = setInterval (() => {
            numero--;
            if(numero <= 0){
              clearInterval(lanzamiento);
            } 
            else{
              if (confirmacion == 'ok'){
                numero = -1;
                mostrarTempo.innerText= "INGRESO DETECTADO!";
                mostrarTempo.style.color = "purple";
              }
              else if(numero ==1){
                mostrarTempo.innerText= "TIEMPO AGOTADO!";
                mostrarTempo.style.color = "red";
                fetch('/desapartar9', {method:'POST'});
              }
              else if(variable9=='ocupado'){
                mostrarTempo.innerText= "TOMARON TU LUGAR! HABLA CON LA SEGURIDAD";
                mostrarTempo.style.color = "red";
                numero = -1;
              }
              else{         
                mostrarTempo.innerHTML = numero;
              }
            }
          }, 1000);  
    }


    function apartar10(){
      
        variable10 = parametros.get('Variable10');
        confirmacion = parametros.get('Confirmacion');
        console.log('Confirmacion:', confirmacion);
        // Hacer algo con las variables
        console.log('Variable2:', variable2);

        fetch('/apartar10',{method:'POST'});

          let mostrarTempo = document.getElementById('temporeg');
          let numero = 60;
          let lanzamiento = setInterval (() => {
            numero--;
            if(numero <= 0){
              clearInterval(lanzamiento);
            } 
            else{
              if (confirmacion == 'ok'){
                numero = -1;
                mostrarTempo.innerText= "INGRESO DETECTADO!";
                mostrarTempo.style.color = "purple";
              }
              else if(numero ==1){
                mostrarTempo.innerText= "TIEMPO AGOTADO!";
                mostrarTempo.style.color = "red";
                fetch('/desapartar10', {method:'POST'});
              }
              else if(variable10=='ocupado'){
                mostrarTempo.innerText= "TOMARON TU LUGAR! HABLA CON LA SEGURIDAD";
                mostrarTempo.style.color = "red";
                numero = -1;
              }
              else{         
                mostrarTempo.innerHTML = numero;
              }
            }
          }, 1000);  
    }


    function apartar11(){
      
        variable11 = parametros.get('Variable11');
        confirmacion = parametros.get('Confirmacion');
        console.log('Confirmacion:', confirmacion);
        // Hacer algo con las variables
        console.log('Variable11:', variable11);

        fetch('/apartar2',{method:'POST'});

          let mostrarTempo = document.getElementById('temporeg');
          let numero = 60;
          let lanzamiento = setInterval (() => {
            numero--;
            if(numero <= 0){
              clearInterval(lanzamiento);
            } 
            else{
              if (confirmacion == 'ok'){
                numero = -1;
                mostrarTempo.innerText= "INGRESO DETECTADO!";
                mostrarTempo.style.color = "purple";
              }
              else if(numero ==1){
                mostrarTempo.innerText= "TIEMPO AGOTADO!";
                mostrarTempo.style.color = "red";
                fetch('/desapartar11', {method:'POST'});
              }
              else if(variable11=='ocupado'){
                mostrarTempo.innerText= "TOMARON TU LUGAR! HABLA CON LA SEGURIDAD";
                mostrarTempo.style.color = "red";
                numero = -1;
              }
              else{         
                mostrarTempo.innerHTML = numero;
              }
            }
          }, 1000);  
    }


    function apartar12(){
      
        variable12 = parametros.get('Variable12');
        confirmacion = parametros.get('Confirmacion');
        console.log('Confirmacion:', confirmacion);
        // Hacer algo con las variables
        console.log('Variable12:', variable12);

        fetch('/apartar12',{method:'POST'});

          let mostrarTempo = document.getElementById('temporeg');
          let numero = 60;
          let lanzamiento = setInterval (() => {
            numero--;
            if(numero <= 0){
              clearInterval(lanzamiento);
            } 
            else{
              if (confirmacion == 'ok'){
                numero = -1;
                mostrarTempo.innerText= "INGRESO DETECTADO!";
                mostrarTempo.style.color = "purple";
              }
              else if(numero ==1){
                mostrarTempo.innerText= "TIEMPO AGOTADO!";
                mostrarTempo.style.color = "red";
                fetch('/desapartar12', {method:'POST'});
              }
              else if(variable12=='ocupado'){
                mostrarTempo.innerText= "TOMARON TU LUGAR! HABLA CON LA SEGURIDAD";
                mostrarTempo.style.color = "red";
                numero = -1;
              }
              else{         
                mostrarTempo.innerHTML = numero;
              }
            }
          }, 1000);  
    }

    function actualizar(){
      fetch('http://192.168.55.203/enviar_datos/')
      .then(response => response.text())
      .then(data => {
        // Analizar los datos recibidos
        parametros = new URLSearchParams(data);
        variable1 = parametros.get('Variable1');
        variable2 = parametros.get('Variable2');
        variable3 = parametros.get('Variable3');
        variable4 = parametros.get('Variable4');
        variable5 = parametros.get('Variable5');
        variable6 = parametros.get('Variable6');
        variable7 = parametros.get('Variable7');
        variable8 = parametros.get('Variable8');
        variable9 = parametros.get('Variable9');
        variable10 = parametros.get('Variable10');
        variable11 = parametros.get('Variable11');
        variable12 = parametros.get('Variable12');
        confirmacion = parametros.get('Confirmacion');
        confirmacionc = parametros.get('Confirmacionc');


        // Hacer algo con las variables
        console.log('Variable1:', variable1);
        console.log('Variable2:', variable2);
        console.log('Variable3:', variable3);
        console.log('Variable4:', variable4);
        console.log('Variable5:', variable5);
        console.log('Variable6:', variable6);
        console.log('Variable7:', variable7);
        console.log('Variable8:', variable8);
        console.log('Variable9:', variable9);
        console.log('Variable10:', variable10);
        console.log('Variable11:', variable11);
        console.log('Variable12:', variable12);
        console.log('Confirmacion:', confirmacion);
        console.log('Confirmacionc:', confirmacionc);

        if (variable1 == 'libre'){
          var divestadoCajon1 = document.getElementById("estadoCajon1");
          divestadoCajon1.innerText= "CAJON 1";
          divestadoCajon1.style.color = "green";
          var miBoton1 = document.getElementById('apartar1');
          miBoton1.style.display = 'block';
        }
        else if (variable1 == 'ocupado'){
          var divestadoCajon1 = document.getElementById("estadoCajon1");
          divestadoCajon1.innerText= "CAJON 1";
          divestadoCajon1.style.color = "red";
          var miBoton1 = document.getElementById('apartar1');
          miBoton1.style.display = 'none';
        }
        else if (variable1 == 'apartado'){
          var divestadoCajon1 = document.getElementById("estadoCajon1");
          divestadoCajon1.innerText= "CAJON 1";
          divestadoCajon1.style.color = "yellow";
          var miBoton1 = document.getElementById('apartar1');
          miBoton1.style.display = 'none';
        }

        if (variable2 == 'libre'){
          var divestadoCajon2 = document.getElementById("estadoCajon2");
          divestadoCajon2.innerText= "CAJON 2";
          divestadoCajon2.style.color = "green";
          var miBoton2 = document.getElementById('apartar2');
          miBoton2.style.display = 'block';
        }
        else if (variable2 == 'ocupado'){
          var divestadoCajon2 = document.getElementById("estadoCajon2");
          divestadoCajon2.innerText= "CAJON 2";
          divestadoCajon2.style.color = "red";
          var miBoton2 = document.getElementById('apartar2');
          miBoton2.style.display = 'none';
        }
        else if (variable2 == 'apartado'){
          var divestadoCajon2 = document.getElementById("estadoCajon2");
          divestadoCajon2.innerText= "CAJON 2";
          divestadoCajon2.style.color = "yellow";
          var miBoton2 = document.getElementById('apartar2');
          miBoton2.style.display = 'none';
        }

        if (variable3 == 'libre'){
          var divestadoCajon3 = document.getElementById("estadoCajon3");
          divestadoCajon3.innerText= "CAJON 3";
          divestadoCajon3.style.color = "green";
          var miBoton3 = document.getElementById('apartar3');
          miBoton3.style.display = 'block';
        }
        else if (variable3 == 'ocupado'){
          var divestadoCajon3 = document.getElementById("estadoCajon3");
          divestadoCajon3.innerText= "CAJON 3";
          divestadoCajon3.style.color = "red";
          var miBoton3 = document.getElementById('apartar3');
          miBoton3.style.display = 'none';
        }
        else if (variable3 == 'apartado'){
          var divestadoCajon3 = document.getElementById("estadoCajon3");
          divestadoCajon3.innerText= "CAJON 3";
          divestadoCajon3.style.color = "yellow";
          var miBoton3 = document.getElementById('apartar3');
          miBoton3.style.display = 'none';
        }

        if (variable4 == 'libre'){
          var divestadoCajon4 = document.getElementById("estadoCajon4");
          divestadoCajon4.innerText= "CAJON 4";
          divestadoCajon4.style.color = "green";
          var miBoton4 = document.getElementById('apartar4');
          miBoton4.style.display = 'block';
        }
        else if (variable4 == 'ocupado'){
          var divestadoCajon4 = document.getElementById("estadoCajon4");
          divestadoCajon4.innerText= "CAJON 4";
          divestadoCajon4.style.color = "red";
          var miBoton4 = document.getElementById('apartar4');
          miBoton4.style.display = 'none';
        }
        else if (variable4 == 'apartado'){
          var divestadoCajon4 = document.getElementById("estadoCajon4");
          divestadoCajon4.innerText= "CAJON 4";
          divestadoCajon4.style.color = "yellow";
          var miBoton4 = document.getElementById('apartar4');
          miBoton4.style.display = 'none';
        }

        if (variable5 == 'libre'){
          var divestadoCajon5 = document.getElementById("estadoCajon5");
          divestadoCajon5.innerText= "CAJON 5";
          divestadoCajon5.style.color = "green";
          var miBoton5 = document.getElementById('apartar5');
          miBoton5.style.display = 'block';
        }
        else if (variable5 == 'ocupado'){
          var divestadoCajon5 = document.getElementById("estadoCajon5");
          divestadoCajon5.innerText= "CAJON 5";
          divestadoCajon5.style.color = "red";
          var miBoton5 = document.getElementById('apartar5');
          miBoton5.style.display = 'none';
        }
        else if (variable5 == 'apartado'){
          var divestadoCajon5 = document.getElementById("estadoCajon5");
          divestadoCajon5.innerText= "CAJON 5";
          divestadoCajon5.style.color = "yellow";
          var miBoton5 = document.getElementById('apartar5');
          miBoton5.style.display = 'none';
        }

        if (variable6 == 'libre'){
          var divestadoCajon6 = document.getElementById("estadoCajon6");
          divestadoCajon6.innerText= "CAJON 6";
          divestadoCajon6.style.color = "green";
          var miBoton6 = document.getElementById('apartar6');
          miBoton6.style.display = 'block';
        }
        else if (variable6 == 'ocupado'){
          var divestadoCajon6 = document.getElementById("estadoCajon6");
          divestadoCajon6.innerText= "CAJON 6";
          divestadoCajon6.style.color = "red";
          var miBoton6 = document.getElementById('apartar6');
          miBoton6.style.display = 'none';
        }
        else if (variable6 == 'apartado'){
          var divestadoCajon6 = document.getElementById("estadoCajon6");
          divestadoCajon6.innerText= "CAJON 6";
          divestadoCajon6.style.color = "yellow";
          var miBoton6 = document.getElementById('apartar6');
          miBoton6.style.display = 'none';
        }

        if (variable7 == 'libre'){
          var divestadoCajon7 = document.getElementById("estadoCajon7");
          divestadoCajon7.innerText= "CAJON 7";
          divestadoCajon7.style.color = "green";
          var miBoton7 = document.getElementById('apartar7');
          miBoton7.style.display = 'block';
        }
        else if (variable7 == 'ocupado'){
          var divestadoCajon7 = document.getElementById("estadoCajon7");
          divestadoCajon7.innerText= "CAJON 7";
          divestadoCajon7.style.color = "red";
          var miBoton7 = document.getElementById('apartar7');
          miBoton7.style.display = 'none';
        }
        else if (variable7 == 'apartado'){
          var divestadoCajon7 = document.getElementById("estadoCajon7");
          divestadoCajon7.innerText= "CAJON 7";
          divestadoCajon7.style.color = "yellow";
          var miBoton7 = document.getElementById('apartar7');
          miBoton7.style.display = 'none';
        }

        if (variable8 == 'libre'){
          var divestadoCajon8 = document.getElementById("estadoCajon8");
          divestadoCajon8.innerText= "CAJON 8";
          divestadoCajon8.style.color = "green";
          var miBoton8 = document.getElementById('apartar8');
          miBoton8.style.display = 'block';
        }
        else if (variable8 == 'ocupado'){
          var divestadoCajon8 = document.getElementById("estadoCajon8");
          divestadoCajon8.innerText= "CAJON 8";
          divestadoCajon8.style.color = "red";
          var miBoton8 = document.getElementById('apartar8');
          miBoton8.style.display = 'none';
        }
        else if (variable8 == 'apartado'){
          var divestadoCajon8 = document.getElementById("estadoCajon8");
          divestadoCajon8.innerText= "CAJON 8";
          divestadoCajon8.style.color = "yellow";
          var miBoton8 = document.getElementById('apartar8');
          miBoton8.style.display = 'none';
        }

        if (variable9 == 'libre'){
          var divestadoCajon9 = document.getElementById("estadoCajon9");
          divestadoCajon9.innerText= "CAJON 9";
          divestadoCajon9.style.color = "green";
          var miBoton9 = document.getElementById('apartar9');
          miBoton9.style.display = 'block';
        }
        else if (variable9 == 'ocupado'){
          var divestadoCajon9 = document.getElementById("estadoCajon9");
          divestadoCajon9.innerText= "CAJON 9";
          divestadoCajon9.style.color = "red";
          var miBoton9 = document.getElementById('apartar9');
          miBoton9.style.display = 'none';
        }
        else if (variable9 == 'apartado'){
          var divestadoCajon9 = document.getElementById("estadoCajon9");
          divestadoCajon9.innerText= "CAJON 9";
          divestadoCajon9.style.color = "yellow";
          var miBoton9 = document.getElementById('apartar9');
          miBoton9.style.display = 'none';
        }

        if (variable10 == 'libre'){
          var divestadoCajon10 = document.getElementById("estadoCajon10");
          divestadoCajon10.innerText= "CAJON 10";
          divestadoCajon10.style.color = "green";
          var miBoton10 = document.getElementById('apartar10');
          miBoton10.style.display = 'block';
        }
        else if (variable10 == 'ocupado'){
          var divestadoCajon10 = document.getElementById("estadoCajon10");
          divestadoCajon10.innerText= "CAJON 10";
          divestadoCajon10.style.color = "red";
          var miBoton10 = document.getElementById('apartar10');
          miBoton10.style.display = 'none';
        }
        else if (variable10 == 'apartado'){
          var divestadoCajon10 = document.getElementById("estadoCajon10");
          divestadoCajon10.innerText= "CAJON 10";
          divestadoCajon10.style.color = "yellow";
          var miBoton10 = document.getElementById('apartar10');
          miBoton10.style.display = 'none';
        }

        if (variable11 == 'libre'){
          var divestadoCajon11 = document.getElementById("estadoCajon11");
          divestadoCajon11.innerText= "CAJON 11";
          divestadoCajon11.style.color = "green";
          var miBoton11 = document.getElementById('apartar11');
          miBoton11.style.display = 'block';
        }
        else if (variable11 == 'ocupado'){
          var divestadoCajon11 = document.getElementById("estadoCajon11");
          divestadoCajon11.innerText= "CAJON 11";
          divestadoCajon11.style.color = "red";
          var miBoton11 = document.getElementById('apartar11');
          miBoton11.style.display = 'none';
        }
        else if (variable11 == 'apartado'){
          var divestadoCajon11 = document.getElementById("estadoCajon11");
          divestadoCajon11.innerText= "CAJON 11";
          divestadoCajon11.style.color = "yellow";
          var miBoton11 = document.getElementById('apartar11');
          miBoton11.style.display = 'none';
        }

        if (variable12 == 'libre'){
          var divestadoCajon12 = document.getElementById("estadoCajon12");
          divestadoCajon12.innerText= "CAJON 12";
          divestadoCajon12.style.color = "green";
          var miBoton12 = document.getElementById('apartar12');
          miBoton12.style.display = 'block';
        }
        else if (variable12 == 'ocupado'){
          var divestadoCajon12 = document.getElementById("estadoCajon12");
          divestadoCajon12.innerText= "CAJON 12";
          divestadoCajon12.style.color = "red";
          var miBoton12 = document.getElementById('apartar12');
          miBoton12.style.display = 'none';
        }
        else if (variable12 == 'apartado'){
          var divestadoCajon12 = document.getElementById("estadoCajon12");
          divestadoCajon12.innerText= "CAJON 12";
          divestadoCajon12.style.color = "yellow";
          var miBoton12 = document.getElementById('apartar12');
          miBoton12.style.display = 'none';
        }


      })
      .catch(error => {
        console.error('Error al obtener datos:', error);
      });
    }

  </script>

  <a target="_blank" href= "https://www.instagram.com/ox_browny/">Contacto </a>

</body>
</html>
)rawliteral";