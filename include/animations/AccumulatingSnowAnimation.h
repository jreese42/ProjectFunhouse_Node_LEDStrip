/** AccumulatingSnowAnimation.h
 * 
 * Author: jreese
 * Date: 2018-19-17
 * 
 * Does an animation of a color with accumulating snow.
 * Palette primary color is used for the snow, and secondary color (or black if none) for the background.
 */

#ifndef ANIMATIONS_ACCUMULATINGSNOWANIMATION_H_
#define ANIMATIONS_ACCUMULATINGSNOWANIMATION_H_

#include <AnimationPattern.h>

class AccumulatingSnowAnimation : public AnimationPattern {
public:
    AccumulatingSnowAnimation(int length, const ColorPalette& palette);
    void stepAnimation(CRGB* buffer, int elapsedTime);
    void resetAnimation(CRGB* buffer);
};

#endif /* ANIMATIONS_ACCUMULATINGSNOWANIMATION_H_ */