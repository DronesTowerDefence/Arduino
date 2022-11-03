// Original-Code von: https://github.com/robsoncouto/arduino-songs

// Song, welcher abgespielt werden soll, nicht mehr als einen song includen
#include "../songs/cantinaBand.cpp"

// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
// there are two values per note (pitch and duration), so for each note there are four bytes
int notes = sizeof(melody) / sizeof(melody[0]) / 2;

// this calculates the duration of a whole note in ms
int wholenote = (60000 * 2) / tempo;

int divider = 0, noteDuration = 0;

/// @brief Spielt den ausgewählten Song ab
/// @param buzzerPin Den Pin, an welchem der Buzzer angeschlossen ist
/// @param noteCount Die Note, welche als nächstes gespielt werden soll
/// @return Ob noteCount im gültigen Bereich lag
bool playSong(int buzzerPin, int noteCount)
{
    if (noteCount < notes * 2)
    {
        // calculates the duration of each note
        divider = melody[noteCount + 1];
        if (divider > 0)
        {
            // regular note, just proceed
            noteDuration = (wholenote) / divider;
        }
        else if (divider < 0)
        {
            // dotted notes are represented with negative durations!!
            noteDuration = (wholenote) / abs(divider);
            noteDuration *= 1.5; // increases the duration in half for dotted notes
        }

        // we only play the note for 90% of the duration, leaving 10% as a pause
        tone(buzzerPin, melody[noteCount], noteDuration * 0.9);

        // Wait for the specief duration before playing the next note.
        delay(noteDuration);

        // stop the waveform generation before the next note.
        noTone(buzzerPin);

        return true;
    }
    else
        return false;
}