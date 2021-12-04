#include "gtest/gtest.h"

#define private public
#include "Recipe.h"

class RecipeTest : public ::testing::Test {
 protected:
  Recipe* r;

  virtual void SetUp() {
    r = new Recipe();

    r->m_RecipeStep.clear();
    r->m_Name="Caipirinha";

    r->appendStep("Limettenstuecke", 8);
    r->appendStep("Zucker", 15);
    r->appendStep("Stampfen", 20);
    r->appendStep("Eis", 90);
    r->appendStep("Cachaca", 5);
    r->appendStep("Mischen", 10);
  }

  virtual void TearDown() {
    delete r;
  }
};

TEST_F(RecipeTest,getNoOfRecipeStepsReturnsValueOfAttribute) {
  int noOfRecipeSteps=r->m_RecipeStep.size();
  EXPECT_EQ(noOfRecipeSteps,r->getNoOfRecipeSteps());
}

TEST_F(RecipeTest,getRecipeStepReturnsCorrectRecipeStep){
  RecipeStep* rezstep;
  rezstep = r->getRecipeStep(0);
  EXPECT_EQ(rezstep->getZutat(),"Limettenstuecke");
}

TEST_F(RecipeTest,getNameReturnName) {
  std::string name=r->m_Name;
  EXPECT_EQ(name,"Caipirinha");
}

TEST_F(RecipeTest,setName) {
  r->setName("Margarita");
  EXPECT_EQ(r->getName(),"Margarita");
}

TEST_F(RecipeTest,browseReturnRecipeSteps) {
  std::vector<std::string>* steps;
  steps=r->browse();
  EXPECT_EQ(steps->at(0),"Limettenstuecke");
  EXPECT_EQ(steps->at(1),"Zucker");
  EXPECT_EQ(steps->at(2),"Stampfen");
  EXPECT_EQ(steps->at(3),"Eis");
  EXPECT_EQ(steps->at(4),"Cachaca");
  EXPECT_EQ(steps->at(5),"Mischen");
}

TEST_F(RecipeTest,appendStep){
  RecipeStep* step;
  step=r->appendStep("Limettenstuecke", 8);
  float m= step->getMenge();
  std::string z= step->getZutat();
  EXPECT_EQ(m,8);
  EXPECT_EQ(z,"Limettenstuecke");
}