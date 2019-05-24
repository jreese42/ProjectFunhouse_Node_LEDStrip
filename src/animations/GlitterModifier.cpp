#include <animations/GlitterModifier.h>

GlitterModifier::GlitterModifier(AnimationPattern* ap) :
    ap(ap), AnimationPattern(length, palette)
{
    //FOr now this just applies the glitter on top of the buffer
    //but maybe it should maintain two separate buffers and merge them so it fades separately
}

void GlitterModifier::stepAnimation(CRGB* buffer, int elapsedTime)
{
    //step colors using animation pattern

    fill_solid(buffer, this->length, this->palette.getPrimary());
}

void GlitterModifier::resetAnimation(CRGB* buffer) {

}