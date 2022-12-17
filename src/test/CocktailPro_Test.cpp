#include <string>
#include "gtest/gtest.h"
#define protected public
#define private public
#include "Timer.h"
#include "CocktailPro.h"
#undef protected
#undef private

class CocktailPro_Test : public ::testing::Test {

 protected:
  CocktailPro* testPro;
  std::basic_streambuf<char>* oldBufInput;
  std::stringstream new_cin;
  int inputNumber = 10;
  std::string input = "5";
  int max = 20;
  char** demomode;
  Timer *theTimer;

  virtual void SetUp() {
    oldBufInput = std::cin.rdbuf(new_cin.rdbuf());
    demomode = new char*[2];
    char demoChar[2] = {'-', 'X'};
    demomode[1] = demoChar;
    testPro = new CocktailPro(2,demomode);
    theTimer = Timer::getInstance();
    theTimer->set_Turbo(1000);
  }
  virtual void TearDown() {
    std::cin.rdbuf(oldBufInput);
    delete [] demomode;
    delete testPro;
  }
};


TEST_F(CocktailPro_Test, waehleTest){
  new_cin << "5" << std::endl;
  EXPECT_EQ(testPro->waehle(), 5);
  new_cin.clear();
  new_cin << "0" << std::endl;
  EXPECT_EQ(testPro->waehle(), 0);
}

TEST_F(CocktailPro_Test, testStartMinus2){
  testPro->isATest2 = true;
  testPro->start();
  EXPECT_EQ(testPro->isATest2, false);
}

TEST_F(CocktailPro_Test, overload){
  CocktailPro* cpy(testPro);

  EXPECT_EQ(cpy, testPro);

  CocktailPro* overload = new CocktailPro(2, demomode);

  overload = testPro;

  EXPECT_EQ(overload, testPro);

}
TEST_F(CocktailPro_Test, checkInputInListForStartIfExitWithExistingCocktailEqualsTrueAndTestPrepareCocktail){
  int numOfCocktails = testPro->waehle();
  bool cocktailExist = false;
  int max = testPro->theMischbaresRezeptbuch->getNumberOfRecipes();
  testPro->theMischbaresRezeptbuch->getRecipe(0)->setNumber(0);
  testPro->checkInputInListForStart(numOfCocktails, max, cocktailExist);
  EXPECT_EQ(true, cocktailExist);

  bool cocktailExists = true;
  Recipe* testRecipe = new Recipe();
  testRecipe->setNumber(1);
  testRecipe->setName("TestCocktail");
  testPro->theMischbaresRezeptbuch->recipeList.push_back(testRecipe);
  numOfCocktails = 1;
  testPro->prepareCocktail(cocktailExists, numOfCocktails);
  EXPECT_EQ(true, testPro->testFlag);
}

TEST_F(CocktailPro_Test, testStart){
  testPro->setIsATest(true);
  testPro->start();
  EXPECT_EQ(false, testPro->getIsATest());
}

TEST_F(CocktailPro_Test, assignmentOperatorCocktailPro){
  CocktailPro * testPro2 = testPro;
  EXPECT_EQ(testPro2,testPro);
}

