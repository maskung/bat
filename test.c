#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
 
#define RELAY (int)14
void setup() {
        wiringPiSetup();
        pinMode(RELAY, OUTPUT);
	digitalWrite(RELAY, HIGH);
}

int main(void) {

        setup();
 
        while (1) {

	    digitalWrite(RELAY, HIGH);
            delay(1000);
             digitalWrite(RELAY, LOW);
            delay(1000);
            
        }
 
   
    return 0;

}

