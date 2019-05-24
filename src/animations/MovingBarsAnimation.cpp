#include <animations/MovingBarsAnimation.h>

MovingBarsAnimation::MovingBarsAnimation(int length, const ColorPalette& palette, int barSpeed, int numBars, int fadeRate, Direction direction) :
    AnimationPattern(length, palette), barSpeed(barSpeed), numBars(numBars), fadeRate(fadeRate), direction(direction), 
    barWidth(length/numBars), 
    currOffset(0),
    resetOffset(barWidth * this->palette.paletteSize())
{

}

void MovingBarsAnimation::stepAnimation(CRGB* buffer, int elapsedTime)
{
    //rotate the background buffer by barSpeed in Direction
    if (this->direction == Direction::REVERSE) {
        this->currOffset -= this->barSpeed * elapsedTime / 1000;        
        if (this->currOffset < 0)
            this->currOffset = this->resetOffset;
    } else {
        this->currOffset += this->barSpeed * elapsedTime / 1000;
        if (this->currOffset > this->resetOffset)
            this->currOffset = 0;
    }

    for (int i = 0; i < this->length; i++) {
        int color_idx = ((int)((i+this->currOffset) / this->barWidth));
        CRGB targetColor = CRGB::Black;
        if (this->direction == Direction::FORWARD) targetColor = this->palette.getColor((color_idx % this->palette.paletteSize()));
        else if (this->direction == Direction::REVERSE) targetColor = this->palette.getColor(this->palette.paletteSize() - (color_idx % this->palette.paletteSize()) - 1);
        if (buffer[i] != targetColor) {
            int fadeAmount = 256*elapsedTime/fadeRate;
            if (fadeAmount > 256)
                fadeAmount = 256;
            buffer[i] = blend(buffer[i], targetColor, (uint8_t)fadeAmount);
        }
    }

}

void MovingBarsAnimation::resetAnimation(CRGB* buffer) {

}