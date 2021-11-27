//@(#) Stampfer.cpp

#include <sys/time.h>
#include "Stampfer.h"

Stampfer::Stampfer() : InternalDevice() {
}

void Stampfer::doIt(float workTime) {
  //time_t start = time(nullptr);
  //time_t msStart = start * 1000;
  myTimer->sleep_in_intervals(workTime * 1000); // uses the function of the class time
  std::cout << std::endl;
  /*time_t end = time(nullptr);
  time_t msEnd = end * 1000;
  float neededTime = msEnd-msStart;
  return neededTime;*/
}
