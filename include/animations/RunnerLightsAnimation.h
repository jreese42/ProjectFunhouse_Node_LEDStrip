/** RunnerLightsAnimation.h
 * 
 * Author: jreese
 * Date: 2018-19-17
 * 
 * Does an animation with lights running down the length of the strip with tails 
 * Bolts alternate between all palette colors.
 */

#ifndef ANIMATIONS_RUNNERLIGHTSANIMATION_H_
#define ANIMATIONS_RUNNERLIGHTSANIMATION_H_

#include <AnimationPattern.h>

class RunnerLightsAnimation : public AnimationPattern {
public:
    RunnerLightsAnimation(int length, const ColorPalette& palette, int speed, int spacing, int tailLength, Direction direction);
    void stepAnimation(CRGB* buffer, int elapsedTime);
    void resetAnimation(CRGB* buffer);

private:
    int speed;
    int spacing;
    int tailLength;
    Direction direction;
};

#endif /* ANIMATIONS_RUNNERLIGHTSANIMATION_H_ */