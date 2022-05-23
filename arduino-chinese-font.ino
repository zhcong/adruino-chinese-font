#include <ST7302SPI.h>
#include "ChineseFontBitMap.h"

#define _PIN_RST_ 1
#define _PIN_DC_ 0
#define _PIN_CS_ 7
#define _PIN_SCK_ 2
#define _PIN_MOSI_ 3
#define _PIN_MISO_ -1

# define BYTE_SIZE 8

ST7302SPI st7302spi(_PIN_SCK_, _PIN_MISO_, _PIN_MOSI_, _PIN_RST_, _PIN_DC_, _PIN_CS_, 250, 122);
ChineseFontBitMap chineseFontBitMap;

void print_chinese(int x_byte_start, int y_start,  String str[], int len) {
  for (int i = 0; i != len; i++) {
    st7302spi.set_memory(x_byte_start + i * int(chineseFontBitMap.get_pixel_len() / BYTE_SIZE), y_start, chineseFontBitMap.get_pixel_len(), chineseFontBitMap.get_pixel_len(), chineseFontBitMap.get_map(str[i]), chineseFontBitMap.get_byte_len());
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH);
  st7302spi.begin();
//  st7302spi.inversion_on();
  
  String str[]={"你","好","B","站"};
  print_chinese(10, 10, str, 4);
  st7302spi.flush_buffer();
}

void loop() {
  // delay(2000);
}
