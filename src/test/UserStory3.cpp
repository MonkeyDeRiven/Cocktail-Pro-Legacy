#include <limits.h>
#include "gtest/gtest.h"

#define protected public
#define private public
#include "CocktailPro.h"
#undef protected
#undef private

class UserStory3Test : public ::testing::Test {
 protected:
  CocktailZubereiter * theCocktailZubereiter;
  DeviceVerwalter * theDeviceVerwalter;
  MischbaresRezeptbuch * theMischbaresRezeptbuch;
  VorhandeneZutaten * theZutatenVerwalter;

  virtual void SetUp() {
    theZutatenVerwalter = new VorhandeneZutaten;
    theMischbaresRezeptbuch = new MischbaresRezeptbuch(theZutatenVerwalter);
    theDeviceVerwalter = new DeviceVerwalter(theZutatenVerwalter);
    theCocktailZubereiter = new CocktailZubereiter(theDeviceVerwalter);
    Timer *t = Timer::getInstance();
    t->set_Turbo(1000);
  }

  virtual void TearDown() {
    delete theCocktailZubereiter;
    delete theDeviceVerwalter;
    delete theMischbaresRezeptbuch;
    delete theZutatenVerwalter;
  }
};

TEST_F(UserStory3Test, userStoryTestFull){
  int CocktailNo = 1;
  Recipe * rezeptptr = theMischbaresRezeptbuch->getRecipe(CocktailNo - 1);
  std::cout << rezeptptr->getName() << std::endl;
  theCocktailZubereiter->cocktailZubereiten(rezeptptr, theZutatenVerwalter);
  theZutatenVerwalter->browse();
  std::cout << std::endl << "********** Mischbare Rezepte **********" << std::endl;
  theMischbaresRezeptbuch->browse();
  std::cout << std::endl << std::endl;
  std::cout << "Neuer Test:" << std::endl;
}

TEST_F(UserStory3Test, userStoryTestEmty){
  int CocktailNo = 1;
  Recipe * rezeptptr = theMischbaresRezeptbuch->getRecipe(CocktailNo - 1);
  std::cout << rezeptptr->getName() << std::endl;
  theCocktailZubereiter->cocktailZubereiten(rezeptptr, theZutatenVerwalter);
  theZutatenVerwalter->zutaten->at(0)->setAmount(40);
  theZutatenVerwalter->browse();
  std::cout << std::endl << "********** Mischbare Rezepte **********" << std::endl;
  theMischbaresRezeptbuch->browse();
  std::cout << rezeptptr->getName() << std::endl;
  theCocktailZubereiter->cocktailZubereiten(rezeptptr, theZutatenVerwalter);
  std::cout << std::endl << std::endl;
}
