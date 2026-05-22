// =====================================================
// DECLARACIÓN DE PINES DE LOS LEDS
// =====================================================


int LED1 = 23;
int LED2 = 22;
int LED3 = 21;
int LED4 = 19;
int SW1 = 18;
int SW2 = 5;
int SW3 = 17;
int SW4 = 16;
int potenciometroPin = 4;

// Variable para almacenar lectura analógica
int sensorValue = 0;

// Variable convertida de 0 a 100
int potenciometro = 0;

// Variable para almacenar valor decimal del DIP SWITCH
int dipsw = 0;

// Variable auxiliar para controlar condiciones
int estado = 0;

void setup() {

  Serial.begin(115200);

  // Configurar LEDs como salidas
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  // Configurar DIP SWITCH como entradas
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  pinMode(SW3, INPUT);
  pinMode(SW4, INPUT);
}

void loop() {

  // Leer valor analógico
  sensorValue = analogRead(potenciometroPin);

  // Convertir rango 0-4095 a 0-100
  potenciometro = map(sensorValue, 0, 4095, 0, 100);

  // Mostrar valor del potenciómetro
  Serial.print("Potenciometro: ");
  Serial.println(potenciometro);

  // Convertir cada switch a decimal
  int valorSW1 = digitalRead(SW1) * 1;
  int valorSW2 = digitalRead(SW2) * 2;
  int valorSW3 = digitalRead(SW3) * 4;
  int valorSW4 = digitalRead(SW4) * 8;

  // Suma total de los bits
  dipsw = valorSW1 + valorSW2 + valorSW3 + valorSW4;

  // Mostrar valor decimal del DIP SWITCH
  Serial.print("DIP SWITCH: ");
  Serial.println(dipsw);
  estado = (potenciometro <= 30) * 2 + (dipsw > 7);


  switch (estado) {
    case 0:

 
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);

      break;

    case 1:

      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);

      break;



    case 2:

      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);
      delay(500);


      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      delay(500);

      break;

    case 3:

      digitalWrite(LED1, HIGH);
      delay(300);

     
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      delay(300);

    
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, HIGH);
      delay(300);

      digitalWrite(LED3, LOW); 
      digitalWrite(LED4, HIGH);
      delay(300);

      digitalWrite(LED4, LOW);

      break;
  }
}