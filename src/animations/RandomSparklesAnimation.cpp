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

    //fade everything towards black
    for (int i = 0; i < this->length; i++) {
        buffer[i] = blend(buffer[i], CRGB::Black, elapsedTime);
    }

    //Bright lightning happens slowly, but flashes brighter on average
    if (random8() < sparkleChance) {
        sparkleChance = 0;
        position = random16() % this->length;
        brightness = (random8() % 128) + 128; //random brightness 50% or greater
    } else {
        sparkleChance += (elapsedTime * 80) / this->length;
    }

    //determine color and fill
    if (position != -1) {
        buffer[position] = this->palette.getColor((random8() % this->palette.paletteSize())); //pick random color
        buffer[position].fadeToBlackBy(256 - brightness);
    }
}

void RandomSparklesAnimation::resetAnimation(CRGB* buffer) {

}