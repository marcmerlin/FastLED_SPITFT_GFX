/*-------------------------------------------------------------------------
  Arduino library based on Adafruit_Neomatrix but modified to work with SmartMatrix
  by Marc MERLIN <marc_soft@merlins.org>

  You should have received a copy of the GNU Lesser General Public
  License along with NeoMatrix.  If not, see
  <http://www.gnu.org/licenses/>.
  -------------------------------------------------------------------------*/

#include <FastLED_SPITFT_GFX.h>

FastLED_SPITFT_GFX::FastLED_SPITFT_GFX(CRGB *fb, const uint16_t fbw, const uint16_t fbh, 
	const uint16_t tftw, const uint16_t tfth, Adafruit_SPITFT* spitft, uint8_t rot): 
  Framebuffer_GFX(fb, fbw, fbh, NULL), _tftw(tftw), _tfth(tfth) { 
      rotation = rot;
      _spitft = spitft;
}

void FastLED_SPITFT_GFX::begin() {
    uint16_t ms = _tftw * 2;
    Serial.print("Malloc FastLED_SPITFT_GFX _line for transpositions, bytes: ");
    Serial.println(ms);
    while ((_line = (uint16_t *) malloc(ms)) == NULL) Serial.println("malloc failed");
    Framebuffer_GFX::begin();
    Framebuffer_GFX::show_free_mem();
}


void FastLED_SPITFT_GFX::show() {
    switch(rotation) {
    case 0:
	for (uint16_t tftline = 0; tftline < _tfth; tftline++) {
	    for (uint16_t i = 0; i < _tftw; i++) {
		_line[i] = Color24to16(CRGBtoint32(_fb[tftline*matrixWidth + i]));
	    }

	    yield();
	    _spitft->startWrite();
	    _spitft->writePixels(_line, _tftw);
	    _spitft->endWrite();
	}
	break;

	// tftw =96; tfth=64, width = 64 height 96
    case 1:
	for (uint16_t tftline = 0; tftline < _tfth; tftline++) {
	    for (uint16_t i = 0; i < _tftw; i++) {
		_line[_tftw-i-1] = Color24to16(CRGBtoint32(_fb[i*matrixWidth + tftline]));
	    }

	    yield();
	    _spitft->startWrite();
	    _spitft->writePixels(_line, _tftw);
	    _spitft->endWrite();
	}
	break;
    }
}

// vim:sts=4:sw=4
//
