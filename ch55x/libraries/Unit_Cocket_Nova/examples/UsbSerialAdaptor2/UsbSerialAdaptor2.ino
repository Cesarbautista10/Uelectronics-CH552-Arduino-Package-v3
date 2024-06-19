/*
  UsbSerialAdaptor

  A simple example turns CH552 to a serial adaptor, 
  relaying data between USB serial and Serial0.

  Baudrate of Serial0 is determined by USB serial's rate.

  created 2020
  by Deqing Sun for use with CH55xduino

  This example code is in the public domain.

*/

extern __xdata uint8_t LineCoding[]; //lineCoding of CDC is located in this array
__xdata uint32_t oldBaudRate = 9600;
void blinkPatternA();

void blinkPatternB();

void blinkPatternC();
char str[50];
#define LED_BUILTIN 33

void setup() {
  Serial0_begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
  if (USBSerial_available()) {
    char serialChar = USBSerial_read();

    Serial0_write(serialChar);
    if (serialChar == 'a') {
      blinkPatternA();
    } else if (serialChar == 'b') {
      blinkPatternB();
    } else if (serialChar == 'c') {
      blinkPatternC();
    }
      
                        // wait for a second
  }
  if (Serial0_available()) {
    char serialChar = Serial0_read();
    USBSerial_write(serialChar);
  }

  __xdata uint32_t currentBaudRate = *((__xdata uint32_t *)LineCoding); //both linecoding and sdcc are little-endian

  if (oldBaudRate != currentBaudRate) {
    oldBaudRate = currentBaudRate;
    Serial0_begin(currentBaudRate);
  }

}


void blinkPatternA() {

  const char *helloCH552 = "Respondo desde el CH552";
  
  for (int i = 0; i < strlen(helloCH552); i++) {
    char serialChar = helloCH552[i];
    digitalWrite(LED_BUILTIN, HIGH);
    delay(20);
    digitalWrite(LED_BUILTIN, LOW);
    delay(20);
    
    USBSerial_write(serialChar);
  }
  
}

void blinkPatternB() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100);
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
}

void blinkPatternC() {
   const char *helloWorld = "hello world";
  
  for (int i = 0; i < strlen(helloWorld); i++) {
    char serialChar = helloWorld[i];
    digitalWrite(LED_BUILTIN, HIGH);
    delay(200);
    digitalWrite(LED_BUILTIN, LOW);
    delay(200);
    
    Serial0_write(serialChar);
  }
}
