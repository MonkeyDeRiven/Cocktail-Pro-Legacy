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
    d->myWaage = new Waage();
    d->myTimer = new Timer();
    d->doinIt = true;
    d->update();
  }

  virtual void TearDown(){
    delete d;
  }
};

TEST_F(DosiererTest, testUpdateForCheckpointReached){
  EXPECT_EQ(true, d->testCheckpoint);

  d->doinIt = false;
  EXPECT_EQ()

}

TEST_F(DosiererTest, testUpdateForCheckpoint2Reached){
  EXPECT_EQ(false, d->testCheckpoint2);
}

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

