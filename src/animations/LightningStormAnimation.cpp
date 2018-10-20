#include <animations/LightningStormAnimation.h>

LightningStormAnimation::LightningStormAnimation(int length, const ColorPalette& palette) :
    AnimationPattern(length, palette)
{
    
}

void LightningStormAnimation::stepAnimation(CRGB* buffer, int elapsedTime)
{
    static int lightningChanceCounterBright;
    static int lightningChanceCounterDim;
    static int rainChanceCounter;

    int endBrightness = 0; //out of 256

    //fade everything towards the secondary color
    for (int i = 0; i < this->length; i++) {
        buffer[i] = blend(buffer[i], this->palette.getSecondary(), elapsedTime);
    }

    //Dim lightning happens often, but flashes brighter on average
    if (random16() < lightningChanceCounterDim) { 
        lightningChanceCounterDim = 0;
        endBrightness = random8() % 128; //brightness is 50% or less
    } else {
        lightningChanceCounterDim += elapsedTime;
    }

    //Bright lightning happens slowly, but flashes brighter on average
    if (random16() < lightningChanceCounterBright) {
        lightningChanceCounterBright = 0;
        endBrightness = (random8() % 128) + 128; //brightness is 50% or greater. Always overrides dim lightning.
    } else {
        lightningChanceCounterBright += elapsedTime/2;
    }

    //Occassionally set random pixels to the third color (rain). Use primary color if not third color.
    if (random8() < rainChanceCounter) {
        rainChanceCounter = 0;
        int index = random16() % this->length;
        if (this->palette.paletteSize() > 2)
            buffer[index] = this->palette.getColor(2);
        else
            buffer[index] = this->palette.getPrimary();
    } else {
        rainChanceCounter += elapsedTime;
    }

    //determine color and fill
    if (endBrightness != 0) {
        CRGB color = blend(this->palette.getPrimary(), this->palette.getSecondary(), endBrightness);
        fill_solid(buffer, this->length, color);
    }
}