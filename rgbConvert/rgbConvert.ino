void setup() {
Serial.begin(9600);
String s="16711680";
long l=s.toInt();
long r = l >> 16;
long g = l >> 8 & 0xFF;
long b = l & 0xFF;
Serial.println();
Serial.println(r);
Serial.println(g);
Serial.println(b);

// put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
