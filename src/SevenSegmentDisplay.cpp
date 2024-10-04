#include "SevenSegmentDisplay.h"

SevenSegmentDisplay::SevenSegmentDisplay(seven_segment_display_wired_t displayWired)
{
    commonPin = displayWired.common_pin;

    /* Assign pins to segments A through G */
    segmentPins[0] = displayWired.pin_a;
    segmentPins[1] = displayWired.pin_b;
    segmentPins[2] = displayWired.pin_c;
    segmentPins[3] = displayWired.pin_d;
    segmentPins[4] = displayWired.pin_e;
    segmentPins[5] = displayWired.pin_f;
    segmentPins[6] = displayWired.pin_g;

    /* Initialize the decimal point pin here to prevent evaluating the condition twice in the init method. */
    pinDpConnected = displayWired.pin_dp != 0XFF;
    if (pinDpConnected)
    {
        pinDp = displayWired.pin_dp;
        pinMode(pinDp, OUTPUT);
    }

    /* Invert the original digits map for common anode; no inversion for common cathode */
    if (!commonPin)
    {
        for (u_int8_t digit = 0; digit < 10; digit++)
        {
            for (uint8_t segment = 0; segment < 7; segment++)
            {
                digitsMap[digit][segment] = !digitsMap[digit][segment];
            }
        }
    }

    init();
    off();
}

void SevenSegmentDisplay::init()
{
    for (uint8_t segment = 0; segment < 7; segment++)
    {
        pinMode(segmentPins[segment], OUTPUT);
    }
}

void SevenSegmentDisplay::display(uint8_t digit)
{
    if (digit < 0 || digit > 9)
    {
        return;
    }

    for (uint8_t segment = 0; segment < 7; segment++)
    {
        digitalWrite(segmentPins[segment], digitsMap[digit][segment]);
    }
}

void SevenSegmentDisplay::off()
{
    uint8_t pinOff = commonPin ? 0x0 : 0x1;

    for (uint8_t segment = 0; segment < 7; segment++)
    {
        digitalWrite(segmentPins[segment], pinOff);
    }

    if (pinDpConnected)
    {
        digitalWrite(pinDp, pinOff);
    }
}

void SevenSegmentDisplay::dp(bool on)
{
    if (!pinDpConnected) // if not connected why do you call it?
    {
        return;
    }

    uint8_t pinOn = commonPin ? 0x1 : 0x0;

    if (on)
    {
        digitalWrite(pinDp, pinOn);
    }
    else
    {
        digitalWrite(pinDp, !pinOn);
    }
}
