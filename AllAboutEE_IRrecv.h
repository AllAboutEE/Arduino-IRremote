#ifndef AllAboutEE_IRrecv_h
#define AllAboutEE_IRrecv_h

#include "AllAboutEE_decoder_results.h"

// Values for decode_type
#define NEC 1
#define SONY 2
#define RC5 3
#define RC6 4
#define DISH 5
#define SHARP 6
#define PANASONIC 7
#define JVC 8
#define SANYO 9
#define MITSUBISHI 10
#define SAMSUNG 11
#define LG 12
#define UNKNOWN -1

// Decoded value for NEC when a repeat code is received
#define REPEAT 0xffffffff

// main class for receiving IR
class AllAboutEE_IRrecv
{
public:
  AllAboutEE_decoder_results DR;
  AllAboutEE_IRrecv(int recvpin);
  void blink13(int blinkflag);
  int decode(AllAboutEE_decoder_results *results);
  void enableIRIn();
  void resume();
private:
  // These are called by decode
  int getRClevel(AllAboutEE_decoder_results *results, int *offset, int *used, int t1);
  long decodeNEC(AllAboutEE_decoder_results *results);
  long decodeSony(AllAboutEE_decoder_results *results);
  long decodeSanyo(AllAboutEE_decoder_results *results);
  long decodeMitsubishi(AllAboutEE_decoder_results *results);
  long decodeRC5(AllAboutEE_decoder_results *results);
  long decodeRC6(AllAboutEE_decoder_results *results);
  long decodePanasonic(AllAboutEE_decoder_results *results);
  long decodeLG(AllAboutEE_decoder_results *results);
  long decodeJVC(AllAboutEE_decoder_results *results);
  long decodeSAMSUNG(AllAboutEE_decoder_results *results);
  long decodeHash(AllAboutEE_decoder_results *results);
  int compare(unsigned int oldval, unsigned int newval);

};

// Some useful constants

#define USECPERTICK 50  // microseconds per clock interrupt tick
#define RAWBUF 100 // Length of raw duration buffer

// Marks tend to be 100us too long, and spaces 100us too short
// when received due to sensor lag.
#define MARK_EXCESS 100

#endif
