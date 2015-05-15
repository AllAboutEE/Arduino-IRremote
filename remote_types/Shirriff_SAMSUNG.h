#ifndef _SHIRRIFF__H
#define _SHIRRIFF__H

#define SAMSUNG_HDR_MARK  5000
#define SAMSUNG_HDR_SPACE 5000
#define SAMSUNG_BIT_MARK  560
#define SAMSUNG_ONE_SPACE 1600
#define SAMSUNG_ZERO_SPACE  560
#define SAMSUNG_RPT_SPACE 2250

#define SAMSUNG_BITS 32

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
