/** SolidColorAnimation.h
 * 
 * Author: jreese
 * Date: 2018-10-17
 * 
 * Controller object which holds the objects needed to build and display animations on an LED Strip.
 */

#ifndef ANIMATIONS_SOLIDCOLORANIMATION_H_
#define ANIMATIONS_SOLIDCOLORANIMATION_H_

#include <AnimationPattern.h>

class SolidColorAnimation : public AnimationPattern {
public:
    SolidColorAnimation(int length, const ColorPalette& palette);
    void stepAnimation(CRGB* buffer, int elapsedTime);
};

#endif /* ANIMATIONS_SOLIDCOLORANIMATION_H_ */