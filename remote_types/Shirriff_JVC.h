#ifndef _SHIRRIFF__H
#define _SHIRRIFF__H

#define JVC_HDR_MARK 8000
#define JVC_HDR_SPACE 4000
#define JVC_BIT_MARK 600
#define JVC_ONE_SPACE 1600
#define JVC_ZERO_SPACE 550
#define JVC_RPT_LENGTH 60000

#define JVC_BITS 16

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
