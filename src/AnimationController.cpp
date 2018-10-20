#include <AnimationController.h>
#include <FastLED.h>

AnimationController::AnimationController() :
    cycleTiming(0)
{

}

AnimationController::AnimationController(LEDStrip* ledStrip)
{
    this->ledStrip = ledStrip;
}

void AnimationController::addAnimationPattern(AnimationPattern* ap)
{
    this->animationPatternsList.push_back(ap);
    //For now, just set the animation to this one until cycling is written
    // this->ledStrip->setAnimation(ap);
}

void AnimationController::setCycleMode(CycleMode mode, int timing) {
    this->cycleMode = mode;
    this->cycleTiming = timing;
}

void AnimationController::run()
{
    static int timing = 0;
    static int patternId = 0;

    this->ledStrip->stepAnimation();

    EVERY_N_MILLISECONDS(10) {
        if (timing > 0)
            timing -= 10;
    }

    //once time expires, cycle to the next animation
    if (timing <= 0 && this->cycleTiming != 0) {
        timing = this->cycleTiming;

        switch (this->cycleMode) {
            case CycleMode::CycleModeLoop:
                if (++patternId >= this->animationPatternsList.size()) {
                    patternId = 0;
                }
                this->ledStrip->setAnimation(this->animationPatternsList[patternId]);
                break;
            case CycleMode::CycleModeRandom:
                this->ledStrip->setAnimation(this->animationPatternsList[random8()%this->animationPatternsList.size()]);
                break;

        }
    }

}