#include <ByteConvert.hpp>

void setup() {
  Serial.begin(9600);
  Serial.println("Simple test");
  Serial.println("size(short): "+String(sizeof(short)));
  Serial.println("size(int): "+String(sizeof(int)));
  Serial.println("size(float): "+String(sizeof(float)));
  Serial.println("size(char): "+String(sizeof(char)));
  Serial.println("size(uint8_t): "+String(sizeof(uint8_t)));
  Serial.println("valToHex: 9->"+String(ByteConvert::valToHex(0x09)));
  Serial.println("valToHex: b->"+String(ByteConvert::valToHex(0x0b)));
  Serial.println("byteToHexString: fa->"+String(ByteConvert::byteToHexString(0xfa)));

  uint8_t array1[] = {0xfa,0xca,0xde,0xda};
  Serial.println("facadeda -> "+ByteConvert::arrayToString(4,array1));

  size_t s2 = 0;
  uint8_t *array2 = ByteConvert::stringToArray(s2,"bedababa");
  Serial.println("Size(bedababba): "+String(s2));
  Serial.println("bedababba -> "+ ByteConvert::arrayToString(s2,array2));

  delete array2;

  int in = 5;
  Serial.println("Orig: 5 -> "+String(in));
  size_t s3 = 0;
  uint8_t *array3 = ByteConvert::varToArray<int>(s3,in);
  Serial.println("0005 -> "+ ByteConvert::arrayToString(s3,array3));
  Serial.println("5 -> "+ String(ByteConvert::arrayToVar<int>(array3)));

  delete array3;
}

void loop() {

}
