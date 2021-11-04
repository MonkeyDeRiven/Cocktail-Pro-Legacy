//@(#) Mixer.h
//Das ist der Header vom Mixer
#ifndef MIXER_H_H
#define MIXER_H_H

#include <iostream>

#include "InternalDevice.h"

class Mixer : public InternalDevice {
public:
    Mixer();

    void doIt(float time);

private:

};

#endif
