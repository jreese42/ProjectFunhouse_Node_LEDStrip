#include <ColorPalette.h>

ColorPalette::ColorPalette() : 
    mPaletteSize(0)
{

}

ColorPalette::ColorPalette(CRGB c1) :
    mPaletteSize(1)
{
    this->palette = new CRGB[1];
    this->palette[0] = c1;
}
ColorPalette::ColorPalette(CRGB c1, CRGB c2) :
    mPaletteSize(2)
{
    this->palette = new CRGB[2];
    this->palette[0] = c1;
    this->palette[1] = c2;
}

ColorPalette::ColorPalette(CRGB c1, CRGB c2, CRGB c3) :
    mPaletteSize(3)
{
    this->palette = new CRGB[3];
    this->palette[0] = c1;
    this->palette[1] = c2;
    this->palette[2] = c3;
}

ColorPalette::ColorPalette(CRGB c1, CRGB c2, CRGB c3, CRGB c4) :
    mPaletteSize(3)
{
    this->palette = new CRGB[4];
    this->palette[0] = c1;
    this->palette[1] = c2;
    this->palette[2] = c3;
    this->palette[3] = c4;
}

ColorPalette::~ColorPalette()
{
    delete this->palette;
}

//Track # of colors set
int ColorPalette::paletteSize()
{
    return this->mPaletteSize;
}

//Fetch color by index
CRGB ColorPalette::getColor(uint8_t index)
{
    if (index < this->mPaletteSize) {
        return this->palette[index];
    } else {
        return CRGB::Black;
    }
}

CRGB ColorPalette::getPrimary()
{
    if (this->mPaletteSize > 0) {
        return this->palette[0];
    } else {
        return CRGB::Black;
    }
}

CRGB ColorPalette::getSecondary()
{
    if (this->mPaletteSize > 1) {
        return this->palette[1];
    } else {
        return CRGB::Black;
    }
}