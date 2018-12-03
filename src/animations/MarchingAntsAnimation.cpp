#include <animations/MarchingAntsAnimation.h>

MarchingAntsAnimation::MarchingAntsAnimation(int length, const ColorPalette& palette, int antSpacing, int millisRate, Direction direction) :
    AnimationPattern(length, palette), antSpacing(antSpacing), millisRate(millisRate), direction(direction)
{
    
}

void MarchingAntsAnimation::stepAnimation(CRGB* buffer, int elapsedTime)
{
    static uint8_t curr_offset = 0;
    static uint8_t color_offset = 0;

    EVERY_N_MILLISECONDS(this->millisRate) { //todo replace this with elapsedTime
        int color_idx = 0;

        //set current pixels to black
        for (int i = curr_offset; i < this->length; i+=this->antSpacing) {
            buffer[i] = CRGB::Black;
        }
    
        if (this->direction == Direction::FORWARD) {      
            if (++curr_offset >= this->antSpacing) {
                curr_offset = 0;
                color_offset++; //Swap the colors to give the illusion that the colors move down the strip
                if (color_offset > this->palette.paletteSize())
                    color_offset = 0;
            }
        } else if (this->direction == Direction::REVERSE) {
            if (curr_offset-- == 0) {
                curr_offset = this->antSpacing-1;
                color_offset++; //Swap the colors to give the illusion that the colors move down the strip
                if (color_offset > this->palette.paletteSize())
                    color_offset = 0;
            }
        }

        //set new pixels to colors from palette
        for (int i = curr_offset; i < this->length; i+=this->antSpacing) {
            buffer[i] = this->palette.getColor((color_idx + color_offset) % this->palette.paletteSize());
            color_idx++;
        }

    }
}

void MarchingAntsAnimation::resetAnimation(CRGB* buffer) {

}