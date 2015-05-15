/*
 * IRremote
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * For details, see http://arcfn.com/2009/08/multi-protocol-infrared-remote-library.htm http://arcfn.com
 * Edited by Mitra to add new controller SANYO
 *
 * Interrupt code based on NECIRrcv by Joe Knapp
 * http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1210243556
 * Also influenced by http://zovirl.com/2008/11/12/building-a-universal-remote-with-an-arduino/
 *
 * JVC and Panasonic protocol added by Kristian Lauszus (Thanks to zenwheel and other people at the original blog post)
 * LG added by Darryl Smith (based on the JVC protocol)
 * Whynter A/C ARC-110WD added by Francesco Meschia
 */

#ifndef SHIRRIFF_IRREMOTE_H
#define SHIRRIFF_IRREMOTE_H

// Decoded value for NEC when a repeat code is received
#define REPEAT 0xffffffff

// Some useful constants

#define USECPERTICK 50  // microseconds per clock interrupt tick
#define RAWBUF 100 // Length of raw duration buffer

// Marks tend to be 100us too long, and spaces 100us too short
// when received due to sensor lag.
#define MARK_EXCESS 100

#include <Shirriff_Decode_Results.h>


#ifdef TEST
#define VIRTUAL virtual
#else
#define VIRTUAL
#endif

namespace Shirriff
{
    class IRremote
    {

    public:
        // send related functions
        IRremote(Stream *d = NULL){}
        void sendRaw(unsigned int buf[], int len, int hz);
        void enableIROut(int khz);
        VIRTUAL void mark(int usec);
        VIRTUAL void space(int usec);
        virtual void send(unsigned long data, int nbits) = 0;
        // receive related functions
        IRremote(int recvpin,Stream *d = NULL);
        void blink13(int blinkflag);
        void enableIRIn();
        void resume();

        // other
        int MATCH(int measured, int desired);
        int MATCH_MARK(int measured_ticks, int desired_us);
        int MATCH_SPACE(int measured_ticks, int desired_us);

    private:
        // receive related functions
        int getRClevel(decode_results *results, int *offset, int *used, int t1);
        virtual long decode(Decode_Results *results) = 0;
        long decodeHash(decode_results *results);
        int compare(unsigned int oldval, unsigned int newval);
        // send related
    protected:
        // other
        Stream *debug;
    };
}

#endif
