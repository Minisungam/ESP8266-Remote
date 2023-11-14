#include <ESP8266WiFi.h>

// SSID and Password of WiFi network
const char* ssid = "";
const char* password = "";

// IP and Port of Vicreo Server
const char* serverAddress = "";
const int serverPort = 10001; // Default port for Vicreo

// Vicreo password hashed with MD5
const String tcpPass = "";

// WiFi client object
WiFiClient client;

// GPIO pins to use for buttons
const int buttonPinD1 = 5;
const int buttonPinD2 = 4;

// Debouncing variables
unsigned long lastDebounceTimeD1 = 0;
unsigned long lastDebounceTimeD2 = 0;
const unsigned long debounceDelay = 50;

// Button state variables
bool buttonStateD1 = HIGH;
bool lastButtonStateD1 = HIGH;

bool buttonStateD2 = HIGH;
bool lastButtonStateD2 = HIGH;

// Connect to WiFi and initialize pins
void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  pinMode(buttonPinD1, INPUT_PULLUP);
  pinMode(buttonPinD2, INPUT_PULLUP);
}

// Main looping code
void loop() {
  char command = Serial.read();

  if (!client.connected()) {
    Serial.print("Connecting to server... ");
    if (client.connect(serverAddress, serverPort)) {
      Serial.println("connected");
    } else {
      Serial.println("connection failed");
    }
  }

  // Check button state for D1
  int readingD1 = digitalRead(buttonPinD1);
  if (readingD1 != lastButtonStateD1) {
    lastDebounceTimeD1 = millis();
  }

  if ((millis() - lastDebounceTimeD1) > debounceDelay) {
    if (readingD1 != buttonStateD1) {
      buttonStateD1 = readingD1;

      if (buttonStateD1 == LOW) {
        Serial.println("Button D1 pressed");
        client.print("{ \"key\":\"left\", \"type\":\"press\", \"password\":\"" + tcpPass + "\" }");
      }
    }
  }

  // Check button state for D2
  int readingD2 = digitalRead(buttonPinD2);
  if (readingD2 != lastButtonStateD2) {
    lastDebounceTimeD2 = millis();
  }

  if ((millis() - lastDebounceTimeD2) > debounceDelay) {
    if (readingD2 != buttonStateD2) {
      buttonStateD2 = readingD2;

      if (buttonStateD2 == LOW) {
        Serial.println("Button D2 pressed");
        client.print("{ \"key\":\"right\", \"type\":\"press\", \"password\":\"" + tcpPass + "\" }");
      }
    }
  }

  // Update lastButtonStateD1 and lastButtonStateD2
  lastButtonStateD1 = readingD1;
  lastButtonStateD2 = readingD2;
}
