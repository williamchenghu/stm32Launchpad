// STM32 MIDI Launchpad
// by Cheng
// based on earl's STM32F103C8T6 MIDI Controller for MIDI2LR
// https://microcontrollerelectronics.com/an-stm32f103c8t6-based-midi-controller-for-midi2lr/
 
/* 
 *            +-----------------[USB]-----------------+
  [SS2|PB12] | [31]                            [Gnd] |
 [SCK2|PB13] | [30]                  +---+     [Gnd] |
[MISO2|PB14] | [29]    +-----+       |0 0|     [3V3] |
[MOSI2|PB15] | [28]    |Reset|       |x x|   [Reset] | 
       [PA8] | [27]    +-----+       |1 1|      [ 0] | [PB11|SDA2|RX3] 
   [TX1|PA9] | [26]                  +---+      [ 1] | [PB10|SCL2|TX3]
  [RX1|PA10] | [25]                   ^ ^       [33] | [PB1]
 [USB-|PA11] | [24]            Boot1--+ |       [ 3] | [PB0|A0]
 [USB+|PA12] | [23]            Boot0----+       [ 4] | [PA7|A1|MOSI1]
      [PA15] | [20]                             [ 5] | [PA6|A2|MISO1]
       [PB3] | [19]     +---------------+       [ 6] | [PA5|A3|SCK1]
       [PB4] | [18]     | STM32F103C8T6 |       [ 7] | [PA4|A4|SS1]
       [PB5] | [17]     |   Blue Pill   |       [ 8] | [PA3|A5|RX2]
  [SCL1|PB6] | [16]     +---------------+       [ 9] | [PA2|A6|TX2]
  [SDA1|PB7] | [15]                             [10] | [PA1|A7]
       [PB8] | [32]                             [11] | [PA0|A8]
       [PB9] | [PB9]                            [12] | [PC15]
             | [5V]      +---------------+      [13] | [PC14]
             | [Gnd]     |    ST-Link    |      [14] | [PC13|LED]
             | [3V3]     |3V3 DIO CLK GND|     [Vbat]| 
             +-------------+---+---+---+-------------+
                           |   |   |   |
*/
#include <USBComposite.h>

USBMIDI midi;
#define LED PC13
#define KeyDelay 200

const char ManufacturerName[] = "Generic BluePill (STM32F103C8T6)";
const char DeviceName[]       = "STM32 MIDI Launchpad";
const char DeviceSerial[]     = "4f3cc4fe-4b74-4bfa-beb4-a1fd44b4b0e5"; // https://www.uuidgenerator.net/version4
const int  ProductId          = 0x0031;
const int  VendorId           = 0x1EAF;

const byte ROWS = 6;
const byte COLS = 6;
const int debounceTime = 20;
char hexaKeys[ROWS][COLS] = {
  {'5', 'B', 'H', 'N', 'T', 'Z'},
  {'4', 'A', 'G', 'M', 'S', 'Y'},
  {'3', '9', 'F', 'L', 'R', 'X'},
  {'2', '8', 'E', 'K', 'Q', 'W'},
  {'1', '7', 'D', 'J', 'P', 'V'},
  {'0', '6', 'C', 'I', 'O', 'U'},
};
byte colPins[COLS] = {PA5, PA4, PA3, PA2, PA1, PA0};
byte rowPins[ROWS] = {PA6, PA7, PB0, PB1, PB10, PB11};

