#include <stdio.h>
#undef PUTC
#undef PUTS
#undef PRINTF
#if defined _PRINTF_ || defined _XPRINTF_
void xprintf (__code const char *fmt, ...) __reentrant __naked;
#define PUTC(c)     putchar(c)
#define PUTS(s)     puts(s)
#if defined _PRINTF_
#define PRINTF(...) printf(__VA_ARGS__)
#else
#define PRINTF(...) xprintf(__VA_ARGS__)
#endif
#else
#define PUTC(c)
#define PUTS(s)
#define PRINTF(...)
#endif

