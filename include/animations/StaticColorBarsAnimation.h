/** StaticColorBarsAnimation.h
 * 
 * Author: jreese
 * Date: 2018-11-27
 * 
 * Displays bars of a set width. The bars fade in at the start, and are of a specified width.
 * Palette is cycled in order to color bars.
 */

#ifndef ANIMATIONS_STATICCOLORBARSANIMATION_H_
#define ANIMATIONS_STATICCOLORBARSANIMATION_H_

#include <AnimationPattern.h>

class StaticColorBarsAnimation : public AnimationPattern {
public:
    StaticColorBarsAnimation(int length, const ColorPalette& palette, int barWidth);
    void stepAnimation(CRGB* buffer, int elapsedTime);
    void resetAnimation(CRGB* buffer);

private:
    int barWidth;
    int startupTimer; //Active timer
    int startupTime; //Value startupTimer is set to on start
};

#endif /* ANIMATIONS_STATICCOLORBARSANIMATION_H_ */