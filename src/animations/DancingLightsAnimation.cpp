#include <animations/DancingLightsAnimation.h>

DancingLightsAnimation::DancingLightsAnimation(int length, const ColorPalette& palette, int spacing, int jumpDistance, int numBlinks, int fadeTime, int onTime, int offTime) :
    spacing(spacing), jumpDistance(jumpDistance), numBlinks(numBlinks), fadeTime(fadeTime), 
    onTime(onTime), offTime(offTime), maxBrightness(240), AnimationPattern(length, palette)
{
    
}

void DancingLightsAnimation::stepAnimation(CRGB* buffer, int elapsedTime)
{
    static DancingLightsDirectionState animState_direction = DancingLightsDirectionState::LEFT;
    static DancingLightsFlashState animState_flash = DancingLightsFlashState::FADE_UP;
    static int anim_timer = -1;
    static int blink_count = 0;

    //calculate start position
    int start_index = (animState_direction == DancingLightsDirectionState::LEFT) ? 0:this->jumpDistance;
    int current_brightness = 0;

    //calculate brightness by state, fadeTime, onTime, etc. maps to 0-maxBrightness
    if (animState_flash == DancingLightsFlashState::OFF) {
        current_brightness = 0;
    }
    else if (animState_flash == DancingLightsFlashState::ON) {
        current_brightness = this->maxBrightness;
    }
    else if (animState_flash == DancingLightsFlashState::FADE_UP) {
        current_brightness = (this->fadeTime - anim_timer) * (this->maxBrightness) / (this->fadeTime);
    }
    else if (animState_flash == DancingLightsFlashState::FADE_DOWN) {
        current_brightness = (anim_timer) * (this->maxBrightness) / (this->fadeTime);
    }

    //fill colors, alternating between all colors in the palette
    int color_idx = 0;
    for (int i = start_index; i < this->length; i+=this->spacing) {
        buffer[i] = this->palette.getColor((color_idx % this->palette.paletteSize()));
        buffer[i].fadeToBlackBy(255 - current_brightness);
        
        color_idx++;
    }

    if (anim_timer == -1 && animState_direction == DancingLightsDirectionState::LEFT && animState_flash == DancingLightsFlashState::FADE_UP) {
        //initialization corner case
        anim_timer = this->fadeTime;
    } else if (anim_timer == 0) {
        //Timer expired. Progress State and reset timer.
        if (animState_flash == DancingLightsFlashState::FADE_UP) {
            animState_flash = DancingLightsFlashState::ON;
            anim_timer = this->onTime;
        }
        else if (animState_flash == DancingLightsFlashState::ON) {
            animState_flash = DancingLightsFlashState::FADE_DOWN;
            anim_timer = this->fadeTime;
        }
        else if (animState_flash == DancingLightsFlashState::FADE_DOWN) {
            animState_flash = DancingLightsFlashState::OFF;
            anim_timer = this->offTime;
        }
        else if (animState_flash == DancingLightsFlashState::OFF) {
            animState_flash = DancingLightsFlashState::FADE_UP;
            anim_timer = this->fadeTime;
            fill_solid(buffer, this->length, CRGB::Black);

            //end of the cycle, so count up blinks
            //if we're at numBlinks, also switch direction
            if (++blink_count >= this->numBlinks) {
                blink_count = 0;
                animState_direction = (animState_direction == DancingLightsDirectionState::LEFT) ? DancingLightsDirectionState::RIGHT : DancingLightsDirectionState::LEFT;
            }
        }
    }

    if (anim_timer > elapsedTime) {
        anim_timer -= elapsedTime;
    } else {
        anim_timer = 0;
    }
}

void DancingLightsAnimation::resetAnimation(CRGB* buffer) {
    fill_solid(buffer, this->length, CRGB::Black);
}