void setup() {
  USBComposite.setManufacturerString(ManufacturerName);
  USBComposite.setProductString(DeviceName);
  USBComposite.setSerialString(DeviceSerial);
  USBComposite.setVendorId(VendorId);
  USBComposite.setProductId(ProductId);
  midi.begin();
  while (!USBComposite);
  for(int i=0; i<COLS; i++) {
    pinMode(colPins[i], OUTPUT);
    digitalWrite(colPins[i], HIGH);
    }
  for(int i=0; i<ROWS; i++) {
    pinMode(rowPins[i], INPUT_PULLUP);
    digitalWrite(rowPins[i], HIGH);
    }
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);
  char customKey = getKey();

  if (customKey) {
    switch (customKey) {
      case '0':
        midi.sendNoteOn(0, 48, 127);
        digitalWrite(LED, LOW);
        delay(KeyDelay);
        midi.sendNoteOff(0, 48, 0);
        break;
      case '1':
        midi.sendNoteOn(0, 49, 127);
        digitalWrite(LED, LOW);
        delay(KeyDelay);
        midi.sendNoteOff(0, 49, 0);
        break;
      case '2':
        midi.sendNoteOn(0, 50, 127);
        digitalWrite(LED, LOW);
        delay(KeyDelay);
        midi.sendNoteOff(0, 50, 0);
        break;
      case '3':
        midi.sendNoteOn(0, 51, 127);
        digitalWrite(LED, LOW);
        delay(KeyDelay);
        midi.sendNoteOff(0, 51, 0);
        break;
      case '4':
        midi.sendNoteOn(0, 52, 127);
        digitalWrite(LED, LOW);
        delay(KeyDelay);
        midi.sendNoteOff(0, 52, 0);
        break;
      case '5':
        midi.sendNoteOn(0, 53, 127);
        digitalWrite(LED, LOW);
        delay(KeyDelay);
        midi.sendNoteOff(0, 53, 0);
        break;
      case '6':
        midi.sendNoteOn(0, 54, 127);
        digitalWrite(LED, LOW);
        delay(KeyDelay);
        midi.sendNoteOff(0, 54, 0);
        break;
      case '7':
        midi.sendNoteOn(0, 55, 127);
        digitalWrite(LED, LOW);
        delay(KeyDelay);
        midi.sendNoteOff(0, 55, 0);
        break;
      case '8':
        midi.sendNoteOn(0, 56, 127);
        digitalWrite(LED, LOW);
        delay(KeyDelay);
        midi.sendNoteOff(0, 56, 0);
        break;
      case '9':
        midi.sendNoteOn(0, 57, 127);
        digitalWrite(LED, LOW);
        delay(KeyDelay);
        midi.sendNoteOff(0, 57, 0);
        break;
      case 'A':
        midi.sendNoteOn(0, 58, 127);
        digitalWrite(LED, LOW);
        delay(KeyDelay);
        midi.sendNoteOff(0, 58, 0);
        break;
      case 'B':
        midi.sendNoteOn(0, 59, 127);
        digitalWrite(LED, LOW);
        delay(KeyDelay);
        midi.sendNoteOff(0, 59, 0);
        break;
      case 'C':
        midi.sendNoteOn(0, 60, 127);
        digitalWrite(LED, LOW);
        delay(KeyDelay);
        midi.sendNoteOff(0, 60, 0);
        break;
      case 'D':
        midi.sendNoteOn(0, 61, 127);
        digitalWrite(LED, LOW);
        delay(KeyDelay);
        midi.sendNoteOff(0, 61, 0);
        break;
      case 'E':
        midi.sendNoteOn(0, 62, 127);
        digitalWrite(LED, LOW);
        delay(KeyDelay);
        midi.sendNoteOff(0, 62, 0);
        break;
      case 'F':
        midi.sendNoteOn(0, 63, 127);
        digitalWrite(LED, LOW);
        delay(KeyDelay);
        midi.sendNoteOff(0, 63, 0);
        break;
      case 'G':
        midi.sendNoteOn(0, 64, 127);
        digitalWrite(LED, LOW);
        delay(KeyDelay);
        midi.sendNoteOff(0, 64, 0);
        break;
      case 'H':
        midi.sendNoteOn(0, 65, 127);
        digitalWrite(LED, LOW);
        delay(KeyDelay);
        midi.sendNoteOff(0, 65, 0);
        break;
      case 'I':
        midi.sendNoteOn(0, 66, 127);
        digitalWrite(LED, LOW);
        delay(KeyDelay);
        midi.sendNoteOff(0, 66, 0);
        break;
      case 'J':
        midi.sendNoteOn(0, 67, 127);
        digitalWrite(LED, LOW);
        delay(KeyDelay);
        midi.sendNoteOff(0, 67, 0);
        break;
      case 'K':
        midi.sendNoteOn(0, 68, 127);
        digitalWrite(LED, LOW);
        delay(KeyDelay);
        midi.sendNoteOff(0, 68, 0);
        break;
      case 'L':
        midi.sendNoteOn(0, 69, 127);
        digitalWrite(LED, LOW);
        delay(KeyDelay);
        midi.sendNoteOff(0, 69, 0);
        break;
      case 'M':
        midi.sendNoteOn(0, 70, 127);
        digitalWrite(LED, LOW);
        delay(KeyDelay);
        midi.sendNoteOff(0, 70, 0);
        break;
      case 'N':
        midi.sendNoteOn(0, 71, 127);
        digitalWrite(LED, LOW);
        delay(KeyDelay);
        midi.sendNoteOff(0, 71, 0);
        break;
      case 'O':
        midi.sendNoteOn(0, 72, 127);
        digitalWrite(LED, LOW);
        delay(KeyDelay);
        midi.sendNoteOff(0, 72, 0);
        break;
      case 'P':
        midi.sendNoteOn(0, 73, 127);
        digitalWrite(LED, LOW);
        delay(KeyDelay);
        midi.sendNoteOff(0, 73, 0);
        break;
      case 'Q':
        midi.sendNoteOn(0, 74, 127);
        digitalWrite(LED, LOW);
        delay(KeyDelay);
        midi.sendNoteOff(0, 74, 0);
        break;
      case 'R':
        midi.sendNoteOn(0, 75, 127);
        digitalWrite(LED, LOW);
        delay(KeyDelay);
        midi.sendNoteOff(0, 75, 0);
        break;
      case 'S':
        midi.sendNoteOn(0, 76, 127);
        digitalWrite(LED, LOW);
        delay(KeyDelay);
        midi.sendNoteOff(0, 76, 0);
        break;
      case 'T':
        midi.sendNoteOn(0, 77, 127);
        digitalWrite(LED, LOW);
        delay(KeyDelay);
        midi.sendNoteOff(0, 77, 0);
        break;
      case 'U':
        midi.sendNoteOn(0, 78, 127);
        digitalWrite(LED, LOW);
        delay(KeyDelay);
        midi.sendNoteOff(0, 78, 0);
        break;
      case 'V':
        midi.sendNoteOn(0, 79, 127);
        digitalWrite(LED, LOW);
        delay(KeyDelay);
        midi.sendNoteOff(0, 79, 0);
        break;
      case 'W':
        midi.sendNoteOn(0, 80, 127);
        digitalWrite(LED, LOW);
        delay(KeyDelay);
        midi.sendNoteOff(0, 80, 0);
        break;
      case 'X':
        midi.sendNoteOn(0, 81, 127);
        digitalWrite(LED, LOW);
        delay(KeyDelay);
        midi.sendNoteOff(0, 81, 0);
        break;
      case 'Y':
        midi.sendNoteOn(0, 82, 127);
        digitalWrite(LED, LOW);
        delay(KeyDelay);
        midi.sendNoteOff(0, 82, 0);
        break;
      case 'Z':
        midi.sendNoteOn(0, 83, 127);
        digitalWrite(LED, LOW);
        delay(KeyDelay);
        midi.sendNoteOff(0, 83, 0);
        break;
    }
  }
}

char getKey() {
  char key = 0;
  for (int i=0; i<COLS; i++) {
    digitalWrite(colPins[i], LOW);
    for (int j=0; j<ROWS; j++) {
      if (digitalRead(rowPins[j]) == LOW) {
        delay(debounceTime);
        while (digitalRead(rowPins[j]) == LOW)
                ;//Wait for key release
        key = hexaKeys[j][i];
      }
    }
    digitalWrite(colPins[i],HIGH);
  }
  return key;
}
