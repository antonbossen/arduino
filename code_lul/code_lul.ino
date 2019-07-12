int code[5] = {2, 1, 2, 3, 1};
bool red = true;
bool green = false;
bool yellow = false;
int trycode[5];


void print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
    Serial.print(arr[i]);
    
  }
  Serial.println();
}

void button_mesh (int state[], int button, int size) {
  for (int i = 0; i < size; i++) {
    if (!state[i]) {
      if (button != trycode[i -1]) {
        trycode[i] = button;
      }
      break;
    }
  }
}

void reset_response() {
  red = true;
  for (int i = 0; i < 5; i++) {
    trycode[i] = 0;
    }
  for (int i = 0; i <= 4; i++){
    digitalWrite(6, red);
    delay(500);
    red = !red;
    }
  green = false;
  digitalWrite(7, green);
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
  int in = 0;
  int input[4];
  
  for (int i = 0; i <= 3; i++) {
    input[i] = digitalRead(i+2);
    if (input[i]) {
      yellow = true;
      in = i;
      }
     
  }
  digitalWrite(8, yellow);
   

  if (input[0]) {
    reset_response();
    }
  if (in) {
    button_mesh(trycode, in, 5);
  }
  print(trycode, 5);
  Serial.println(in);
  bool same = true;
  for (int i = 0; i < 5; i++) {
    if (trycode[i] != code[i]) {
      same = false;
      break;
      }
    }
  if (same) {
    green = true;
    digitalWrite(7, green);
    red = false;
    digitalWrite(6, red);
  }

  


  
}
