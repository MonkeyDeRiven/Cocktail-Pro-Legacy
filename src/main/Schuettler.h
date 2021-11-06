//@(#) Schuettler.h

#ifndef SCHUETTLER_H_H
#define SCHUETTLER_H_H

#include "InternalDevice.h"

/**
 * @class Schuettler
 *
 * @brief Schuettler informs the user that the shaker is working
 *
 * When the shaker is activated for the given time, '*' indicates to the user that the shaker is working
 *
 */
class Schuettler : public InternalDevice {
public:
    /**
     * @brief Constructor
     */
    Schuettler();

    /**
     * @brief The Method signals the user that the shaker is working
     * @param time a float for the time the shaker is working
     */
    void doIt(float time);

private:
};

#endif
