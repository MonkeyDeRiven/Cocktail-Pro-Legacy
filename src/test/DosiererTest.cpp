#include <limits.h>
#include "gtest/gtest.h"

#define protected public
#define private public
#include "Dosierer.h"
#undef protected
#undef private

class DosiererTest : public ::testing::Test {
 protected:
  Dosierer* d;

  virtual void SetUp(){
    d = new Dosierer();
  }

  virtual void TearDown(){
    delete d;
  }
};

/*TEST_F(DosiererTest, testDoItForCorrectInputStoring){
  float testVal = 4.2;
  d->doIt(testVal);
  EXPECT_EQ(testVal,d->getGwicht());
}*/

TEST_F(DosiererTest, testGetStueckProZeitForReturnValue){
  float testVal = 6.9;
  d->grammProZeit = testVal;
  EXPECT_EQ(testVal,d->getStueckProZeit());
}

TEST_F(DosiererTest, testGetGwichtForReturnValue){
  float testVal = 6.4;
  d->gwicht = testVal;
  EXPECT_EQ(testVal,d->getGwicht());
}
