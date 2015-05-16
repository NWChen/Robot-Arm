const int k_pBase = A0;
const int k_pShoulder = A1;
const int k_pElbow = A2;

const int k_vBase = 11;
const int k_vShoulder = 10;
const int k_vElbow = 9;

int pBase, pShoulder, pElbow,
    vBase, vShoulder, vElbow;

void setup() {
  Serial.begin(9600);
}

void loop() {
  pBase = analogRead(k_pBase);
  pShoulder = analogRead(k_pShoulder);
  pElbow = analogRead(k_pElbow);

  Serial.print("base=");
  Serial.print(pBase);
  Serial.print(", shoulder=");
  Serial.print(pShoulder);
  Serial.print(", elbow=");
  Serial.println(pElbow);

  delay(100);
}

