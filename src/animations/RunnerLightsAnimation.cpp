#include <animations/RunnerLightsAnimation.h>

RunnerLightsAnimation::RunnerLightsAnimation(int length, const ColorPalette& palette, int speed, int spacing, int tailLength, Direction direction) :
    AnimationPattern(length, palette), speed(speed), spacing(spacing), tailLength(tailLength), direction(direction)
{
    
}

void RunnerLightsAnimation::stepAnimation(CRGB* buffer, int elapsedTime)
{
    static int current_offset = 0;
    static int update_timer = 0;

    update_timer += elapsedTime;

    //fade everything towards the secondary color. Amount depends on the tail length
    for (int i = 0; i < this->length; i++) {
        buffer[i] = blend(buffer[i], this->palette.getSecondary(), 256/this->tailLength);
    }

    //calculate bolt positions and redraw them
    for (int i = current_offset; i < this->length; i += this->spacing) {
        buffer[i] = this->palette.getPrimary();
    }

    //update the offset to move the dots down the line
    if (this->direction == Direction::FORWARD) {
        if (++current_offset >= spacing) {
            current_offset = 0;
        }
    } else if (this->direction == Direction::REVERSE) {
        if (--current_offset <= 0) {
            current_offset = spacing;
        }
    }
}