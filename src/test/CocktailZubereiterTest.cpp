//
// Created by Max on 01.12.2021.
//


#include <limits.h>
#include "gtest/gtest.h"

#define protected public
#define private public
#include "CocktailZubereiter.h"
#undef protected
#undef private

class CocktailZubereiterTest : public ::testing::Test {
 protected:
  VorhandeneZutaten* vz;
  DeviceVerwalter* dv;
  CocktailZubereiter* r;
  Recipe* recipe;
  std::basic_streambuf<char>* oldBufOutput;
  std::stringstream newCout;

  virtual void SetUp() {
    oldBufOutput = std::cout.rdbuf(newCout.rdbuf());
    vz = new VorhandeneZutaten();
    dv = new DeviceVerwalter(vz);
    r = new CocktailZubereiter(dv);
    r->myDeviceVerwalter->mySchuettler->myTimer->set_Turbo(20);

    recipe = new Recipe();
    recipe->setName("Caipirinha");
    recipe->appendStep("Limettenstuecke", 8);
  }

  virtual void TearDown() {
    std::cout.rdbuf(oldBufOutput);
    delete r;
  }
};

TEST_F(CocktailZubereiterTest, cocktailZubereiterInitialisesCorrect){
  EXPECT_EQ(r->myDeviceVerwalter, dv);
}

TEST_F(CocktailZubereiterTest, cocktailZubereitenDoesNotCrash){
  EXPECT_EQ(r->cocktailZubereiten(recipe, vz), true);
}

TEST_F(CocktailZubereiterTest, setAmountToGramm){
  float amount = 10;
  std:: string Eis = "Eis";
  std::string Limettenstuecke = "Limettenstuecke";

  EXPECT_EQ(r->amountToGramm(Eis,amount), 20);
  EXPECT_EQ(r->amountToGramm(Limettenstuecke, amount), 100);
}

/*TEST_F(CocktailZubereiterTest, CleanUsedDev) {
  int number = 1;
  recipe->setNumber(number);

  newCout.flush();
  r->cleanUsedDevices(recipe);
  std::string testString = "Device mit der Aktion:Limettenstuecke wird jetzt geputzt\n";
  EXPECT_EQ(testString, newCout.str().substr(318));
}*/
