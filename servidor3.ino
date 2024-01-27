#include <ESPAsyncWebServer.h>
#include <WiFi.h>
#include <SPI.h>
#include <MFRC522.h>
#include "codigohtml.h"

#include "Arduino.h"
#include "PCF8574.h"
//DESCARGAR LA LIBRERÍA AHORA: https://github.com/ELECTROALL/LIBRERIAS/blob/master/PCF8574_library-master.rar

PCF8574 pcf8574A(0x20);// dirección de la configuración del dispositivo
PCF8574 pcf8574B(0x21);// dirección de la configuración del dispositivo
PCF8574 pcf8574C(0x22);// dirección de la configuración del dispositivo

int confirmar = 25;
int confirmacionb=0;

int confirmarc = 0;
int confirmacionbc=0;

#include <LiquidCrystal.h>
// Se incializan los pines (RS, E, D4, D5,D6, D7)
LiquidCrystal lcd(19, 23, 18, 17, 16, 15);

#include <ESP32Servo.h> // librería para servomotor
int pinServo_entrada=32;
int pinServo_salida=33;
Servo servo_entrada;
Servo servo_salida;

#define SS_PIN 15  // Pin del ESP32 conectado al pin SDA del módulo RFID
#define RST_PIN 5 // Pin del ESP32 conectado al pin RST del módulo RFID
/* RST/Reset   RST          15 (TDO)      
 * SPI SS      SDA(SS)      5 
 * SPI MOSI    MOSI         19 
 * SPI MISO    MISO         23 
 * SPI SCK     SCK          18 */

MFRC522 mfrc522(SS_PIN, RST_PIN);

const char *ssid = "Carlos galaxy s10";
const char *password = "ijus4866";

AsyncWebServer server(80);

unsigned long tiempopluma1=0;
unsigned long tiempopluma2=0;
unsigned long tiempo_estado=0;
unsigned long tiempo_estado2=0;

int valorpluma1=1;
int valorpluma2=1;
int sensorpluma1 = 36;
int sensorpluma2 = 13;


int sensor1=34 ;
int sensor2=35 ;
int sensor3=26 ;
int sensor4=27;
int sensor5=12 ;
int sensor6=4 ;


int valorSensor1;
int valorSensor2;
int valorSensor3;
int valorSensor4;
int valorSensor5;
int valorSensor6;
int valorSensor7;
int valorSensor8;
int valorSensor9;
int valorSensor10;
int valorSensor11;
int valorSensor12;

String variable1 = "";
String variable2 = "";
String variable3 = "";
String variable4 = "";
String variable5 = "";
String variable6 = "";
String variable7 = "";
String variable8 = "";
String variable9 = "";
String variable10 = "";
String variable11 = "";
String variable12 = "";
String confirmacion = "";
String confirmacionc = "";


