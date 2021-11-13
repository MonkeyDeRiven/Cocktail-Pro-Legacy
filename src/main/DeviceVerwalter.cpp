//@(#) DeviceVerwalter.cpp


#include "DeviceVerwalter.h"

DeviceVerwalter::DeviceVerwalter(VorhandeneZutaten * zv) {
    setZutatenVerwalter(zv);
    this->createDevices();
}

void DeviceVerwalter::createDevices() {
    theWaage = new Waage();
    myDevices = new std::map<std::string, InternalDevice *>;

    myEntleerer = new Entleerer(25, 1000, theWaage);
    myDevices->insert(std::make_pair("Entleeren", myEntleerer));

    myStampfer = new Stampfer();
    myDevices->insert(std::make_pair("Stampfen", myStampfer));

    mySchuettler = new Schuettler();
    myDevices->insert(std::make_pair("Schuetteln", mySchuettler));

    myMixer = new Mixer();
    myDevices->insert(std::make_pair("Mischen", myMixer));

    std::string myZutat;
    for (int i = myZutatenVerwalter->getAnzahlVorhandeneZutaten() - 1; i >= 0; i--) {
        myZutat=myZutatenVerwalter->getZutat(i);
        if (myZutat == "Eis")
            myDevices->insert(std::make_pair(myZutat, new Dosierer(20, 1000, myZutat, theWaage)));
        else if (myZutat == "Limettenstuecke")
            myDevices->insert(std::make_pair(myZutat, new Dosierer(10, 1000, myZutat, theWaage)));
        else
            myDevices->insert(std::make_pair(myZutat, new Dosierer(1, 250, myZutat, theWaage)));
    }
}

void DeviceVerwalter::setZutatenVerwalter(VorhandeneZutaten * zv) {
    myZutatenVerwalter = zv;
}

void DeviceVerwalter::rezeptSchrittZubereiten(std::string zutat, float menge) {

    std::map<std::string, InternalDevice *>::iterator tmpDevice;

    //tmpDevice = myDevices->find(zutat);

    if (zutat == "Limettenstuecke") {
        // The customer wants to measure limes by piece and not by weight.
        int stckProZeit = dynamic_cast<Dosierer *>((myDevices)->at(zutat))->getStueckProZeit();
        myDevices->at(zutat)->doIt(menge * stckProZeit);
    } else {
        myDevices->at(zutat)->doIt(menge);
    }
}