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
   * @brief default constructor
   */
  DeviceVerwalter();
  /**
   * @brief constructor creates objects from CocktailPro
   *
   * @param ze points on VorhandeneZutaten
   */
    explicit DeviceVerwalter(VorhandeneZutaten * ze);
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
  /**
  *map with string and InternalDevice
  */
  std::map<std::string, InternalDevice *> * myDevices;
 private:
    /**
    *@brief this method defines myZutatenVerwalter
    *@see myZutatenVerwalter
    *@param ze defines myZutatenVerwalter 
    */
    void setZutatenVerwalter(VorhandeneZutaten * ze);
    /**
    * object of Mixer
    */
    Mixer * myMixer;
    /**
    * object of Stampfer
    */
    Stampfer * myStampfer;
    /**
    * object of Schuettler
    */
    Schuettler * mySchuettler;
    /**
    * object of VorhandeneZutaten
    */
    VorhandeneZutaten * myZutatenVerwalter;
    /**
    * object of Waage
    */
    Waage * theWaage;
    /**
    *@brief this method creates all needed devices and calibrates the Dosierer
    */
    void createDevices();

};

#endif
