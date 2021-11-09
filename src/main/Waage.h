//@(#) Waage.h

#ifndef WAAGE_H_H
#define WAAGE_H_H

#include "Subject.h"

/**
 * @class Waage
 * @brief the class can tare, measure weights and display it.
 */
class Waage : public Subject {
 public:
  /**
   * @brief change our weight to a any given weight
   * @param v the weight we want
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