
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
    e->myWaage = new Waage();
    e->myTimer = new Timer();
    e->doinIt = true;
    e->update();
  }

  virtual void TearDown(){
    delete e;
  }
};

TEST_F(EntleererTest, testUpdateForCheckpointReached){
  EXPECT_EQ(true, e->testCeckpoint);
}

TEST_F(EntleererTest, testUpdateForCheckpoint2Reached){
  EXPECT_EQ(false, e->testCeckpoint2);
}
