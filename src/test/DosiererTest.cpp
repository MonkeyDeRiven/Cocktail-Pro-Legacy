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
  Waage *testWaage;

  virtual void SetUp(){
    testWaage = new Waage();
    std::string testString = "TestZutat";
    d = new Dosierer(10.0, 1000, testString, testWaage);
    d->doinIt = false;
    d->grammProZeit = 10;
    d->zeiteinheit = 1000;
    d->inhalt = "TestZutat";
    Timer *t = Timer::getInstance();
    t->set_Turbo(50);
  }

  virtual void TearDown(){
    delete testWaage;
    delete d;
  }
};

TEST_F(DosiererTest, testUpdateIfItCorrectlyUpdates) {
  d->doinIt = true;
  d->gwicht = 4.2;
  d->update();
  EXPECT_EQ(d->doinIt, true);
}

TEST_F(DosiererTest, checkIfDoItDoesCorrectAmount) {
  float amount = 9.9;
  d->doIt(amount);
  EXPECT_GE(testWaage->getDelta(), amount);
}

TEST_F(DosiererTest, testGetStueckProZeitForReturnValue){
  float testVal = 6.9;
  d->grammProZeit = testVal;
  EXPECT_EQ(testVal,d->getStueckProZeit());
}
