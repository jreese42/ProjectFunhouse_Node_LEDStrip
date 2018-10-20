/** MarchingAntsAnimation.h
 * 
 * Author: jreese
 * Date: 2018-10-17
 * 
 * Does an animation of marching lights. If the palette has multiple colors, the each "ant" will alternate colors.
 */

#ifndef ANIMATIONS_MARCHINGANTSANIMATION_H_
#define ANIMATIONS_MARCHINGANTSANIMATION_H_

#include <AnimationPattern.h>

class MarchingAntsAnimation : public AnimationPattern {
public:
    MarchingAntsAnimation(int length, const ColorPalette& palette, int antSpacing, int millisRate, Direction direction);
    void stepAnimation(CRGB* buffer, int elapsedTime);

private:
    int antSpacing;
    int millisRate;
    Direction direction;
};

#endif /* ANIMATIONS_MARCHINGANTSANIMATION_H_ */