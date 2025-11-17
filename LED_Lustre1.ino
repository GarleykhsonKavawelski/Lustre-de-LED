// ==== Pinos ====
int led1 = 2;     // Sempre ligado
int led2 = 3;     // Oscila tempo
int led3 = 4;     // Acende com botão
int botao = 5;    // Botão

// ==== Variáveis para o LED oscilante ====
unsigned long tempoAnterior = 0;
unsigned long intervalo = 1000; // Começa em 1 segundo
bool estadoLed2 = LOW;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(botao, INPUT_PULLUP);  // botão com resistor interno

  // LED 1 já começa ligado
  digitalWrite(led1, HIGH);
}

void loop() {

  // ===== LED 2: Pisca variando de 1s até 5s =====
  unsigned long tempoAtual = millis();

  if (tempoAtual - tempoAnterior >= intervalo) {
    tempoAnterior = tempoAtual;

    // Alterna o LED
    estadoLed2 = !estadoLed2;
    digitalWrite(led2, estadoLed2);

    // Aumenta o tempo do pisca de 1s → 5s
    intervalo += 1000;

    // Reinicia o ciclo
    if (intervalo > 5000) {
      intervalo = 1000;
    }
  }

  // ===== LED 3: Controlado pelo botão =====
  if (digitalRead(botao) == LOW) { // Botão pressionado
    digitalWrite(led3, HIGH);
  } else {
    digitalWrite(led3, LOW);
  }
}