#ifndef SEVEN_SEGMENT_DISPLAY_H
#define SEVEN_SEGMENT_DISPLAY_H

#include "Arduino.h"
#include "seven_segment_display_t.h"

class SevenSegmentDisplay
{
public:
    /**
     * @deprecated          use SevenSegmentDisplay(seven_segment_display_wired_t displayWired) instead
     *
     * @param commonPin     Display type: Anode: false; Cathode: true
     *
     * @param pinA          Output Pin number connected to the A segment
     *
     * @param pinB          Output Pin number connected to the B segment
     *
     * @param pinC          Output Pin number connected to the C segment
     *
     * @param pinD          Output Pin number connected to the D segment
     *
     * @param pinE          Output Pin number connected to the E segment
     *
     * @param pinF          Output Pin number connected to the F segment
     *
     * @param pinG          Output Pin number connected to the G segment
     */
    SevenSegmentDisplay(bool commonPin, uint8_t pinA, uint8_t pinB, uint8_t pinC, uint8_t pinD, uint8_t pinE, uint8_t pinF, uint8_t pinG);

    /**
     * @deprecated          use SevenSegmentDisplay(seven_segment_display_wired_t displayWired) instead
     *
     * @param commonPin     Display type: Anode: false; Cathode: true
     *
     * @param pinA          Output Pin number connected to the A segment
     *
     * @param pinB          Output Pin number connected to the B segment
     *
     * @param pinC          Output Pin number connected to the C segment
     *
     * @param pinD          Output Pin number connected to the D segment
     *
     * @param pinE          Output Pin number connected to the E segment
     *
     * @param pinF          Output Pin number connected to the F segment
     *
     * @param pinG          Output Pin number connected to the G segment
     *
     * @param pinDp         Output Pin number connected to the Decimal Point(DP) segment
     */
    SevenSegmentDisplay(bool commonPin, uint8_t pinA, uint8_t pinB, uint8_t pinC, uint8_t pinD, uint8_t pinE, uint8_t pinF, uint8_t pinG, uint8_t pinDp);

    SevenSegmentDisplay(seven_segment_display_wired_t displayWired);

    /**
     * @brief               Display a digit on the Seven Segment Display
     *
     * @param digit         digit to display
     */
    void display(uint8_t digit);

    /**
     * @brief               Turn on or turn off the Decimal Point (DP) segment
     *
     * @param on            true for turning on; false for turning off
     */
    void dp(bool on);

    /**
     * @brief               turn off all the segments, even the Decimal Point (DP) segment if set
     */
    void off();

private:
    bool commonPin;         /* false: Anode Common; true: Cathode Common */

    uint8_t segmentPins[7]; /* storage for the the pines from A to G */

    bool pinDpConnected;    /* if the DP segment pin is set or not. */

    uint8_t pinDp;          /* Output Pin number connected to the Decimal Point segment */

    /**
     * The digits representation for a Cathode Seven Segment Display (commonPin is true)
     * In the Anode Seven Segment Display representation is the inverse of this (commonPin is false)
     */
    bool digitsMap[10][7] = {
        {0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x0}, /* 0 */
        {0x0, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0}, /* 1 */
        {0x1, 0x1, 0x0, 0x1, 0x1, 0x0, 0x1}, /* 2 */
        {0x1, 0x1, 0x1, 0x1, 0x0, 0x0, 0x1}, /* 3 */
        {0x0, 0x1, 0x1, 0x0, 0x0, 0x1, 0x1}, /* 4 */
        {0x1, 0x0, 0x1, 0x1, 0x0, 0x1, 0x1}, /* 5 */
        {0x1, 0x0, 0x1, 0x1, 0x1, 0x1, 0x1}, /* 6 */
        {0x1, 0x1, 0x1, 0x0, 0x0, 0x0, 0x0}, /* 7 */
        {0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1}, /* 8 */
        {0x1, 0x1, 0x1, 0x0, 0x0, 0x1, 0x1}  /* 9 */
    };

    /**
     * @brief               Set the pines (A-G) to mode OUTPUT.
     */
    void init();
};

#endif /* SEVEN_SEGMENT_DISPLAY_H */
