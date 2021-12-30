//@(#) CocktailZubereiter.cpp


#include "CocktailZubereiter.h"

CocktailZubereiter::CocktailZubereiter(DeviceVerwalter * dv) {
  myDeviceVerwalter = dv;
}

bool CocktailZubereiter::cocktailZubereiten(Recipe * rzpt, VorhandeneZutaten* ingredients) {
  //std::system("clear");
  checkMixinPossible(rzpt, ingredients);
  if(!ausreichend) return false;

    std::cout << "Hallo, ich bin der CocktailZubereiter!" << std::endl
              << "Ich habe Ihre Bestellung: " << rzpt->getName() << " erhalten." << std::endl
              << "Jetzt geht es los!\n" << std::endl;
    int i = 0;

    for (i = 0; i < rzpt->getNoOfRecipeSteps(); i++) {

      RecipeStep *schritt = rzpt->getRecipeStep(i);
      std::string zutat = schritt->getZutat();
      float menge = schritt->getMenge();
      float amountInGramm = amountToGramm(zutat, menge);

      std::cout << "Rezeptschritt: " << zutat << ", " << menge << std::endl;
      int restAmount = ingredients->getIngredientByName(zutat)->getAmount() - amountInGramm;
      if (restAmount < 0) {
        ingredients->getIngredientByName(zutat)->setAmount(0);
      } else {
        ingredients->getIngredientByName(zutat)->setAmount(restAmount);
      }
      myDeviceVerwalter->rezeptSchrittZubereiten(zutat, menge);
    }

    myDeviceVerwalter->myEntleerer->doIt(i);


  cleanUsedDevices(rzpt);
  return (true);


  //for (std::map<std::string, InternalDevice *>::iterator cleanIt = myDeviceVerwalter->myDevices->begin();
  //     cleanIt != myDeviceVerwalter->myDevices->end(); ++cleanIt) {
  // std::cout << "Device mit der Aktion: " << cleanIt->first << " wird jetzt geputzt: " << std::endl;
  //  cleanIt->second->putzen();
  // }
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

void CocktailZubereiter::checkMixinPossible(Recipe *rzpt, VorhandeneZutaten *ingredients) {
  for (int i = 0; i < rzpt->getNoOfRecipeSteps() - 1; ++i){

      RecipeStep *schritt = rzpt->getRecipeStep(i);
      std::string zutat = schritt->getZutat();
      float menge = schritt->getMenge();
      float amountInGramm = amountToGramm(zutat, menge);

      if (zutat == "Stampfen")
        continue;

      if (ingredients->getIngredientByName(zutat)->getAmount() < amountInGramm) {
       std::cout << " ===== Der Cocktail kann nicht zubereitet werden, da die Zutat " << zutat
                 << " nicht ausreichend vorhanden ist =====\n";
       ausreichend = false;
      }
  }

}