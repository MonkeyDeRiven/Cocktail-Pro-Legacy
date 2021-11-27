#include "gtest/gtest.h"

#define protected public
#define private public
#include "Schuettler.h"
#undef protected
#undef private

class SchuettlerTest : public ::testing::Test {
 protected:
  Schuettler* r;
  float turbo=20;

  virtual void SetUp() {
    r = new Schuettler();
    r->myTimer->set_Turbo(turbo);
  }

  virtual void TearDown() {
    delete r;
  }
};

/*TEST_F(SchuettlerTest,doIt) {
  float t = 20;
  float neededTime = r->doIt(t)*turbo;
  float expTime=t*1000;
  EXPECT_FLOAT_EQ(neededTime, expTime);
}*/