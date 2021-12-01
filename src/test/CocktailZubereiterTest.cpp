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

  virtual void SetUp() {
    vz = new VorhandeneZutaten();
    dv = new DeviceVerwalter(vz);
    r = new CocktailZubereiter(dv);
    r->myDeviceVerwalter->mySchuettler->myTimer->set_Turbo(20);

    recipe = new Recipe();
    recipe->setName("Caipirinha");
    recipe->appendStep("Limettenstuecke", 8);
  }

  virtual void TearDown() {
    delete r;
  }
};

TEST_F(CocktailZubereiterTest, cocktailZubereiterInitialisesCorrect){
  EXPECT_EQ(r->myDeviceVerwalter, dv);
}

TEST_F(CocktailZubereiterTest, cocktailZubereitenDoesNotCrash){
  EXPECT_EQ(r->cocktailZubereiten(recipe), true);
}