#include <animations/MarchingAntsAnimation.h>

MarchingAntsAnimation::MarchingAntsAnimation(int length, const ColorPalette& palette, int antSpacing, int millisRate, Direction direction) :
    AnimationPattern(length, palette), antSpacing(antSpacing), millisRate(millisRate), direction(direction)
{
    
}

void MarchingAntsAnimation::stepAnimation(CRGB* buffer, int elapsedTime)
{
    static uint8_t curr_offset = 0;
    static bool swapColors = false;

    EVERY_N_MILLISECONDS(this->millisRate) { //todo replace this with elapsedTime
        int color_idx = 0;

        //set current pixels to black
        for (int i = curr_offset; i < this->length; i+=this->antSpacing) {
            buffer[i] = CRGB::Black;
        }
    
        if (this->direction == Direction::FORWARD) {      
            if (++curr_offset >= this->antSpacing) {
                curr_offset = 0;
                swapColors = !swapColors; //Swap the colors to give the illusion that the colors move down the strip
            }
        } else if (this->direction == Direction::REVERSE) {
            if (curr_offset-- == 0) {
                curr_offset = this->antSpacing-1;
                swapColors = !swapColors; //Swap the colors to give the illusion that the colors move down the strip
            }
        }

        //set new pixels to colors from palette
        for (int i = curr_offset; i < this->length; i+=this->antSpacing) {
            if (swapColors)
                buffer[i] = (color_idx++)&0x01 ? this->palette.getSecondary() : this->palette.getPrimary();
            else
                buffer[i] = (color_idx++)&0x01 ? this->palette.getPrimary() : this->palette.getSecondary();
        }

    }
}