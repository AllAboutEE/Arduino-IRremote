#ifndef SHIRRIFF_IRRECV_H
#define SHIRRIFF_IRRECV_H

namespace Shirriff
{
    class IRrecv
    {
        public:
        IRrecv(int recvpin);
        void blink13(int blinkflag);
        int decode(decode_results *results);
        void enableIRIn();
        void resume();
        private:
        // These are called by decode
        int getRClevel(decode_results *results, int *offset, int *used, int t1);

        #ifdef DECODE_NEC
            long decodeNEC(decode_results *results);
        #endif
        #ifdef DECODE_SONY
            long decodeSony(decode_results *results);
        #endif
        #ifdef DECODE_SANYO
            long decodeSanyo(decode_results *results);
        #endif
        #ifdef DECODE_MITSUBISHI
            long decodeMitsubishi(decode_results *results);
        #endif
        #ifdef DECODE_RC5
            long decodeRC5(decode_results *results);
        #endif
        #ifdef DECODE_RC6
        long decodeRC6(decode_results *results);
        #endif
        #ifdef DECODE_PANASONIC
            long decodePanasonic(decode_results *results);
        #endif
        #ifdef DECODE_LG
            long decodeLG(decode_results *results);
        #endif
        #ifdef DECODE_JVC
            long decodeJVC(decode_results *results);
        #endif
        #ifdef DECODE_SAMSUNG
            long decodeSAMSUNG(decode_results *results);
        #endif

        #ifdef DECODE_WHYNTER
            long decodeWhynter(decode_results *results);
        #endif

        #ifdef DECODE_AIWA_RC_T501
            long decodeAiwaRCT501(decode_results *results);
        #endif

        long decodeHash(decode_results *results);
        int compare(unsigned int oldval, unsigned int newval);

    } ;
}

#endif
