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
  std::string ingredient = "Banana";
  RecipeStep* step = new RecipeStep();
  virtual void setup(){

  }

  virtual void tearDown(){
    delete step;
  }
};

TEST_F(RecipeStepTest, getIngredient){
  step->setZutat(ingredient);
  std::string testIngredient = step->getZutat();
  EXPECT_EQ(testIngredient, "Banana");
}

TEST_F(RecipeStepTest, getIngredientAmount){
  step->setMenge(0.5);
  EXPECT_EQ(step->getMenge(), 0.5);
}

TEST_F(RecipeStepTest, setIngredient){
  ingredient = "Apfel";
  step->setZutat(ingredient);
  EXPECT_EQ(step->getZutat(), "Apfel");
}

TEST_F(RecipeStepTest, setAmount){
  step->setMenge(1.5);
  EXPECT_EQ(step->getMenge(), 1.5);
}