/** GlitterModifier.h
 * 
 * Author: jreese
 * Date: 2018-11-27
 * 
 * Modifier which operates on another Animation Pattern and adds a sparkling glitter effect
 */

#ifndef ANIMATIONS_GLITTERMODIFIER_H_
#define ANIMATIONS_GLITTERMODIFIER_H_

#include <AnimationPattern.h>

class GlitterModifier : public AnimationPattern {
public:
    GlitterModifier(AnimationPattern* ap);
    void stepAnimation(CRGB* buffer, int elapsedTime);
    void resetAnimation(CRGB* buffer);
    
private:
    AnimationPattern* ap;
};

#endif /* ANIMATIONS_GLITTERMODIFIER_H_ */