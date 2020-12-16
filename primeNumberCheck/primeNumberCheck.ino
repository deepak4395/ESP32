// (Inline Comment) Arduino Integrated Development Enviornment

/*
   Group Comment
   This code checks n number for whether they are prime or not.
   n=6
*/
const int n = 6; // Amount of number to check;
int checkNumber1[n] = {789, 833, 577, 920, 29, 1111111}; // Numbers to check. Must be equal to amount of number.
bool result1[n] = {true, true, true, true, true, true} ;
int r = -1;
int i = 2;
void setup() {
  Serial.begin(9600); //baud rate bits per seconds.
  for (int x = 0; x < n; x = x + 1) {
    i = 2;
    r = -1;
    while (i < checkNumber1[x]) {
      r = checkNumber1[x] % i;
      if (r == 0) {
        // Number is not prime
        result1[x] = false;
        break;
      }
      else {
        i = i + 1;
      }
    }

  }
  for (int i = 0; i < n; i = i + 1) {
    Serial.print("For number ");
    Serial.print(checkNumber1[i]);
    Serial.print(" result is ");
    Serial.println(result1[i]);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
