int buzzLED1 = 12;
int buzzLED2 = 6;

int greenLED = 11;
int yellowLED = 10;
int redLED = 9;

int button1 = 13;
int button2 = 4;

int buzzer = 7;
bool buttonPressed = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzLED1, OUTPUT);
  pinMode(buzzLED2, OUTPUT);

  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  pinMode(buzzer, OUTPUT);

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  
  randomSeed(analogRead(A0)); 
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(greenLED, HIGH);
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
  delay(900);
  digitalWrite(greenLED, LOW);

  digitalWrite(yellowLED, HIGH);
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
  delay(900);
  digitalWrite(yellowLED, LOW);

  digitalWrite(redLED, HIGH);
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
  delay(random(900,4901));
  digitalWrite(redLED, LOW);


  while (buttonPressed == 0) {

    digitalWrite(buzzLED1, HIGH);
    digitalWrite(buzzLED2, HIGH);
    if (digitalRead(button1) == 0) {
      buttonPressed = 1;
      digitalWrite(buzzLED2, LOW);
    } else if (digitalRead(button2) == 0) {
      buttonPressed = 1;
      digitalWrite(buzzLED1, LOW);
    }
  }
  digitalWrite(buzzer,HIGH);
  delay(500);
  digitalWrite(buzzer,LOW);
  delay(1500);
  digitalWrite(buzzLED1,LOW);
  digitalWrite(buzzLED2,LOW);
  buttonPressed=0;
}
