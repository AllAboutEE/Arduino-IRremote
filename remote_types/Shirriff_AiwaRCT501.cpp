
/**
 * Aiwa system
 * Remote control RC-T501
 * Lirc file http://lirc.sourceforge.net/remotes/aiwa/RC-T501 
 *
 */
 #ifdef DECODE_AIWA_RC_T501
long IRrecv::decodeAiwaRCT501(decode_results *results) {
  int data = 0;
  int offset = 1; // skip first garbage read

  // Check SIZE
  if(irparams.rawlen < 2 * (AIWA_RC_T501_SUM_BITS) + 4) {
    return ERR;
  }
  
  // Check HDR
  if(!MATCH_MARK(results->rawbuf[offset], AIWA_RC_T501_HDR_MARK)) {
    return ERR;
  }
  offset++;

  // Check HDR space
  if(!MATCH_SPACE(results->rawbuf[offset], AIWA_RC_T501_HDR_SPACE)) {
    return ERR;
  }
  offset++;

  offset += 26; // skip pre-data - optional
  while(offset < irparams.rawlen - 4) {
    if(MATCH_MARK(results->rawbuf[offset], AIWA_RC_T501_BIT_MARK)) {
      offset++;
    } 
    else {
      return ERR;
    }
    
    // ONE & ZERO
    if(MATCH_SPACE(results->rawbuf[offset], AIWA_RC_T501_ONE_SPACE)) {
      data = (data << 1) | 1;
    } 
    else if(MATCH_SPACE(results->rawbuf[offset], AIWA_RC_T501_ZERO_SPACE)) {
      data <<= 1;
    } 
    else {
      // End of one & zero detected
      break;
    }
    offset++;
  }
  
  results->bits = (offset - 1) / 2;
  if(results->bits < 42) {
    return ERR;
  }
  results->value = data;
  results->decode_type = AIWA_RC_T501;
  return DECODED;
}

#endif

/**
 * Aiwa system
 * Remote control RC-T501
 * Lirc file http://lirc.sourceforge.net/remotes/aiwa/RC-T501 
 *
 */

 #ifdef SEND_AIWA_RC_T501
void IRsend::sendAiwaRCT501(int code) {
  // PRE-DATA, 26 bits, 0x227EEC0
  long int pre = 0x227EEC0;
  int i;
  
  enableIROut(AIWA_RC_T501_HZ);
  
  // HDR mark + HDR space
  mark(AIWA_RC_T501_HDR_MARK);
  space(AIWA_RC_T501_HDR_SPACE);

  // Skip leading zero's
  pre <<= 6;
  // Send pre-data
  for(i=0; i < 26; i++) {
    mark(AIWA_RC_T501_BIT_MARK);
    if(pre & TOPBIT) {
      space(AIWA_RC_T501_ONE_SPACE);
    } else {
      space(AIWA_RC_T501_ZERO_SPACE);
    }
    pre <<= 1;
  }

  // Skip firts code bit
  code <<= 1;
  // Send code
  for(i=0; i < 15; i++) {
    mark(AIWA_RC_T501_BIT_MARK);
    if(code & TOPBIT) {
      space(AIWA_RC_T501_ONE_SPACE);
    } else {
      space(AIWA_RC_T501_ZERO_SPACE);
    }
    code <<= 1;
  }
  // POST-DATA, 1 bit, 0x0
  mark(AIWA_RC_T501_BIT_MARK);
  space(AIWA_RC_T501_ZERO_SPACE);

  mark(AIWA_RC_T501_BIT_MARK);
  space(0);
}
#endif

