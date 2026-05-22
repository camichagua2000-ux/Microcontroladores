/*
  Programa: Control de LEDs con Potenciómetro y DIP Switch
  Descripción:
  Dependiendo del valor del potenciómetro y la suma
  del DIP Switch de 4 bits, se ejecutan diferentes
  secuencias de LEDs.
*/

// -------------------- DECLARACIÓN DE PINES --------------------

// LEDs
int LED1 = 23;
int LED2 = 22;
int LED3 = 21;
int LED4 = 19;

// DIP SWITCH
int SW1 = 18;
int SW2 = 5;
int SW3 = 17;
int SW4 = 16;

// Potenciómetro
int potenciometroPin = 4;

// Variables globales
int sensorValue = 0;
int potenciometro = 0;

void setup() {

  // Inicializa comunicación serial
  Serial.begin(115200);

  // Configuración de LEDs como salida
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

  // Configuración de DIP Switch como entrada
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
  pinMode(SW3, INPUT);
  pinMode(SW4, INPUT);
}

void loop() {

  // -------------------- LECTURA DEL POTENCIÓMETRO --------------------

  // Lee el valor analógico del potenciómetro
  sensorValue = analogRead(potenciometroPin);

  // Convierte el valor de 0-4095 a 0-100
  potenciometro = map(sensorValue, 0, 4095, 0, 100);

  // Muestra el valor en el monitor serial
  Serial.print("Potenciometro: ");
  Serial.println(potenciometro);
delay(1000);

  // -------------------- LECTURA DEL DIP SWITCH --------------------

  // Conversión de binario a decimal
  int valorSW1 = digitalRead(SW1) * 1;
  int valorSW2 = digitalRead(SW2) * 2;
  int valorSW3 = digitalRead(SW3) * 4;
  int valorSW4 = digitalRead(SW4) * 8;

  // Suma total del DIP Switch
  int dipsw = valorSW1 + valorSW2 + valorSW3 + valorSW4;

  // Muestra el valor del DIP Switch
  Serial.print("DIP SWITCH: ");
  Serial.println(dipsw);

  // ============================================================
  // PRIMERA CONDICIÓN
  // Potenciómetro > 30 y DIP Switch <= 7
  // Encender LED1 y LED2
  // Apagar LED3 y LED4
  // ============================================================

  if (potenciometro > 30 && dipsw <= 7) {

    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);

    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
  }

  // ============================================================
  // SEGUNDA CONDICIÓN
  // Potenciómetro > 30 y DIP Switch > 7
  // Apagar LED1 y LED2
  // Encender LED3 y LED4
  // ============================================================

  else if (potenciometro > 30 && dipsw > 7) {

    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);

    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
  }

  // ============================================================
  // TERCERA CONDICIÓN
  // Potenciómetro <= 30 y DIP Switch <= 7
  // Todos los LEDs parpadean juntos infinitamente
  // ============================================================

  else if (potenciometro <= 30 && dipsw <= 7) {

    // Encender todos los LEDs
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);

    delay(500);

    // Apagar todos los LEDs
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);

    delay(500);
  }

  // ============================================================
  // CUARTA CONDICIÓN
  // Potenciómetro <= 30 y DIP Switch > 7
  // Encendido secuencial de LEDs
  // ============================================================

  else if (potenciometro <= 30 && dipsw > 7) {

    // LED1
    digitalWrite(LED1, HIGH);
    delay(300);
    digitalWrite(LED1, LOW);

    // LED2
    digitalWrite(LED2, HIGH);
    delay(300);
    digitalWrite(LED2, LOW);

    // LED3
    digitalWrite(LED3, HIGH);
    delay(300);
    digitalWrite(LED3, LOW);

    // LED4
    digitalWrite(LED4, HIGH);
    delay(300);
    digitalWrite(LED4, LOW);
  }
}

