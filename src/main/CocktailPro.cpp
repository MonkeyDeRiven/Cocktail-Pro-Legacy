//@(#) CocktailPro.cpp


#include "CocktailPro.h"
#include <string>

void CocktailPro::start(){
    while (true) {
        int CocktailNo = waehle();
        bool cocktailExist=false;
        int max = theMischbaresRezeptbuch->getNumberOfRecipes();
        int numInList = checkInputInListForStart(CocktailNo, max, cocktailExist);
        prepareCocktail(cocktailExist, numInList);
    }
}
int CocktailPro::checkInputInListForStart(int CocktailNo, int max, bool &cocktailExist) {
  int numInList = 0;
  for(int rlist=0; rlist<max; rlist++) {
    if (cocktailExist) {
      continue;
    }
    numInList++;
    if (CocktailNo == theMischbaresRezeptbuch->getRecipe(rlist)->getNumber()) {
      cocktailExist = true;
    }
  }
  return numInList;
}
void CocktailPro::prepareCocktail(bool cocktailExist, int numInList) {
  if (cocktailExist) {
    Recipe * rezeptptr = theMischbaresRezeptbuch->getRecipe(numInList - 1);
    std::cout << rezeptptr->getName() << std::endl;
    theCocktailZubereiter->cocktailZubereiten(rezeptptr);
  } else {
    std::cout << "Falsche Cocktailnummer!" << std::endl;
  }
}

CocktailPro::CocktailPro(int argc, char * * param) {

    theZutatenVerwalter = new VorhandeneZutaten;
    theMischbaresRezeptbuch = new MischbaresRezeptbuch(theZutatenVerwalter);
    theDeviceVerwalter = new DeviceVerwalter(theZutatenVerwalter);
    theCocktailZubereiter = new CocktailZubereiter(theDeviceVerwalter);


    Timer * theTimer = Timer::getInstance();
    if (argc == 2) {// this has to be changed later
        if (std::string(param[1]) == "-D") {
            theTimer->set_Turbo(1000);
            this->demo();
            exit(0);
        } else { // Parameter => Turbo an
            theTimer->set_Turbo(10);
        }
    }
    // mix
}

CocktailPro::CocktailPro(CocktailPro &toCopyObject){
  *this = toCopyObject;
}

void CocktailPro::demo() {
    int CocktailNo = 1;
    Recipe * rezeptptr = theMischbaresRezeptbuch->getRecipe(CocktailNo - 1);
    std::cout << rezeptptr->getName() << std::endl;
    theCocktailZubereiter->cocktailZubereiten(rezeptptr);
}


int CocktailPro::waehle() {
    while (true) {
      std::cout << "********** Mischbare Rezepte **********" << std::endl;
      theMischbaresRezeptbuch->browse();
      std::cout << "Was haetten Sie denn gern? (-1 zum Verlassen)" << std::endl;

      std::string input = "";

      // std::cin.ignore();
      std::cin >> input;

      int inputNumber = atoi(input.c_str());
      //int max = theMischbaresRezeptbuch->getNumberOfRecipes();
      if (inputNumber == -1) {
        exit(0);
      }
      return checkInput(input, inputNumber);
    }
}
int CocktailPro::checkInput(const std::string &input, int inputNumber) {
  int inputInList = checkInputInList(inputNumber);
  if(inputInList!=0)
    return inputNumber;
  std::cout << "MEEEP! Too many fingers on keyboard error!" << std::endl;
  std::cout << "Ihre Eingabe: " << input << " ist nicht in der Auswahl vorhanden!" << std::endl;
  return 0;
}

int CocktailPro::checkInputInList(int inputNumber) {
  int inputIsInList = 0;
  for (int rlist = 0; rlist < theMischbaresRezeptbuch->getNumberOfRecipes(); rlist++) {
    if (inputNumber == theMischbaresRezeptbuch->getRecipe(rlist)->getNumber()) {
      inputIsInList = inputNumber;
    }
  }
  return inputIsInList;
}


CocktailPro& CocktailPro::operator=(CocktailPro overload) {
  theMischbaresRezeptbuch = overload.theMischbaresRezeptbuch;
  theDeviceVerwalter = overload.theDeviceVerwalter;
  theCocktailZubereiter = overload.theCocktailZubereiter;
  theZutatenVerwalter = overload.theZutatenVerwalter;
  return *this;
}

