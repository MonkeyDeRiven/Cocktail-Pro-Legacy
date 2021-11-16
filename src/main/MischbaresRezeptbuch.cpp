//@(#) MischbaresRezeptbuch.cpp


#include "MischbaresRezeptbuch.h"
#include <iostream>
//

void MischbaresRezeptbuch::browse() {
    std::cout << "*********************************************" << std::endl;
    std::cout << "Es gibt " << this->getNumberOfRecipes() << " Cocktails" << std::endl;

    for (int i = 0; i<this->getNumberOfRecipes(); i++) {
        Recipe* r = this->getRecipe(i);
        std::cout << i + 1 << ". ";
        r->browse();
        std::cout << std::endl;
    }
    std::cout << "*********************************************" << std::endl;

}

MischbaresRezeptbuch::MischbaresRezeptbuch(VorhandeneZutaten * zv) {

    // Debug *********
    std::cout << "********** Rezepte vor dem Filtern **********" << std::endl;
    browse();
    // ******************

    setZutatenVerwalter(zv);

  for (int i = 0; i < getNumberOfRecipes(); i++) {//iterates through recipes
    bool verifiedRecipe = true;
    Recipe *r = getRecipe(i);
    for (int j = 0; j < r->getNoOfRecipeSteps(); j++) {//iterates through recipe steps
      std::string gesuchteZutat;

      gesuchteZutat = r->getRecipeStep(j)->getZutat();

      bool foundIngredient = isIngredientInStock(gesuchteZutat);
      if (!foundIngredient) {
        verifiedRecipe = false;
      }
    }
    if (!verifiedRecipe) {
      deleteRecipe(i);
    }
  }
}
bool MischbaresRezeptbuch::isIngredientInStock(const std::string &gesuchteZutat) {
  for (int k = 0; k < myZutatenVerwalter->getAnzahlVorhandeneZutaten(); k++) {//checks for needed ingredient
    if (myZutatenVerwalter->getZutat(k) == gesuchteZutat) {
      return true;
    }
  }
  return false;
}

void MischbaresRezeptbuch::setZutatenVerwalter(VorhandeneZutaten * zv) {
    myZutatenVerwalter = zv;
}

