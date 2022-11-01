#include <Wire.h>

const int MPU_ADDR = 0x68; // I2C Adresse vom MPU (Sensor)

unsigned int accelerometer_x, accelerometer_y, accelerometer_z;

/// @brief !! Nur fürs setup !!
void accelerationSensorSetup()
{
    Wire.begin();
    Wire.beginTransmission(MPU_ADDR);
    Wire.write(0x6B);
    Wire.write(0); // Null gesetzt, wach geschaltet
    Wire.endTransmission(true);
}

/// @brief Auslesen der Sensordaten
/// @return Beschleunigung in x-Richtung
int accelerationSensorRead()
{
    Wire.beginTransmission(MPU_ADDR);
    Wire.write(0x3B);
    Wire.endTransmission(false);          // Verbindung bleibt aktiv WICHTIG
    Wire.requestFrom(MPU_ADDR, 14, true); // 14 Register

    // Werte werden ausgelesen
    accelerometer_x = Wire.read() << 8 | Wire.read(); // reading registers: 0x3B (ACCEL_XOUT_H) and 0x3C (ACCEL_XOUT_L)
    accelerometer_y = Wire.read() << 8 | Wire.read(); // reading registers: 0x3D (ACCEL_YOUT_H) and 0x3E (ACCEL_YOUT_L)
    accelerometer_z = Wire.read() << 8 | Wire.read(); // reading registers: 0x3F (ACCEL_ZOUT_H) and 0x40 (ACCEL_ZOUT_L)

    Serial.print("Beschleunigung-X: ");
    Serial.println(accelerometer_x);
    Serial.print("Beschleunigung-Y: ");
    Serial.println(accelerometer_y);
    Serial.print("Beschleunigung-Z: ");
    Serial.println(accelerometer_z);

    return accelerometer_x;
}