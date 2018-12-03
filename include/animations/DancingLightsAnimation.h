/** AccumulatingSnowAnimation.h
 * 
 * Author: jreese
 * Date: 2018-12-01
 * 
 * Does an animation of a lights that jump back and forth and fade in and out.
 */

#ifndef ANIMATIONS_DANCINGLIGHTSANIMATION_H_
#define ANIMATIONS_DANCINGLIGHTSANIMATION_H_

#include <AnimationPattern.h>

typedef enum DancingLightsDirectionState {
    LEFT,
    RIGHT,
} DancingLightsDirectionState;

typedef enum DancingLightsFlashState {
    FADE_UP,
    ON,
    FADE_DOWN,
    OFF,
} DancingLightsFlashState;

class DancingLightsAnimation : public AnimationPattern {
public:
    DancingLightsAnimation(int length, const ColorPalette& palette, int spacing, int jumpDistance, int numBlinks, int fadeSpeed, int onTime, int offTime);
    void stepAnimation(CRGB* buffer, int elapsedTime);
    void resetAnimation(CRGB* buffer);

private:
    int spacing; //the distance between the center of each blinking light
    int jumpDistance; //the distance each light jumps left and right of it's center (radius)
    int numBlinks; //the lights jump back and forth every numBlinks blinks
    int fadeTime; //ms to fade on or off
    int onTime; //ms spent at 100%
    int offTime; //ms spent at 0%
    int maxBrightness;
};

#endif /* ANIMATIONS_DANCINGLIGHTSANIMATION_H_ */