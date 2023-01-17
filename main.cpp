#include <iostream>
#include "bitvector.h"

int main() {
    skt::BitVector t(78);
    t.set(5, 1);
    t.set(0, 1);
    t.set(76, 1);
    t.set(5, 0);
    t.set(5, 1);
    t.set(8, 0);
    std::cout << t.get(0) << t.get(5) << t.get(8) << "\n"; 
    t.show();
}