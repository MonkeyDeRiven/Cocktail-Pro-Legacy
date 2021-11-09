//@(#) Observer.h

#ifndef OBSERVER_H_H
#define OBSERVER_H_H

/**
 *  @class observer
 *  @brief provides a virtual update function for all display devices.
 */
class Observer {
public:
    /**
     * @brief virtual update function for all devices which needs an update on its
     * displays.
     */
    virtual void update() = 0;

};

#endif
