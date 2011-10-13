all: SYSTEMC
	@g++ -m32 -I/Library/SystemC/Current/include -L/Library/SystemC/Current/lib-macosx -lsystemc -lm main.cpp -o main
	@./main

SYSTEMC:
	g++ -c nand.h exor.h stim.h mon.h -m32 -I/Library/SystemC/Current/include -L/Library/SystemC/Current/lib-macosx
