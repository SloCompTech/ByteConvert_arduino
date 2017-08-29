#ifndef _ByteConvert_hpp_
#define _ByteConvert_hpp_

#include "Arduino.h"

namespace ByteConvert {
  template<class T>
  T arrayToVar(uint8_t *array) {
    size_t size = sizeof(T)/sizeof(uint8_t);
    T var = 0x00;
    for (size_t i = 0;i < (size);i++) {
      if (i != 0) var <<= 8;
      var |= array[i];
    }
    return var;
  }
  template<class T>
  uint8_t *varToArray(size_t &size,T var) {
    size = sizeof(T)/sizeof(uint8_t);
    uint8_t *array = new uint8_t[size]; // Alocate memory
    for (size_t i = 0;i < size;i++) {
      if (i != 0) var >>= 8;
      array[size-1-i] = (uint8_t)(var&0xff);
    }
    return array;
  }
  char valToHex(uint8_t val);
  uint8_t hexToVal(char c);
  String byteToHexString(uint8_t b);
  uint8_t hexStringToByte(String block);
  String arrayToString(size_t size,uint8_t *src);
  uint8_t* stringToArray(size_t &size,String src);
}

#endif