void setup() {

  pcf8574A.begin();// inicializamos la comunicación entre el uc y el CI PCF8574

  pcf8574A.pinMode(P0, OUTPUT);  //se declará el pin PO del CI PCF8574 como SALIDA
  pcf8574A.pinMode(P1, OUTPUT);  //se declará el pin P1 del CI PCF8574 como SALIDA
  pcf8574A.pinMode(P2, OUTPUT);  //se declará el pin P2 del CI PCF8574 como SALIDA
  pcf8574A.pinMode(P3, OUTPUT);  //se declará el pin P3 del CI PCF8574 como SALIDA
  pcf8574A.pinMode(P4, OUTPUT);  //se declará el pin P4 del CI PCF8574 como SALIDA
  pcf8574A.pinMode(P5, OUTPUT);  //se declará el pin P5 del CI PCF8574 como SALIDA
  pcf8574A.pinMode(P6, OUTPUT);  //se declará el pin P6 del CI PCF8574 como SALIDA
  pcf8574A.pinMode(P7, OUTPUT);  //se declará el pin P7 del CI PCF8574 como SALIDA

  pcf8574B.begin();// inicializamos la comunicación entre el uc y el CI PCF8574

  pcf8574B.pinMode(P0, OUTPUT);  //se declará el pin PO del CI PCF8574 como SALIDA
  pcf8574B.pinMode(P1, OUTPUT);  //se declará el pin P1 del CI PCF8574 como SALIDA
  pcf8574B.pinMode(P2, OUTPUT);  //se declará el pin P2 del CI PCF8574 como SALIDA
  pcf8574B.pinMode(P3, OUTPUT);  //se declará el pin P3 del CI PCF8574 como SALIDA
  pcf8574B.pinMode(P4, OUTPUT);  //se declará el pin P4 del CI PCF8574 como SALIDA
  pcf8574B.pinMode(P5, OUTPUT);  //se declará el pin P5 del CI PCF8574 como SALIDA
  pcf8574B.pinMode(P6, OUTPUT);  //se declará el pin P6 del CI PCF8574 como SALIDA
  pcf8574B.pinMode(P7, OUTPUT);  //se declará el pin P7 del CI PCF8574 como SALIDA

  pcf8574C.begin();// inicializamos la comunicación entre el uc y el CI PCF8574

  pcf8574C.pinMode(P0, OUTPUT);  //se declará el pin PO del CI PCF8574 como SALIDA
  pcf8574C.pinMode(P1, OUTPUT);  //se declará el pin P1 del CI PCF8574 como SALIDA
  pcf8574C.pinMode(P2, OUTPUT);  //se declará el pin P2 del CI PCF8574 como SALIDA
  pcf8574C.pinMode(P3, OUTPUT);  //se declará el pin P3 del CI PCF8574 como SALIDA
  pcf8574C.pinMode(P4, OUTPUT);  //se declará el pin P4 del CI PCF8574 como SALIDA
  pcf8574C.pinMode(P5, OUTPUT);  //se declará el pin P5 del CI PCF8574 como SALIDA
  pcf8574C.pinMode(P6, OUTPUT);  //se declará el pin P6 del CI PCF8574 como SALIDA
  pcf8574C.pinMode(P7, OUTPUT);  //se declará el pin P7 del CI PCF8574 como SALIDA

  pinMode(confirmar, INPUT);
  pinMode(confirmarc, INPUT);

  pinMode(sensorpluma1, INPUT);
  pinMode(sensorpluma1, INPUT);

  servo_entrada.attach(pinServo_entrada);
  servo_salida.attach(pinServo_salida);
  servo_entrada.write(0);
  servo_salida.write(0);


  SPI.begin(); 
  mfrc522.PCD_Init(); // Inicializar el lector RFID
  Serial.println("Lector RFID listo para escanear...");

  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  pinMode(sensor5, INPUT);
  pinMode(sensor6, INPUT);
  
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("OCUPADOS: ");
  lcd.setCursor(0, 1);
  lcd.print("LIBRES: ");

  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a WiFi...");
  }

  // Rutas del servidor
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    request->send_P(200, "text/html", index_html);
  });

  server.on("/enviar_datos", HTTP_GET, [](AsyncWebServerRequest *request) {

    if (variable1!="apartado"){
      if (valorSensor1 == 1) {
        variable1 = "ocupado";
      } else {
        variable1 = "libre";
      }
    } 
    else {
      if (valorSensor1 ==1) {
        variable1 = "ocupado";
      } 
    }

    if (variable2!="apartado"){
      if (valorSensor2 ==1) {
        variable2 = "ocupado";
      } else {
        variable2 = "libre";
      }
    } 
    else {
      if (valorSensor2 ==1) {
        variable2 = "ocupado";
      } 
    }

    if (variable3!="apartado"){
      if (valorSensor3 ==1) {
        variable3 = "ocupado";
      } else {
        variable3 = "libre";
      }
    } 
    else {
      if (valorSensor3 ==1) {
        variable3 = "ocupado";
      } 
    }

    if (variable4!="apartado"){
      if (valorSensor4 ==1) {
        variable4 = "ocupado";
      } else {
        variable4 = "libre";
      }
    } 
    else {
      if (valorSensor4 ==1) {
        variable4 = "ocupado";
      } 
    }

    if (variable5!="apartado"){
      if (valorSensor5 ==1) {
        variable5 = "ocupado";
      } else {
        variable5 = "libre";
      }
    } 
    else {
      if (valorSensor5 ==1) {
        variable5 = "ocupado";
      } 
    }

    if (variable6!="apartado"){
      if (valorSensor6 ==1) {
        variable6 = "ocupado";
      } else {
        variable6 = "libre";
      }
    } 
    else {
      if (valorSensor6 ==1) {
        variable6 = "ocupado";
      } 
    }

    if (variable7!="apartado"){
      if (valorSensor7 ==1) {
        variable7 = "ocupado";
      } else {
        variable7 = "libre";
      }
    } 
    else {
      if (valorSensor7 ==1) {
        variable7 = "ocupado";
      } 
    }

    if (variable8!="apartado"){
      if (valorSensor8 ==1) {
        variable8 = "ocupado";
      } else {
        variable8 = "libre";
      }
    } 
    else {
      if (valorSensor8 ==1) {
        variable8 = "ocupado";
      } 
    }

    if (variable9!="apartado"){
      if (valorSensor9 ==1) {
        variable9 = "ocupado";
      } else {
        variable9 = "libre";
      }
    } 
    else {
      if (valorSensor9 ==1) {
        variable9 = "ocupado";
      } 
    }

    if (variable10 !="apartado"){
      if (valorSensor10 ==1) {
        variable10 = "ocupado";
      } else {
        variable10 = "libre";
      }
    } 
    else {
      if (valorSensor10 ==1) {
        variable10 = "ocupado";
      } 
    }

    if (variable11!="apartado"){
      if (valorSensor11 ==1) {
        variable11 = "ocupado";
      } else {
        variable11 = "libre";
      }
    } 
    else {
      if (valorSensor11 ==1) {
        variable11 = "ocupado";
      } 
    }

    if (variable12!="apartado"){
      if (valorSensor12 ==1) {
        variable12 = "ocupado";
      } else {
        variable12 = "libre";
      }
    } 
    else {
      if (valorSensor12 ==1) {
        variable12 = "ocupado";
      } 
    }

    String respuesta = "Variable1=" + variable1 
    + "&Variable2=" + variable2
    + "&Variable3=" + variable3
    + "&Variable4=" + variable4
    + "&Variable5=" + variable5
    + "&Variable6=" + variable6
    + "&Variable7=" + variable7
    + "&Variable8=" + variable8
    + "&Variable9=" + variable9
    + "&Variable10=" + variable10
    + "&Variable11=" + variable11
    + "&Variable12=" + variable12
    + "&Confirmacion=" + confirmacion;
    + "&Confirmacion=" + confirmacionc;

    request->send(200, "text/plain", respuesta);
  });

  server.on("/apartar1", HTTP_POST, [](AsyncWebServerRequest *request) {
    variable1 = "apartado";
    request->send(200, "text/plain", "correcto");
    Serial.println(variable1);
  });

  server.on("/desapartar1", HTTP_POST, [](AsyncWebServerRequest *request) {
    variable1 = "libre";
    request->send(200, "text/plain", "correcto");
    Serial.println(variable1);
  });

  server.on("/apartar2", HTTP_POST, [](AsyncWebServerRequest *request) {
    variable2 = "apartado";
    request->send(200, "text/plain", "correcto");
    Serial.println(variable1);
  });

  server.on("/desapartar2", HTTP_POST, [](AsyncWebServerRequest *request) {
    variable2 = "libre";
    request->send(200, "text/plain", "correctoo");
    Serial.println(variable1);
  });

  server.on("/apartar3", HTTP_POST, [](AsyncWebServerRequest *request) {
    variable3 = "apartado";
    request->send(200, "text/plain", "correcto");
    Serial.println(variable1);
  });

  server.on("/desapartar3", HTTP_POST, [](AsyncWebServerRequest *request) {
    variable3 = "libre";
    request->send(200, "text/plain", "correctoo");
    Serial.println(variable1);
  });

  server.on("/apartar4", HTTP_POST, [](AsyncWebServerRequest *request) {
    variable4 = "apartado";
    request->send(200, "text/plain", "correcto");
    Serial.println(variable1);
  });

  server.on("/desapartar4", HTTP_POST, [](AsyncWebServerRequest *request) {
    variable4 = "libre";
    request->send(200, "text/plain", "correctoo");
    Serial.println(variable1);
  });

  server.on("/apartar5", HTTP_POST, [](AsyncWebServerRequest *request) {
    variable5 = "apartado";
    request->send(200, "text/plain", "correcto");
    Serial.println(variable1);
  });

  server.on("/desapartar5", HTTP_POST, [](AsyncWebServerRequest *request) {
    variable5 = "libre";
    request->send(200, "text/plain", "correctoo");
    Serial.println(variable1);
  });

  server.on("/apartar6", HTTP_POST, [](AsyncWebServerRequest *request) {
    variable6 = "apartado";
    request->send(200, "text/plain", "correcto");
    Serial.println(variable1);
  });

  server.on("/desapartar6", HTTP_POST, [](AsyncWebServerRequest *request) {
    variable6 = "libre";
    request->send(200, "text/plain", "correctoo");
    Serial.println(variable1);
  });

  server.on("/apartar7", HTTP_POST, [](AsyncWebServerRequest *request) {
    variable7 = "apartado";
    request->send(200, "text/plain", "correcto");
    Serial.println(variable1);
  });

  server.on("/desapartar7", HTTP_POST, [](AsyncWebServerRequest *request) {
    variable7 = "libre";
    request->send(200, "text/plain", "correctoo");
    Serial.println(variable1);
  });

  server.on("/apartar8", HTTP_POST, [](AsyncWebServerRequest *request) {
    variable8 = "apartado";
    request->send(200, "text/plain", "correcto");
    Serial.println(variable1);
  });

  server.on("/desapartar8", HTTP_POST, [](AsyncWebServerRequest *request) {
    variable8 = "libre";
    request->send(200, "text/plain", "correctoo");
    Serial.println(variable1);
  });

  server.on("/apartar9", HTTP_POST, [](AsyncWebServerRequest *request) {
    variable9 = "apartado";
    request->send(200, "text/plain", "correcto");
    Serial.println(variable1);
  });

  server.on("/desapartar9", HTTP_POST, [](AsyncWebServerRequest *request) {
    variable9 = "libre";
    request->send(200, "text/plain", "correctoo");
    Serial.println(variable1);
  });

  server.on("/apartar10", HTTP_POST, [](AsyncWebServerRequest *request) {
    variable10 = "apartado";
    request->send(200, "text/plain", "correcto");
    Serial.println(variable1);
  });

  server.on("/desapartar10", HTTP_POST, [](AsyncWebServerRequest *request) {
    variable10 = "libre";
    request->send(200, "text/plain", "correctoo");
    Serial.println(variable1);
  });

  server.on("/apartar11", HTTP_POST, [](AsyncWebServerRequest *request) {
    variable11 = "apartado";
    request->send(200, "text/plain", "correcto");
    Serial.println(variable1);
  });

  server.on("/desapartar11", HTTP_POST, [](AsyncWebServerRequest *request) {
    variable11 = "libre";
    request->send(200, "text/plain", "correctoo");
    Serial.println(variable1);
  });

  server.on("/apartar12", HTTP_POST, [](AsyncWebServerRequest *request) {
    variable12 = "apartado";
    request->send(200, "text/plain", "correcto");
    Serial.println(variable1);
  });

  server.on("/desapartar12", HTTP_POST, [](AsyncWebServerRequest *request) {
    variable12 = "libre";
    request->send(200, "text/plain", "correctoo");
    Serial.println(variable1);
  });

  

  server.begin();
}

