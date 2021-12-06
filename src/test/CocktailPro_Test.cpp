#include <string>
#include "gtest/gtest.h"
#define protected public
#define private public

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

  virtual void SetUp() {
    oldBufInput = std::cin.rdbuf(new_cin.rdbuf());
    demomode = new char*[2];
    char demoChar[2] = {'-', 'D'};
    demomode[1] = demoChar;
    testPro = new CocktailPro(2,demomode);

  }
  virtual void TearDown() {
    std::cin.rdbuf(oldBufInput);
    delete [] demomode;
    delete testPro;
  }
};


TEST_F(CocktailPro_Test, checkInput){
  EXPECT_EQ(10, testPro->checkInput(input, inputNumber, max));
}
TEST_F(CocktailPro_Test, checkInputMax){
  EXPECT_LE(testPro->checkInputMax(input, inputNumber, max), max);
}
TEST_F(CocktailPro_Test, waehleTest){

  new_cin << "5" << std::endl;
  EXPECT_EQ(testPro->waehle(), 5);
  new_cin.clear();
  new_cin << "0" << std::endl;

  EXPECT_EQ(testPro->waehle(), 0);
}