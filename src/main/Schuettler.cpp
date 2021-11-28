//@(#) Schuettler.cpp

#include "Schuettler.h"

Schuettler::Schuettler() : InternalDevice() {
}

void Schuettler::doIt(float time) {
  myTimer->sleep_in_intervals(time * 1000); // uses the function of the class time
  std::cout << std::endl;

}
