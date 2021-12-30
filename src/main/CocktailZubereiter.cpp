//@(#) CocktailZubereiter.cpp


#include "CocktailZubereiter.h"

CocktailZubereiter::CocktailZubereiter(DeviceVerwalter * dv) {
    myDeviceVerwalter = dv;
}

bool CocktailZubereiter::cocktailZubereiten(Recipe * rzpt, VorhandeneZutaten* ingredients) {
    //std::system("clear");
    std::cout << "Hallo, ich bin der CocktailZubereiter!" << std::endl
            << "Ich habe Ihre Bestellung: " << rzpt->getName() << " erhalten." << std::endl
            << "Jetzt geht es los!\n" << std::endl;
	int i=0;
    bool enoughAmount=true;
  prepareSteps(rzpt, ingredients, i, enoughAmount);
  if(enoughAmount){
      myDeviceVerwalter->myEntleerer->doIt(i);
      cleanUsedDevices(rzpt);
    }else
      std::cout << "Diese Zutat ist leer! Bitte nachfüllen!" << std::endl;
  return (true);


  //for (std::map<std::string, InternalDevice *>::iterator cleanIt = myDeviceVerwalter->myDevices->begin();
  //     cleanIt != myDeviceVerwalter->myDevices->end(); ++cleanIt) {
   // std::cout << "Device mit der Aktion: " << cleanIt->first << " wird jetzt geputzt: " << std::endl;
  //  cleanIt->second->putzen();
 // }
}

void CocktailZubereiter::prepareSteps(Recipe *rzpt, VorhandeneZutaten *ingredients, int &i, bool &enoughAmount) {
  for (i = 0; i < rzpt->getNoOfRecipeSteps(); i++) {
      RecipeStep * schritt = rzpt->getRecipeStep(i);
      std::string zutat = schritt->getZutat();
      float menge = schritt->getMenge();
      float amountInGramm = amountToGramm(zutat, menge);
      std::cout << "Rezeptschritt: " << zutat << ", " << menge << std::endl;
      int restAmount = ingredients->getIngredientByName(zutat)->getAmount() - amountInGramm;
      if(i!=rzpt->getNoOfRecipeSteps()-1&&rzpt->getRecipeStep(i)->getZutat()!= "Stampfen") {
        if (restAmount < 0) {
          ingredients->getIngredientByName(zutat)->setAmount(0);
          enoughAmount=false;
          break;
        } else {
          ingredients->getIngredientByName(zutat)->setAmount(restAmount);
        }
      }
      myDeviceVerwalter->rezeptSchrittZubereiten(zutat, menge);
  }
}

void CocktailZubereiter::cleanUsedDevices(Recipe *rzpt) const {
  for(u_int16_t k = 0; k<rzpt->getNoOfRecipeSteps(); ++k){
    RecipeStep* schritt = rzpt->getRecipeStep(k);//we use the same pointer as above, as it is already pointing to the right date
    std::string putzen = schritt->getZutat();
    std::cout << "Device mit der Aktion:" << putzen << " wird jetzt geputzt" << std::endl;
  }
}
float CocktailZubereiter::amountToGramm(const std::string &zutat, float menge) const {
  float amountInGramm = menge;
  if(zutat == "Limettenstuecke"){
    amountInGramm = menge*10;
  }
  if(zutat == "Eis"){
    amountInGramm = menge + 10;
  }
  return amountInGramm;
}
/*DeviceVerwalter *CocktailZubereiter::getMyDeviceVerwalter() const {
  return myDeviceVerwalter;
}
CocktailZubereiter& CocktailZubereiter::operator=(CocktailZubereiter overload) {
  this->myDeviceVerwalter = overload.getMyDeviceVerwalter();
  return *this;
}*/

