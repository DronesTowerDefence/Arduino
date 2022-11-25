// Beschleunigungssensor
#include <Wire.h>
#include <MPU6050_light.h>

/*
SENSOR-INFOS:
---------------------------------------------------------------------------------
Ruhezustand "getAcc":
X:0 | Y:0 | Z:1 -> Zeigt an wie sehr die Erdbeschleunigung auf die Achse wirkt
---------------------------------------------------------------------------------
GYRO:
Gyro zeigt temporär falsche Werte an, wenn man es zu schnell bewegt.
(Braucht einige Sekunden, um wieder auf 0 zu kommen)
(Könnte auch an der Bau-Rate des seriellen Monitors liegen)
Die Z-Achse steigt oder singt manchmal konstant, ist ein bekanntes Problem.
(https://github.com/rfetick/MPU6050_light/issues/34)
Die Funktion getAccAngle berechnet den Winkel nicht mit dem Gyro, sondern mit g,
dort tritt der Fehler nicht auf, ist dafür aber ungenauer
---------------------------------------------------------------------------------

*/

MPU6050 mpu(Wire);
float accelerationGravity[3];
float acceleration = 0.0f;

/// @brief Setup für den Beschleunigungssensor
void accelerationSensorSetup()
{
    Wire.begin();
    mpu.begin();

    // Setzt die aktuelle Position des Gyro's auf 0
    // Wenn das Auto bei Aufruf der Funktion schief steht, wird diese Schräge trotzdem als 0 genommen
    mpu.calcGyroOffsets();

    // Setzt die aktuelle Geschwindigkeit als den 0 Wert des Sensors
    // Auto sollte dabei still stehen
    mpu.calcAccOffsets();

    // Wenn der Sensor falsch herum eingebaut wurde (auf dem Kopf)
    // mpu.upsideDownMounting = true;
}

/// @brief Liest die Daten aus dem Sensor aus und berechnet die Geschwindigkeit (min. 0.8829m/s)
/// @param index 0:X | 1:Y | 2:Z
/// @return Geschwindigkeit in m/s Vorwärts(+)/Rückwärts(-)
int accelerationSensorRead(int index)
{
    mpu.update();

    acceleration = 0;
    accelerationGravity[0] = mpu.getAccX();
    accelerationGravity[1] = mpu.getAccY();
    accelerationGravity[2] = mpu.getAccZ();

    if (index >= 0 && index <= 2)
    {
        if (accelerationGravity[index] >= 0.09)
        {
            acceleration = accelerationGravity[index] * 9.81;
        }

        // Ausgabe zum testen
        /* if (acceleration > 0)
        {
            Serial.print("A-X: ");
            Serial.print(acceleration);
            Serial.print(" m/s");

            Serial.println();
            Serial.println();
        } */
    }
    return acceleration;
}