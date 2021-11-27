
#include <limits.h>
#include "gtest/gtest.h"

#define protected public
#define private public
#include "Entleerer.h"
#undef protected
#undef private

 class EntleererTest : public ::testing::Test {
  protected:
  Entleerer* e;

  virtual void SetUp(){
    e = new Entleerer();
  }

  virtual void TearDown(){
    delete e;
  }
};

/*TEST_F(EntleererTest, testDoItForCorrectInputStoring){
  float testVal = 4.2;
  e->doIt(testVal);
  EXPECT_EQ(testVal,e->getValue());
}*/
