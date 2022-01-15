//
// Created by arian on 23/11/2021.
//

#include <limits.h>
#include "gtest/gtest.h"

#define protected public
#define private public
#include "MischbaresRezeptbuch.h"
#undef protected
#undef private

class MischbaresRezeptbuchTest : public ::testing::Test {
 protected:
  VorhandeneZutaten* ingredients;
  MischbaresRezeptbuch* mixableRecipeBook;

  virtual void SetUp() {
    ingredients = new VorhandeneZutaten();
    mixableRecipeBook = new MischbaresRezeptbuch(ingredients);
    mixableRecipeBook->recipeList.clear();

    Recipe* testRecipe1 = new Recipe();
    testRecipe1->setName("Margarita");
    testRecipe1->appendStep("Zitronensaft", 2);
    testRecipe1->appendStep("Cointreau", 2);
    testRecipe1->appendStep("Tequilla", 4);
    testRecipe1->appendStep("Eis", 50);
    testRecipe1->appendStep("Mischen", 20);
    mixableRecipeBook->recipeList.push_back(testRecipe1);


    Recipe* testRecipe2 = new Recipe();
    testRecipe2->setName("Planters Punch");
    testRecipe2->appendStep("Zitronensaft", 2);
    testRecipe2->appendStep("Grenadine", 1);
    testRecipe2->appendStep("Orangensaft", 8);
    testRecipe2->appendStep("Rum braun", 6);
    testRecipe2->appendStep("Eis", 100);
    testRecipe2->appendStep("Mischen", 20);
    mixableRecipeBook->recipeList.push_back(testRecipe2);

  }

  virtual void TearDown() {
    // Code here will be called immediately after each test
    // (right before the destructor).
    delete ingredients;
    delete mixableRecipeBook;
  }
};

TEST_F(MischbaresRezeptbuchTest,isRecipeValidTest){
  bool valid = mixableRecipeBook->isRecipeStepValid(mixableRecipeBook->recipeList[0]);
  EXPECT_EQ(valid, true);
  valid = mixableRecipeBook->isRecipeStepValid(mixableRecipeBook->recipeList[1]);
  EXPECT_EQ(valid, false);
}

TEST_F(MischbaresRezeptbuchTest, isIngredientInStock){
  bool valid = mixableRecipeBook->isIngredientInStock("Zucker");
  EXPECT_EQ(valid, true);
  valid = mixableRecipeBook->isIngredientInStock("Rum braun");
  EXPECT_EQ(valid, false);
}

TEST_F(MischbaresRezeptbuchTest, setZutatenVerwalter){
  mixableRecipeBook->setZutatenVerwalter(nullptr);
  EXPECT_EQ(mixableRecipeBook->myZutatenVerwalter, nullptr);
  mixableRecipeBook->setZutatenVerwalter(ingredients);
  EXPECT_EQ( mixableRecipeBook->myZutatenVerwalter, ingredients);
}

TEST_F(MischbaresRezeptbuchTest, allRecipesMixableTrueTest){
  mixableRecipeBook->getRecipe(1)->isMixable = false;
  mixableRecipeBook->allRecipesMixableTrue();
  EXPECT_EQ(mixableRecipeBook->getRecipe(1)->isMixable, true);
}