# LED Strip Node for Project Funhouse
## Hardware
### MCU
This project uses an ESP8266 as the main controller. I use a NodeMCU v2, although this code will probably run on any other ESP8266-based controller.

### LED Strip
By default, the code is configured to use a NeoPixel strip. This should work with any LED Strip that can be controlled with FastLED, but I have tested it only with ws2812b lights.
  
### Everything Else
You will also need to power the MCU and LED Strip. For a single LED strip, a NodeMCU v2 can supply enough current, but for larger setups you may need to add a separate power supply.

## Dependencies
This library uses FastLED to control the LED Strip. It is recommended to set this project up using PlatformIO and use the latest version of FastLED installed through PlatformIO.

## How to Use
  ### General Concepts

  #### Animations
The core unit is an Animation. Each animation implements ``stepAnimation`` which is called to move the animation forward. The timing of how often the animation is stepped is managed by the LEDStrip object, so the Animation object should always step the animation forward without any regard for timing. If timing is important for the animation, ``stepAnimation`` includes a timing parameter which specifies the number of milliseconds which have passed since the last call. The Animation object is persistent so animations can be stateful. Animations can also be made configurable through constructor arguments, which is useful for allowing variants of animations which run in reverse, or at a different speed for example.

  #### Palettes
A palette defines an ordered set of colors. This is used to make the Animations configurable. The Animation object is responsible for using the palette in a reasonable way. For instance, consider two animations and three palettes.

The palettes are: 

| Name | Colors |
| ---- | ------ |
| Halloween | Orange, Purple, and Black |
| Christmas | Red, Green, and White | 
| Just Blue | Blue |

The Animations are:

| Name | Configurable Options | Description |
| ---- | -------------------- | ----------- |
| Alternate Colors | cycleDuration | Cycles through all colors in the palette, displaying each one for a duration set by cycleDuration. |
| Lightning Storm | None | Simulates a lightning storm. |

The first animation is simple and just alternates all LED through a set of colors. With the first two palettes, this simple animation can be themed for two different holidays very easily. With the third palette, this animation can support showing a single color without alternating as well.

The second animation is more complex and not configurable, but demonstrates a more complex use of the palette. In this case, the Lightning Storm animation uses the first color for the flashes of lightning, and the second color as a background color. Optionally, if a third color is defined, then the animation will use that color for a "raindrop" effect that plays alongside the lightning. The raindrop effect can be disabled by not defining the third color, or setting it to black. In this case, the "Christmas" palette would result in red lightning over a green background with white raindrops, the "Halloween" palette would be orange lightning over a purple background with no raindrops, and the "Just Blue" palette would be blue flashes of lightning with a black background and no raindrops.

  #### LED Strip
The LED Strip objects holds the main handle on the FastLED object. It can be adjusted to support any LED strip that FastLED can control.

  #### Animation Controller
The animation controller is the programmer's inteface for using the system. In the main file, you should declare a controller as well as any palettes and animations. You can then register the animations with the controller and set up how the animations will be cycled. The controller should be serviced in the main loop.