/** LEDStrip.h
 * 
 * Author: jreese
 * Date: 2018-10-17
 * 
 * Structure which defines an LED Strip's properties and associated math.
 * Handles all of the LED Control via FastLED.
 */

#ifndef LEDSTRIP_H_
#define LEDSTRIP_H_

#include <AnimationPattern.h>

class LEDStrip {
public:
    LEDStrip();
    LEDStrip(int length, int deadZoneLength);

    void setAnimation(AnimationPattern* ap);
    void stepAnimation();

    int getBufferLength();
    CRGB* getBuffer();

private:
    int length;
    int deadZoneLength;
    CRGB* buffer;
    AnimationPattern* animationPattern;
};

#endif /* LEDSTRIP_H_ */