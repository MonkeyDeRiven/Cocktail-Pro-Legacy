//@(#) DeviceVerwalter.h

#ifndef DEVICEVERWALTER_H_H
#define DEVICEVERWALTER_H_H

#include <string>
#include <map>

#include "InternalDevice.h"
#include "VorhandeneZutaten.h"
#include "Dosierer.h"
#include "Mixer.h"
#include "Stampfer.h"
#include "Schuettler.h"
#include "Entleerer.h"
#include "Waage.h"

/**
 * Subsystem
 * @class DeviceVerwalter
 *
 * @brief DeviceVerwalter this class contains pointers to all
 * components of the CocktailPros
 *
 * DeviceVerwalter creates the equipment for the preparation
 */
class DeviceVerwalter {
public:
  /**
   * @brief constructor creates objects from CocktailPro
   *
   * @param ze points on VorhandeneZutaten
   */
    DeviceVerwalter(VorhandeneZutaten * ze);
  /**
   *@brief checks for "Limettenstücke"
   *@param menge amount of ingredients
   *@param zutat type of ingredient
   */
    void rezeptSchrittZubereiten(std::string zutat, float menge);
  /**
   * object of Entelerrer
   */
  Entleerer * myEntleerer;
  std::map<std::string, InternalDevice *> * myDevices;
 private:
    void setZutatenVerwalter(VorhandeneZutaten * ze);

    Mixer * myMixer;

    Stampfer * myStampfer;

    Schuettler * mySchuettler;

    VorhandeneZutaten * myZutatenVerwalter;

    Waage * theWaage;

    void createDevices();

};

#endif
