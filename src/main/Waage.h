//@(#) Waage.h

#ifndef WAAGE_H_H
#define WAAGE_H_H

#include "Subject.h"

class Waage : public Subject {
 public:
  /**
   * @class Waage
   *
   * @brief change our weight to a any given weight
   * @param is the weight we want
   */
  void changeWeight(int v);
  /**
   * @return we initialize our deltaweight with 0 and return it
   */
  int tara();
  /**
   * @return we return our weight
   */
  int getWeight();
  /**
   *
   * @return we return our deltaweight
   */
  int getDelta();
 private:
  int weight;
  int deltaweight;
};

#endif