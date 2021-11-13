//@(#) CocktailZubereiter.cpp


#include "CocktailZubereiter.h"

CocktailZubereiter::CocktailZubereiter(DeviceVerwalter * dv) {
    myDeviceVerwalter = dv;
}

bool CocktailZubereiter::cocktailZubereiten(Recipe * rzpt) {
    //std::system("clear");
    std::cout << "Hallo, ich bin der CocktailZubereiter!" << std::endl
            << "Ich habe Ihre Bestellung: " << rzpt->getName() << " erhalten." << std::endl
            << "Jetzt geht es los!\n" << std::endl;
	int i=0;
    for (i = 0; i < rzpt->getNoOfRecipeSteps(); i++) {
        RecipeStep * schritt = rzpt->getRecipeStep(i);
        std::string zutat = schritt->getZutat();
        float menge = schritt->getMenge();
        std::cout << "Rezeptschritt: " << zutat << ", " << menge << std::endl;
        myDeviceVerwalter->rezeptSchrittZubereiten(zutat, menge);
    }
  myDeviceVerwalter->myEntleerer->doIt(i);

  for (std::map<std::string, InternalDevice *>::iterator i1 = myDeviceVerwalter->myDevices->begin();
       i1 != myDeviceVerwalter->myDevices->end(); ++i1) {
    std::cout << "Device mit der Aktion: " << i1->first << " wird jetzt geputzt: " << std::endl;
    i1->second->putzen();
  }
  return (true);
}
/*DeviceVerwalter *CocktailZubereiter::getMyDeviceVerwalter() const {
  return myDeviceVerwalter;
}
CocktailZubereiter& CocktailZubereiter::operator=(CocktailZubereiter overload) {
  this->myDeviceVerwalter = overload.getMyDeviceVerwalter();
  return *this;
}*/

