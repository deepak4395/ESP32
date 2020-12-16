int old_AB = 0, encoder = 0, steps = 0, reFlag = false, encoderAPin = 21 , encoderBPin = 22 , encoderButtonPin = 23 , encoderSteps = 2,
    lastReadEncoder0Pos, enc_states[16] = {0, -1, 1, 0, 1, 0, 0, -1, -1, 0, 0, 1, 0, 1, -1, 0};
portMUX_TYPE mux = portMUX_INITIALIZER_UNLOCKED;
volatile int16_t encoder0Pos = 0;
void IRAM_ATTR readEncoder_ISR();
void setup() {
  Serial.begin(9600);
  pinMode(encoderAPin, INPUT);
  pinMode(encoderBPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(encoderAPin), readEncoder_ISR, CHANGE);
  attachInterrupt(digitalPinToInterrupt(encoderBPin), readEncoder_ISR, CHANGE);
}

void loop() {

}

void IRAM_ATTR readEncoder_ISR()
{
  portENTER_CRITICAL_ISR(&(mux));
  old_AB <<= 2;                   //remember previous state
  int8_t ENC_PORT = ((digitalRead(encoderBPin)) ? (1 << 1) : 0) | ((digitalRead(encoderAPin)) ? (1 << 0) : 0);
  old_AB |= ( ENC_PORT & 0x03 );  //add current state
  encoder0Pos += ( enc_states[( old_AB & 0x0f )]);
  int16_t _encoder0Pos = encoder0Pos / encoderSteps;
  int16_t encoder0Diff = _encoder0Pos - lastReadEncoder0Pos;
  lastReadEncoder0Pos = _encoder0Pos;
  if (encoder0Diff != 0) {
    encoder += encoder0Diff;
    reFlag = true;
  }
  if (encoder > 40)encoder = 40;
  if (encoder < 0)encoder = 0;
  Serial.println(encoder);
  steps = map(encoder, 0, 40, 0, 97);
  portEXIT_CRITICAL_ISR(&(mux));
}
