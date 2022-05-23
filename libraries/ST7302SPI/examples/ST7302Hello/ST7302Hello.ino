#include <ST7302SPI.h>

#define _PIN_RST_ 1
#define _PIN_DC_ 0
#define _PIN_CS_ 7
#define _PIN_SCK_ 2
#define _PIN_MOSI_ 3
#define _PIN_MISO_ -1

uint8_t font[]={0x06, 0x00, 0x00, 0x18, 0x07, 0x80, 0x00, 0x3c, 0x03, 0x87, 0xff, 0xfe, 0x03, 0xc0, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 0x21, 0x80, 0x70, 0x00, 0x71, 0xff, 0xf8, 0x7f, 0xf9, 0xc0, 0x78, 0x00, 0xf9, 0xc0, 0x70, 0x00, 0xf1, 0xc0, 0x70, 0x01, 0xe1, 0xc0, 0x70, 0x01, 0xe1, 0xc0, 0x70, 0x03, 0xc1, 0xff, 0xf0, 0x03, 0x81, 0xc0, 0x70, 0x07, 0xc0, 0x00, 0x10, 0x0f, 0xe6, 0x00, 0x38, 0x0f, 0xf7, 0xff, 0xfe, 0x1f, 0xbf, 0x0e, 0x3c, 0x37, 0xbf, 0x0e, 0x3c, 0x47, 0x87, 0x0e, 0x3c, 0x07, 0x87, 0x0e, 0x3c, 0x07, 0x87, 0xff, 0xfc, 0x07, 0x87, 0x0e, 0x3c, 0x07, 0x87, 0x0e, 0x3c, 0x07, 0x87, 0x0e, 0x3c, 0x07, 0x87, 0x0e, 0x3c, 0x07, 0x87, 0x0e, 0x3c, 0x07, 0x87, 0xff, 0xfc, 0x07, 0x87, 0x00, 0x3c, 0x07, 0x07, 0x00, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

ST7302SPI st7302spi(_PIN_SCK_, _PIN_MISO_, _PIN_MOSI_, _PIN_RST_, _PIN_DC_, _PIN_CS_, 250, 122);

void setup() {
  st7302spi.begin();
  // inversion screen
  st7302spi.inversion_on();
  //draw point
  st7302spi.point(10,10,1);
  // draw ascii
  char str1[] = "hello word1.";
  st7302spi. text(1, 20, str1, strlen(str1));

  st7302spi.set_memory(0, 40, 32, 32, font, 128);

  st7302spi.flush_buffer();
}

void loop() {
}