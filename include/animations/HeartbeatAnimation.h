/** HeartbeatAnimation.h
 * 
 * Author: jreese
 * Date: 2018-19-17
 * 
 * Does an animation of a pulsing heartbeat. 
 * Palette primary color is used for the pulse, and secondary color (or black if none) for the background.
 */

#ifndef ANIMATIONS_HEARTBEATANIMATION_H_
#define ANIMATIONS_HEARTBEATANIMATION_H_

#include <AnimationPattern.h>

class HeartbeatAnimation : public AnimationPattern {
public:
    HeartbeatAnimation(int length, const ColorPalette& palette, int bpm);
    void stepAnimation(CRGB* buffer, int elapsedTime);
    void resetAnimation(CRGB* buffer);

private:
    int bpm;
};

#endif /* ANIMATIONS_HEARTBEATANIMATION_H_ */