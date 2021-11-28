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