void loop() {
  // Tu código principal aquí
  valorSensor1 = digitalRead(sensor1); // cambiar los touch por entradas digitales d elos sensores
  valorSensor2 = digitalRead(sensor2);
  valorSensor3 = digitalRead(sensor3);
  valorSensor4 = digitalRead(sensor4);
  valorSensor5 = digitalRead(sensor5);
  valorSensor6 = digitalRead(sensor6);
  valorSensor7 = digitalRead(sensor5);
  valorSensor8 = digitalRead(sensor5);
  valorSensor9 = digitalRead(sensor5);
  valorSensor10 = digitalRead(sensor5);
  valorSensor11 = digitalRead(sensor5);
  valorSensor12 = digitalRead(sensor5);

  confirmacionb = digitalRead(confirmar);
  confirmacionbc = digitalRead(confirmarc);

  if (confirmacionb == 1){ // Aqui poner los sensores de pluma y los servos
    confirmacion ="ok";

  } else{
    confirmacion ="no";
  }



  // con el rfid vamos a mandar la confirmacion = ok

  numeroslcd();

  prenderleds();

  moverservos();

}

void numeroslcd(){
  int x1=0, x2=0, x3=0, x4=0, x5=0, x6=0, x7=0, x8=0, x9=0, x10=0, x11=0, x12=0, ocupadoslcd=0, libreslcd=0;

  if ((variable1 == "ocupado") || (variable1 == "apartado")){x1=1;} else {x1=0;}
  if ((variable2 == "ocupado") || (variable2 == "apartado")){x2=1;} else {x2=0;}
  if ((variable3 == "ocupado") || (variable3 == "apartado")){x3=1;} else {x3=0;}
  if ((variable4 == "ocupado") || (variable4 == "apartado")){x4=1;} else {x4=0;}
  if ((variable5 == "ocupado") || (variable5 == "apartado")){x5=1;} else {x5=0;}
  if ((variable6 == "ocupado") || (variable6 == "apartado")){x6=1;} else {x6=0;}
  if ((variable7 == "ocupado") || (variable7 == "apartado")){x7=1;} else {x7=0;}
  if ((variable8 == "ocupado") || (variable8 == "apartado")){x8=1;} else {x8=0;}
  if ((variable9 == "ocupado") || (variable9 == "apartado")){x9=1;} else {x9=0;}
  if ((variable10 == "ocupado") || (variable10 == "apartado")){x10=1;} else {x10=0;}
  if ((variable11 == "ocupado") || (variable11 == "apartado")){x12=1;} else {x11=0;}
  if ((variable12 == "ocupado") || (variable12 == "apartado")){x12=1;} else {x12=0;}

  ocupadoslcd = x1+x2+x3+x4+x5+x6+x7+x8+x9+x10+x11+x12;
  libreslcd = 12 - ocupadoslcd;

  if (ocupadoslcd <10){
    lcd.setCursor(14, 0);
    lcd.print("0");
    lcd.setCursor(15, 0);
    lcd.print(ocupadoslcd);
  }
  else{
    lcd.setCursor(14, 0);
    lcd.print(ocupadoslcd);
  }

  if (libreslcd<10){
    lcd.setCursor(14, 1);
    lcd.print("0");
    lcd.setCursor(15, 1);
    lcd.print(libreslcd);
  }
  else{
    lcd.setCursor(14, 1);
    lcd.print(libreslcd);
  }

}

