//@(#) Stampfer.cpp


#include "Stampfer.h"

Stampfer::Stampfer() : InternalDevice() {
}

void Stampfer::doIt(float time) {
  myTimer->sleep_in_intervals(time * 1000);
    std::cout << std::endl;
}
