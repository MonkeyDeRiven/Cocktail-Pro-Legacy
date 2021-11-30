
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
  Waage *testWaage;

  virtual void SetUp(){
    testWaage = new Waage();
    std::string testString = "TestZutat";
    e = new Entleerer(12, 1000, testWaage);
    e->doinIt = false;
    e->grammProZeit = 12;
    e->zeiteinheit = 1000;
    Timer *t = Timer::getInstance();
    t->set_Turbo(50);
  }

  virtual void TearDown(){
    delete testWaage;
    delete e;
  }
};

TEST_F(EntleererTest, testUpdateIfItCorrectlyUpdates) {
  e->doIt(3);
  EXPECT_EQ(0, e->doinIt);
  EXPECT_EQ(3, e->value);
}

TEST_F(EntleererTest, updateReturnDoinitTrue) {
  e->doinIt = false;
  e->value = 12;
  e->update();
  EXPECT_EQ(0, e->doinIt);
}
