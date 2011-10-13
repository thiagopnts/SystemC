#include "systemc.h"
#include "stim.h"
#include "exor.h"
#include "mon.h"
#include <iostream>


int sc_main (int argc, char * argv[]) {
    sc_signal<bool> ASig, BSig, FSig;
    sc_clock TestClk("TestClock", 10, SC_NS, 0.5);
    stim Stim1("Stimulus");
    Stim1.A(ASig);
    Stim1.B(BSig);
    Stim1.Clk(TestClk);
    exor DUT("exor");
    DUT.A(ASig);
    DUT.B(BSig);
    DUT.F(FSig);
    mon Monitor1("Monitor");
    Monitor1.A(ASig);
    Monitor1.B(BSig);
    Monitor1.F(FSig);
    Monitor1.Clk(TestClk);

    sc_start();
    return 0;
}
