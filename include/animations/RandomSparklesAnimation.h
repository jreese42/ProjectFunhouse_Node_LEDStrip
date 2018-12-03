/** RandomSparklesAnimation.h
 * 
 * Author: jreese
 * Date: 2018-12-02
 * 
 * Does an animation of with fading sparkles of random palette colors in random locations.
 */

#ifndef ANIMATIONS_RANDOMSPARKLESANIMATION_H_
#define ANIMATIONS_RANDOMSPARKLESANIMATION_H_

#include <AnimationPattern.h>

class RandomSparklesAnimation : public AnimationPattern {
public:
    RandomSparklesAnimation(int length, const ColorPalette& palette);
    void stepAnimation(CRGB* buffer, int elapsedTime);
    void resetAnimation(CRGB* buffer);
};

#endif /* ANIMATIONS_RANDOMSPARKLESANIMATION_H_ */