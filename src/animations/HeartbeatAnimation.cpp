#include <animations/HeartbeatAnimation.h>

HeartbeatAnimation::HeartbeatAnimation(int length, const ColorPalette& palette, int bpm) :
    AnimationPattern(length, palette), bpm(bpm)
{
    
}

void HeartbeatAnimation::stepAnimation(CRGB* buffer, int elapsedTime)
{
    static int next_flash_timer = (this->bpm * 1000) / 60;
    static bool downbeat = true;

    //fade everything towards the secondary color
    for (int i = 0; i < this->length; i++) {
        buffer[i] = blend(buffer[i], this->palette.getSecondary(), elapsedTime);
    }

    for (int i = 0; i < elapsedTime; i++) {


        //if the timer is expired, do a flash then reset timer
        if (next_flash_timer <= 0) {
            fill_solid(buffer, this->length, this->palette.getPrimary());

            downbeat = !downbeat;
            if (downbeat)
                next_flash_timer = (this->bpm * 1000) / 60;
            else
                next_flash_timer = 300; //every second flash happens quickly, giving the "heartbeat" effect
        }
        next_flash_timer--;
    }
}