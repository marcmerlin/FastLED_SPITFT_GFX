/*--------------------------------------------------------------------
  Arduino library based on Adafruit_Neomatrix but modified to work with SmartMatrix
  by Marc MERLIN <marc_soft@merlins.org>

  Original notice and license from Adafruit_Neomatrix:
  NeoMatrix is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as
  published by the Free Software Foundation, either version 3 of
  the License, or (at your option) any later version.

  NeoMatrix is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with NeoMatrix.  If not, see
  <http://www.gnu.org/licenses/>.
  --------------------------------------------------------------------*/

#ifndef _FastLED_SPITFT_GFX_H_
#define _FastLED_SPITFT_GFX_H_
#include "Framebuffer_GFX.h"
#include "Adafruit_SPITFT.h"
#include "FastLED.h"

class FastLED_SPITFT_GFX : public Framebuffer_GFX {
  public:
    FastLED_SPITFT_GFX(CRGB *, uint8_t w, uint8_t h, Adafruit_SPITFT* spitft);
    void show();

  protected:
    Adafruit_SPITFT* _spitft;

  private:
    static const uint16_t lcdw = 96;
    static const uint16_t lcdh = 64;
    // temporary storage for rotation and 24bit to 16bit convertion
    uint16_t _line[lcdw];
};

#endif // _FastLED_SPITFT_GFX_H_
// vim:sts=4:sw=4
