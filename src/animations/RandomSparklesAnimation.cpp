#include <animations/RandomSparklesAnimation.h>

RandomSparklesAnimation::RandomSparklesAnimation(int length, const ColorPalette& palette) :
    AnimationPattern(length, palette)
{
    
}

void RandomSparklesAnimation::stepAnimation(CRGB* buffer, int elapsedTime)
{
    static int sparkleChance;

    int brightness = 0; //out of 256
    int position = -1;
    bool doSparkles = false;
    int numSparkles = 1;

    //fade everything towards black
    for (int i = 0; i < this->length; i++) {
        buffer[i] = blend(buffer[i], CRGB::Black, elapsedTime/2);
    }

    //Bright lightning happens slowly, but flashes brighter on average
    if (random8() < sparkleChance) {
        sparkleChance = 0;
        doSparkles = true;
        brightness = (random8() % 128) + 128; //random brightness 50% or greater

        //weighted random value for number of sparkles
        //0-29 (30%) = 1 sparkle, 30-59 (30%) = 2 sparkles, 60-79 (20%) = 3 sparkles, 80 - 94 (15%) 4 sparkles, 95 - 99 (5%) 5 sparkles
        //30% 1, 30% 2, 20% 3, 15% 4, 5% 5
        int seed = random8() % 100;
        if (seed < 30)
            numSparkles = 1;
        else if (seed >= 30 && seed < 60)
            numSparkles = 2;
        else if (seed >= 60 && seed < 80)
            numSparkles = 3;
        else if (seed >= 80 && seed < 95)
            numSparkles = 4;
        else if (seed >= 95)
            numSparkles = 5;

    } else {
        sparkleChance += (elapsedTime * 180) / this->length;
    }

    //determine color and fill
    if (doSparkles) {
        int i = 0;
        for (int i; i < numSparkles; i++) {
            position = random16() % this->length;
            buffer[position] = this->palette.getColor((random8() % this->palette.paletteSize())); //pick random color
            buffer[position].fadeToBlackBy(256 - brightness);
        }
    }
}

void RandomSparklesAnimation::resetAnimation(CRGB* buffer) {

}