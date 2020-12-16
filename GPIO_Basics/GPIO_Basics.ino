/*
 * This code defines pins as input or output.
 */
int i; // Varible declared globally
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // Begin serial with baud rate 9600
  // put your setup code here, to run once:
  pinMode(2, OUTPUT); // Pin defined as input
  pinMode(4, INPUT);//  Pin defined as output
}

void loop() {
  // put your main code here, to run repeatedly:
  i = digitalRead(4); // Read the digital (High or Low) value of pin
  Serial.println(i); // write the value with new line.
  if (i == 1) digitalWrite(2, HIGH);  // Write the digital value high on pin.
  else digitalWrite(2, LOW); // Write the digital value low on pin.
}
