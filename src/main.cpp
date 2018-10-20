#include <Arduino.h>

#include <LEDStrip.h>
#include <AnimationController.h>
#include <animations/SolidColorAnimation.h>
#include <animations/MarchingAntsAnimation.h>
#include <animations/HeartbeatAnimation.h>
#include <animations/LightningStormAnimation.h>
#include <animations/RunnerLightsAnimation.h>
#include <ColorPalette.h>

AnimationController animController;
LEDStrip* ledStrip;

void setup() {
    ledStrip = new LEDStrip(150, 5);

    animController = AnimationController(ledStrip);

    //Declare Palettes (be sure to declare them with new so they do not go out of scope)
    ColorPalette* halloween_OrangeAndPurple = new ColorPalette(CRGB(241, 88, 2),
                                                          CRGB(124, 16, 173));
    ColorPalette* halloween_SolidOrange = new ColorPalette(CRGB(241, 88, 2));
    ColorPalette* halloween_BloodRed = new ColorPalette(CRGB(138, 7, 7));
    ColorPalette* halloween_LightningStorm = new ColorPalette(CRGB(255, 255, 255),CRGB(0,0,0), CRGB(166,166,236));

    //Create Animations and Apply Palettes
    // SolidColorAnimation* ap = new SolidColorAnimation(ledStrip->getBufferLength(),*halloween_OrangeAndPurple);
    MarchingAntsAnimation* anim_2colorAnts = new MarchingAntsAnimation(ledStrip->getBufferLength(), *halloween_OrangeAndPurple, 3, 100, Direction::REVERSE);
    HeartbeatAnimation* anim_redHeartbeat = new HeartbeatAnimation(ledStrip->getBufferLength(), *halloween_BloodRed, 60);
    // HeartbeatAnimation* ap = new HeartbeatAnimation(ledStrip->getBufferLength(), *halloween_OrangeAndPurple, 80);
    LightningStormAnimation* anim_lightningStorm = new LightningStormAnimation(ledStrip->getBufferLength(), *halloween_LightningStorm);
    RunnerLightsAnimation* anim_runnerLights = new RunnerLightsAnimation(ledStrip->getBufferLength(), *halloween_SolidOrange, 10, 15, 4, Direction::REVERSE);

    animController.addAnimationPattern(anim_runnerLights); //Add Animations
    animController.addAnimationPattern(anim_lightningStorm);
    animController.addAnimationPattern(anim_2colorAnts);
    animController.addAnimationPattern(anim_redHeartbeat);
    animController.setCycleMode(AnimationController::CycleModeLoop, 13000);
}

void loop() {
    animController.run();
}