VSPROG	= tools\versaloon\vsprog

.PHONY:	all run_printf run_xprintf

all:
	sdcc -c -o xprintf.rel xprintf.c
	sdar -rc xprintf.lib xprintf.rel
	rm -fr *.a* *.r* *.s* *.lst
	$(MAKE) -C example
run_printf:
	$(VSPROG) -V"tvcc.set 3300" -cc8051f32xL -mc -oe -owf -I example/printf/main.bin
	$(VSPROG) -V"spi.init" -V"spi.config 1 0 0" -V"spi.io 1 0x00" -V"spi.fini" 1>&0
run_xprintf:
	$(VSPROG) -V"tvcc.set 3300" -cc8051f32xL -mc -oe -owf -I example/xprintf/main.bin
	$(VSPROG) -V"spi.init" -V"spi.config 1 0 0" -V"spi.io 1 0x00" -V"spi.fini" 1>&0
