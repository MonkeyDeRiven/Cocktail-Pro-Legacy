//
// Created by arian on 23/11/2021.
//

#include <limits.h>
#include "gtest/gtest.h"

#define protected public
#define private public
#include "RecipeStep.h"
#undef protected
#undef private

class RecipeStepTest : public ::testing::Test{
 protected:
  std::string ingredient;
  RecipeStep* step;
  virtual void setup(){
    ingredient = "Banana";
    step = new RecipeStep();
    step->setZutat(ingredient);
    step->setMenge(0.7);
  }

  virtual void tearDown(){
    delete step;
  }
};

TEST_F(RecipeStepTest, getIngredient){
  std::string testIngredient = step->getZutat();
  EXPECT_EQ(testIngredient, "Banana");
}

TEST_F(RecipeStepTest, getIngredientAmount){
  int amount = step->getMenge();
  EXPECT_EQ(amount, 0.7);
}

TEST_F(RecipeStepTest, setIngredient){
  ingredient = "Apfel";
  step->setZutat(ingredient);
  EXPECT_EQ(step->getZutat(), "Apfel");
}

TEST_F(RecipeStepTest, setAmount){
  step->setMenge(1.33);
  EXPECT_EQ(step->getMenge(), 1.33);
}