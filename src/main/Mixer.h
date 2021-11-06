//@(#) Mixer.h

#ifndef MIXER_H_H
#define MIXER_H_H

#include <iostream>

#include "InternalDevice.h"

/**
 * @class Mixer
 *
 * @brief lets the program sleep for a certain time to pretend its mixing.
 */

class Mixer : public InternalDevice {
public:
    /** @brief constructor.
     */
    Mixer();

    /**
     * @brief mixes the ingredients.
     * @param time says how long the mixer should mix the ingredients.
     *
     * the method sleeps for time seconds, to pretend the mixing process.
     */
    void doIt(float time);

private:

};

#endif
