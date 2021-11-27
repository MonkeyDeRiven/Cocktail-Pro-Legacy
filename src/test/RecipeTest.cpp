#include <limits.h>
#include "gtest/gtest.h"

#define protected public
#define private public
#include "Recipe.h"
#undef protected
#undef private

class RecipeTest : public ::testing::Test {
 protected:
  Recipe* r;

  virtual void SetUp() {
    r = new Recipe();

    r->m_RecipeStep.clear();
    r->m_Name="Caipirinha";
  }

  virtual void TearDown() {
    delete r;
  }
};

TEST_F(RecipeTest,getNoOfRecipeStepsReturnsValueOfAttribute) {
  int noOfRecipeSteps=r->m_RecipeStep.size();
  EXPECT_EQ(noOfRecipeSteps,r->getNoOfRecipeSteps());
}

TEST_F(RecipeTest,getRecipeStep) {

}

TEST_F(RecipeTest,getNameReturnName) {
  std::string name=r->m_Name;
  EXPECT_EQ(name,"Caipirinha");
}

TEST_F(RecipeTest,setName) {

}

TEST_F(RecipeTest,appendStep){
  RecipeStep* step;
  step=r->appendStep("Limettenstuecke", 8);
  float m= step->getMenge();
  std::string z= step->getZutat();
  EXPECT_EQ(m,8);
  EXPECT_EQ(z,"Limettenstuecke");
}