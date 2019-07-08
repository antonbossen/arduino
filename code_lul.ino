int reset = 0;
int b0 = 0;
int b1 = 0;
int b2 = 0;
int code[] = { 0, 1, 2, 0, 1};
bool red = false;
bool green = false;
bool yellow = false;



void reset_response() {
  red = true;
  for (int i = 0; i <= 4; i++){
    digitalWrite(6, red);
    delay(500);
    red = !red;
    }
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i = 2; i <= 8; i++) {
    if (i < 6) {
      pinMode(i, INPUT);
      } else {
        pinMode(i, OUTPUT);
        }
    }
  
  digitalWrite(6, red);
  digitalWrite(7, green);
  digitalWrite(8, yellow);
}

void loop() {
  yellow = false;
  // put your main code here, to run repeatedly

  int input[5];
  for (int i = 0; i <= 3; i++) {
    input[i] = digitalRead(i+2);
    if (input[i]) {
      yellow = true;
      }
  }
     digitalWrite(8, yellow);

  if (input[0]) {
    reset_response();
    }
    delay(100);

}
