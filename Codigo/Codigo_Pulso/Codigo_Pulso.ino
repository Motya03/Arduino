#define BUTTON_BLUE  2
#define BUTTON_RED   3
#define BUTTON_START A2
#define BUTTON_RESET A3
#define BUZZER_PIN 7

int redLEDs[5]  = {8, 9, 10, 11, 12};
int blueLEDs[5] = {4, 5, 6, A4, A5};

volatile bool bluePressed = false;   
volatile bool redPressed  = false;   

bool gameStarted = false;
int position = 4;  
unsigned long lastAction = 0; 
const unsigned long DEBOUNCE_MS = 50;

void onBluePress() {
  
  bluePressed = true;
}

void onRedPress() {
  redPressed = true;
}

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 5; i++) {
    pinMode(redLEDs[i], OUTPUT);
    pinMode(blueLEDs[i], OUTPUT);
  }

  pinMode(BUTTON_BLUE, INPUT_PULLUP);
  pinMode(BUTTON_RED, INPUT_PULLUP);
  pinMode(BUTTON_START, INPUT_PULLUP);
  pinMode(BUTTON_RESET, INPUT_PULLUP);
  pinMode(BUZZER_PIN, OUTPUT);

  
  attachInterrupt(digitalPinToInterrupt(BUTTON_BLUE), onBluePress, FALLING);
  attachInterrupt(digitalPinToInterrupt(BUTTON_RED),  onRedPress,  FALLING);

  resetGame();
}

void loop() {
  
  if (!gameStarted) {
    if (digitalRead(BUTTON_START) == LOW) {
      tone(BUZZER_PIN, 900, 200);
      delay(250);
      gameStarted = true;
      updateStrip();
    }
    return;
  }

  unsigned long now = millis();


  if (bluePressed) {
    
    bluePressed = false;
    if (now - lastAction >= DEBOUNCE_MS) {
      lastAction = now;
      if (position < 9) {
        position++;
        updateStrip();
      } else {
        gameOver("AZUL");
      }
      
      tone(BUZZER_PIN, 1000, 30);
    }
  }

  
  if (redPressed) {
    redPressed = false;
    if (now - lastAction >= DEBOUNCE_MS) {
      lastAction = now;
      if (position > 0) {
        position--;
        updateStrip();
      } else {
        gameOver("ROJO");
      }
      tone(BUZZER_PIN, 800, 30);
    }
  }

  if (digitalRead(BUTTON_RESET) == LOW) {
    
    delay(20);
    if (digitalRead(BUTTON_RESET) == LOW) resetGame();
  }
}

void updateStrip() {
  for (int i = 0; i < 5; i++) {
    digitalWrite(redLEDs[i], LOW);
    digitalWrite(blueLEDs[i], LOW);
  }
  if (position <= 4) digitalWrite(redLEDs[position], HIGH);
  else digitalWrite(blueLEDs[position - 5], HIGH);
}

void gameOver(String winner) {
  Serial.println("Ganó: " + winner);
  tone(BUZZER_PIN, 600, 500);
  delay(500);
  resetGame();
}

void resetGame() {
  position = 4;
  gameStarted = false;
  for (int i = 0; i < 5; i++) {
    digitalWrite(redLEDs[i], LOW);
    digitalWrite(blueLEDs[i], LOW);
  }
  Serial.println("Presiona START para jugar");
}
