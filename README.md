# Tiny PRINTF function for SDCC compiler (MCS51 MCUs)

This compact function is written in assembler and takes up 500 bytes of program memory. During operation, the function does not use any data memory other than the current register bank and stack. This function is compiled as a library.

The example directory contains a program that uses the compiler's standard printf function, or a tiny implementation. The output directories contain binary firmware images and .mem .map files for comparing used program and data memory.

The example is compiled for the C8051F320 microcontroller. To flash firmware, you can use the [Silabs adapter](https://www.silabs.com/development-tools/mcu/8-bit/8-bit-usb-debug-adapter) or the [Versaloon adapter](https://github.com/versaloon/versaloon). The tools directory contains program and driver for Versaloon.

**Supported types and dependent formats are shown below:**

| Type | Format              |
|------|---------------------|
| c    | Character           |
| s    | String              |
| d    | Signed decimal      |
| u    | Unsigned decimal    |
| o    | Unsigned octal      |
| x X  | Unsigned hexdecimal |
| b    | Unsigned binary     |
| p    | Pointer             |

```
Examples:
  PRINTF("%c\n", 'a');                // "a"
  PRINTF("%s\n", "String");           // "String"
  PRINTF("%-4s\n", "abc");            // "abc "
  PRINTF("%4s\n", "abc");             // " abc"
  PRINTF("%04x\n", 0xA3);             // "00a3"
  PRINTF("%08LX\n", 0x123ABCL);       // "00123ABC"
  PRINTF("%d\n", 1234);               // "1234"
  PRINTF("%6d, %03o\n", -200, 27);    // "  -200, 033"
  PRINTF("%-6u\n", 321);              // "100   "
  PRINTF("%ld\n", 12345678L);         // "12345678"
  PRINTF("%p\n", data);               // "I:0x1234"
  PRINTF("%p\n", xdata);              // "C:0x1234"
  PRINTF("%p\n", cdata);              // "X:0x1234"
  PRINTF("%016b\n", 0x550F);          // "0101010100001111"
  PRINTF("%-16b %d%%\n", 0x550F, 99); // "101010100001111  99%"
  PRINTF("%032LB\n", 0x550FL);        // "00000000000000000101010100001111"
```
