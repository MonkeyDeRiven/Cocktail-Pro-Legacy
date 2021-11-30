//@(#) Entleerer.h

#ifndef ENTLEERER_H_H
#define ENTLEERER_H_H

#include <iostream>

#include "Observer.h"
#include "InternalDevice.h"
#include "Waage.h"

/**
*Subsystem
*@class Entleerer
*
*@brief this class executes the output of ingredients.
*/
class Entleerer : public InternalDevice, public Observer {
public:
  /**
   * @brief default constructor
   */
  Entleerer();
/**
    *@brief constructor creates a pointer to the created object
    *@return a pointer to the created object
    *@param g is the amount in gram
    *@param ze is the number of time units
    *@param wg is  a pointer to the specific Waage
    */
    Entleerer(float g, int ze, Waage * wg);
    /**
    *@brief destructor for Entleerer
    */
    ~Entleerer();
    /**
    *@brief this method regulates the amount of output in the cocktail glass
    */
    void update();
    /**
    *@brief this method executes the output of cocktail that gets poured in the glass
    */
    void doIt(float input);
  //float getValue() const;

 private:
    /**
    *object of float
    */
    float grammProZeit;
    /**
    *object of Waage
    */
    Waage * myWaage;
    /**
    *object of float
    */
    float value;
    /**
     * object of boolean
     */
    bool testCeckpoint = false;
    /**
     * object of boolean
     */
    bool testCeckpoint2 = false;


};

#endif
