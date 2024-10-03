# Seven Segment Display

The Seven Segment Display is an Arduino library designed to simplify the control of a seven-segment display. Its main purpose is to display decimal digits one at a time.

There are two types of seven segment display: common anode and common cathode.

## Usage

### Common Anode Display

> [!NOTE]
> Please note that the first argument of the constructor is __false__; this means you are using a common anode display.

An example of displaying digits from 0 to 9, not using the decimal point segment.
```c++
#include "SevenSegmentDisplay.h"

SevenSegmentDisplay myDisplay(false, 23, 22, 15, 17, 4, 21, 19);

void setup() {
 
}

void loop() {
  for(uint8_t number = 0; number < 10; number++) {
    myDisplay.display(number);
    delay(1000);
  }
}
```

An example of displaying the digits from 0 to 9, followed by turning the decimal point on and off.
```c++
#include "SevenSegmentDisplay.h"

SevenSegmentDisplay myDisplay(false, 23, 22, 15, 17, 4, 21, 19, 18);

void setup() {

}

void loop() {
  for(uint8_t number = 0; number < 10; number++) {
    myDisplay.display(number);
    delay(1000);
  }
  myDisplay.dp(true);
  delay(1000);
  myDisplay.dp(false);
  delay(1000);
}
```

### Common Cathode Display

> [!NOTE]
> Please note that the first argument of the constructor is __true__; this means you are using a common cathode display.

An example of displaying digits from 0 to 9, not using the decimal point segment.
```c++
#include "SevenSegmentDisplay.h"

SevenSegmentDisplay myDisplay(true, 23, 22, 15, 17, 4, 21, 19);

void setup() {

}

void loop() {
  for(uint8_t number = 0; number < 10; number++) {
    myDisplay.display(number);
    delay(1000);
  }
}
```

An example of displaying the digits from 0 to 9, followed by turning the decimal point on and off.
```c++
#include "SevenSegmentDisplay.h"

SevenSegmentDisplay myDisplay(true, 23, 22, 15, 17, 4, 21, 19, 18);

void setup() {

}

void loop() {
  for(uint8_t number = 0; number < 10; number++) {
    myDisplay.display(number);
    delay(1000);
  }
  myDisplay.dp(true);
  delay(1000);
  myDisplay.dp(false);
  delay(1000);
}
```

## Methods

### display

```c++
/**
 * @brief               Display a digit on the Seven Segment Display
 *
 * @param digit         digit to display
 */
void display(uint8_t digit);
```

### dp
```c++
/**
 * @brief               Turn on or turn off the Decimal Point (DP) segment
 *
 * @param on            true for turning on; false for turning off
 */
void dp(bool on);
```

### off
```c++
    /**
     * @brief               turn off all the segments, even the Decimal Point (DP) segment if set
     */
    void off();
```
# FAQ

### Other libraries display more characters; why doesn’t this one?
> I believe the purpose of a seven-segment display is to show digits only. Other characters may not be displayed clearly enough to be considered.

### Why are there so many comments in the source code?
> Most comments might be seen as 'well, duh' remarks, but they are meant for beginner programmers.
