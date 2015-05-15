#ifndef _SHIRRIFF__H
#define _SHIRRIFF__H

#define RC5_T1		889
#define RC5_RPT_LENGTH	46000

#define MIN_RC5_SAMPLES 11

namespace Shirriff
{
    class : public IRremote
    {
    public:
        void send(unsigned long data, int nbits);
    private:
        long decode(Decode_Results *results);
    };
}

#endif