void prenderleds(){
  if (variable1 == "ocupado"){
    pcf8574A.digitalWrite(P0, HIGH);//rojo
    pcf8574A.digitalWrite(P1, LOW);//verde
    pcf8574A.digitalWrite(P2, LOW);//amarillo
  } else if(variable1 == "libre"){
    pcf8574A.digitalWrite(P0, LOW);//rojo
    pcf8574A.digitalWrite(P1, HIGH);//verde
    pcf8574A.digitalWrite(P2, LOW);//amarillo
  } else{
    pcf8574A.digitalWrite(P0, LOW);//rojo
    pcf8574A.digitalWrite(P1, LOW);//verde
    pcf8574A.digitalWrite(P2, HIGH);//amarillo
  }


  if (variable2 == "ocupado"){
    pcf8574A.digitalWrite(P3, HIGH);//rojo
    pcf8574A.digitalWrite(P4, LOW);//verde
    pcf8574A.digitalWrite(P5, LOW);//amarillo
  } else if(variable2 == "libre"){
    pcf8574A.digitalWrite(P3, LOW);//rojo
    pcf8574A.digitalWrite(P4, HIGH);//verde
    pcf8574A.digitalWrite(P5, LOW);//amarillo
  } else{
    pcf8574A.digitalWrite(P3, LOW);//rojo
    pcf8574A.digitalWrite(P4, LOW);//verde
    pcf8574A.digitalWrite(P5, HIGH);//amarillo
  }


  if (variable3 == "ocupado"){
    pcf8574B.digitalWrite(P0, HIGH);//rojo
    pcf8574B.digitalWrite(P1, LOW);//verde
    pcf8574B.digitalWrite(P2, LOW);//amarillo
  } else if(variable3 == "libre"){
    pcf8574B.digitalWrite(P0, LOW);//rojo
    pcf8574B.digitalWrite(P1, HIGH);//verde
    pcf8574B.digitalWrite(P2, LOW);//amarillo
  } else{
    pcf8574B.digitalWrite(P0, LOW);//rojo
    pcf8574B.digitalWrite(P1, LOW);//verde
    pcf8574B.digitalWrite(P2, HIGH);//amarillo
  }


  if (variable4 == "ocupado"){
    pcf8574B.digitalWrite(P3, HIGH);//rojo
    pcf8574B.digitalWrite(P4, LOW);//verde
    pcf8574B.digitalWrite(P5, LOW);//amarillo
  } else if(variable4 == "libre"){
    pcf8574B.digitalWrite(P3, LOW);//rojo
    pcf8574B.digitalWrite(P4, HIGH);//verde
    pcf8574B.digitalWrite(P5, LOW);//amarillo
  } else{
    pcf8574B.digitalWrite(P3, LOW);//rojo
    pcf8574B.digitalWrite(P4, LOW);//verde
    pcf8574B.digitalWrite(P5, HIGH);//amarillo
  }


  if (variable5 == "ocupado"){
    pcf8574C.digitalWrite(P0, HIGH);//rojo
    pcf8574C.digitalWrite(P1, LOW);//verde
    pcf8574C.digitalWrite(P2, LOW);//amarillo
  } else if(variable5 == "libre"){
    pcf8574C.digitalWrite(P0, LOW);//rojo
    pcf8574C.digitalWrite(P1, HIGH);//verde
    pcf8574C.digitalWrite(P2, LOW);//amarillo
  } else{
    pcf8574C.digitalWrite(P0, LOW);//rojo
    pcf8574C.digitalWrite(P1, LOW);//verde
    pcf8574C.digitalWrite(P2, HIGH);//amarillo
  }


  if (variable6 == "ocupado"){
    pcf8574C.digitalWrite(P3, HIGH);//rojo
    pcf8574C.digitalWrite(P4, LOW);//verde
    pcf8574C.digitalWrite(P5, LOW);//amarillo
  } else if(variable6 == "libre"){
    pcf8574C.digitalWrite(P3, LOW);//rojo
    pcf8574C.digitalWrite(P4, HIGH);//verde
    pcf8574C.digitalWrite(P5, LOW);//amarillo
  } else{
    pcf8574C.digitalWrite(P3, LOW);//rojo
    pcf8574C.digitalWrite(P4, LOW);//verde
    pcf8574C.digitalWrite(P5, HIGH);//amarillo
  }




}

void moverservos(){

  valorpluma1=digitalRead(sensorpluma1);
  valorpluma2=digitalRead(sensorpluma2);

  if (valorpluma1 == 0) {
    tiempopluma1= millis();  // Almacena el tiempo de inicio cuando el botón se suelta
    servo_entrada.write(90);
    
  } else {
    // Si el botón no está presionado y ha pasado al menos 3 segundos desde que se soltó
    if (millis() - tiempopluma1 >= 2000) {
      servo_entrada.write(0);  // Apaga el LED
    
    }
  }
 
 if (valorpluma2 == 0) {
    tiempopluma2= millis();  // Almacena el tiempo de inicio cuando el botón se suelta
    servo_salida.write(90);
    
    
  } else {
    // Si el botón no está presionado y ha pasado al menos 3 segundos desde que se soltó
    if (millis() - tiempopluma2 >= 2000) {
      servo_salida.write(0);  // Apaga el LED
    
    }
  }
 

}

void srfid(){
  confirmacion ="no";
    // Buscar tarjetas RFID
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
    // Mostrar el UID de la tarjeta
    Serial.print("Tarjeta detectada. UID: ");
    printCardUID();
    confirmacion ="ok";
  }
}

void printCardUID() {
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  }
  Serial.println();
}




