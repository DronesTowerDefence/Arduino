// Licht und Blinker

const int lightBackPin = 53;
const int lightFrontPin1 = 47;
const int lightFrontPin2 = 45;
const int indicatorLeftPin = 51;
const int indicatorRightPin = 49;
const int bluelightPin1 = 43;
const int bluelightPin2 = 41;
const int bluelightSwitchMaxCount = 40;
int bluelightState = 0;
int bluelightSwitchCount = 0;
bool bluelightSwitch = 0;
const int indicatorSwitchMaxCount = 120;
int indicatorState = 0;
int indicatorSwitchCount = 0;
bool indicatorSwitch = false;

/// @brief Licht an/aus
/// @param state
void light(bool state)
{
    if (state)
    {
        digitalWrite(lightFrontPin1, HIGH);
        digitalWrite(lightFrontPin2, HIGH);
        digitalWrite(lightBackPin, HIGH);
    }
    else
    {
        digitalWrite(lightFrontPin1, LOW);
        digitalWrite(lightFrontPin2, LOW);
        digitalWrite(lightBackPin, LOW);
    }
}

/// @brief Blaulicht
/// @param state 0=Aus | 1=An
void blueLight(int state)
{
    if (state == 0 || state == 1)
    {
        bluelightState = state;
    }

    if (bluelightState == 0)
    {
        digitalWrite(bluelightPin1, LOW);
        digitalWrite(bluelightPin2, LOW);
        bluelightSwitchCount = 0;
    }
    else if (bluelightState == 1)
    {
        bluelightSwitchCount++;
        if (bluelightSwitchCount > bluelightSwitchMaxCount && bluelightSwitch)
        {
            digitalWrite(bluelightPin1, LOW);
            digitalWrite(bluelightPin2, HIGH);
            bluelightSwitchCount = 0;
            bluelightSwitch = false;
        }
        else if (bluelightSwitchCount > bluelightSwitchMaxCount && !bluelightSwitch)
        {
            digitalWrite(bluelightPin1, HIGH);
            digitalWrite(bluelightPin2, LOW);
            bluelightSwitchCount = 0;
            bluelightSwitch = true;
        }
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
        if (indicatorSwitchCount > indicatorSwitchMaxCount && indicatorSwitch)
        {
            digitalWrite(indicatorLeftPin, HIGH);
            indicatorSwitchCount = 0;
            indicatorSwitch = false;
        }
        else if (indicatorSwitchCount > indicatorSwitchMaxCount && !indicatorSwitch)
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
        if (indicatorSwitchCount > indicatorSwitchMaxCount && indicatorSwitch)
        {
            digitalWrite(indicatorRightPin, HIGH);
            indicatorSwitchCount = 0;
            indicatorSwitch = false;
        }
        else if (indicatorSwitchCount > indicatorSwitchMaxCount && !indicatorSwitch)
        {
            digitalWrite(indicatorRightPin, LOW);
            indicatorSwitchCount = 0;
            indicatorSwitch = true;
        }
    }
}