#ifndef _SHIRRIFF_DISH_H
#define _SHIRRIFF_DISH_H

#define DISH_HDR_MARK 400
#define DISH_HDR_SPACE 6100
#define DISH_BIT_MARK 400
#define DISH_ONE_SPACE 1700
#define DISH_ZERO_SPACE 2800
#define DISH_RPT_SPACE 6200
#define DISH_TOP_BIT 0x8000

namespace Shirriff
{
    class DISH: public IRremote
    {
    public:
        void send(unsigned long data, int nbits);
    private:
        long decode(Decode_Results *results);
    };
}

#endif
