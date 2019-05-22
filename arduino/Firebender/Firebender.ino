#define BOOSH_PIN_1    8       // solenoid 1 via MOSFET Q1, J3-14, J3 numbers start with 1 in upper right
#define BOOSH_PIN_2    9       // solenoid 2 via MOSFET Q2, J3-13
#define BOOSH_PIN_3    10      // solenoid 3 via MOSFET Q3, J3-16
#define BOOSH_PIN_4    11      // solenoid 4 via MOSFET Q4, J4-3, J4 numbers start with 1 in bottom left
#define BOOSH_PIN_5    12      // solenoid 5 via MOSFET Q5, J4-4
#define BOOSH_PIN_6    13      // solenoid 6 via MOSFET Q6, J4-5

int fireDelay = 150; // in milliseconds

void setup() {
  Serial.begin(9600);
  pinMode(BOOSH_PIN_1, OUTPUT);
  pinMode(BOOSH_PIN_2, OUTPUT);
  pinMode(BOOSH_PIN_3, OUTPUT);
  pinMode(BOOSH_PIN_4, OUTPUT);
  pinMode(BOOSH_PIN_5, OUTPUT);  
  pinMode(BOOSH_PIN_6, OUTPUT);
 // Serial.print("Lets Begin");
  }

  void loop() {
    int cannon;
    if (Serial.available()) {
    Serial.print("Cannon:");
    cannon = Serial.read();
    Serial.println(cannon);
    }

    if(cannon == 1){
      digitalWrite(BOOSH_PIN_1, HIGH);
      digitalWrite(BOOSH_PIN_2, LOW);
      digitalWrite(BOOSH_PIN_3, LOW);
    }
      
    if(cannon == 2){
      digitalWrite(BOOSH_PIN_1, LOW);
      digitalWrite(BOOSH_PIN_2, HIGH);
      digitalWrite(BOOSH_PIN_3, LOW);
    }
    if(cannon == 3){
      digitalWrite(BOOSH_PIN_1, LOW);
      digitalWrite(BOOSH_PIN_2, LOW);
      digitalWrite(BOOSH_PIN_3, HIGH);;
    }
    if(cannon == 4){
      digitalWrite(BOOSH_PIN_4, HIGH);
      digitalWrite(BOOSH_PIN_5, LOW);
      digitalWrite(BOOSH_PIN_6, LOW);
    }
    if(cannon == 5){
      digitalWrite(BOOSH_PIN_4, LOW);
      digitalWrite(BOOSH_PIN_5, HIGH);
      digitalWrite(BOOSH_PIN_6, LOW);
    }
    if(cannon == 6){
      digitalWrite(BOOSH_PIN_4, LOW);
      digitalWrite(BOOSH_PIN_5, LOW);
      digitalWrite(BOOSH_PIN_6, HIGH);
    }
    if(cannon == 7){                 //LEFT FLAMES OFF
      digitalWrite(BOOSH_PIN_1, LOW);
      digitalWrite(BOOSH_PIN_2, LOW);
      digitalWrite(BOOSH_PIN_3, LOW);

    }
    if(cannon == 8){                 //RIGHT FLAMES OFF
      digitalWrite(BOOSH_PIN_4, LOW);
      digitalWrite(BOOSH_PIN_5, LOW);
      digitalWrite(BOOSH_PIN_6, LOW);
    }
    if(cannon == 9){                  //LEFT HAND GESTURE TRIGGER
      digitalWrite(BOOSH_PIN_1, HIGH);
      delay(fireDelay);
      digitalWrite(BOOSH_PIN_2, HIGH);
      delay(fireDelay);
      digitalWrite(BOOSH_PIN_3, HIGH);
      delay(fireDelay);
      digitalWrite(BOOSH_PIN_1, LOW);
      delay(fireDelay);
      digitalWrite(BOOSH_PIN_2, LOW);
      delay(fireDelay);
      digitalWrite(BOOSH_PIN_3, LOW);
    }
     if(cannon == 10){                //RIGHT HAND GESTURE TRIGGER
      digitalWrite(BOOSH_PIN_4, HIGH);
      delay(fireDelay);
      digitalWrite(BOOSH_PIN_5, HIGH);
      delay(fireDelay);
      digitalWrite(BOOSH_PIN_6, HIGH);
      delay(fireDelay);
      digitalWrite(BOOSH_PIN_4, LOW);
      delay(fireDelay);
      digitalWrite(BOOSH_PIN_5, LOW);
      delay(fireDelay);
      digitalWrite(BOOSH_PIN_6, LOW);
    }
  }
