int reset = 0;
int b0 = 0;
int b1 = 0;
int b2 = 0;
int code[] = { 0, 1, 2, 0, 1};
bool red = false;
bool green = false;



void reset_response() {
  for (int i = 0; i <= 4; i++){
    red = !red;
    digitalWrite(6, red);
    delay(500);
    }
  }


void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(6, red);
  digitalWrite(7, green);
}

void loop() {
  // put your main code here, to run repeatedly
  reset = digitalRead(2);
  b0 = digitalRead(3);
  b1 = digitalRead(4);
  b2 = digitalRead(5);

  if (reset) {
    reset_response();
    }

}
