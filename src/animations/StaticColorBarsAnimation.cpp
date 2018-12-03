#include <animations/StaticColorBarsAnimation.h>

StaticColorBarsAnimation::StaticColorBarsAnimation(int length, const ColorPalette& palette, int barWidth) :
    barWidth(barWidth), startupTimer(0), startupTime(5000), AnimationPattern(length, palette)
{
    
}

void StaticColorBarsAnimation::stepAnimation(CRGB* buffer, int elapsedTime)
{
    if (this->startupTimer > 0) {
        //fade in at startup. Colors are the same, but blend it instead of setting it.
        for (int i = 0; i < this->length; i++) {
            int bar_id = this->barWidth / i;
            CRGB color = this->palette.getColor((bar_id % this->palette.paletteSize()));
            buffer[i] = blend(buffer[i], color, 256/this->startupTime);
            
        }

        if (this->startupTimer > elapsedTime) {
            this->startupTimer -= elapsedTime;
        } else {
            this->startupTimer = 0;
        }

    } else {
        //not in startup fade, so fill colors, alternating between all colors in the palette
        int color_idx = 0;
        for (int i = 0; i < this->length; i+=this->barWidth) {
            CRGB color = this->palette.getColor((color_idx % this->palette.paletteSize()));
            fill_solid(buffer + i, this->barWidth, color);
            
            color_idx++;
        }
    }
}

void StaticColorBarsAnimation::resetAnimation(CRGB* buffer) {
    // this->startupTimer = this->startupTime;
}