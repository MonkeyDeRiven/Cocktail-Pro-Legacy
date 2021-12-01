#include "gtest/gtest.h"

#include <sys/time.h>
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

TEST_F(SchuettlerTest,doIt) {
  float t = 20;
  EXPECT_EQ(r->doIt(t), true);
}