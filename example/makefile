.PHONY:	all

all:	printf xprintf 
	sdcc -D_PRINTF_ --no-xinit-opt -o printf/main.ihx main.c ../xprintf.lib
	makebin -p printf/main.ihx printf/main.bin
	rm -fr printf/*.i* printf/*.s* printf/*.a* printf/*.l* printf/*.r*
	sdcc -D_XPRINTF_ --no-xinit-opt -o xprintf/main.ihx main.c ../xprintf.lib
	makebin -p xprintf/main.ihx xprintf/main.bin
	rm -fr xprintf/*.i* xprintf/*.s* xprintf/*.a* xprintf/*.l* xprintf/*.r*
printf xprintf:
	mkdir $@
