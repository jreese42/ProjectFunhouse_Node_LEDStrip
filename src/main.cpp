#include <Arduino.h>

#include <LEDStrip.h>
#include <AnimationController.h>
#include <animations/SolidColorAnimation.h>
#include <animations/MarchingAntsAnimation.h>
#include <animations/HeartbeatAnimation.h>
#include <animations/LightningStormAnimation.h>
#include <animations/RunnerLightsAnimation.h>
#include <animations/AccumulatingSnowAnimation.h>
#include <animations/DancingLightsAnimation.h>
#include <animations/RandomSparklesAnimation.h>
#include <ColorPalette.h>

AnimationController animController;
LEDStrip* ledStrip;

void setup() {
    // ledStrip = new LEDStrip(150*2, 0);
    ledStrip = new LEDStrip(150, 0);
    ledStrip->scaleBrightnessBy(0.4);

    animController = AnimationController(ledStrip);


    // ** Declare Palettes (be sure to declare them with new so they do not go out of scope) ** //
    
    /* Halloween Palettes */
    // ColorPalette* halloween_OrangeAndPurple = new ColorPalette(CRGB(241, 88, 2),
    //                                                       CRGB(124, 16, 173));
    // ColorPalette* halloween_SolidOrange = new ColorPalette(CRGB(241, 88, 2));
    // ColorPalette* halloween_BloodRed = new ColorPalette(CRGB(138, 7, 7));
    // ColorPalette* halloween_LightningStorm = new ColorPalette(CRGB(255, 255, 255),CRGB(0,0,0), CRGB(166,166,236));

    /* Christmas Palettes */
    ColorPalette* xmas_RedAndGreen = new ColorPalette(CRGB(162, 44, 39),CRGB(146,152,103));
    ColorPalette* xmas_RedGreenWhite = new ColorPalette(CRGB(240, 14, 14),CRGB(22,230,22), CRGB(240,240,240));
    ColorPalette* xmas_RedGreenGoldSilver = new ColorPalette(CRGB(230, 22, 22), CRGB(22,230,22), CRGB(230, 160, 22), CRGB(255,255,255));
    ColorPalette* xmas_Snow = new ColorPalette(CRGB(100, 100, 240),CRGB(44,44,120));
    ColorPalette* xmas_YellowLights = new ColorPalette(CRGB(230, 160, 25));


    // ** Create Animations and Apply Palettes ** //

    /* Halloween Animations */
    // MarchingAntsAnimation* anim_2colorAnts = new MarchingAntsAnimation(ledStrip->getBufferLength(), *halloween_OrangeAndPurple, 3, 100, Direction::REVERSE);
    // MarchingAntsAnimation* anim_2colorAnts = new MarchingAntsAnimation(ledStrip->getBufferLength(), *halloween_OrangeAndPurple, 3, 100, Direction::FORWARD);
    // HeartbeatAnimation* anim_redHeartbeat = new HeartbeatAnimation(ledStrip->getBufferLength(), *halloween_BloodRed, 60);
    // HeartbeatAnimation* ap = new HeartbeatAnimation(ledStrip->getBufferLength(), *halloween_OrangeAndPurple, 80);
    // LightningStormAnimation* anim_lightningStorm = new LightningStormAnimation(ledStrip->getBufferLength(), *halloween_LightningStorm);
    // RunnerLightsAnimation* anim_runnerLights = new RunnerLightsAnimation(ledStrip->getBufferLength(), *halloween_SolidOrange, 10, 15, 4, Direction::REVERSE);
    // RunnerLightsAnimation* anim_runnerLights = new RunnerLightsAnimation(ledStrip->getBufferLength(), *halloween_SolidOrange, 5, 10, 4, Direction::REVERSE);

    /* Christmas Animations */
    MarchingAntsAnimation* anim_3colorAnts = new MarchingAntsAnimation(ledStrip->getBufferLength(), *xmas_RedGreenWhite, 3, 100, Direction::FORWARD);
    AccumulatingSnowAnimation* anim_snow = new AccumulatingSnowAnimation(ledStrip->getBufferLength(), *xmas_Snow);
    DancingLightsAnimation* anim_dancingBells = new DancingLightsAnimation(ledStrip->getBufferLength(), *xmas_RedGreenWhite, 5 /*spacing*/, 3 /*jumpDistance*/, 2 /*numBlinks*/, 200 /*fadeTime*/, 100 /*onTime*/, 100 /*offTime*/);
    DancingLightsAnimation* anim_dancingYellowLights = new DancingLightsAnimation(ledStrip->getBufferLength(), *xmas_YellowLights, 5 /*spacing*/, 2 /*jumpDistance*/, 1 /*numBlinks*/, 150 /*fadeTime*/, 150 /*onTime*/, 60 /*offTime*/);
    RandomSparklesAnimation* anim_randomColorSparkles = new RandomSparklesAnimation(ledStrip->getBufferLength(), *xmas_RedGreenGoldSilver);

    animController.addAnimationPattern(anim_3colorAnts); //Add Animations
    animController.addAnimationPattern(anim_snow);
    animController.addAnimationPattern(anim_dancingBells);
    animController.addAnimationPattern(anim_randomColorSparkles);
    animController.addAnimationPattern(anim_dancingYellowLights);
    animController.setCycleMode(AnimationController::CycleModeLoop, 24000);
}

void loop() {
    animController.run();
}