/** MovingBarsAnimation.h
 * 
 * Author: jreese
 * Date: 2018-19-17
 * 
 * Does an animation with the strip split into evenly sized bars which scroll and fade.
 * The full palette is rotated to make the bars, and can be duplicated.
 */

#ifndef ANIMATIONS_MOVINGBARSANIMATION_H_
#define ANIMATIONS_MOVINGBARSANIMATION_H_

#include <AnimationPattern.h>

class MovingBarsAnimation : public AnimationPattern {
public:
    MovingBarsAnimation(int length, const ColorPalette& palette, int barSpeed, int numBars, int fadeRate, Direction direction);
    void stepAnimation(CRGB* buffer, int elapsedTime);
    void resetAnimation(CRGB* buffer);

private:
    int barSpeed; /* in pixels per second */
    int numBars;
    int fadeRate; /* in 256ths per millisecond */ /*fade millis */
    Direction direction;

    int barWidth;
    int currOffset;
    int resetOffset;
};

#endif /* ANIMATIONS_MOVINGBARSANIMATION_H_ */