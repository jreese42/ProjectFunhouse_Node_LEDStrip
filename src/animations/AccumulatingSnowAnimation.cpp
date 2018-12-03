#include <animations/AccumulatingSnowAnimation.h>

AccumulatingSnowAnimation::AccumulatingSnowAnimation(int length, const ColorPalette& palette) :
    AnimationPattern(length, palette)
{
    
}

void AccumulatingSnowAnimation::stepAnimation(CRGB* buffer, int elapsedTime)
{
    static int fadeTimer = 0;
    static int snowfallChance = 0;

    if (fadeTimer > 80) {
        while (fadeTimer > 80) {
            fadeTimer -= 80;
            for (int i = 0; i < this->length; i++) {
                buffer[i] = blend(buffer[i], this->palette.getSecondary(), 1);
            }
        }
    } else {
        fadeTimer += elapsedTime;
    }

    //Occassionally light random pixels for snowfall effect
    if (random8()%100 < snowfallChance) {
        snowfallChance = 0;
        int index = random16() % this->length;
        buffer[index] = this->palette.getPrimary();
    } else {
        snowfallChance += (elapsedTime * 80) / this->length;
    }
}

void AccumulatingSnowAnimation::resetAnimation(CRGB* buffer) {
    fill_solid(buffer, this->length, this->palette.getSecondary());
}