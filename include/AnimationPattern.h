/** AnimationPattern.h
 * 
 * Author: jreese
 * Date: 2018-10-17
 * 
 * Structure which defines an animation pattern which can be played on an LED Strip
 */

#ifndef ANIMATION_PATTERN_H_
#define ANIMATION_PATTERN_H_

#define FASTLED_ESP8266_D1_PIN_ORDER

#include <FastLED.h>
#include <ColorPalette.h>

enum class Direction {
    FORWARD,
    REVERSE
};

class AnimationPattern {
public:
    AnimationPattern(int length, const ColorPalette& palette);
    virtual void stepAnimation(CRGB* buffer, int elapsedTime) = 0;
    virtual void resetAnimation(CRGB* buffer) = 0;

protected:
    int length;
    ColorPalette palette;
 };

 #endif /* ANIMATION_PATTERN_H_ */