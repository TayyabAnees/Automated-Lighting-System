#define PIR_PIN 2           
#define LDR_PIN A0           
#define LED_PIN 9            
#define SWITCH_PIN 12

unsigned long lastMotionTime = 0;
const unsigned long timeout = 5 * 60 * 1000;
int isLightOn = 0;
const int LIGHT_THRESHOLD = 567;

void setup() {
    pinMode(PIR_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
    pinMode(LDR_PIN, INPUT);
    pinMode(SWITCH_PIN, INPUT_PULLUP);
    Serial.begin(9600);
}

void loop() {
    int switchState = digitalRead(SWITCH_PIN);
    
    if (switchState == LOW) {
        analogWrite(LED_PIN, 0);
        Serial.println("System OFF");
        isLightOn = 0;
        return;
    }
    
    int lightLevel = analogRead(LDR_PIN);
    Serial.print("LDR: "); Serial.println(lightLevel);
    
    if (lightLevel >= LIGHT_THRESHOLD) {
        analogWrite(LED_PIN, 0);
        Serial.println("Sufficient light, LED OFF.");
        isLightOn = 0;
        return;
    }
    
    int motion = digitalRead(PIR_PIN);
    Serial.print("Motion: "); Serial.println(motion);
    
    if (motion == HIGH) {
        lastMotionTime = millis();
        int brightness = map(lightLevel, 680, 0, 100, 255);
        brightness = constrain(brightness, 100, 255);
        analogWrite(LED_PIN, brightness);
        Serial.print("Motion detected, LED Brightness: ");
        Serial.println(brightness);
        isLightOn = 1;
    } else {
        if (isLightOn) {
            if (millis() - lastMotionTime > timeout) {
                analogWrite(LED_PIN, 0);
                Serial.println("No motion, LED turned off.");
                isLightOn = 0;
            } else {
                int brightness = map(lightLevel, 680, 0, 100, 255);
                brightness = constrain(brightness, 100, 255);
                analogWrite(LED_PIN, brightness);
                Serial.print("No motion, but within timeout. LED Brightness: ");
                Serial.println(brightness);
            }
        }
    }
}
