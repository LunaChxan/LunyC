int pinD2 = 2;  // GPIO 2 ist der D2-Pin auf dem ESP32

void setup() {
  // Initialisiere den seriellen Monitor
  Serial.begin(9600);
  // Setze den Pin D2 als Ausgang
  pinMode(pinD2, OUTPUT);
  // Pin initial ausschalten
  digitalWrite(pinD2, LOW);
  Serial.println("ESP32 wartet auf serielle Befehle...");
}

void loop() {
  // Prüfe, ob Daten über die serielle Schnittstelle empfangen wurden
  if (Serial.available() > 0) {
    // Lese den Befehl als String
    String command = Serial.readStringUntil('\n');
    command.trim();  // Entferne etwaige Leerzeichen oder neue Zeilenzeichen

    // Überprüfe den Befehl und schalte den Pin D2 entsprechend
    if (command == "ON") {
      digitalWrite(pinD2, HIGH);  // Schalte den Pin D2 ein
      Serial.println("Pin D2 wurde eingeschaltet.");
    } else if (command == "OFF") {
      digitalWrite(pinD2, LOW);   // Schalte den Pin D2 aus
      Serial.println("Pin D2 wurde ausgeschaltet.");
    } else {
      Serial.println("Unbekannter Befehl.");
    }
  }
}
