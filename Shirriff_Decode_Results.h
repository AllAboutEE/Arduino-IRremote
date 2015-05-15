#ifndef SHIRRIFF_DECODE_RESULTS_H
#define SHIRRIFF_DECODE_RESULTS_H

namespace Shirriff
{

// The following are compile-time library options.
// If you change them, recompile the library.
// If DEBUG is defined, a lot of debugging output will be printed during decoding.
// TEST must be defined for the IRtest unittests to work.  It will make some
// methods virtual, which will be slightly slower, which is why it is optional.
//#define DEBUG
// #define TEST

    enum decode_type_t {
      NEC = 1,
      SONY = 2,
      RC5 = 3,
      RC6 = 4,
      DISH = 5,
      SHARP = 6,
      PANASONIC = 7,
      JVC = 8,
      SANYO = 9,
      MITSUBISHI = 10,
      SAMSUNG = 11,
      LG = 12,
      WHYNTER = 13,
      AIWA_RC_T501 = 14,

      UNKNOWN = -1
    };

    // Results returned from the decoder
    class Decode_Results {
    public:
      decode_type_t decode_type; // NEC, SONY, RC5, UNKNOWN
      union { // This is used for decoding Panasonic and Sharp data
        unsigned int panasonicAddress;
        unsigned int sharpAddress;
      };
      unsigned long value; // Decoded value
      int bits; // Number of bits in decoded value
      volatile unsigned int *rawbuf; // Raw intervals in .5 us ticks
      int rawlen; // Number of records in rawbuf.
    };
}

#endif

