#ifndef _SHIRRIFF__H
#define _SHIRRIFF__H

// SA 8650B
#define SANYO_HDR_MARK	3500  // seen range 3500
#define SANYO_HDR_SPACE	950 //  seen 950
#define SANYO_ONE_MARK	2400 // seen 2400  
#define SANYO_ZERO_MARK 700 //  seen 700
#define SANYO_DOUBLE_SPACE_USECS  800  // usually ssee 713 - not using ticks as get number wrapround
#define SANYO_RPT_LENGTH 45000
#define SANYO_BITS 12

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
