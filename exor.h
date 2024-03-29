#include "systemc.h"
#include "nand.h"

SC_MODULE(exor) {
    sc_in<bool> A,B;
    sc_out<bool> F;
    nand n1, n2, n3, n4;
    sc_signal<bool> S1, S2, S3;

    SC_CTOR(exor): n1("N1"), n2("N2"), n3("N3"), n4("N4") {
        n1.A(A); n1.B(B); n1.F(S1);
        n2.A(A); n2.B(S1); n2.F(S2);
        n3.A(S1); n3.B(B); n3.F(S3);
        n4.A(S2); n4.B(S3); n4.F(F);
    }
};
