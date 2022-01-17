#include <limits.h>
#include "gtest/gtest.h"

#define protected public
#define private public
#include "CocktailPro.h"
#undef protected
#undef private

class UserStory5Test : public ::testing::Test {
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
    delete ingredients;
    delete mixableRecipeBook;
  }
};

TEST_F(UserStory5Test, allRecipesMixableTrueTest){
  mixableRecipeBook->getRecipe(1)->isMixable = false;
  mixableRecipeBook->allRecipesMixableTrue();
  EXPECT_EQ(mixableRecipeBook->getRecipe(1)->isMixable, true);
}