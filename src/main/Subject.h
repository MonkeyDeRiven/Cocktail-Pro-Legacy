//@(#) Subject.h

#ifndef SUBJECT_H_H
#define SUBJECT_H_H

#include "Observer.h"

#include <vector>
#include <iostream>

/**
 * @class Subject
 * @brief this class is created to represent the consumer who wants a cocktail.
*/

class Subject {
 public:
  /**
   * @brief the method attach adds an Observer to our Observer vector
   * @param observer we give the method an instanf of Observer
   **/
  void attach(Observer * observer);

  /**
   * @brief Die Methode detach entfernt den aktuellen Beobachter von der Vektorliste
   * @param observer we give the method an instance of Observer
   **/

  void detach(Observer * observer);

  /**
   * @brief the method notify updates all Observer in our Vectorlist
   **/
  void notify();

 private:
  /**
   * @brief list with all our Observers
   */
  std::vector<Observer *> observers;

};

#endif
