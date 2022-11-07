// Licht und Blinker

const int lightPin = 6;
const int indicatorLeftPin = 7;
const int indicatorRightPin = 8;
int indicatorState = 0;
int indicatorSwitchCount = 0;
bool indicatorSwitch = false;

/// @brief Licht an/aus
/// @param state
void light(bool state)
{
    if (state)
    {
        digitalWrite(lightPin, HIGH);
    }
    else
    {
        digitalWrite(lightPin, LOW);
    }
}

/// @brief Blinker an/aus
/// @param state 0=Aus | 1=Links | 2=Rechts
void indicator(int state)
{
    if (state >= 0 && state < 3)
    {
        indicatorState = state;
    }

    if (indicatorState == 0)
    {
        digitalWrite(indicatorLeftPin, LOW);
        digitalWrite(indicatorRightPin, LOW);
        indicatorSwitchCount = 0;
    }
    else if (indicatorState == 1)
    {
        indicatorSwitchCount++;
        digitalWrite(indicatorRightPin, LOW);
        if (indicatorSwitchCount > 50 && indicatorSwitch)
        {
            digitalWrite(indicatorLeftPin, HIGH);
            indicatorSwitchCount = 0;
            indicatorSwitch = false;
        }
        else if (indicatorSwitchCount > 50 && !indicatorSwitch)
        {
            digitalWrite(indicatorLeftPin, LOW);
            indicatorSwitchCount = 0;
            indicatorSwitch = true;
        }
    }
    else if (indicatorState == 2)
    {
        indicatorSwitchCount++;
        digitalWrite(indicatorLeftPin, LOW);
        if (indicatorSwitchCount > 50 && indicatorSwitch)
        {
            digitalWrite(indicatorRightPin, HIGH);
            indicatorSwitchCount = 0;
            indicatorSwitch = false;
        }
        else if (indicatorSwitchCount > 50 && !indicatorSwitch)
        {
            digitalWrite(indicatorRightPin, LOW);
            indicatorSwitchCount = 0;
            indicatorSwitch = true;
        }
    }
}