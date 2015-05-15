#ifdef SEND_WHYNTER
void IRsend::sendWhynter(unsigned long data, int nbits) {
	enableIROut(38);
	mark(WHYNTER_ZERO_MARK);
	space(WHYNTER_ZERO_SPACE);
	mark(WHYNTER_HDR_MARK);
	space(WHYNTER_HDR_SPACE);
    for (int i = 0; i < nbits; i++) {
      if (data & TOPBIT) {
        mark(WHYNTER_ONE_MARK);
        space(WHYNTER_ONE_SPACE);
      } 
      else {
        mark(WHYNTER_ZERO_MARK);
        space(WHYNTER_ZERO_SPACE);
      }
      data <<= 1;
    }
	mark(WHYNTER_ZERO_MARK);
	space(WHYNTER_ZERO_SPACE);
}
#endif

#ifdef DECODE_WHYNTER
long IRrecv::decodeWhynter(decode_results *results) {
  long data = 0;
  
  if (irparams.rawlen < 2 * WHYNTER_BITS + 6) {
     return ERR;
  }
  
  int offset = 1; // skip initial space

  // sequence begins with a bit mark and a zero space
  if (!MATCH_MARK(results->rawbuf[offset], WHYNTER_BIT_MARK)) {
    return ERR;
  }
  offset++;
  if (!MATCH_SPACE(results->rawbuf[offset], WHYNTER_ZERO_SPACE)) {
    return ERR;
  }
  offset++;

  // header mark and space
  if (!MATCH_MARK(results->rawbuf[offset], WHYNTER_HDR_MARK)) {
    return ERR;
  }
  offset++;
  if (!MATCH_SPACE(results->rawbuf[offset], WHYNTER_HDR_SPACE)) {
    return ERR;
  }
  offset++;

  // data bits
  for (int i = 0; i < WHYNTER_BITS; i++) {
    if (!MATCH_MARK(results->rawbuf[offset], WHYNTER_BIT_MARK)) {
      return ERR;
    }
    offset++;
    if (MATCH_SPACE(results->rawbuf[offset], WHYNTER_ONE_SPACE)) {
      data = (data << 1) | 1;
    } 
    else if (MATCH_SPACE(results->rawbuf[offset],WHYNTER_ZERO_SPACE)) {
      data <<= 1;
    } 
    else {
      return ERR;
    }
    offset++;
  }
  
  // trailing mark
  if (!MATCH_MARK(results->rawbuf[offset], WHYNTER_BIT_MARK)) {
    return ERR;
  }
  // Success
  results->bits = WHYNTER_BITS;
  results->value = data;
  results->decode_type = WHYNTER;
  return DECODED;
}
#endif
