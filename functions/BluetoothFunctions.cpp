// Bluetooth: Empfangen und Senden

int bluetoothStatus = 3;

/// @brief Bluetooth Empfang und Umsetzung der erhaltenen Daten
/// @return Ob eine Nachricht angekommen ist
bool checkBluetoothHeader()
{
    bool returnValue = false; // Return-Wert

    if (Serial1.available() > 0)
    {
        String dataSource = "";         // String welcher an der Schnittstelle gelesen wird
        String data = "";               // Inhalt eines Headers (Informationen hinter dem Header)
        String dataSourceTmp;           // Hilfsstring
        char header = '\0';             // Header
        int first = 0;                  // Hilfsvariable
        int second = 0;                 // Hilfsvariable
        int length = 0;                 // Hilfsvariable
        int dataReadOfString = 0;       // Länge des bereits gelesenen Strings (wie viele Zeichen von 'dataSource' bereits gelesen wurde)
        bool nextHeaderInString = true; // Ob die While-Schleife nochmal durchgegangen werden soll

        dataSource = Serial1.readString();

        Serial.print("Erhaltene Daten: "); // Ausgabe: Rohdaten
        Serial.println(dataSource);

        while (nextHeaderInString) // Solange noch ein Header in dem String kommt
        {
            // Zurücksetzen der Variablen
            nextHeaderInString = false;
            data = "";
            header = '\0';
            first = 0;
            second = 0;
            length = 0;

            first = dataSource.indexOf("\x01"); // Sucht das erste Steuerzeichen (SOH)
            header = dataSource[first + 1];

            Serial.print("Erhaltener Header: "); // Ausgabe: Header
            Serial.println(header);

            first = dataSource.indexOf("\x02");  // Sucht SOH
            second = dataSource.indexOf("\x03"); // Sucht ETX
            length = second - first - 1;

            data = dataSource.substring(first + 1, second); // Kopiert das, was zwischen den beiden Steuerzeichen steht in einen anderen String

            Serial.print("Erhaltener Inhalt: "); // Ausgabe: Inhalt
            Serial.println(data);

            if (dataReadOfString + second < dataSource.length())
            {
                nextHeaderInString = true;
                dataReadOfString = second;
                dataSourceTmp = dataSource;
                dataSource = dataSourceTmp.substring(second + 1, dataSourceTmp.length()); // Kopiert den Rest des Strings in den String
                Serial.print("Rest: ");
                Serial.println(dataSource);
            }
            
            // Header-Überprüfung:
            if (header == '1') // Bewegung: Vor/Zurück
            {
                returnValue = true;

                if (data == "0") // Bremsen
                {
                    // Bremsen
                    Serial.println("Bremsen");
                }
                else if (data == "1") // Vorwärts
                {
                    // Vorwärts
                    Serial.println("Vorwärts");
                }
                else if (data == "2") // Rückwärts
                {
                    // Rückwärts
                    Serial.println("Rückwärts");
                }
            }
            else if (header == '2') // Lenkung
            {
                // Lenkung
                returnValue = true;
                Serial.println("Lenken");
            }
            else if (header == '4') // Licht
            {
                // Licht
                returnValue = true;
                Serial.println("Licht");
            }
            else if (header == '5') // Hupe
            {
                // Hupe
                returnValue = true;
                Serial.println("Hupe");
            }
            else // Ungültiger Header
            {
                Serial.println("Ungültiger Header");
            }
        }
    }
    return returnValue;
}

/// @brief Bluetooth Senden (Noch nicht getestet) | 1:Geschwindigkeit | 2:IR-Sensor
/// @return Ob die Daten gesendet wurden
bool sendBluetoothData(int parameter, int parameter2)
{
    int header = 0;
    int value = parameter2;
    switch (parameter)
    {
    case 1: // Geschwindigkeit
        header = 3;
        break;

    case 2: // IR-Sensor
        header = 6;
        break;

    default:
        return false;
    }

    Serial.print("Header: "); // Ausgabe: Header
    Serial.println(header);
    Serial.print("Value: "); // Ausgabe: Inhalt
    Serial.println(value);

    if (Serial1.print("\x01" + String(header) + "\x02" + String(value) + "\x03") > 0)
        return true;
    else
        return false;
}

/// @brief Überprüft, ob die Verbindung zur Fernbedienung noch steht oder nicht
/// @return True wenn Verbindung vorhanden
bool checkBluetoothConnection()
{
    if(digitalRead(bluetoothStatus) == 1)
    {
        return true;
    }
    else
    {
        //Bremsen
        return false;
    }
}