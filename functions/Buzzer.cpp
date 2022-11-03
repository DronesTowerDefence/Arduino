// Buzzer (Hupe)

// Song welcher abgespielt wird, wenn die Hupe betätigt wird
#include "BuzzerSong.cpp"

const int buzzerPin = 9;
int buzzerCount = 0;

/// @brief Die Hupe spielt einen Song ab
/// @param hornswitch
void horn(bool hornswitch)
{
    if (hornswitch || buzzerCount > 0)
    {
        playSong(buzzerPin, buzzerCount);
        buzzerCount += 2;
    }
    else
    {
        buzzerCount = 0;
        noTone(buzzerPin);
    }
}

/*void horn(bool hornSwitch) //Einzelner Hupenton
{
    if (hornSwitch)
    {
        buzzerCount = 0;
    }
    else
    {
        if (buzzerCount == 0)
        {
            tone(buzzerPin, 500);
        }
        else if (buzzerCount > 50)
        {
            noTone(buzzerPin);
        }
        buzzerCount++;
    }
} */