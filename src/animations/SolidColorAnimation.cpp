#include <animations/SolidColorAnimation.h>

SolidColorAnimation::SolidColorAnimation(int length, const ColorPalette& palette) :
    AnimationPattern(length, palette)
{
    //take in color
}

void SolidColorAnimation::stepAnimation(CRGB* buffer, int elapsedTime)
{
    //no need to do anything, the color is static
}

void SolidColorAnimation::resetAnimation(CRGB* buffer) {
    fill_solid(buffer, this->length, this->palette.getPrimary());
}