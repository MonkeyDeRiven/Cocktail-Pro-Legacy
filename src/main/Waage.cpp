//@(#) Waage.cpp


#include "Waage.h"

Waage::Waage() {
  this->weight = 0;
  this->deltaweight = 0;
}

void Waage::changeWeight(int v) {
    weight += v;
    if (weight < 0)
        weight = 0;
    deltaweight += v;
    notify();
}

int Waage::tara() {
    return deltaweight = 0;
}

int Waage::getWeight() {
    return weight;
}

int Waage::getDelta() {
    return deltaweight;
}
