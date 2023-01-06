// Buzzer (Hupe)

// Song welcher abgespielt wird, wenn die Hupe betätigt wird
#include "BuzzerSong.cpp"

const int buzzerPin = 9;
int buzzerCount = 0;

/// @brief Die Hupe spielt einen Song ab
/// @param hornswitch
void horn(int hornswitch)
{
    if (hornswitch == 1 && buzzerCount == 0)
    {
        playSong(buzzerPin, 0);
        buzzerCount += 2;
    }
    else if (hornswitch == 2 && buzzerCount > 0)
    {
        if (!playSong(buzzerPin, buzzerCount))
        {
            buzzerCount = 0;
        }
        buzzerCount += 2;
    }
    else if (hornswitch == 0)
    {
        buzzerCount = 0;
        noTone(buzzerPin);
    }
}

/// @brief Einzelner Hupenton
/// @param hornSwitch an/nichts
void hornSingle(bool hornSwitch)
{
    if (hornSwitch)
    {
        buzzerCount = 0;
    }

    buzzerCount++;
    if (buzzerCount == 0)
    {
        tone(buzzerPin, 500);
    }
    else if (buzzerCount > 50)
    {
        noTone(buzzerPin);
        buzzerCount = 0;
    }
}