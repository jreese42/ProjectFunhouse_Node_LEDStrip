#define FASTLED_ESP8266_D1_PIN_ORDER
#define FASTLED_ALLOW_INTERRUPTS 0
#include <LEDStrip.h>

#include <FastLED.h>

#define DATA_PIN 5

LEDStrip::LEDStrip() :
    length(0), deadZoneLength(0)
{

}

LEDStrip::LEDStrip(int length, int deadZoneLength) :
    length(length), deadZoneLength(deadZoneLength)
{
    this->buffer = new CRGB[length];
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(this->buffer, getBufferLength());
}

void LEDStrip::setAnimation(AnimationPattern* ap) 
{
    this->animationPattern = ap;
    this->animationPattern->resetAnimation(getBuffer());
}

void LEDStrip::stepAnimation()
{
    //Todo make 60ms not a magic number
    EVERY_N_MILLISECONDS(60) {
        if (this->animationPattern)
            this->animationPattern->stepAnimation(getBuffer(), 60);

        FastLED.show();
    }
}

int LEDStrip::getBufferLength() 
{
    return this->length - this->deadZoneLength;
}

CRGB* LEDStrip::getBuffer()
{
    return this->buffer + this->deadZoneLength;
}

/** Accepts a scale value as 0.0-1.0. All output to the LED strip will be scaled by this amount. **/
void LEDStrip::scaleBrightnessBy(float scale) {
    if (scale >= 0.0 && scale <= 1.0) {
        uint8_t scaledMax = 255 * scale;
        FastLED.setBrightness(scaledMax);
    }
}