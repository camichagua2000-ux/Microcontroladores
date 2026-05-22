// =====================================================
// PINES DE LOS LEDS (SALIDAS)
// =====================================================
int LED1 = 23;
int LED2 = 22;
int LED3 = 21;
int LED4 = 19;
// =====================================================
// PINES DE ENTRADA (DIP SWITCH)
// =====================================================
int SW1 = 18;
int SW2 = 5;
// =====================================================
// POTENCIÓMETRO 
// =====================================================
int potenciometroPin = 4;
// =====================================================

// Variable para almacenar lectura analógica (0–4095)
int sensorValue = 0;

// Variable convertida a escala de 0–100
int potenciometro = 0;

// Variable que guarda el estado del DIP Switch (0 a 3)
int estadoSW = 0;

// Variable que controla velocidad (delay)
int velocidad = 0;


void setup() {

  Serial.begin(115200);


  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
}

void loop() {

 // -------------------- LECTURA DEL POTENCIÓMETRO --------------------

  // Lee el valor analógico del potenciómetro
  sensorValue = analogRead(potenciometroPin);

  // Convierte el valor de 0-4095 a 0-100
  potenciometro = map(sensorValue, 0, 4095, 0, 100);
   // Convierte el potenciómetro a tiempo de delay (inverso)
  // 0 = lento (1000 ms), 50 = rápido (50 ms)
  velocidad = map(potenciometro, 0, 100, 1000, 50);

  // Muestra el valor en el monitor serial
  Serial.print("Potenciometro: ");
  Serial.println(potenciometro);
delay(500);

  Serial.print("DIP SWITCH: ");
  Serial.println(estadoSW);

  int b0 = digitalRead(SW1) * 1;
  int b1 = digitalRead(SW2) * 2;
  estadoSW = b0 + b1;


  // =====================================================
  // SWITCH CASE PRINCIPAL
  // =====================================================
  switch (estadoSW) {
    // =====================================================
    // CASE 0 → 00
    // TODOS LOS LEDS APAGADOS
    // =====================================================
    case 0:

      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);

      break;


    // =====================================================
    // CASE 1 → 01
    // TODOS LOS LEDS PARPADEAN JUNTOS
    // CONTROLADOS POR POTENCIÓMETRO
    // =====================================================
    case 1:

      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);

      delay(velocidad);

      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);

      delay(velocidad);

      break;


    // =====================================================
    // CASE 2 → 10
    // SECUENCIA FIJA SIN CONTROL DEL POTENCIÓMETRO
    // SOLO SE MUESTRAN DIP SWITCH EN SERIAL
    // =====================================================
    case 2:

      digitalWrite(LED1, HIGH);
      delay(100);
      digitalWrite(LED1, LOW);

      digitalWrite(LED2, HIGH);
      delay(100);
      digitalWrite(LED2, LOW);

      digitalWrite(LED3, HIGH);
      delay(100);
      digitalWrite(LED3, LOW);

      digitalWrite(LED4, HIGH);
      delay(100);
      digitalWrite(LED4, LOW);

      break;


    // =====================================================
    // CASE 3 → 11
    // SECUENCIA CONTROLADA POR POTENCIÓMETRO
    // =====================================================
    case 3:

      // Mostrar estado de DIP Switch
     Serial.print("SW1:");
     Serial.print(digitalRead(SW1));
     Serial.print("  SW2:");
     Serial.println(digitalRead(SW2));
     Serial.println(digitalRead(potenciometro));

      digitalWrite(LED1, HIGH);
      delay(velocidad);
      digitalWrite(LED1, LOW);

      digitalWrite(LED2, HIGH);
      delay(velocidad);
      digitalWrite(LED2, LOW);

      digitalWrite(LED3, HIGH);
      delay(velocidad);
      digitalWrite(LED3, LOW);

      digitalWrite(LED4, HIGH);
      delay(velocidad);
      digitalWrite(LED4, LOW);

      break;
  }
}