#ifndef _SHIRRIFF_NEC_H
#define _SHIRRIFF_NEC_H

#define NEC_HDR_MARK	9000
#define NEC_HDR_SPACE	4500
#define NEC_BIT_MARK	560
#define NEC_ONE_SPACE	1690
#define NEC_ZERO_SPACE	560
#define NEC_RPT_SPACE	2250

#define NEC_BITS 32

namespace Shirriff
{
    class NEC: public IRremote
    {
    public:
        void send(unsigned long data, int nbits);
    private:
        long decode(Decode_Results *results);
    };
}

#endif
