//@(#) Timer.h

#ifndef TIMER_H_H
#define TIMER_H_H

/**
 * @brief the #include chrono is used to simulate the time
 **/
#include <chrono>

using namespace std::chrono;
#include <iostream>

class Timer {
 public:
  /**
    * @class Timer
    *
    * @brief setter to set the booster from our instance
    * @param turbo is given to set a certain number to our booster
    */
  void set_Turbo(int turbo);
  /**
 * @brief the method getInstance returns a static Timer what we can use to set our instanceFlag attribute
 * @return as return we get a Timer Instance
 * 	~Timer( )
 *     {
 *         instanceFlag = false;
 *     };
 */

  static Timer * getInstance();

  /**
   * @brief timer to wait in several intervalls
   * @param milliseconds is needed to wait a specific time
   *
   * in the method sleep_in_intervals we wait several times, depends on how long our
   * paramater is
   * if our parameter is > 0, we set our delay to 1000 and our parameter to parameter - our delay
   * then we wait till our parameter is >= 1000
   * if its >= 1000, we set our delay to = 0 and we stop waiting
   */

  void sleep_in_intervals(long milliseconds);
  /**
   * @brief Methode sleep waits one time, how long we wait is depending on our parameter
   * @param delay_in_ms is the time we wait
   */

  void sleep(long delay_in_ms);


 private:

  static bool instanceFlag;
/**
 * Object from class Timer
 */
  static Timer * theTimer;

  int booster;
/**
 * Constructor who sets our booster to 1
 */
  Timer() : booster(1) {
  };

};

#endif
