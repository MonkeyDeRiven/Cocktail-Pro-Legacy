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

  for(u_int16_t k = 0; k<rzpt->getNoOfRecipeSteps(); ++k){
    RecipeStep* schritt = rzpt->getRecipeStep(k);//we use the same pointer as above, as it is already pointing to the right date
    std::string putzen = schritt->getZutat();
    std::cout << "Device mit der Aktion:" << putzen << " wird jetzt geputzt" << std::endl;
  }
  return (true);


  //for (std::map<std::string, InternalDevice *>::iterator cleanIt = myDeviceVerwalter->myDevices->begin();
  //     cleanIt != myDeviceVerwalter->myDevices->end(); ++cleanIt) {
   // std::cout << "Device mit der Aktion: " << cleanIt->first << " wird jetzt geputzt: " << std::endl;
  //  cleanIt->second->putzen();
 // }
}
/*DeviceVerwalter *CocktailZubereiter::getMyDeviceVerwalter() const {
  return myDeviceVerwalter;
}
CocktailZubereiter& CocktailZubereiter::operator=(CocktailZubereiter overload) {
  this->myDeviceVerwalter = overload.getMyDeviceVerwalter();
  return *this;
}*/

