#include <limits.h>
#include "gtest/gtest.h"

#define protected public
#define private public
#include "CocktailPro.h"
#undef protected
#undef private

class UserStory4Test : public ::testing::Test {
 protected:
  VorhandeneZutaten* vz;
  std::string IngredientName;

  virtual void SetUp() {
    vz = new VorhandeneZutaten();
    vz->zutaten->clear();
    IngredientName = "Limettensaft";
    vz->zutaten->push_back(new Ingredient(IngredientName, 1000));
    IngredientName = "Tequilla";
    vz->zutaten->push_back(new Ingredient(IngredientName, 1000));
    IngredientName = "Gin";
    vz->zutaten->push_back(new Ingredient(IngredientName, 500));
    IngredientName = "Gin";
    vz->zutaten->push_back(new Ingredient(IngredientName, 1000));
    IngredientName = "Noilly Prat";
    vz->zutaten->push_back(new Ingredient(IngredientName, 1000));
    IngredientName = "Mischen";
    vz->zutaten->push_back(new Ingredient(IngredientName, 0));
    IngredientName = "Stampfen";
    vz->zutaten->push_back(new Ingredient(IngredientName, 0));
    IngredientName = "Schuetteln";
    vz->zutaten->push_back(new Ingredient(IngredientName, 0));
  }

  virtual void TearDown() {
    delete vz;
  }
};

TEST_F(UserStory4Test, isSecondDispenserUsed){
  std::string name = "Gin";
  Ingredient* secondGin = vz->getIngredientByName(name);
  EXPECT_EQ(secondGin->getAmount(), 1000);

  secondGin->setAmount(0);
  Ingredient* firstGin = vz->getIngredientByName(name);
  EXPECT_EQ(firstGin->getAmount(), 500);
}