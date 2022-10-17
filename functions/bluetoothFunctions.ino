// Bluetooth-Zeug

// Bluetooth Empfang und Umsetzung der Erhaltenen Daten
int checkBluetoothHeader()
{
    if (Serial1.available() > 0)
    {
        String dataSource = "";         // String welcher an der Schnittstelle gelesen wird
        String data = "";               // Inhalt eines Headers (Informationen hinter dem Header)
        String dataSourceTmp            // Hilfsstring
            char header = '';           // Header
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
            dataSource = "";
            data = "";
            header = "";
            first = 0;
            second = 0;
            length = 0;

            first = dataSource.indexOf("\1"); // Sucht das erste Steuerzeichen (SOH)
            header = dataSource[first + 1];

            Serial.print("Erhaltener Header: "); // Ausgabe: Header
            Serial.println(header);

            first = dataSource.indexOf("\2");  // Sucht SOH
            second = dataSource.indexOf("\3"); // Sucht ETX
            length = second - first - 1;

            for (int i = 0; i < length; i++) // Kopiert das, was zwischen den beiden Steuerzeichen steht in einen anderen String
            {
                data[i] = dataSource[i + first];
            }

            Serial.print("Erhaltener Inhalt: "); // Ausgabe: Inhalt
            Serial.println(data);

            if (dataReadOfString + data.length() + header.length() + 3 < dataSource.length())
            {
                nextHeaderInString = true;
                dataReadOfString += data.length() + header.length() + 3;
                dataSourceTmp = dataSource;
                dataSource = "";
                for (int i = dataReadOfString, j = 0; i < dataSource.length(); i++, j++)
                {
                    dataSource[j] += dataSourceTmp[i];
                }
            }

            // Header-Überprüfung:
            if (header == "1") // Bewegung: Vor/Zurück
            {
                if (data == "0") // Bremsen
                {
                    // Bremsen
                }
                else if (data == "1") // Vorwärts
                {
                    // Vorwärts
                }
                else if (data == "2") // Rückwärts
                {
                    // Rückwärts
                }
                return 1;
            }
            else if (header == "2") // Lenkung
            {
                // Lenkung
                return 2;
            }
            else if (header == "4") // Licht
            {
                // Licht
                return 4;
            }
            else if (header == "5") // Hupe
            {
                // Hupe
                return 5;
            }
            else // Ungültiger Header
            {
                return 0;
            }
        }
    }
}

// Bluetooth Senden
// 1: Geschwindigkeit
// 2: IR-Sensor
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

    Serial1.write("\1" + to_string(header) + "\2" + to_string(value) + "\3");
    return true;
}