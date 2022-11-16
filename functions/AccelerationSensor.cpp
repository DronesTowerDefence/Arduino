// Beschleunigungssensor
#include <Wire.h>
#include <MPU6050_light.h>

MPU6050 mpu(Wire);
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

    // Wenn der Gyro falsch herum eingebaut wurde (auf dem Kopf)
    // mpu.upsideDownMounting = true;
}

/// @brief Liest die Daten aus dem Sensor aus und berechnet die Geschwindigkeit
/// @return Geschwindigkeit Vorwärts(+)/Rückwärts(-)
int accelerationSensorRead()
{
    mpu.update();

    Serial.print("G-X: ");
    Serial.print(mpu.getAngleX());
    Serial.print("  | G-Y: ");
    Serial.print(mpu.getAngleY());
    Serial.print("  | G-Z: ");
    Serial.print(mpu.getAngleZ());
    Serial.print("  | A-X: ");
    Serial.print(mpu.getAccX());
    Serial.print("  | A-Y: ");
    Serial.print(mpu.getAccY());
    Serial.print("  | A-Z: ");
    Serial.print(mpu.getAccZ());
    Serial.println();
    Serial.println();

    acceleration = mpu.getAccX();

    return acceleration;
}