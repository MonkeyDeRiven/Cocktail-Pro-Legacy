#include "gtest/gtest.h"

#define private public
#include "Timer.h"

class TimerTest : public ::testing::Test {
 protected:
  Timer* t;

  virtual void SetUp() {
    t = new Timer();

  }

  virtual void TearDown() {
    delete t;
  }
};

TEST_F(TimerTest,setTurboTest) {
  t->set_Turbo(20);
  EXPECT_EQ(t->booster,20);
}


TEST_F(TimerTest,getInstanceTest) {
  Timer* testTimer;
  t->instanceFlag=true;
  testTimer = t->getInstance();
  EXPECT_EQ(testTimer->theTimer,t->theTimer);

  t->instanceFlag=false;
  testTimer = t->getInstance();
  EXPECT_EQ(testTimer->theTimer,t->theTimer);
}

TEST_F(TimerTest,sleepTest) {
  EXPECT_EQ(t->sleep(100),true);
}

TEST_F(TimerTest,sleep_in_intervals_Test) {
  EXPECT_EQ(t->sleep_in_intervals(100),true);
}