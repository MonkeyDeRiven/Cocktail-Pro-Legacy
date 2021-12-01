#include "gtest/gtest.h"

#include <sys/time.h>
#define protected public
#define private public
#include "Stampfer.h"
#undef protected
#undef private

class StampferTest : public ::testing::Test {
 protected:
  Stampfer* r;
  float turbo=20;

  virtual void SetUp() {
    r = new Stampfer();
    r->myTimer->set_Turbo(turbo);
  }

  virtual void TearDown() {
    delete r;
  }
};

TEST_F(StampferTest,doIt) {
  float t=20;
  EXPECT_EQ(r->doIt(t), true);
}