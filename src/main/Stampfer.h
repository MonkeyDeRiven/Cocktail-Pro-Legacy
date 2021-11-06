//@(#) Stampfer.h

#ifndef STAMPFER_H_H
#define STAMPFER_H_H

#include "InternalDevice.h"

/**
 * @class Stampfer
 *
 * @brief Stampfer informs the user that the masher is working
 *
 * When the masher is activated for the given time, '*' indicates to the user that the masher is working
 *
 */
class Stampfer : public InternalDevice {
public:

    /**
     * @brief Constructor
     */
    Stampfer();

    /**
     * @brief The Method signals the user that the masher is working
     * @param time a float for the time the masher is working
     */
    void doIt(float time);

private:
};

#endif
