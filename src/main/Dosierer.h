//@(#) Dosierer.h

#ifndef DOSIERER_H_H
#define DOSIERER_H_H

#include <string>
#include <iostream>

#include "Observer.h"
#include "InternalDevice.h"
#include "Waage.h"

/**
*Subsystem
*@class Dosierer
*
*@brief this class stores and regulates the amount of ingredients.
*/
class Dosierer : public InternalDevice, public Observer {
public:
    /**
     * @brief default constructor
     */
    Dosierer();
    /**
    *@brief constructor creates objects from Dosierer
    *@return a pointer to the created object
    *@param g is the amount in gram
    *@param ze is the number of time units
    *@param input_inhalt is the name of the ingredient
    *@param wg is a pointer to the specific Waage
    */
    Dosierer(float g, int ze, std::string &input_inhalt, Waage * wg);
    /**
    *@brief this method regulates the amount put on myWaage
    */
    virtual void update();
    /**
    *@brief this method executes the output of ingredients on the Waage.
    */
    bool doIt(float gramm);
    /**
    *@brief this method returns grammProZeit
    *@return grammProZeit
    */
    /**
    * object of int
    */
    float getStueckProZeit();

private:
    /**
    * object of float
    */
    float grammProZeit;
    /**
    * object of Waage
    */
    Waage * myWaage;
    /**
    * object of float
    */
    float gwicht;
    /**
    * object of std::string
    */
    std::string inhalt;
    /**
     * @brief
     * @return the weight
     */
    float getGwicht() const;
    /**
     * object of boolean
     */
    bool testCheckpoint = false;
    /**
     * object of boolean
     */
    bool testCheckpoint2 = false;
};

#endif
