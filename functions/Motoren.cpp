
int powerrel = 10, directrel = 11, safetyrel = 12;

void motorbefehl(int signal)
{
    if (signal == 0) //Nichts / rollen lassen
    {
        digitalWrite(powerrel, LOW);
        Serial.println("Nichts");
    }
    if (signal == 1) // Vorwärts
    {
        digitalWrite(directrel, HIGH);
        digitalWrite(powerrel, HIGH);
        digitalWrite(safetyrel, HIGH);
        Serial.println("Vorwärts");
    }
    if (signal == 2) // Bremsen / Rückwärts
    {
        if(accelaration==0){
        digitalWrite(directrel, LOW);
        digitalWrite(powerrel, HIGH);
        digitalWrite(safetyrel, LOW);
        Serial.println("Rückwärts");
        }
        else{
        digitalWrite(powerrel, LOW);
        Serial.println("Nichts");
        }
    }
}
