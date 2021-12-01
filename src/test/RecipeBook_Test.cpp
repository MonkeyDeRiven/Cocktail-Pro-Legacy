#include <limits.h>
#include "gtest/gtest.h"

#define protected public
#define private public
#include "RecipeBook.h"
#undef protected
#undef private

class RecipeBookTest : public ::testing::Test {
 protected:
  RecipeBook* r;

  virtual void SetUp() {
        r = new RecipeBook();
        // you never know what the constructor is really doing
        // so make the list empty and fill it yourself!
        
        r->m_Recipe.clear();
        Recipe* r1;

        r1 = new Recipe;
        r1->setName("Caipirinha");
        r1->appendStep("Limettenstuecke", 8);
        r->m_Recipe.push_back(r1);

        r1 = new Recipe;
        r1->setName("Margarita");
        r1->appendStep("Zitronensaft", 2);
        r->m_Recipe.push_back(r1);
          
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test
    // (right before the destructor).
    delete r;
  }
};

TEST_F(RecipeBookTest,getNumberOfRecipesReturnsValueOfAttribute){
    int noOfRecipes=r->m_Recipe.size();
    EXPECT_EQ(noOfRecipes,r->getNumberOfRecipes());
}

TEST_F(RecipeBookTest,getRecipeReturnsCorrectRecipe){
    Recipe* rez;
    rez = r->getRecipe(0);
    EXPECT_EQ(rez->getName(),"Caipirinha");

    rez = r->getRecipe(1);
    EXPECT_EQ(rez->getName(),"Margarita");
}

TEST_F(RecipeBookTest,deleteRecipeRemovesCorrectRecipe){
    EXPECT_FALSE(r->deleteRecipe(-1));
    EXPECT_FALSE(r->deleteRecipe(42));
    EXPECT_FALSE(r->deleteRecipe(2)); 
    
    EXPECT_TRUE(r->deleteRecipe(0));
    // Since recipe #0 is deleted now Margarita is #0
    Recipe* rez;
    rez = r->getRecipe(0);
    EXPECT_EQ(rez->getName(),"Margarita");    
}

TEST_F(RecipeBookTest, addRecipeAddsCorrectRecipe){
  std::ifstream recipes;
  std::istringstream input("Bloody Mary;Bananen;10;Eis;5\nMy Drink;Zucker;2;Limetten;6");
  recipes.basic_ios<char>::rdbuf(input.rdbuf());
  //recipes.open("C:\\Users\\Max\\clion_projects\\src\\test\\RecipeBookTest.txt", std::ifstream::in);
  std::string line;
  EXPECT_EQ(r->getNumberOfRecipes(), 2);
  r->addRecipes(recipes, line);
  EXPECT_EQ(r->getNumberOfRecipes(), 4);
  EXPECT_EQ(r->getRecipe(3)->getName(), "My Drink");
}

TEST_F(RecipeBookTest, importRecipeCreatesRecipe){
  Recipe testRecipe;
  std::istringstream input("Bananen;10;Eis;5");
  r->importRecipe(input, &testRecipe);
  EXPECT_EQ(testRecipe.getNoOfRecipeSteps(), 2);
  EXPECT_EQ(testRecipe.getRecipeStep(0)->getMenge(), 10);
  EXPECT_EQ(testRecipe.getRecipeStep(1)->getZutat(), "Eis");
}

TEST_F(RecipeBookTest, RecipeElseAppendsTxtSteps){
  std::ifstream recipes;
  std::istringstream input("Bloody Mary;Bananen;10;Eis;5\nMy Drink;Zucker;2;Limetten;6");
  recipes.basic_ios<char>::rdbuf(input.rdbuf());
  r->recipeElse(recipes);
  EXPECT_EQ(r->getNumberOfRecipes(), 4);
  EXPECT_EQ(r->getRecipe(2)->getName(), "Bloody Mary");
}