/** LightningStormAnimation.h
 * 
 * Author: jreese
 * Date: 2018-19-17
 * 
 * Does an animation of a lightning storm.
 * Palette primary color is used for the pulse, and secondary color (or black if none) for the background.
 */

#ifndef ANIMATIONS_LIGHTNINGSTORMANIMATION_H_
#define ANIMATIONS_LIGHTNINGSTORMANIMATION_H_

#include <AnimationPattern.h>

class LightningStormAnimation : public AnimationPattern {
public:
    LightningStormAnimation(int length, const ColorPalette& palette);
    void stepAnimation(CRGB* buffer, int elapsedTime);
    void resetAnimation(CRGB* buffer);
};

#endif /* ANIMATIONS_LIGHTNINGSTORMANIMATION_H_ */