#include "systemc.h"

SC_MODULE(nand) {
    sc_in<bool> A, B;
    sc_out<bool> F;

    void do_nand() {
        F.write(!(A.read() && B.read()));
    }

    SC_CTOR(nand) {
        SC_METHOD(do_nand);
        sensitive << A << B;
    }
};
