#include <animations/SolidColorAnimation.h>

SolidColorAnimation::SolidColorAnimation(int length, const ColorPalette& palette) :
    AnimationPattern(length, palette)
{
    //take in color
}

void SolidColorAnimation::stepAnimation(CRGB* buffer, int elapsedTime)
{
    //fill color and return
    fill_solid(buffer, this->length, this->palette.getPrimary());
}