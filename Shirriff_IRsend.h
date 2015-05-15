#ifndef SHIRRIFF_IRRECV_H
#define SHIRRIFF_IRRECV_H


// Only used for testing; can remove virtual for shorter code
#ifdef TEST
#define VIRTUAL virtual
#else
#define VIRTUAL
#endif

namespace Shirriff
{
    class IRsend
    {
        public:
          IRsend() {}
          void sendRaw(unsigned int buf[], int len, int hz);
        #ifdef SEND_RC5
          void sendRC5(unsigned long data, int nbits);
        #endif
        #ifdef SEND_RC6
          void sendRC6(unsigned long data, int nbits);
        #endif
        #ifdef SEND_WHYNTER
          void sendWhynter(unsigned long data, int nbits);
        #endif
        #ifdef SEND_NEC 
          void sendNEC(unsigned long data, int nbits);
        #endif
        #ifdef SEND_SONY 
          void sendSony(unsigned long data, int nbits);
          // Neither Sanyo nor Mitsubishi send is implemented yet
          //  void sendSanyo(unsigned long data, int nbits);
          //  void sendMitsubishi(unsigned long data, int nbits);
        #endif
        #ifdef SEND_DISH 
          void sendDISH(unsigned long data, int nbits);
        #endif
        #ifdef SEND_SHARP
          void sendSharp(unsigned int address, unsigned int command);
          void sendSharpRaw(unsigned long data, int nbits);
        #endif
        #ifdef SEND_IRsendSHARP
          void sendSharp(unsigned long data, int nbits);
        #endif
        #ifdef SEND_PANASONIC
          void sendPanasonic(unsigned int address, unsigned long data);
        #endif
        #ifdef SEND_JVC
          void sendJVC(unsigned long data, int nbits, int repeat); // *Note instead of sending the REPEAT constant if you want the JVC repeat signal sent, send the original code value and change the repeat argument from 0 to 1. JVC protocol repeats by skipping the header NOT by sending a separate code value like NEC does.
        #endif
        #ifdef SEND_AIWA_RC_T501
          void sendAiwaRCT501(int code);
        #endif
        #ifdef SEND_SAMSUNG 
          void sendSAMSUNG(unsigned long data, int nbits);
        #endif
          void enableIROut(int khz);
          VIRTUAL void mark(int usec);
          VIRTUAL void space(int usec);
    } ;
}

#endif
