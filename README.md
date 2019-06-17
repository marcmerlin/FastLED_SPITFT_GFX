FastLED_SPITFT::GFX, TFT Screens Like SSD1331, ST7735, or ILI9341 with Adafruit GFX and FastLED APIs
====================================================================================================

Blog post with more pictures/details: 
http://marc.merlins.org/perso/arduino/post_2019-05-26_FastLED_SPITFT_GFX-on-top-of-Framebuffer_GFX-_SPI-TFTs-like-SSD1331-or-ILI9341_.html

Adafruit_GFX and FastLED-compatible library for TFT displays like SSD1331 or ILI9341.

Adafruit provides basic GFX support for them, but this library maps a FastLED
RGB888 (24bit) framebuffer onto those chips (downsampling to 16bit RGB565 color resolution 
as needed), as well as allows rotating the display when it's not supported like for SSD1331.

![image](https://user-images.githubusercontent.com/1369412/58442520-cdf4b580-80a0-11e9-8612-17fdab509714.png)

SSD1331 (96x64) vs ST7735 (128x128) vs ST7735 (160x128) vs ILI9341 (320x240):
![image](https://user-images.githubusercontent.com/1369412/59638838-4d106300-910e-11e9-82a2-65223ead57df.png)
(note that the ESP32 was sending ST7735 160x128 SPI which didn't work at all on SSD1331 and not quite on the ILI screen which requires its own protocol)
* 128x160 video demo of TableME: https://www.youtube.com/watch?v=0-Fq1s2xQbM
* 128x128 video demo of Aurora: https://www.youtube.com/watch?v=YwbfFoFp0ko

This is the same 96x64 display and demo between a P3 RGBPanel and an SSD1331:
![image](https://user-images.githubusercontent.com/1369412/58442645-5c693700-80a1-11e9-8005-f57b7da63482.png)

The big thing to note is that this library has to store the entire framebuffer in memory, so
you'll need a processor with more RAM (like ESP8266, ESP32, Teensy, etc...), but then you benefit
from having the entire framebuffer in memory which is used for code that apply transformations
to the entire framebuffer like fading or rotations.

https://github.com/marcmerlin/Framebuffer_GFX/blob/master/README.md details the 3 APIs available
to you and why you'd want to use this layer on top of the SSD1331 driver.  
Similarly this driver works great with ST7735 based TFTs (128x128 or 128x160).
It does also work with ILI9341, but memory becomes an issue as the framebuffer uses 225KB of RAM which only fits on a teensy 3.5/3.6 for me (too big for ESP32) and leaves very little room to run other code.

This library requires FastLED and Adafruit_GFX libraries as well as this base class library:
- https://github.com/marcmerlin/Framebuffer_GFX
Please look at the Framebuffer_GFX page for details on how the APIs work and you can also look the example demo code:
- https://github.com/marcmerlin/FastLED_NeoMatrix/blob/master/examples/MatrixGFXDemo/MatrixGFXDemo.ino

You can find a lot of demo code here:
https://github.com/marcmerlin/FastLED_NeoMatrix_SmartMatrix_LEDMatrix_GFX_Demos as well as
a big integrated demo here: https://github.com/marcmerlin/NeoMatrix-FastLED-IR

This library requires one of:
- https://github.com/adafruit/Adafruit-SSD1331-OLED-Driver-Library-for-Arduino
- https://github.com/adafruit/Adafruit_ILI9341
- or another Adafruit SPI backed TFT library

and these:
- https://github.com/marcmerlin/Framebuffer_GFX (base class)
- https://github.com/adafruit/Adafruit-GFX-Library
- https://github.com/FastLED/FastLED  
- https://github.com/marcmerlin/LEDMatrix is optional if you have code that uses that API
