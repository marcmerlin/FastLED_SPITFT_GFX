/*-------------------------------------------------------------------------
  Arduino library based on Adafruit_Neomatrix but modified to work with SmartMatrix
  by Marc MERLIN <marc_soft@merlins.org>

  You should have received a copy of the GNU Lesser General Public
  License along with NeoMatrix.  If not, see
  <http://www.gnu.org/licenses/>.
  -------------------------------------------------------------------------*/

#include <FastLED_SPITFT_GFX.h>

FastLED_SPITFT_GFX::FastLED_SPITFT_GFX(CRGB *fb, uint8_t fbw, uint8_t fbh, 
	lcdw, lcdh, Adafruit_SPITFT* spitft): 
  Framebuffer_GFX(fb, fbw, fbh, NULL) { 
      _spitft = spitft;
}


void FastLED_SPITFT_GFX::show() {
#if 0
    for (uint16_t line = 0; line < lcdh; line++) {
	for (uint16_t i = 0; i < lcdw; i++) {
	    _line[i] = Color24to16(CRGBtoint32(_fb[i*matrixWidth + line]));
	}

	_spitft->startWrite();
	_spitft->writePixels(_line, lcdw);
	_spitft->endWrite();
	yield();
    }
#endif
    for (uint16_t line = 0; line < lcdh; line++) {
	for (uint16_t i = 0; i < lcdw; i++) {
	    _line[i] = Color24to16(CRGBtoint32(_fb[line*matrixWidth + i]));
	}

	yield();
	_spitft->startWrite();
	_spitft->writePixels(_line, lcdw);
	_spitft->endWrite();
    }
}

// vim:sts=4:sw=4
