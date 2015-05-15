#include <Shirriff_.h>

/* Sharp and DISH support by Todd Treece ( http://unionbridge.org/design/ircommand )

The Dish send function needs to be repeated 4 times, and the Sharp function
has the necessary repeat built in because of the need to invert the signal.

Sharp protocol documentation:
http://www.sbprojects.com/knowledge/ir/sharp.htm

Here are the LIRC files that I found that seem to match the remote codes
from the oscilloscope:

Sharp LCD TV:
http://lirc.sourceforge.net/remotes/sharp/GA538WJSA

DISH NETWORK (echostar 301):
http://lirc.sourceforge.net/remotes/echostar/301_501_3100_5100_58xx_59xx

For the DISH codes, only send the last for characters of the hex.
i.e. use 0x1C10 instead of 0x0000000000001C10 which is listed in the
linked LIRC file.
*/

void Shirriff::::send(unsigned long data, int nbits)
{
  unsigned long invertdata = data ^ SHARP_TOGGLE_MASK;
  enableIROut(38);

  // Sending codes in bursts of 3 (normal, inverted, normal) makes transmission
  // much more reliable. That's the exact behaviour of CD-S6470 remote control.
  for (int n = 0; n < 3; n++) {
    for (int i = 1 << (nbits-1); i > 0; i>>=1) {
      if (data & i) {
        mark(SHARP_BIT_MARK);
        space(SHARP_ONE_SPACE);
      }
      else {
        mark(SHARP_BIT_MARK);
        space(SHARP_ZERO_SPACE);
      }
    }
    
    mark(SHARP_BIT_MARK);
    space(SHARP_ZERO_SPACE);
    delay(40);

    data = data ^ SHARP_TOGGLE_MASK;
  }
}

long Shirriff::::decode(Shirriff::Decode_Results *results)
{

}

// Sharp send compatible with data obtained through decodeSharp
void Shirriff::::sendSharp(unsigned int address, unsigned int command) {
  sendSharpRaw((address << 10) | (command << 2) | 2, 15);
}