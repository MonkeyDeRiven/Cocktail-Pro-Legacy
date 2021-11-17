//@(#) CocktailPro.cpp


#include "CocktailPro.h"
#include <string>

void CocktailPro::start(){
    while (true) {
        int CocktailNo = waehle();
        int max = theMischbaresRezeptbuch->getNumberOfRecipes();
        if (CocktailNo > 0 && CocktailNo <= max) {
            Recipe * rezeptptr = theMischbaresRezeptbuch->getRecipe(CocktailNo - 1);
            std::cout << rezeptptr->getName() << std::endl;
            theCocktailZubereiter->cocktailZubereiten(rezeptptr);
        } else {
            std::cout << "Falsche Cocktailnummer!" << std::endl;
        }
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

        //cin.ignore();       
        std::cin >> input;

        int inputNumber = atoi(input.c_str());
        int max = theMischbaresRezeptbuch->getNumberOfRecipes();
        if (inputNumber == -1) {
          exit(0);
        }
        
        return checkInput(input, inputNumber, max);
    }
}
int CocktailPro::checkInput(const std::string &input, int inputNumber, int max) const {

  if (inputNumber > 0 && inputNumber <= max) {
      return inputNumber;
  } else {
      //std::system("clear");
      std::cout << "MEEEP! Too many fingers on keyboard error!" << std::endl;
      std::cout << "Ihre Eingabe: " << input << " war nicht zwischen 1 und " << max << "!" << std::endl;
      return 0;
  }
}

CocktailPro& CocktailPro::operator=(CocktailPro overload) {
  theMischbaresRezeptbuch = overload.theMischbaresRezeptbuch;
  theDeviceVerwalter = overload.theDeviceVerwalter;
  theCocktailZubereiter = overload.theCocktailZubereiter;
  theZutatenVerwalter = overload.theZutatenVerwalter;
  return *this;
}

