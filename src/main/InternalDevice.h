//@(#) InternalDevice.h

#ifndef INTERNALDEVICE_H_H
#define INTERNALDEVICE_H_H

#include "Timer.h"

/**
 *  @class InternalDevice
 *
 *  @brief base class for internal devices, such as dispenser or processing units.
 *
 *  this class is a virtual base class for all internal devices of the CocktailPro.
 *  It contains a function for cleaning the devices and provides a timer.
 *  the virtual function DoIt, gets overridden by the task function of each internal device.
 */
class InternalDevice {
public:
    /** @brief implements a virtual base function for the task functions of the internal devices.
     *  @param value is a float, which represents the time.
     */
    virtual void doIt(float value) = 0;

    /** @brief cleans the device.
     */
    void putzen();

private:
    /** @brief sets a timer.
     */
    //void setTimer();


public:
    /** @brief constructor of the virtual class InternalDevices.
     *
     *  creates a timer for the device and initialises the doit bool with false.
     */
    InternalDevice();
protected:
    /**
     * contains the time
     */
    int zeiteinheit;

    /**
     *  is true if the device is doing something and false if not.
     */
    bool doinIt;

    /**
     *  points to a instance of the object Timer
     */
    Timer * myTimer;

};

#endif
