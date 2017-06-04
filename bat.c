#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
 
#define RELAY 15
#define TRIG 4
#define ECHO 5
 
void setup() {
        wiringPiSetup();
        pinMode(TRIG, OUTPUT);
        pinMode(ECHO, INPUT);
        pinMode(RELAY, OUTPUT);
 
        //TRIG pin must start LOW
        digitalWrite(TRIG, LOW);
        digitalWrite(RELAY, HIGH);
        delay(30);
        printf("set up successful\n");
}
 
int getCM() {
        //Send trig pulse
        digitalWrite(TRIG, HIGH);
        delayMicroseconds(20);
        digitalWrite(TRIG, LOW);
 
        //Wait for echo start
        while(digitalRead(ECHO) == LOW);
 
        //Wait for echo end
        long startTime = micros();
        while(digitalRead(ECHO) == HIGH);
        long travelTime = micros() - startTime;
 
        //Get distance in cm
        int distance = travelTime / 58;
 
        return distance;
}
 
int main(void) {
        //cat fly pass 
        int distant;

        setup();
 
        while (1) {

            //find distant
            distant  = getCM();

            // if objects are in range not more than 100 centimetre
            if (distant >= 20 && distant <= 100) {
                digitalWrite(RELAY, LOW);
		printf("Relay On\n");
            }else{
		digitalWrite(RELAY, HIGH);    
		printf("Relay Off\n");
	    }
            printf("Distance: %dcm\n", distant);
            delay(1000);
            


        }
 
        return 0;
}

