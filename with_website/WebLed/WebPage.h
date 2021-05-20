#ifndef _WEBPAGE_h
#define _WEBPAGE_h

const String WebPage = R"DATA(
<!DOCTYPE html>
<html>
    <head>
        <title>Emilys Led Wolke</title>
        <link href='https://fonts.googleapis.com/css?family=Roboto:300' rel='stylesheet' type='text/css'>
        <link href='main.css' rel='stylesheet' type='text/css'>
        <link rel="apple-touch-icon" sizes="180x180" href="/apple-touch-icon-180x180.png">
        <link rel="icon" type="image/png" sizes="144x144"  href="/favicon-144x144.png">
        <link rel="icon" type="image/png" sizes="48x48" href="/favicon.ico">
        <link rel="manifest" href="/manifest.json">
        <meta name="theme-color" content="#00878f">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <script>
        var connection = new WebSocket('ws://' + "emily" + ':81/', ['arduino']);
connection.onopen = function () {
  connection.send('Connect ' + new Date());
};
connection.onerror = function (error) {
  console.log('WebSocket Error ', error);
};
connection.onmessage = function (e) {
  console.log('Server: ', e.data);
};
connection.onclose = function () {
  console.log('WebSocket connection closed');
};

function sendMsgMode (btn) {
  var Msg = "mode:" + btn.id
  console.log(Msg);
  connection.send(Msg);
}

function sendMsgSlider(sld){
  var Msg = sld.id + ":" + document.getElementById(sld.id).value
  console.log(Msg);
  connection.send(Msg);
}

        </script>
    </head>

    <body style="background-color:rgb(41, 41, 41);">
        <center>
            <header style="color:rgb(240, 240, 240)">Emilys Led Wolke</header>
            <div>
                <p style="margin:8px 0px;color:rgb(255, 255, 255)">
                    <button id="off" class="button" style="background-color:rgb(192, 192, 192);width: 30%;" onclick="sendMsgMode(this);">Off</button> 
                </p>
                <table>
                    <tr>
                        <td style="width:14.4px;text-align: right; color:rgb(206, 206, 206)">Hue: </td>
                        <td><input class="enabled" id="H" type="range" min="0" max="255" step="1" oninput="sendMsgSlider(this);" value="0"></td>
                    </tr>
                    <tr>
                        <td style="width:14.4px; text-align: right; color:rgb(240, 240, 240)">Sat: </td>
                        <td><input class="enabled" id="S" type="range" min="0" max="255" step="1" oninput="sendMsgSlider(this);" value="255"></td>
                    </tr>
                    <tr>
                        <td style="width:14.4px; text-align: right; color:rgb(240, 240, 240)">Val: </td>
                        <td><input class="enabled" id="V" type="range" min="0" max="255" step="1" oninput="sendMsgSlider(this);" value="127"></td>
                    </tr>
                    <tr>
                        <td style="width:14.4px; text-align: right; color:rgb(240, 240, 240)">Speed: </td>
                        <td><input class="enabled" id="D" type="range" min="0" max="200" step="1" oninput="sendMsgSlider(this);" value="127"></td>
                    </tr>
                    <tr>
                        <td style="width:14.4px; text-align: right; color:rgb(240, 240, 240)">Amount: </td>
                        <td><input class="enabled" id="A" type="range" min="0" max="10" step="1" oninput="sendMsgSlider(this);" value="127"></td>
                    </tr>
                    <tr>
                        <td style="width:14.4px; text-align: right; color:rgb(240, 240, 240)">Width: </td>
                        <td><input class="enabled" id="W" type="range" min="2" max="20" step="1" oninput="sendMsgSlider(this);" value="127"></td>
                    </tr>
                </table>
                <p style="margin:8px 0px;color:rgb(255, 255, 255)">
                    <button id="static" class="button" style="background-color:rgb(192, 192, 192);width: 35%;" onclick="sendMsgMode(this);">Static</button> 
                </p>
                <p style="margin:8px 0px;color:rgb(255, 255, 255)">
                    <button id="strobe" class="button" style="background-color:rgb(192, 192, 192);width: 35%;" onclick="sendMsgMode(this);">Strobe</button> 
                </p>
                <p style="margin:8px 0px;color:rgb(255, 255, 255)">
                    <button id="random_strobe" class="button" style="background-color:rgb(192, 192, 192);width: 35%;" onclick="sendMsgMode(this);">Random Strobe</button> 
                </p>
                <p style="margin:8px 0px;color:rgb(255, 255, 255)">
                    <button id="rainbow_cycle" class="button" style="background-color:rgb(192, 192, 192);width: 35%;" onclick="sendMsgMode(this);">Rainbow Cycle</button> 
                </p>
                <p style="margin:8px 0px;color:rgb(255, 255, 255)">
                    <button id="walking_light" class="button" style="background-color:rgb(192, 192, 192);width: 35%;" onclick="sendMsgMode(this);">Walking Light</button> 
                </p>
                <p style="margin:8px 0px;color:rgb(255, 255, 255)">
                    <button id="rainbow_fading" class="button" style="background-color:rgb(192, 192, 192);width: 35%;" onclick="sendMsgMode(this);">Rainbow Fading</button> 
                </p>
                <p style="margin:8px 0px;color:rgb(255, 255, 255)">
                    <button id="random_colors" class="button" style="background-color:rgb(192, 192, 192);width: 35%;" onclick="sendMsgMode(this);">Random Colors</button> 
                </p>
            </div>
        </center>
    </body>
</html>
)DATA";


#endif
