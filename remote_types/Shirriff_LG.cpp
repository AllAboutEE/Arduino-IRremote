#ifdef DECODE_LG
long IRrecv::decodeLG(decode_results *results) {
    long data = 0;
    int offset = 1; // Skip first space
  
    // Initial mark
    if (!MATCH_MARK(results->rawbuf[offset], LG_HDR_MARK)) {
        return ERR;
    }
    offset++; 
    if (irparams.rawlen < 2 * LG_BITS + 1 ) {
        return ERR;
    }
    // Initial space 
    if (!MATCH_SPACE(results->rawbuf[offset], LG_HDR_SPACE)) {
        return ERR;
    }
    offset++;
    for (int i = 0; i < LG_BITS; i++) {
        if (!MATCH_MARK(results->rawbuf[offset], LG_BIT_MARK)) {
            return ERR;
        }
        offset++;
        if (MATCH_SPACE(results->rawbuf[offset], LG_ONE_SPACE)) {
            data = (data << 1) | 1;
        } 
        else if (MATCH_SPACE(results->rawbuf[offset], LG_ZERO_SPACE)) {
            data <<= 1;
        } 
        else {
            return ERR;
        }
        offset++;
    }
    //Stop bit
    if (!MATCH_MARK(results->rawbuf[offset], LG_BIT_MARK)){
        return ERR;
    }
    // Success
    results->bits = LG_BITS;
    results->value = data;
    results->decode_type = LG;
    return DECODED;
}


#endif
