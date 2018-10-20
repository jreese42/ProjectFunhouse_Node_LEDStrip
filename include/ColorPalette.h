/** ColorPalette.h
 * 
 * Author: jreese
 * Date: 2018-10-17
 * 
 * Structure which defines a color palette. Used by an AnimationPattern to draw colors to an LED Strip.
 */

#ifndef COLOR_PALETTE_H_
#define COLOR_PALETTE_H_

#include <FastLED.h>

class ColorPalette {
public:
    //Track up to 16 colors
    ColorPalette();
    ColorPalette(CRGB c1);
    ColorPalette(CRGB c1, CRGB c2);
    ColorPalette(CRGB c1, CRGB c2, CRGB c3);
    ~ColorPalette();
    //Track # of colors set
    int paletteSize();
    //Fetch color by ID
    CRGB getColor(uint8_t index);
    CRGB getPrimary();
    CRGB getSecondary();

private:
    int mPaletteSize;
    CRGB* palette;
};

#endif /* COLOR_PALETTE_H_ */