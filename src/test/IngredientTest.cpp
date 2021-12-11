//
// Created by kaane on 11.12.2021.
//
#include "gtest/gtest.h"
#define protected public
#define private public

#include "CocktailPro.h"
#undef protected
#undef private

class IngredientTest : public ::testing::Test {
  protected:
  Ingredient* i;


  void SetUp(){
    std::string name = "Wodka";
    int amount = 100;
    i = new Ingredient(name, amount);
  }
  void TearDown(){
    delete i;
  }
};

TEST_F(IngredientTest, getterAndSetter){
  EXPECT_EQ(i->getName(), "Wodka");
  EXPECT_EQ(i->getAmount(), 100);
  int amount = 50;
  i->setAmount(50);
  EXPECT_EQ(i->getAmount(), amount);

}
TEST_F(IngredientTest, getterAmount){

  EXPECT_EQ(i->getAmount(), 100);

}
TEST_F(IngredientTest, setAmount){

  int amount = 50;
  i->setAmount(50);
  EXPECT_EQ(i->getAmount(), amount);

}