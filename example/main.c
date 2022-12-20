#include <C8051F320.h>
#include "../xprintf.h"

__data __at(0x12) char data[2];
__xdata __at(0x0123) char xdata[2];
__code char cdata[] = "string";

void main (void)
{
  PCA0MD = 0;                       // WDOG disabled
  CLKMUL = 0;
  OSCICN = 0x81;                    // SYSCLK = 3MHz
  CKCON = 0x08;                     // TIM1 - uart
  TL1 = TH1 = 243;                  // UART = 115200
  TMOD = 0x20;
  TCON = 0x40;
  XBR0 = 0x01;
  XBR1 = 0x40;
  SCON0 = 0x10;
  #if defined _PRINTF_
  PUTS("\n\033[36mMCS51 printf example\033[0m");
  #else
  PUTS("\n\033[36mMCS51 xprintf example\033[0m");
  #endif
  PRINTF("%c\n", 'a');              // "a"
  PRINTF("%s\n", "String");         // "String"
  PRINTF("%-4s\n", "abc");          // "abc "
  PRINTF("%4s\n", "abc");           // " abc"
  PRINTF("%04x\n", 0xA3);           // "00a3"
  PRINTF("%08LX\n", 0x123ABCL);     // "00123ABC"
  PRINTF("%d\n", 1234);             // "1234"
  PRINTF("%6d, %03o\n", -200, 27);  // "  -200, 033"
  PRINTF("%-6u\n", 321);            // "100   "
  PRINTF("%ld\n", 12345678L);       // "12345678"
  PRINTF("%p\n", data);             // "I:0x1234"
  PRINTF("%p\n", xdata);            // "C:0x1234"
  PRINTF("%p\n", cdata);            // "X:0x1234"
  PRINTF("%016b\n", 0x550F);        // "0101010100001111"
  PRINTF("%-16b\n", 0x550F);        // "101010100001111  99%"
  PRINTF("%032LB\n", 0x550FL);      // "00000000000000000101010100001111"
  while(1);
}

#if defined _PRINTF_ || defined _XPRINTF_
int putchar (int ch)
{
  if(ch == '\n') putchar('\r');
  for(SBUF0 = ch; !TI0; );
  TI0 = 0;
  return ch;
}

int getchar (void)
{
  while(!RI0);
  RI0 = 0;
  return SBUF0;
}
#endif
