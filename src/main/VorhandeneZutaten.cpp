//@(#) VorhandeneZutaten.cpp

#include "VorhandeneZutaten.h"
#include <vector>
#include <fstream>
//

VorhandeneZutaten& VorhandeneZutaten::operator= (VorhandeneZutaten original){
  this->zutaten = original.zutaten;
  this->anzahlDosierer = original.anzahlDosierer;
  return *this;
}

VorhandeneZutaten::VorhandeneZutaten() {
  zutaten = new std::vector<Ingredient*>;

  // int einlesen(list<string>* zutaten, std::string FileName)
// Stream anlegen


  ZutatenDateiEinlesen("../src/resources/zutaten.txt");


  browse();
  std::string name = std::string("Mischen");
  zutaten->push_back(new Ingredient(name, 0));
  name = std::string("Stampfen");
  zutaten->push_back(new Ingredient(name, 0));
  name = std::string("Schuetteln");
  zutaten->push_back(new Ingredient(name, 0));

  anzahlDosierer = zutaten->size();

}

VorhandeneZutaten::VorhandeneZutaten(VorhandeneZutaten &copy) {
  *this = copy;
}

VorhandeneZutaten::~VorhandeneZutaten(void) {

}

void VorhandeneZutaten::getOurData(std::ifstream& in, VorhandeneZutaten* ingredient){
  std::string zeile;
  while (getline(in, zeile)) {

    // Cut trailing \r - to make Linux or Windows Files equal
    if (zeile.size() && zeile[zeile.size() - 1] == '\r') {
      zeile = zeile.substr(0, zeile.size() - 1);
    }

    ingredient->zutaten->push_back(new Ingredient(zeile, 1000));
  }
}
void VorhandeneZutaten::ZutatenDateiEinlesen(std::string myfile) {
    std::ifstream in;

    FileName = myfile;

    in.open(FileName.c_str(), std::ios::in); // c_str wandelt den String in char[]
    // das braucht fstream

    if (!in) {// File konnte nicht geoeffnet werden
        std::string my_exception = "File not found: " + FileName;
        std::cout << my_exception << std::endl;
        throw my_exception;
    }

    std::cout << "Oeffne Zutatendatei " << FileName << std::endl;

  getOurData(in, this);


    in.close();
}

void VorhandeneZutaten::browse(void) {
    std::cout << "*********** Verfuegbare Einheiten bzw. Zutaten: ***********" << std::endl;
    for (unsigned int i = 0; i < zutaten->size()-3; i++/*std::string zutat : zutaten*/) {
        std::cout << zutaten->at(i)->getName() << "  " << zutaten->at(i)->getAmount() << "g";
        if(zutaten->at(i)->getAmount() == 0){
          std::cout << " (empty)";
        }
        else if(zutaten->at(i)->getAmount() < 100){
        std::cout << " *";
      }
      std::cout << std::endl;
    }
    std::cout << "**********************************************************" << std::endl;
}

Ingredient* VorhandeneZutaten::getZutat(int i) {
    return zutaten->at(i);
}

int VorhandeneZutaten::getAnzahlVorhandeneZutaten() {
    return zutaten->size();
}

void VorhandeneZutaten::fillIngredients() {
  for(unsigned int i = 0; i < zutaten->size()-3; i++){
    zutaten->at(i)->setAmount(1000);
  }
  std::cout << "Alle Zutaten wurden nachgefüllt!" << std::endl;
}

Ingredient* VorhandeneZutaten::getIngredientByName(std::string &name) {
  Ingredient* zutat = nullptr;
  for(unsigned int i = 0; i < zutaten->size(); i++){
    if(zutaten->at(i)->getName() == name){
      zutat = zutaten->at(i);
    }
  }
  return zutat;
}

bool VorhandeneZutaten::isIngredientDoubled(std::string &inputIngredient){
  std::string line_;
  std::vector<std::string> zutatenInVec;
  std::ifstream zutatenIfstream("../src/resources/zutaten.txt");
  if(zutatenIfstream.is_open()){
    while(getline(zutatenIfstream, line_)){
      zutatenInVec.push_back(line_);
    }
    zutatenIfstream.close();
  }
  else
    std::cout << "zutaten.txt kann nicht geoeffnet werden." << std::endl;
  int counter = 0;
  for(unsigned int posInVec = 0; posInVec < zutatenInVec.size(); posInVec++){
    if(zutatenInVec.at(posInVec) == inputIngredient)
      counter++;
    if(counter == 1)
      return true;
  }
  return false;
}

void VorhandeneZutaten::doubleIngredient(std::string inputIngredient){
  std::string line_;
  std::vector<std::string> zutatenInVec;
  std::ifstream zutatenIfstream("../src/resources/zutaten.txt");
  if(zutatenIfstream.is_open()){
    while(getline(zutatenIfstream, line_)){
      zutatenInVec.push_back(line_);
    }
    zutatenIfstream.close();
  }

  zutatenInVec.push_back(inputIngredient);
  std::ofstream zutatenOfstream;
  zutatenOfstream.open("../src/resources/zutaten.txt");
  if(!zutatenOfstream){
    std::cerr << "zutaten.txt kann nicht geoeffnet werden.\n" << std::endl;
    return;
  }
  for(unsigned int i = 0; i < zutatenInVec.size(); i++){
    zutatenOfstream << zutatenInVec.at(i) << std::endl;
  }
  zutatenOfstream.close();
  zutaten->pop_back();
  zutaten->pop_back();
  zutaten->pop_back();
  zutaten->push_back(new Ingredient(inputIngredient, 0));
  std::string name = std::string("Mischen");
  zutaten->push_back(new Ingredient(name, 0));
  name = std::string("Stampfen");
  zutaten->push_back(new Ingredient(name, 0));
  name = std::string("Schuetteln");
  zutaten->push_back(new Ingredient(name, 0));
}


