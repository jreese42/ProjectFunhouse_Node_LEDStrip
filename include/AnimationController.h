/** AnimationController.h
 * 
 * Author: jreese
 * Date: 2018-10-17
 * 
 * Controller object which holds the objects needed to build and display animations on an LED Strip.
 */

#ifndef ANIMATION_CONTROLLER_H_
#define ANIMATION_CONTROLLER_H_

#include <AnimationPattern.h>

#include <LEDStrip.h>
#include <vector>


class AnimationController {
public:
    enum CycleMode {
        CycleModeLoop,
        CycleModeRandom,
    };

    AnimationController();
    AnimationController(LEDStrip* ledStrip);

    void addAnimationPattern(AnimationPattern* ap);
    void setCycleMode(CycleMode mode, int timing);

    void run();



private:
    LEDStrip* ledStrip;

    CycleMode cycleMode;
    int cycleTiming;
    std::vector<AnimationPattern*> animationPatternsList;
};

#endif /* ANIMATION_CONTROLLER_H_ */