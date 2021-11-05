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
 * DeviceVerwalter erstellt die Geräte für die Zubereitung
 */
class DeviceVerwalter {
public:
  /**
   * @brief Konstruktor erzeugt Objekte von CocktailPro
   *
   * @param ze
   */
    DeviceVerwalter(VorhandeneZutaten * ze);

    void rezeptSchrittZubereiten(std::string zutat, float menge);

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
