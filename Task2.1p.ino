const int dotDuration = 300;
const int dashDuration = 700;
const int ledPin = 13;
const String myName = "samarth";

const char *MORSE_CODE[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--.."
};

volatile int currentIndex = 0;
volatile bool isBlinking = true; 

void setup() {
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    if (isBlinking) {
        Serial.println(myName);
        blinkName();
        delay(3000);  
    }
}
void blinkDash() {
    digitalWrite(ledPin, HIGH);
    delay(dashDuration);
    digitalWrite(ledPin, LOW);
    delay(dotDuration);
}
void blinkDot() {
    digitalWrite(ledPin, HIGH);
    delay(dotDuration);
    digitalWrite(ledPin, LOW);
    delay(dotDuration);
}



void blinkCharacter(char characterToBlink) {
    int index = characterToBlink - 'a';
    if (index >= 0 && index < 26) {
        const char *pattern = MORSE_CODE[index];
        for (int i = 0; pattern[i]; i++) {
            if (pattern[i] == '.') {
                blinkDot();
            } else if (pattern[i] == '-') {
                blinkDash();
            }
            if (pattern[i + 1]) {
                delay(dotDuration);
            }
        }
    }
}
void blinkName() {
    for (int i = 0; i < myName.length(); i++) {
        blinkCharacter(tolower(myName[i]));
        if (i < myName.length() - 1) {
            delay(700);
 }
}
}
