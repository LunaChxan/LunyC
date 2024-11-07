import serial
import time

# Serielle Konfiguration (Passe den Port an deinen an)
SERIAL_PORT = "COM3"  # oder z.B. '/dev/ttyUSB0' für Linux/macOS
BAUD_RATE = 9600

def steuer_pin_d2(status):
    # Serielle Verbindung öffnen
    with serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1) as ser:
        # Nachricht senden: "ON" oder "OFF"
        command = "ON" if status else "OFF"
        ser.write(command.encode())  # Nachricht senden
        print(f"Pin D2 wurde auf {command} gesetzt.")
        time.sleep(1)  # Kurze Pause, damit der Befehl verarbeitet werden kann

# Beispielanwendung
steuer_pin_d2(True)  # Pin auf ON setzen
steuer_pin_d2(False) # Pin auf OFF setzen
