//@(#) Dosierer.cpp


#include "Dosierer.h"

Dosierer::Dosierer(float g, int ze, std::string input_inhalt, Waage * wg) : InternalDevice(), inhalt(input_inhalt) {
    this->grammProZeit = g;
    this->zeiteinheit = ze;
    this->myWaage = wg;
    this->myWaage->attach(this);
}

void Dosierer::update() {
    if (!this->doinIt) return;
    this->testCheckpoint = true;
    if (myWaage->getDelta() >= gwicht) {
        doinIt = false;
    }
}

void Dosierer::doIt(float gramm) {
    this->gwicht = gramm;
    myWaage->tara();
    doinIt = true;
    std::cout << inhalt << " Ventil wurde geoeffnet" << std::endl;
    while (doinIt) {
      myTimer->sleep_in_intervals(zeiteinheit);
        myWaage->changeWeight(grammProZeit);
        //myWaage->changeWeight(0);
    }
    testCheckpoint2 = true;
    std::cout << std::endl << inhalt << " Ventil wurde geschlossen" << std::endl;
    std::cout << "Es wurden " << myWaage->getDelta() << "g " << inhalt << " abgefuellt" << std::endl;
    std::cout << std::endl;
}

float Dosierer::getStueckProZeit() {
    return this->grammProZeit;
}
Dosierer::Dosierer() {
  
}
float Dosierer::getGwicht() const {

  return gwicht;
}
